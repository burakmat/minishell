/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:07:40 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/24 19:49:57 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*son;
	size_t	a;

	a = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	son = malloc(sizeof(char) * len + 1);
	if (!son)
		return (0);
	while (a < len && s[start + a])
	{
		son[a] = s[start + a];
		a++;
	}
	son[a] = '\0';
	return (son);
}
