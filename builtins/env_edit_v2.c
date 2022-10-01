/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_edit_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:05:17 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/23 16:07:24 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	edit_unset(t_shell *shell, t_node *node)
{
	int		i;
	int		len;
	int		a;

	i = 1;
	while (node->exec_args[i] != NULL)
	{
		len = 0;
		while (shell->env[len])
			len++;
		if (builtin_exist(shell, node->exec_args[i]) >= 0)
		{
			a = builtin_exist(shell, node->exec_args[i]);
			free(shell->env[a]);
			shell->env[a] = shell->env[len - 1];
			shell->env[len - 1] = NULL;
			build_new_env(shell);
		}
		i++;
	}
}

int	builtin_exist(t_shell *shell, char *argv)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp_builtin(shell->env[i], argv, ft_strlen(argv)))
			return (i);
		i++;
	}
	return (-1);
}

void	build_new_env(t_shell *shell)
{
	int		i;
	char	**temp;

	i = 0;
	while (shell->env[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (shell->env[i])
	{
		temp[i] = shell->env[i];
		i++;
	}
	temp[i] = shell->env[i];
	free(shell->env);
	shell->env = temp;
}

int	is_env_valid(char *argv, int mode)
{
	int	i;

	i = 0;
	if ((argv[i] <= '9' && argv[i] >= '0') || argv[i] == '=')
	{
		if (mode == 1)
			printf("\"%s\" not a valid identifier\n", argv);
		return (0);
	}
	while (argv[i] != '=' && argv[i] != '\0')
	{
		if (!(argv[i] <= 'Z' && argv[i] >= 'A') && \
			!(argv[i] <= 'z' && argv[i] >= 'a') && argv[i] != '_' \
			&& !(argv[i] <= '9' && argv[i] >= '0'))
		{
			if (mode == 1)
				printf("\"%s\" not a valid identifier\n", argv);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_last_equal(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '=' && argv[i] != '\0')
		i++;
	if (argv[i] == '=')
		return (1);
	return (0);
}
