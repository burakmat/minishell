/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:32:11 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 21:03:37 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_process(t_shell *shell, t_node *node)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		set_input_redirections(node, check_input_redirections(node));
		set_output_redirections(node);
		if (node->previous_node != NULL && node->in == 0)
			dup2(shell->pipes[node->id - 1][0], 0);
		if (node->next_node != NULL && node->out == 0)
			dup2(shell->pipes[node->id][1], 1);
		close_all_node_fd(shell);
		if (builtin_check(node->exec_args[0]) != 0)
			go_to_builtin(shell, node, node->exec_args[0]);
		if (node->cmd_path != NULL)
			execve(node->cmd_path, node->exec_args, NULL);
		exit(1);
	}
}

t_node	*builtin_process(t_shell *shell, t_node *node)
{
	if (node->exec_args && builtin_check(node->exec_args[0]) == 7)
		builtin_exit(shell, node);
	if (node->exec_args && builtin_check(node->exec_args[0]) == 2)
		builtin_cd(shell, node);
	if (node->exec_args && builtin_check(node->exec_args[0]) == 5)
		edit_unset(shell, node);
	if (node->exec_args && builtin_check(node->exec_args[0]) == 4)
		export_director(shell, node);
	new_process(shell, node);
	if (node->next_node != NULL)
		node = node->next_node;
	return (node);
}

void	execute(t_shell *shell, t_node *node)
{
	int	i;
	int	a;

	i = -1;
	while (1)
	{
		if (i++ < shell->totalnode - 1)
			node = builtin_process(shell, node);
		else
		{
			close_all_node_fd(shell);
			while (1)
			{
				a = wait(&shell->exit_status_before);
				if (a < 0)
					break ;
				if (shell->exit_status != 127 && \
					shell->exit_status_before == 256 && node->exec_args && \
					builtin_check(node->exec_args[0]) == 0)
					shell->exit_status = 1;
			}
			break ;
		}
	}
}

void	go_to_builtin(t_shell *shell, t_node *node, char *argv)
{
	if (builtin_check(argv) == 1)
		builtin_echo(node);
	if (builtin_check(argv) == 3)
		builtin_pwd();
	if (builtin_check(argv) == 4 && node->exec_args[1] == NULL)
		builtin_export(shell);
	if (builtin_check(argv) == 6)
		builtin_env(shell);
	exit(1);
}
