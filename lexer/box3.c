/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:49 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 12:09:26 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	i = escapespace(argv, tolex);
	while (argv[i] != '\0')
		tolex->box3[tolex->box3index++] = argv[i++];
	return (i);
}
