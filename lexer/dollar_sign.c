/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:25:27 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/23 16:01:00 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dollar_sign(char *argv, t_shell *shell)
{
	int		i;

	shell->temp_readline = malloc(sizeof(char) * (ft_strlen(argv) + 3000));
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '"')
			i += dollarsign_inquote(argv + i, shell);
		else if (argv[i] == 39)
			i += dollarsign_insinglequote(argv + i, shell);
		else if (argv[i] == '$')
			i += dollarsign_check(argv + i, shell);
		else
			shell->temp_readline[shell->readline_index++] = argv[i++];
	}
	free(argv);
	shell->temp_readline[shell->readline_index++] = '\0';
	return (shell->temp_readline);
}

int	dollarsign_check(char *argv, t_shell *shell)
{
	int		i;
	int		a;
	char	*temp2;

	i = 1;
	a = 0;
	if (argv[i] == '?' && (((argv[i + 1] <= 13 && argv[i + 1] >= 9) \
		|| argv[i + 1] == 32) || argv[i + 1] == '\0'))
		dollar_status(shell);
	temp2 = malloc(sizeof(char) * 1000);
	while (argv[i] != '\0' && !((argv[i] <= 13 && argv[i] >= 9) \
	|| argv[i] == 32) && argv[i] != '$' && argv[i] != '"' && argv[i] != 39)
		temp2[a++] = argv[i++];
	dollarsign_check_norm(shell, temp2);
	free(temp2);
	if (i == 1 && ft_strlen(argv) == 1)
		shell->temp_readline[shell->readline_index++] = argv[0];
	return (i);
}

void	dollarsign_check_norm(t_shell *shell, char *temp2)
{
	int	c;
	int	a;

	a = 0;
	while (shell->env[a] && temp2 != NULL)
	{
		if (ft_strncmp(shell->env[a], temp2, until_equal(shell->env[a])) \
			&& ft_strncmp(shell->env[a], temp2, ft_strlen(temp2)))
		{
			c = 0;
			while (shell->env[a][c] != '=')
				c++;
			c++;
			shell->temp_readline[shell->readline_index++] = '"';
			while (shell->env[a][c])
				shell->temp_readline[shell->readline_index++] = \
					shell->env[a][c++];
			shell->temp_readline[shell->readline_index++] = '"';
			break ;
		}
		a++;
	}
}
