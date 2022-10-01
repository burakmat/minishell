/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:37:57 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 09:37:58 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path(t_shell *shell, int ind)
{
	char	**copy_path;

	copy_path = ft_split(shell->env[ind], ':');
	edit_first_path(copy_path);
	return (copy_path);
}

void	edit_first_path(char **all_path_copy)
{
	char	*first_path;
	int		i;
	int		j;

	i = ft_strlen(all_path_copy[0]);
	i -= 5;
	first_path = malloc(i + 1);
	j = 0;
	while (j < i)
	{
		first_path[j] = all_path_copy[0][j + 5];
		++j;
	}
	first_path[i] = '\0';
	free(all_path_copy[0]);
	all_path_copy[0] = first_path;
}

int	is_there_path(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5))
			return (i);
		++i;
	}
	return (-1);
}

void	free_all_path(char **path)
{
	int	i;

	if (path != NULL)
	{
		i = 0;
		while (path[i])
			free(path[i++]);
		free(path);
		path = NULL;
	}
}
