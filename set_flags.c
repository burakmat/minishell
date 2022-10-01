/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:31:36 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 10:31:37 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	legal_flag_manager(t_node *node)
{
	int		i;
	char	**flags;
	char	**tmp;

	free(node->exec_args[1]);
	free(node->exec_args[0]);
	free(node->exec_args);
	node->exec_args = NULL;
	flags = ft_split(node->flags, ' ');
	i = 0;
	while (flags[i])
		++i;
	tmp = malloc(sizeof(char *) * (i + 2));
	tmp[0] = ft_strdup(node->command);
	i = 0;
	while (flags[i] != NULL)
	{
		tmp[i + 1] = flags[i];
		i++;
	}
	tmp[i + 1] = flags[i];
	node->exec_args = tmp;
	free(flags);
}

void	set_flags(t_shell *shell, t_node *node)
{
	(void)shell;
	if (node->flags != NULL)
	{
		if (node->illegalflag == 1)
		{
			node->exec_args = malloc(sizeof(char *) * 3);
			node->exec_args[0] = ft_strdup(node->command);
			node->exec_args[1] = ft_strdup(node->flags);
			node->exec_args[2] = NULL;
		}
		else
			legal_flag_manager(node);
	}
}
