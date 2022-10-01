/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:09:04 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/18 15:09:09 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_shell *shell)
{
	show_env(shell);
}

void	show_env(t_shell *shell)
{
	int	a;

	a = 0;
	while (shell->env[a])
	{	
		if (env_is_there_equal(shell->env[a]) == 1)
			printf("%s\n", shell->env[a]);
		a++;
	}
}

int	env_is_there_equal(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
