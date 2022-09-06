/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:01:06 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/25 03:08:04 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*d;

	a = 0;
	if (!s)
		return (0);
	d = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (0);
	while (s[a])
	{
			d[a] = f(a, s[a]);
			a++;
	}
	d[a] = '\0';
	return (d);
}
