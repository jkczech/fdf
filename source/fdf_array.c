/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:15:21 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/13 11:37:25 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	array_len(char **array)
{
	int	len;

	if (!array)
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}

int	*atoi_array(char **char_array)
{
	int	*int_array;
	int	i;

	if (!char_array)
		return (0);
	int_array = malloc((array_len(char_array) + 1) * sizeof(int));
	if (!int_array)
		return (0);
	i = 0;
	while (char_array[i])
	{
		int_array[i] = ft_atoi(char_array[i]);
		i++;
	}
	return (int_array);
}

void	array_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
