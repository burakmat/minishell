/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_source.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:32:52 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 11:32:53 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_input(char **re, int i)
{
	char	*buffer;

	while (1)
	{
		buffer = readline("> ");
		if (ft_strncmp_exact(buffer, &re[i][2], \
			ft_strlen(&re[i][2])))
		{
			free(buffer);
			break ;
		}
		free(buffer);
	}
}

void	last_less_less(int *pipes, char **re, int i)
{
	char	*buffer;

	pipe(pipes);
	while (1)
	{
		buffer = readline("> ");
		if (ft_strncmp_exact(buffer, &re[i][2], \
			ft_strlen(&re[i][2])))
		{
			free(buffer);
			close(pipes[1]);
			dup2(pipes[0], 0);
			close(pipes[0]);
			return ;
		}
		else
		{
			write(pipes[1], buffer, ft_strlen(buffer));
			write(pipes[1], "\n", 1);
			free(buffer);
		}
	}
}

void	last_less(char **re, int i, t_node *node)
{
	int	fd;

	fd = open(&re[i][1], O_RDONLY, 0777);
	dup2(fd, 0);
	close(fd);
	node->in = 1;
	free_2d_char(re);
}

int	handle_inputs(t_node *node, char **re, int i, int *input_num)
{
	int		pipes[2];
	char	*buffer;

	if (re[i][0] == '<' && re[i][1] != '<')
	{
		if (--(*input_num) < 1)
		{
			last_less(re, i, node);
			return (1);
		}
	}
	else if (re[i][0] == '<' && re[i][1] == '<')
	{
		buffer = NULL;
		if (--(*input_num) < 1)
		{
			last_less_less(pipes, re, i);
			return (1);
		}
		else
			empty_input(re, i);
	}
	return (0);
}

void	set_input_redirections(t_node *node, int input_num)
{
	char	**re;
	int		i;

	if (node->redirections != NULL)
	{
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i])
		{
			if (handle_inputs(node, re, i, &input_num) == 1)
				return ;
			++i;
		}
		free_2d_char(re);
	}
}
