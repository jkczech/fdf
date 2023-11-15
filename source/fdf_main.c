/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:01:25 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/14 11:05:57 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Wrong number of parameters\n");
		return (0);
	}
	data.map = map_init(argv[1]);
	data.map.size_y = file_len(data.map.path, 0);
	if (map_parse(&data.map) != -1)
	{
		set_init(&data);
		dim_init(&data);
		map_display(data);
	}
	map_free(data.map);
	return (0);
}

void	set_init(t_data *data)
{
	data->dim.projection = 1;
	data->dim.step = 1;
	data->dim.cs = 1;
	data->dim.dim = 0;
}

void	dim_init(t_data *data)
{
	double	diagonal;

	diagonal = sqrt(pow(data->map.size_x, 2) + pow(data->map.size_y, 2));
	if ((data->map.z.size) == 0)
		data->dim.height = 1.0;
	else
		data->dim.height = 10.0 / data->map.z.size;
	data->dim.size = (600 / diagonal);
	data->dim.shift_x = WIN_SIZE_X / 2 + 70;
	data->dim.shift_y = WIN_SIZE_Y / 2;
	if (data->dim.projection == 1)
	{
		data->dim.rotation_x = 0.0;
		data->dim.rotation_z = 0.0;
	}
	else
	{
		data->dim.rotation_x = -PI / 4 - PI / 16;
		data->dim.rotation_z = -PI / 4;
	}
	data->dim.rotation_y = 0.0;
	if (ft_strncmp(data->map.name, "42.fdf", 6) == 0)
		data->dim.height = 0.15;
}

/* void	print_map_dimensions(t_map map)
{
	char	*num;

	num = ft_dtoa(map.size_x, 3);
	ft_printf("size x: %s\n", num);
	free(num);
	num = ft_dtoa(map.size_y, 3);
	ft_printf("size y: %s\n", num);
	free(num);
	num = ft_dtoa(map.z.min, 3);
	ft_printf("size zm: %s\n", num);
	free(num);
	num = ft_dtoa(map.z.max, 3);
	ft_printf("size zM: %s\n", num);
	free(num);
} */
//never gets to map free and return or does it

/* void	delay(int num)
{
	int		ms;
	clock_t	start_time;

	ms = 1000 * num;
	start_time = clock();
	while (clock() < start_time + ms)
		continue ;
} */
