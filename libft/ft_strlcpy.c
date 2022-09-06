/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:51:03 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/24 18:50:24 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t b)
{
	size_t	a;
	size_t	c;

	a = 0;
	c = ft_strlen(src);
	if (b > 0)
	{
		while (a < b - 1 && src[a])
		{
			dst[a] = src[a];
			a++;
		}
			dst[a] = '\0';
	}
	return (c);
}
