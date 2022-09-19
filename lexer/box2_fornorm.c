/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box2_fornorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:48:15 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 20:15:19 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_second_box_null(t_lexout *tolex)
{
	if (tolex->box2index == 0)
	{
		free(tolex->box2);
		tolex->box2 = NULL;
	}
	if (tolex->box2index > 0)
	{
		tolex->box2[tolex->box2index++] = '\0';
	}
}

int	secondbox_fornorm(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == 39)
		return (2);
	if (argv[i] != '-' && (isbeforeflag(tolex) || tolex->box2lastisspace == 1))
	{
		tolex->box2runaway = 1;
		return (0);
	}
	return (1);
}

int	secondbox_fornorm_v2(char *argv, t_lexout *tolex)
{
	int	i;

	i = 1;
	if (argv[i] == '"')
		return (2);
	if (argv[i] != '-' && (isbeforeflag(tolex) || tolex->box2lastisspace == 1))
	{
		tolex->box2runaway = 1;
		return (0);
	}
	return (1);
}
