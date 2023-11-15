/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:28:46 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 16:52:56 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_data *data, t_point begin, t_point end, int color)
{
	double	length;
	double	step_x;
	double	step_y;
	double	step_z;
	int		i;

	length = fmax(fabs(end.x - begin.x), fabs(end.y - begin.y));
	length = fmax(length, fabs(end.z - begin.z));
	step_x = (end.x - begin.x) / length;
	step_y = (end.y - begin.y) / length;
	step_z = (end.z - begin.z) / length;
	i = 0;
	while (i <= length)
	{
		put_point(*data, begin, color);
		begin.x += step_x;
		begin.y += step_y;
		begin.z += step_z;
		i++;
	}
}

void	draw_map(t_data data)
{
	t_point	curr;
	int		x;
	int		y;

	y = 0;
	while (y < data.map.size_y)
	{
		x = 0;
		while (x < data.map.size_x)
		{
			curr = (t_point){(x -(data.map.size_x / 2)) * data.dim.size,
				(y -(data.map.size_y / 2)) * data.dim.size,
				data.map.data[y][x] * data.dim.size * data.dim.height};
			draw_grid(data, curr, x + 1, y);
			draw_grid(data, curr, x, y + 1);
			x++;
		}
		y++;
	}
}

void	draw_grid(t_data data, t_point curr, int x, int y)
{
	t_point	next;

	if (y < data.map.size_y && x < data.map.size_x)
	{
		next = (t_point){(x -(data.map.size_x / 2)) * data.dim.size,
			(y -(data.map.size_y / 2)) * data.dim.size,
			(data.map.data[y][x]) * data.dim.size * data.dim.height};
		if (curr.x * curr.x + curr.y * curr.y > 100000)
			return ;
		draw_line(&data, curr, next, -1);
	}
}

/* void	draw_axis(t_data data)
{
	t_point	end1;
	t_point	end2;

	end1 = (t_point){-1 + data.dim.offset_x, -1 + data.dim.offset_y,
		-100 * data.dim.size + data.dim.offset_z};
	end2 = (t_point){-1 + data.dim.offset_x, -1 + data.dim.offset_y,
		100 * data.dim.size + data.dim.offset_z};
	draw_line(&data, end1, end2, RED);
	end1 = (t_point){-1 + data.dim.offset_x,
		100 * data.dim.size + data.dim.offset_y, 0 + data.dim.offset_z};
	end2 = (t_point){-1 + data.dim.offset_x,
		-100 * data.dim.size + data.dim.offset_y, 0 + data.dim.offset_z};
	draw_line(&data, end1, end2, GREEN);
	end1 = (t_point){100 * data.dim.size + data.dim.offset_x,
		-1 + data.dim.offset_y, 0 + data.dim.offset_z};
	end2 = (t_point){-100 * data.dim.size + data.dim.offset_x,
		-1 + data.dim.offset_y, 0 + data.dim.offset_z};
	draw_line(&data, end1, end2, BLUE);
} */
