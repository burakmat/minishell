/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totalnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:45:10 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/08 17:52:23 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	totalnode(char *argv, t_lexout *tolex)
{
	int i;

	i = 0;
	tolex->totalnode = 1;
	while (argv[i] != '\0')
	{
		if(argv[i] == '"')
			i += totalnodeinquote(argv + i);
		if(argv[i] == 39)
			i += totalnodeinsinglequote(argv + i);
		if (argv[i] == '|')
			tolex->totalnode++;
		i++;
	}
}

int	totalnodeinquote(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '"' && argv[i] != '\0')
		i++;
	return(i + 1);
}

int	totalnodeinsinglequote(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != 39 && argv[i] != '\0')
		i++;
	return(i + 1);
}