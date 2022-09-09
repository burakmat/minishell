/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:16:51 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/09 13:12:54 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	firstbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	while (((argv[i] <= 13 && argv[i] >= 9)
			|| argv[i] == 32) && argv[i] != '\0')
		i++;
	while (!((argv[i] <= 13 && argv[i] >= 9)
			|| argv[i] == 32) && argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box1indoublequote(argv + i, tolex);
		else if (argv[i] == 39)
			i += box1insinglequote(argv + i, tolex);
		else if (argv[i] != '"' && argv[i] != 39)
			tolex->box1[tolex->box1index++] = argv[i++];
	}
	if (tolex->box1index == 0)
		tolex->box1 = NULL;	
	return (i);
}

int	box1indoublequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	while (argv[i] != '"')
	{
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	i++;
	return (i);
}

int	box1insinglequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	while (argv[i] != 39)
	{
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	i++;
	return (i);
}
