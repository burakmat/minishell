/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 15:30:00 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	tolex->box2space = 2;
	i = 0;
	(void) shell;
	fourthbox(argv, tolex);
	printf("%s\n", argv);
	i += firstbox(argv, tolex);
	i += secondbox(argv + i, tolex);
	i += thirdbox(argv + i, tolex);
	fourthbox(argv, tolex);
	printf("firstbox %s\n", tolex->box1);
	printf("secondbox %s\n", tolex->box2);
	printf("third %s\n", tolex->box3);
	printf("fourth %s\n", tolex->box4);
	printf("%d\n", tolex->error.illegalflag);
	return (1);
}
