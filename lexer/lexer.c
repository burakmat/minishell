/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 12:47:53 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	tolex->box2space = 2;
	i = 0;
	i += firstbox(argv, tolex);
	i += secondbox(argv + i, tolex);
	i += thirdbox(argv + i, tolex);
	(void) shell;
	printf("firstbox %s\n", tolex->box1);
	printf("secondbox %s\n", tolex->box2);
	printf("third %s\n", tolex->box3);
	printf("%d\n", tolex->error.illegalflag);
	return (1);
}
