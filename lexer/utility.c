/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:10:16 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 12:40:59 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen(char *s1)
{
	int	a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*last;
	int		b;

	a = 0;
	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	while (b > a)
	{
		last[a] = s1[a];
		a++;
	}
	a = 0;
	while (ft_strlen(s1) + ft_strlen(s2) > a)
	{
		last[b + a] = s2[a];
		a++;
	}
	free(s1);
	free(s2);
	return (last);
}

int	escapespace(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '\0')
	{
		while (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && argv[i] != '\0')
			i++;
		if (tolex->box2space == 2 && tolex->box2index != 0)
			tolex->box2[tolex->box2index++] = 32;
		tolex->box2lastisspace = 1;
	}
	return (i);
}
