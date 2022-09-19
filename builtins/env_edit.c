/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:05:38 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/18 15:30:25 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_director(t_shell *shell, t_node *node)
{
	int		b;
	int		i;

	b = 1;
	i = 0;
	re_malloc_env(shell, node, i, b);
	different_value(shell, node);
}

void	re_malloc_env(t_shell *shell, t_node *node, int i, int b)
{
	char	**temp;
	int		a;

	a = 0;
	while (node->exec_args[b])
	{
		if (is_env_valid(node->exec_args[b], 1) == 1 \
			&& env_dup_check(shell, node->exec_args[b]) == 0)
			i++;
		b++;
	}
	while (shell->env[a])
		a++;
	temp = malloc((a + i + 1) * sizeof(char *));
	a = 0;
	b = 0;
	while (shell->env[a])
	{
		temp[a] = shell->env[a];
		a++;
	}
	temp[a + i] = NULL;
	free(shell->env);
	shell->env = temp;
	add_env(shell, node, a);
}

void	different_value(t_shell *shell, t_node *node)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (node->exec_args[i])
	{
		b = env_dup_check(shell, node->exec_args[i]);
		if (b != 0 && is_env_valid(node->exec_args[i], 0) == 1 \
			&& is_last_equal(node->exec_args[i]) == 1)
		{
			free(shell->env[b]);
			shell->env[b] = ft_strdup(node->exec_args[i]);
		}
		i++;
	}
}

int	env_dup_check(t_shell *shell, char *argv)
{
	int	i;
	int	a;
	int	b;
	int	d;

	i = 0;
	a = 0;
	b = 0;
	d = 0;
	while (argv[a] != '=' && argv[a] != '\0')
		a++;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], argv, a) == 0)
			b++;
		if (ft_strncmp(shell->env[i], argv, a) == 1)
			d = i;
		i++;
	}
	if (b == i)
		return (d);
	return (d);
}

void	add_env(t_shell *shell, t_node *node, int a)
{
	int	i;

	i = 1;
	while (node->exec_args[i])
	{
		if (env_dup_check(shell, node->exec_args[i]) == 0 \
			&& is_env_valid(node->exec_args[i], 0) == 1)
		{
			shell->env[a] = ft_strdup(node->exec_args[i]);
			a++;
		}
		i++;
	}
}
