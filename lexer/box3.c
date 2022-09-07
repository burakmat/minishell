/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:49 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 15:36:37 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	i += lexer_escapespace(argv, tolex);
	while (argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box3inquote(argv + i, tolex);
		else
			tolex->box3[tolex->box3index++] = argv[i++];
		i += lexer_escapespace(argv + i, tolex);
	}
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
	return (i);
}

int	box3escapespace(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	while (((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '\0')
	{
		i++;	
		tolex->box4space = 1;
	}
	return (i);
}
