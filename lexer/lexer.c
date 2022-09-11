/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/10 10:33:27 by osyalcin         ###   ########.fr       */
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
	tolex->currentnode += 1;
	/*printf("firstbox %p\n", tolex->box1);
	printf("illegalcomand %d\n", tolex->illegalcommand);
	printf("secondbox %p\n", tolex->box2);
	printf("thirdbox %p\n", tolex->box3);
	printf("\n%d\n", tolex->box3null);
	printf("\nfourth %p\n", tolex->box4);
	printf("aloo %d\n", tolex->illegalflag);*/
	if (argv[i] == '|')
		lexer(argv + i + 1, tolex, shell);
	shell->totalnode = tolex->totalnode;
	return (1);
}