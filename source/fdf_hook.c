/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:25:46 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 10:58:40 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//2468
void	translation_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->dim.shift_x -= data->dim.size * data->dim.step;
	else if (keycode == 65363)
		data->dim.shift_x += data->dim.size * data->dim.step;
	else if (keycode == 65362)
		data->dim.shift_y -= data->dim.size * data->dim.step;
	else if (keycode == 65364)
		data->dim.shift_y += data->dim.size * data->dim.step;
	else if (keycode == 99)
	{
		if (data->dim.cs == 1)
			data->dim.cs = 2;
		else if (data->dim.cs == 2)
			data->dim.cs = 3;
		else
			data->dim.cs = 1;
	}
}

void	rotation_hook(int keycode, t_data *data)
{
	if (keycode == 111)
		data->dim.rotation_x -= PI / 18;
	else if (keycode == 112)
		data->dim.rotation_x += PI / 18;
	else if (keycode == 107)
		data->dim.rotation_y -= PI / 18;
	else if (keycode == 108)
		data->dim.rotation_y += PI / 18;
	else if (keycode == 110)
		data->dim.rotation_z -= PI / 18;
	else if (keycode == 109)
		data->dim.rotation_z += PI / 18;
}

//+-* Space Enter/
void	zoom_hook(int keycode, t_data *data)
{
	if (keycode == 65453 || keycode == 45)
		data->dim.size *= pow(0.95, data->dim.step);
	else if (keycode == 65451 || keycode == 43)
		data->dim.size *= pow(1.05, data->dim.step);
	else if (keycode == 65455)
		data->dim.height *= pow(0.96, data->dim.step);
	else if (keycode == 65450)
		data->dim.height *= pow(1.04, data->dim.step);
	else if (keycode == 32)
	{
		if (data->dim.projection == 1)
		{
			dim_init(data);
			data->dim.projection = 2;
			data->dim.rotation_x = -PI / 4 - PI / 16;
			data->dim.rotation_z = -PI / 4;
		}
		else
		{
			data->dim.projection = 1;
			dim_init(data);
		}
	}
}

//DS
void	invert_hook(int keycode, t_data *data)
{
	if (keycode == 114)
		dim_init(data);
	if (keycode == 100)
	{
		if (data->dim.dim == 0)
			data->dim.dim = 1;
		else
			data->dim.dim = 0;
	}
	else if (keycode == 115)
	{
		if (data->dim.step == 1)
			data->dim.step = 2;
		else if (data->dim.step == 2)
			data->dim.step = 4;
		else if (data->dim.step == 4)
			data->dim.step = 8;
		else
			data->dim.step = 1;
	}
}

/* //1234R
void	angle_hook(int keycode, t_data *data)
{
	if (keycode == 49)
		data->dim.angle_cos -= 0.1;
	else if (keycode == 50)
		data->dim.angle_cos += 0.1;
	else if (keycode == 51)
		data->dim.angle_sin -= 0.1;
	else if (keycode == 52)
		data->dim.angle_sin += 0.1;
	else if (keycode == 114)
		dim_init(data);
} */

/*
int	key_hook(int keycode, t_data *data)
{
	ft_printf("pressed %d\n", keycode);
	
	
	else if (keycode == 65421)
	{
		if (data->dim.invert == 0)
			data->dim.invert = 2;
		else
			data->dim.invert = 0;
	}
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_map(*data);
	put_legend(*data, keycode);
	return (0);
}
*/

/* if (keycode == 65361 + data->dim.invert)
		data->dim.offset_x -= data->dim.size * data->dim.step;
	else if (keycode == 65363 - data->dim.invert)
		data->dim.offset_x += data->dim.size * data->dim.step;
	else if (keycode == 65362 + data->dim.invert)
		data->dim.offset_y -= data->dim.size * data->dim.step;
	else if (keycode == 65364 - data->dim.invert)
		data->dim.offset_y += data->dim.size * data->dim.step;
	else if (keycode == 65366)
		data->dim.offset_z -= data->dim.height * data->dim.size
			* data->dim.step;
	else if (keycode == 65365)
		data->dim.offset_z += data->dim.height * data->dim.size
			* data->dim.step; */
