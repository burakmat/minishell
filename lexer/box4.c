/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:06:38 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 17:41:07 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void fourthbox(char *argv, t_lexout *tolex)
{
	int i;

	i = 0;
	while (argv[i] != '\0' && argv[i] != '|')
	{
		if (argv[i] == '"')
			i += box4passquote(argv + i);
		else if (argv[i] == 39)
			i += box4passsinglequote(argv + i);
		else if(argv[i] == '<')
		{
			if (argv[i + 1] == '<')
				i += box4lessless(argv + i, tolex);
			else if (argv[i + 1] == '>')
				i += box4wtf(argv + i, tolex);
			else
				i += box4less(argv + i, tolex);
		}
		else if(argv[i] == '>')
		{
			if (argv[i + 1] == '>')
				i += box4greatgreat(argv + i, tolex);
			else
				i += box4great(argv + i, tolex);
		}
		else
		{
			tolex->box4space = 1;
			i++;
		}	
	}
}

int box4passquote(char *argv)
{
	int i;

	i = 1;
	while (argv[i] != '"' && argv[i] != '\0')
		i++;
	return (i + 1);
}

int box4passsinglequote(char *argv)
{
	int i;

	i = 1;
	while (argv[i] != 39 && argv[i] != '\0')
		i++;
	return (i + 1);
}

int box4inquote_mode2(char *argv, t_lexout *tolex)
{
	int i;

	i = 0;
	argv[i++] = 32;
	while (argv[i] != '"' && argv[i] != '\0')
	{
		tolex->box4[tolex->box4index++] = argv[i];
		argv[i++] = 32;
	}
	argv[i++] = 32;
	return(i);	
}

int box4insinglequote_mode2(char *argv, t_lexout *tolex)
{
	int i;

	i = 0;
	argv[i++] = 32;
	while (argv[i] != 39 && argv[i] != '\0')
	{
		tolex->box4[tolex->box4index++] = argv[i];
		argv[i++] = 32;
	}
	argv[i++] = 32;
	return(i);	
}