/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:32 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 13:10:07 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	secondbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	i += escapespace(argv + i, tolex);
	while (tolex->box2runaway != 1 && argv[i] != '\0')
	{
		if (argv[i] == '"')
			i += secondboxinquote(argv + i, tolex);
		else if (argv[i] == 39)
			i += secondboxinsinglequote(argv + i, tolex);
		else if (argv[i] == '-')
		{
			if (((argv[i + 1] <= 13 && argv[i + 1] >= 9) || argv[i + 1] == 32))
			{
				tolex->box2runaway = 1;
				return (i);
			}
			while (!((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32) && argv[i] != '"' && argv[i] != '\0' && argv[i] != 39)
				tolex->box2[tolex->box2index++] = argv[i++];
			tolex->box2lastisspace = 0;
		}
		else if (tolex->box2index > 0 && tolex->box2lastisspace != 1)
		{
			tolex->box2[tolex->box2index++] = argv[i++];
			tolex->box2lastisspace = 0;
		}
		else
			tolex->box2runaway = 1;
		i += escapespace(argv + i, tolex);
	}
	return (i);
}

int	secondboxinquote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == '"')
	{
		i++;
		return (i);
	}
	if (argv[i] != '-' && (isbeforeflag(tolex) || tolex->box2lastisspace == 1))
	{
		tolex->box2runaway = 1;
		return (0);
	}
	else
	{
		if (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && tolex->box2lastisspace == 1)
		{
			tolex->box2runaway = 1;
			return (0);
		}
		while (argv[i] != '"')
		{
			if ((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32)
				tolex->error.illegalflag = 1;
			tolex->box2[tolex->box2index++] = argv[i++];
		}
	}
	tolex->box2lastisspace = 0;
	return (i + 1);
}

int	secondboxinsinglequote(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == 39)
	{
		i++;
		return (i);
	}
	if (argv[i] != '-' && (isbeforeflag(tolex) || tolex->box2lastisspace == 1))
	{
		tolex->box2runaway = 1;
		return (0);
	}
	else
	{
		if (((argv[i] <= 13 && argv[i] >= 9)
				|| argv[i] == 32) && tolex->box2lastisspace == 1)
		{
			tolex->box2runaway = 1;
			return (0);
		}
		while (argv[i] != 39)
		{
			if ((argv[i] <= 13 && argv[i] >= 9) || argv[i] == 32)
				tolex->error.illegalflag = 1;
			tolex->box2[tolex->box2index++] = argv[i++];
		}
	}
	tolex->box2lastisspace = 0;
	return (i + 1);
}

int	isbeforeflag(t_lexout *tolex)
{
	int	i;

	i = tolex->box2index;
	if (tolex->box2index == 0)
		return (1);
	if (((tolex->box2[i] <= 13 && tolex->box2[i] >= 9)
			|| tolex->box2[i] == 32))
		return (1);
	return (0);
}
