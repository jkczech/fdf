/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:37:04 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 17:35:16 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAP_PATH "../source/test_maps/"
# define WIN_SIZE_X 960//1920 
# define WIN_SIZE_Y 540//1080 
# define WHITE 0xF3F3F3
# define BLACK 0x000000
# define RED 0xE63939
# define GREEN 0x66C36A
# define BLUE 0x5786AF
# define GRAY 0xC8C9C7
# define PI 3.14159265359
# define BBLUE 0x0000FF
# define WWHITE 0xFFFFFF

// Standard C functions
// perror
# include <stdio.h>
// malloc, free, and exit
# include <stdlib.h>
// strerror
# include <string.h>
// open, close, read, and write
# include <unistd.h>
// open
# include <fcntl.h>

// Math functions
# include <math.h>

// MiniLibX
# include <mlx.h>

#endif