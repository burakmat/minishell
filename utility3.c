/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:22:50 by bmat              #+#    #+#             */
/*   Updated: 2022/09/18 15:22:51 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp_exact(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0')
		return (0);
	return (1);
}

int	ft_strlcpy(char *dst, char *src, int b)
{
	int	a;
	int	c;

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

char	*ft_strjoin_path(char *s1, char *s2)
{
	char	*last;
	int		b;

	if (s2 == NULL)
		return (ft_strdup(s1));
	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!last || !s1)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	last[b] = '/';
	ft_strlcpy(&last[b + 1], s2, ft_strlen(s2) + 1);
	return (last);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ps;

	ps = malloc(size * count);
	if (ps == 0)
		return (0);
	ft_bzero(ps, size * count);
	return (ps);
}
