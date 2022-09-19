/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totalnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:45:10 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/15 10:48:29 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	totalnode(char *argv, t_lexout *tolex, t_shell *shell)
{
	int	i;

	i = 0;
	tolex->totalnode = 1;
	while (argv[i] != '\0')
	{
		if (argv[i] == '"')
			i += totalnodeinquote(argv + i, shell);
		else if (argv[i] == 39)
			i += totalnodeinsinglequote(argv + i, shell);
		else if (argv[i] == '|')
			tolex->totalnode++;
		i++;
	}
}

int	totalnodeinquote(char *argv, t_shell *shell)
{
	int	i;

	i = 1;
	while (argv[i] != '"' && argv[i] != '\0')
		i++;
	if (argv[i] != '"')
		shell->err_code = 5;
	return (i);
}

int	totalnodeinsinglequote(char *argv, t_shell *shell)
{
	int	i;

	i = 1;
	while (argv[i] != 39 && argv[i] != '\0')
		i++;
	if (argv[i] != 39)
		shell->err_code = 5;
	return (i);
}
