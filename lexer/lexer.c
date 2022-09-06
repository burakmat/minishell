/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/06 14:47:11 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

int	lexer(char *argv, t_lexout *tolex)
{
	int	i;

	i = 0;
	i += firstbox(argv, tolex);
	i += escapespace(argv + i);
	printf("firstbox %s\n", tolex->box1);
	return (1);
}
