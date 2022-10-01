/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:48:09 by bmat              #+#    #+#             */
/*   Updated: 2022/09/18 15:48:10 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err1(t_shell *shell, t_node *node)
{
	if (shell->err_code == 2)
	{
		write(2, ": command not found\n", 20);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 3)
	{
		write(2, node->command, ft_strlen(node->command));
		write(2, ": command not found\n", 20);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 4)
	{
		write(2, "syntax error '|'\n", 18);
		shell->exit_status = 258;
	}
}

void	print_err2(t_shell *shell)
{
	if (shell->err_code == 5)
	{
		write(2, "quote hasn't been closed\n", 26);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 6)
	{
		write(2, "syntax error '|'\n", 18);
		shell->exit_status = 258;
	}
	else if (shell->err_code == 8)
	{
		write(2, "syntax error \"redirection need a string\"\n", 42);
		shell->exit_status = 258;
	}
}

void	print_error(t_shell *shell, t_node *node)
{
	if (shell->err_code <= 4)
		print_err1(shell, node);
	else
		print_err2(shell);
}
