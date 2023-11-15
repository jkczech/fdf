/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:11:03 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/14 11:07:22 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "macros.h"
# include "structures.h"

//libraries
# include "../library/libft/libft.h"
# include "../library/get_next_line/get_next_line.h"
# include "../library/printf/ft_printf.h"

//fdf_array.c
int		array_len(char **array);
int		*atoi_array(char **char_map);
void	array_free(char **array);

//fdf_draw.c
void	draw_line(t_data *data, t_point begin, t_point end, int color);
void	draw_map(t_data data);
void	draw_grid(t_data data, t_point curr, int x, int y);

//fdf_hook.c
void	translation_hook(int keycode, t_data *data);
void	rotation_hook(int keycode, t_data *data);
void	zoom_hook(int keycode, t_data *data);
void	invert_hook(int keycode, t_data *data);

//fdf_legend.c
void	put_legend(t_data data, int custom);
void	show_dim(t_data data, int custom);
void	mlx_putl(t_data data, t_lstr leg);

//fdf_main.c
int		main(int argc, char **argv);
void	set_init(t_data *data);
void	dim_init(t_data *data);

//fdf_map.c
t_map	map_init(char *map_name);
int		file_len(char *file, int len);
int		map_parse(t_map *map);
void	map_free(t_map map);
int		count_nl(char *str, int readlen);
void	calc_z(t_map *map, int *row);

//fdf_mlx.c
int		mlx_close(t_data *data);
int		key_hook(int keycode, t_data *data);
void	map_display(t_data data);
int		put_pixel(t_data *data, int x, int y, int color);

//fdf_point.c
void	rotate(t_data data, t_point *point);
void	put_point(t_data data, t_point point, int color);
float	lerp(float a, float b, float t);
int		lerp_color(t_data data, t_cs cs, double z, int color);
t_cs	set_cs(t_data data);

//test
/* void	draw_axis(t_data data); */
/* void	print_map_dimensions(t_map map); */
/* void	print_point(t_point point); */
/* void	map_print(t_map map); */
/* void	angle_hook(int keycode, t_data *data); */
#endif
