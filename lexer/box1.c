/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:16:51 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/06 13:34:42 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	firstbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	while (argv[i] == ' ' && argv[i] != '\0')
		i++;
	while (argv[i] != ' ' && argv[i] != '\0')
	{
		if (argv[i] == '"')
			i += box1indoublequote(argv + i, tolex);
		if (argv[i] == 39)
			i += box1insinglequote(argv + i, tolex);
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	return (i);
}

int	box1indoublequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	while (argv[i] != '"')
	{
		if (argv[i] == ' ')
		{
			printf("ERROR\n");
			exit(1);
		}
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
		if (argv[i] == ' ')
		{
			printf("ERROR\n");
			exit(1);
		}
		tolex->box1[tolex->box1index++] = argv[i++];
	}
	i++;
	return (i);
}
