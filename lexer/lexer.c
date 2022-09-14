/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:14 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/14 12:14:00 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	tolex->box2space = 2;
	i = 0;
	fillboxes(tolex, shell);
	fourthbox(argv, tolex);
	i += firstbox(argv, tolex);
	i += secondbox(argv + i, tolex);
	i += thirdbox(argv + i, tolex);
	if (argv[0] != '|')
		create_node(shell, tolex);
	else
		shell->err_code = 4;
	tolex->currentnode += 1;
	// printf("firstbox %s\n", tolex->box1);
	// printf("illegalcomand %d\n", tolex->illegalcommand);
	// printf("secondbox %p\n", tolex->box2);
	// printf("thirdbox %s\n", tolex->box3);
	// printf("\n%d\n", tolex->box3null);
	// printf("\nfourth -%s\n", tolex->box4);
	// printf("aloo %d\n", tolex->illegalflag);
	if (argv[i] == '|' && argv[0] != '|')
		lexer(argv + i + 1, tolex, shell);
	shell->totalnode = tolex->totalnode;
	return (1);
}