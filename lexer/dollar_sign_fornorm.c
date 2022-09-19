/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_fornorm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:26:21 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 12:26:47 by osyalcin         ###   ########.fr       */
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
