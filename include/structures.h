/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:22:20 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 19:24:43 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_lstr
{
	char	*text;
	float	number;
	int		precision;
	int		offset;
}	t_lstr;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;	
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_minmax
{
	int	min;
	int	max;
	int	size;
}	t_minmax;

typedef struct s_map
{
	char		*name;
	char		*path;
	int			size_x;
	int			size_y;
	t_minmax	z;
	int			**data;
}	t_map;

typedef struct s_cs
{
	int	low;
	int	mid;
	int	high;
}	t_cs;

typedef struct s_dimensions
{
	double	size;
	double	shift_x;
	double	shift_y;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	double	height;
	int		invert;
	int		dim;
	int		step;
	int		projection;
	int		cs;
}	t_dimensions;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	t_map			map;
	t_dimensions	dim;
}	t_data;