/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:31:07 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 10:31:08 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**open_up_space(t_node *node, int *i)
{
	char	**tmp;

	*i = 0;
	while (node->exec_args[*i])
		++(*i);
	tmp = malloc(sizeof(char *) * (*i + node->null_num + 1));
	*i = -1;
	while (node->exec_args[++(*i)] != NULL)
		tmp[*i] = node->exec_args[*i];
	tmp[*i + node->null_num] = node->exec_args[*i];
	return (tmp);
}

void	set_arguments(t_node *node)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	if (node->argument != NULL)
	{
		tmp = open_up_space(node, &i);
		k = 0;
		j = 0;
		while (k < node->null_num)
		{
			tmp[i] = ft_strdup(&node->argument[j]);
			while (node->argument[j] != '\0')
				++j;
			++j;
			++i;
			++k;
		}
		free(node->exec_args);
		node->exec_args = tmp;
	}
}

void	set_path_name_to_execargs(t_node *node)
{
	if (node->command)
	{
		node->exec_args = malloc(sizeof(char *) + 1);
		node->exec_args[0] = ft_strdup(node->command);
		node->exec_args[1] = NULL;
	}
}

void	set_node(t_shell *shell, t_node *node)
{
	node->cmd_path = search_in_path(shell, node);
	if (node->command != NULL)
		node->is_builtin = builtin_check(node->command);
	if (node->illegalcommand == 1 && node->is_builtin == 0)
	{
		shell->err_code = 2;
		print_error(shell, node);
	}
	else if (node->cmd_path == NULL && \
		node->command != NULL && node->is_builtin == 0)
	{
		shell->err_code = 3;
		print_error(shell, node);
	}
	free_all_path(node->my_path);
	if (node->command == NULL)
		return ;
	if (node->illegalflag != 1)
		set_path_name_to_execargs(node);
	set_flags(shell, node);
	set_arguments(node);
}
