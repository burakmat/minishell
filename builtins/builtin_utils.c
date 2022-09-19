/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:03:27 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 22:11:31 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_builtin(char *s1, char *s2)
{
	char	*last;
	int		b;

	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&last[b], s2, ft_strlen(s2) + 1);
	free(s1);
	return (last);
}

int	ft_strncmp_builtin(char *s1, char *s2, int a)
{
	int	i;

	i = 0;
	while (i < a && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '=' || s1[i] == '\0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strjoin_env(char *s1, char *s2)
{
	char	*last;
	int		b;

	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&last[b], s2, ft_strlen(s2) + 1);
	free(s2);
	return (last);
}

char	*ft_strdup_env(char *s1)
{
	char	*s;
	int		len;
	int		i;
	int		a;

	i = 0;
	a = 5;
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * len - 4);
	if (!s)
		return (0);
	while (s1[a] != '\0')
	{
		s[i] = s1[a];
		i++;
		a++;
	}
	s[i] = '\0';
	return (s);
}
