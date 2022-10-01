/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:21:34 by bmat              #+#    #+#             */
/*   Updated: 2022/09/23 12:07:45 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *s1)
{
	int	a;

	if (!s1)
		return (0);
	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

unsigned int	str_in_array(char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	ind1;
	unsigned int	ind2;

	if (!s1)
		return (s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ind1 = 0;
	while (s1[ind1])
	{
		str[ind1] = s1[ind1];
		ind1++;
	}
	ind2 = 0;
	while (s2[ind2])
		str[ind1++] = s2[ind2++];
	str[ind1] = '\0';
	free(s1);
	if (s2 != NULL)
		free(s2);
	return (str);
}
