/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:49 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 12:22:14 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	before_thirdbox(char *argv, t_lexout *tolex)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	a += box3escapespace(argv, tolex);
	i += thirdbox(argv, tolex, a);
	return (i);
}

int	thirdbox(char *argv, t_lexout *tolex, int i)
{
	while (argv[i] != '\0' && argv[i] != '|')
	{
		if (tolex->box3space == 1)
		{
			tolex->box3[tolex->box3index++] = '\0';
			tolex->box3null++;
			tolex->box3space = 0;
		}
		else if (argv[i] == '"')
			i += box3inquote(argv + i, tolex);
		else if (argv[i] == 39)
			i += box3insinglequote(argv + i, tolex);
		else
		{
			tolex->box3[tolex->box3index++] = argv[i++];
			tolex->box3space = 0;
		}
		i += box3escapespace(argv + i, tolex);
	}
	if (thirdbox_is_null(tolex))
		return (i);
	tolex->box3[tolex->box3index++] = '\0';
	tolex->box3null++;
	return (i);
}

int	box3insinglequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == 39)
	{
		i++;
		return (i);
	}
	while (argv[i] != 39)
	{
		tolex->box3[tolex->box3index++] = argv[i++];
	}
	i++;
	tolex->box3space = 0;
	return (i);
}

int	box3inquote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == '"')
	{
		i++;
		return (i);
	}
	while (argv[i] != '"')
	{
		tolex->box3[tolex->box3index++] = argv[i++];
	}
	i++;
	tolex->box3space = 0;
	return (i);
}

int	box3escapespace(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	if (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '\0')
	{
		while (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) \
			&& argv[i] != '\0')
			i++;
		if (tolex->box3index > 0)
			tolex->box3space = 1;
	}
	return (i);
}
