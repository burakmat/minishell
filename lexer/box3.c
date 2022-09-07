/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:49 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 18:18:30 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	i += box3escapespace(argv, tolex);
	while (argv[i] != '\0' && argv[i] != '|')
	{
		if (tolex->box3space == 1)
		{
			tolex->box3[tolex->box3index++] = '\0';
			tolex->box3null++;	
		}
		if (argv[i] == '"')
			i += box3inquote(argv + i, tolex);
		if (argv[i] == 39)
			i += box3insinglequote(argv + i, tolex);
		else
		{
			tolex->box3[tolex->box3index++] = argv[i++];
			tolex->box3space = 0;
		}
		i += box3escapespace(argv + i, tolex);
	}
	tolex->box3[tolex->box3index++] = '\0';
	tolex->box3null++;	
	return (i);
}

int	box3insinglequote(char *argv, t_lexout *tolex)
{
	int i;

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
	int i;

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
	while (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '\0')
	{
		i++;
		if (tolex->box3index > 0)
			tolex->box3space = 1;
	}
	return (i);
}
