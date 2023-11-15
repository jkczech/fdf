/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:16:18 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 10:58:33 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	mlx_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	map_free(data->map);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		return (mlx_close(data));
	translation_hook(keycode, data);
	rotation_hook(keycode, data);
	invert_hook(keycode, data);
	zoom_hook(keycode, data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_map(*data);
	put_legend(*data, keycode);
	return (0);
}

void	map_display(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		return ;
	data.win = mlx_new_window(data.mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf");
	data.img = mlx_new_image(data.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	draw_map(data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	put_legend(data, 0);
	mlx_hook(data.win, 17, 0, mlx_close, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}

int	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_SIZE_X || y >= WIN_SIZE_Y)
		return (1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}
