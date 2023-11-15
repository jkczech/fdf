/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:33:22 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 16:51:25 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_data data, t_point *point)
{
	double	temp_y;
	double	temp_x;

	temp_y = point->y;
	temp_x = point->x;
	point->y = temp_y * cos(data.dim.rotation_x)
		- point->z * sin(data.dim.rotation_x);
	point->z = temp_y * sin(data.dim.rotation_x)
		+ point->z * cos(data.dim.rotation_x);
	point->x = temp_x * cos(data.dim.rotation_y)
		+ point->z * sin(data.dim.rotation_y);
	point->z = -temp_x * sin(data.dim.rotation_y)
		+ point->z * cos(data.dim.rotation_y);
	temp_x = point->x;
	point->x = temp_x * cos(data.dim.rotation_z)
		- point->y * sin(data.dim.rotation_z);
	point->y = temp_x * sin(data.dim.rotation_z)
		+ point->y * cos(data.dim.rotation_z);
}

void	put_point(t_data data, t_point point, int color)
{
	int		my_color;
	t_cs	cs;

	cs = set_cs(data);
	my_color = lerp_color(data, cs, point.z, color);
	rotate(data, &point);
	put_pixel(&data,
		round((point.x - point.y) * cos(0.5)) + data.dim.shift_x,
		round(-point.z + (point.x + point.y) * sin(0.5)) + data.dim.shift_y,
		my_color);
}

float	lerp(float a, float b, float t)
{
	return (a + t * (b - a));
}

int	lerp_color(t_data data, t_cs cs, double z, int color)
{
	float	t;
	t_color	rgb;

	if (color != -1 || data.map.z.size == 0)
		return (cs.low);
	t = (z - data.map.z.min)
		/ (data.map.z.size * data.dim.height * data.dim.size);
	if (cs.mid != -1)
	{
		if (t <= 0.5)
			return (lerp_color(data, (t_cs){cs.low, -1, cs.mid}, z * 2, color));
		return (lerp_color(data, (t_cs){cs.mid, -1, cs.high}, z, color));
	}
	rgb.r = lerp((cs.low >> 16) & 0xFF, (cs.high >> 16) & 0xFF, t);
	rgb.g = lerp((cs.low >> 8) & 0xFF, (cs.high >> 8) & 0xFF, t);
	rgb.b = lerp(cs.low & 0xFF, cs.high & 0xFF, t);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

t_cs	set_cs(t_data data)
{
	t_cs	cs;

	if (data.dim.cs == 1)
	{
		cs.low = BLUE;
		cs.mid = GREEN;
		cs.high = WHITE;
	}
	else if (data.dim.cs == 2)
	{
		cs.low = BBLUE;
		cs.mid = -1;
		cs.high = WHITE;
	}
	else
	{
		cs.low = RED;
		cs.mid = BLUE;
		cs.high = WHITE;
	}
	return (cs);
}
