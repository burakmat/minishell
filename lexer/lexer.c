/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/06 18:16:15 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	i = 0;
	i += firstbox(argv, tolex);
	i += escapespace(argv + i, tolex);
	printf("i bura %d\n", i);
	tolex-> box2space = 2;
	i += secondbox(argv + i, tolex);
	(void) shell;
	printf("firstbox %s\n", tolex->box1);
	printf("secondbox %s\n", tolex->box2);
	return (1);
}
