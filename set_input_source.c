/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_source.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <bmat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:32:52 by bmat              #+#    #+#             */
/*   Updated: 2022/09/23 12:04:01 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	last_less(char *re_i)
{
	int	fd;

	fd = open(&re_i[1], O_RDONLY, 0777);
	dup2(fd, 0);
	close(fd);
}

int	handle_inputs(t_node *node, char *re_i, int *input_num)
{
	int		pipes[2];

	if (re_i[0] == '<' && re_i[1] != '<')
	{
		file_checker(re_i);
		if (--(*input_num) < 1)
		{
			last_less(re_i);
			return (1);
		}
	}
	else if (re_i[0] == '<' && re_i[1] == '<')
	{
		if (--(*input_num) < 1)
		{
			pipe(pipes);
			write(pipes[1], node->heredoc_input, \
				ft_strlen(node->heredoc_input));
			close(pipes[1]);
			dup2(pipes[0], 0);
			close(pipes[0]);
			return (1);
		}
	}
	return (0);
}

void	set_input_redirections(t_node *node, int input_num)
{
	char	**re;
	int		i;

	if (node->redirections != NULL)
	{
		if (input_num > 0)
			node->in = 1;
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i])
		{
			if (handle_inputs(node, re[i], &input_num) == 1)
			{
				free_2d_char(re);
				return ;
			}
			++i;
		}
		free_2d_char(re);
	}
}

void	empty_input(char *re_i)
{
	char	*buffer;
	int		pid;

	g_shell.heredoc_interrupt = 1;
	signal(SIGINT, &sig_int);
	pid = fork();
	if (!pid)
	{
		while (1)
		{
			buffer = readline("> ");
			if (buffer == NULL)
				exit(0);
			if (ft_strncmp_exact(buffer, &re_i[2], \
				ft_strlen(&re_i[2])))
			{
				free(buffer);
				exit(0);
			}
			free(buffer);
		}
	}
	g_shell.heredoc_interrupt = 0;
	waitpid(pid, NULL, 0);
}
