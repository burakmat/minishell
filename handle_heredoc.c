/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:17:56 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/23 12:37:22 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_input(int *pipes, char **re, int i)
{
	char	*buffer;

	close(pipes[0]);
	while (1)
	{
		buffer = readline("> ");
		if (buffer == NULL)
		{
			close(pipes[1]);
			exit(0);
		}	
		if (ft_strncmp_exact(buffer, &re[i][2], \
			ft_strlen(&re[i][2])))
		{
			free(buffer);
			close(pipes[1]);
			exit(0);
		}
		else
		{
			write(pipes[1], buffer, ft_strlen(buffer));
			write(pipes[1], "\n", 1);
			free(buffer);
		}
	}
}

void	last_less_less(char **re, int i, t_node *node)
{
	char	*buffer;
	int		pid;
	int		pipes[2];

	pipe(pipes);
	g_shell.heredoc_interrupt = 1;
	signal(SIGINT, &sig_int);
	pid = fork();
	if (!pid)
		heredoc_input(pipes, re, i);
	else
	{
		g_shell.heredoc_interrupt = 0;
		close(pipes[1]);
		waitpid(pid, NULL, 0);
		while (1)
		{
			buffer = get_next_line(pipes[0]);
			if (buffer != NULL)
				node->heredoc_input = ft_strjoin(node->heredoc_input, buffer);
			else
				return ;
		}
	}
}

void	wait_for_input(char **re, int number_of_heredoc, int i, t_node *node)
{
	if (g_shell.heredoc_interrupt == 1)
		return ;
	if (--(number_of_heredoc) < 1)
	{
		last_less_less(re, i, node);
		return ;
	}
	else
		empty_input(re[i]);
}

void	node_heredoc_input(t_node *node, int number_of_heredoc)
{
	char	**re;
	int		i;

	if (node->redirections != NULL && number_of_heredoc > 0)
	{
		re = ft_split(node->redirections, ' ');
		i = -1;
		while (re[++i])
		{
			if (re[i][0] == '<' && re[i][1] == '<')
				wait_for_input(re, number_of_heredoc, i, node);
		}
		free_2d_char(re);
	}
}

void	get_heredoc_inputs(t_shell *shell, t_node *node)
{
	(void)shell;
	while (node != NULL)
	{
		node_heredoc_input(node, number_of_heredoc_in_node(node));
		if (g_shell.heredoc_interrupt == 1)
			return ;
		node = node->next_node;
	}
}
