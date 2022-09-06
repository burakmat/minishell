/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:51:00 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/25 04:41:51 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = 0;
	while (s[a])
	{
		if (s[a] == (char )c)
			return ((char *)(s + a));
		a++;
	}
	if (s[a] == (char )c)
		return ((char *)(s + a));
	return (0);
}
