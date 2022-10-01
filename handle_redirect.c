/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:35:02 by bmat              #+#    #+#             */
/*   Updated: 2022/09/23 10:37:13 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_checker(char *re_i)
{
	int	fd;

	fd = open(&re_i[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		write(2, &re_i[1], ft_strlen(&re_i[1]));
		write(1, ": No such file or directory\n", 28);
		exit(1);
	}
	close(fd);
}

int	number_of_inputs_node(t_node *node)
{
	int		i;
	int		in;
	char	**re;

	if (node->redirections != NULL)
	{
		in = 0;
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i] != NULL)
		{
			if (re[i][0] == '<' && re[i][1] == '<')
				++in;
			else if (re[i][0] == '<' && re[i][1] != '<')
				++in;
			++i;
		}
		free_2d_char(re);
		return (in);
	}
	return (0);
}

int	number_of_heredoc_in_node(t_node *node)
{
	int		i;
	int		in;
	char	**re;

	if (node->redirections != NULL)
	{
		in = 0;
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i] != NULL)
		{
			if (re[i][0] == '<' && re[i][1] == '<')
				++in;
			++i;
		}
		free_2d_char(re);
		return (in);
	}
	return (0);
}

//OUTPUT

void	open_files(char **re, int fd, t_node *node, int i)
{
	if (re[i][0] == '>' && re[i][1] != '>' && node->out == 0)
	{
		fd = open(&re[i][1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fd, 1);
		close(fd);
		node->out = 1;
	}
	else if (re[i][0] == '>' && re[i][1] != '>')
	{
		fd = open(&re[i][1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		close(fd);
	}
	else if (re[i][0] == '>' && re[i][1] == '>' && node->out == 0)
	{
		fd = open(&re[i][2], O_WRONLY | O_CREAT | O_APPEND, 0777);
		dup2(fd, 1);
		close(fd);
		node->out = 1;
	}
	else if (re[i][0] == '>' && re[i][1] == '>')
	{
		fd = open(&re[i][2], O_WRONLY | O_CREAT | O_APPEND, 0777);
		close(fd);
	}
}

void	set_output_redirections(t_node *node)
{
	char	**re;
	int		i;
	int		fd;

	fd = 0;
	if (node->redirections != NULL)
	{
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i])
			++i;
		--i;
		while (i >= 0)
		{
			open_files(re, fd, node, i);
			--i;
		}
		free_2d_char(re);
	}
}
