/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/08 13:04:19 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	tolex->box2space = 2;
	i = 0;
	fillboxes(tolex);
	fourthbox(argv, tolex);
	//printf("%s\n", argv);
	i += firstbox(argv, tolex);
	i += secondbox(argv + i, tolex);
	i += thirdbox(argv + i, tolex);

	create_node(shell, tolex);
	
	printf("firstbox %s\n", tolex->box1);
	printf("secondbox %s\n", tolex->box2);
	readbox3(tolex->box3);
	printf("\n%d\n", tolex->box3null);
	printf("\nfourth %s\n", tolex->box4);
	if (argv[i] == '|')
		lexer(argv + i + 1, tolex, shell);
	return (1);
}