/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:31:04 by jkoupy            #+#    #+#             */
/*   Updated: 2023/09/07 15:22:32 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ddest;
	const char	*ssrc;

	ddest = (char *)dest;
	ssrc = (const char *)src;
	i = 0;
	if (ddest < ssrc)
	{
		while (i < n)
		{
			ddest[i] = ssrc[i];
			i++;
		}
	}
	else if (ddest > ssrc)
	{
		while (i < n)
		{
			ddest[n - i - 1] = ssrc[n - i - 1];
			i++;
		}
	}
	return (dest);
}
