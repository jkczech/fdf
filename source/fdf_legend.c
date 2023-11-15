/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_legend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:42:19 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 19:18:43 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_legend(t_data data, int custom)
{
	mlx_string_put(data.mlx, data.win, 10, 2 * 15, WHITE,
		"      zoom: [-]/[+]");
	mlx_string_put(data.mlx, data.win, 10, 3 * 15, WHITE,
		"      move: [Arrows]");
	mlx_string_put(data.mlx, data.win, 10, 4 * 15, WHITE,
		"projection: [Space]");
	mlx_string_put(data.mlx, data.win, 10, 5 * 15, WHITE,
		"  rotation: [O/P] [K/L] [N/M]");
	mlx_string_put(data.mlx, data.win, 10, 6 * 15, WHITE,
		"     Reset: [R]");
	mlx_string_put(data.mlx, data.win, 10, 7 * 15, WHITE,
		"Dimensions: [D]");
	if (data.dim.dim == 1)
		show_dim(data, custom);
}

void	show_dim(t_data data, int custom)
{
	mlx_putl(data, (t_lstr){"    height: ", data.dim.height, 3, 9 * 15});
	mlx_putl(data, (t_lstr){"      size: ", data.dim.size, 3, 10 * 15});
	mlx_putl(data, (t_lstr){"   shift_x: ", data.dim.shift_x, 3, 11 * 15});
	mlx_putl(data, (t_lstr){"   shift_y: ", data.dim.shift_y, 3, 12 * 15});
	mlx_putl(data, (t_lstr){"projection: ", data.dim.projection, 0, 13 * 15});
	mlx_putl(data, (t_lstr){"      step: ", data.dim.step, 0, 14 * 15});
	mlx_putl(data, (t_lstr){"color mode: ", data.dim.cs, 0, 15 * 15});
	mlx_putl(data, (t_lstr){"   pressed: ", custom, 0, 16 * 15});
}

void	mlx_putl(t_data data, t_lstr leg)
{
	char		*num;
	char		*message;

	num = ft_dtoa(leg.number, leg.precision);
	message = ft_strjoin(leg.text, num);
	mlx_string_put(data.mlx, data.win, 10, leg.offset, WHITE, message);
	free(message);
	free(num);
}
/* mlx_string_put(data.mlx, data.win, 11, 201, BLACK,
		"         zoom: [-]/[+]");
	mlx_string_put(data.mlx, data.win, 11, 216, BLACK,
		"         move: arrows / bild");
	mlx_string_put(data.mlx, data.win, 11, 231, BLACK,
		"invert arrows: [Enter]");
	mlx_string_put(data.mlx, data.win, 11, 246, BLACK,
		"   cos change: [1]/[2]");
	mlx_string_put(data.mlx, data.win, 11, 261, BLACK,
		"   sin change: [3]/[4]");
	mlx_string_put(data.mlx, data.win, 11, 276, BLACK,
		"        RESET: [R]");
	mlx_string_put(data.mlx, data.win, 9, 199, BLACK,
		"         zoom: [-]/[+]");
	mlx_string_put(data.mlx, data.win, 9, 214, BLACK,
		"         move: arrows / bild");
	mlx_string_put(data.mlx, data.win, 9, 229, BLACK,
		"invert arrows: [Enter]");
	mlx_string_put(data.mlx, data.win, 9, 244, BLACK,
		"   cos change: [1]/[2]");
	mlx_string_put(data.mlx, data.win, 9, 259, BLACK,
		"   sin change: [3]/[4]");
	mlx_string_put(data.mlx, data.win, 9, 274, BLACK,
		"        RESET: [R]"); */
