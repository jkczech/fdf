/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:41:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/14 11:06:54 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	map_init(char *map_name)
{
	t_map	map;

	map.name = map_name;
	map.path = ft_strjoin(MAP_PATH, map.name);
	map.size_x = 0;
	map.size_y = 0;
	map.z.min = 0;
	map.z.max = 0;
	return (map);
}

int	file_len(char *file, int len)
{
	int		readlen;
	char	buf[BUFFER_SIZE];
	int		fd;
	int		i;

	len = 0;
	readlen = 1;
	i = BUFFER_SIZE;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (readlen)
	{
		readlen = read(fd, &buf, BUFFER_SIZE);
		if (readlen)
			i = 0;
		while (i < readlen)
		{
			if (buf[i++] == '\n')
				len++;
		}
	}
	if (buf[i - 1] != '\n')
		len++;
	return (close(fd), len);
}

int	map_parse(t_map *map)
{
	char	*line;
	char	**split;
	int		fd;
	int		i;

	map->data = malloc((map->size_y + 1) * sizeof(int *));
	fd = open(map->path, O_RDONLY);
	if (fd == -1 || !map->data)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		split = ft_split(line, ' ');
		map->size_x = array_len(split);
		map->data[i] = atoi_array(split);
		if (map->data[i] == 0)
			return (-1);
		calc_z(map, map->data[i]);
		array_free(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (close(fd));
}

void	map_free(t_map map)
{
	int	i;

	i = 0;
	if (!map.data)
		return ;
	while (i < map.size_y)
	{
		free(map.data[i]);
		i++;
	}
	free(map.data);
	free(map.path);
}

void	calc_z(t_map *map, int *row)
{
	int	i;

	i = 0;
	while (i < map->size_x)
	{
		if (row[i] < map->z.min)
			map->z.min = row[i];
		if (row[i] > map->z.max)
			map->z.max = row[i];
		i++;
	}
	map->z.size = map->z.max - map->z.min;
}

/* x_iso = (x - y) * cos(30 degrees) * scale
y_iso = -z + (x + y) * sin(30 degrees) * scale */

/* void	print_point(t_point point)
{
	ft_printf("Point x:%d, y:%d, z:%d", point.x, point.y, point.z);
} */

/* void	map_print(t_map map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map.size_y)
	{
		x = 0;
		while (x < map.size_x)
		{
			if (map.data[y][x] == 0)
				ft_printf(".  ");
			else
				ft_printf("%d ", map.data[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
} */
