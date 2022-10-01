/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:00:40 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 15:00:48 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_home(t_shell *shell)
{
	char	*dup;
	int		i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "HOME=", 5))
			dup = ft_strdup_env(shell->env[i]);
		i++;
	}
	return (dup);
}
