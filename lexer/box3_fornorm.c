/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box3_fornorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:17:26 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 12:21:39 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thirdbox_is_null(t_lexout *tolex)
{
	if (tolex->box3index == 0)
	{
		free(tolex->box3);
		tolex->box3 = NULL;
		return (1);
	}
	return (0);
}
