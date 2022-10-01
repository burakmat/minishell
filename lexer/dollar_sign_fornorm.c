/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_fornorm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:26:21 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 12:30:16 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dollarsign_insinglequote(char *argv, t_shell *shell)
{
	int	i;

	i = 0;
	shell->temp_readline[shell->readline_index++] = argv[i++];
	while (argv[i] != 39 && argv[i] != '\0')
		shell->temp_readline[shell->readline_index++] = argv[i++];
	return (i);
}

int	dollarsign_inquote(char *argv, t_shell *shell)
{
	int	i;

	i = 0;
	shell->temp_readline[shell->readline_index++] = argv[i++];
	while (argv[i] != '"' && argv[i] != '\0')
	{
		if (argv[i] == '$')
			i += dollarsign_check(argv + i, shell);
		else
			shell->temp_readline[shell->readline_index++] = argv[i++];
	}
	shell->temp_readline[shell->readline_index++] = argv[i++];
	return (i);
}

int	until_equal(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '=' && argv[i] != '\0')
		i++;
	return (i);
}

void	dollar_status(t_shell *shell)
{
	char	*temp;
	int		i;

	temp = ft_itoa(shell->exit_status);
	i = 0;
	while (temp[i])
		shell->temp_readline[shell->readline_index++] = temp[i++];
	free(temp);
}
