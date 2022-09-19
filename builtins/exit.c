/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:09:24 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/19 21:02:50 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi(char *str)
{
	long int	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10 + ((*str) - '0') * sign;
		if (ret > 2147483647)
			return (-1);
		else if (ret < -2147483648)
			return (0);
		str++;
	}
	return (ret);
}

void	builtin_exit(t_shell *shell, t_node *node)
{
	int	i;

	i = 0;
	printf("exit\n");
	if (node->exec_args && node->exec_args[2] != NULL)
	{
		printf("too many arguments\n");
		shell->exit_status = 1;
		return ;
	}
	while (node->exec_args[1][i])
	{
		if (!(node->exec_args[1][i] >= '0' && node->exec_args[1][i] <= '9'))
		{
			printf("none numeric\n");
			exit(255);
		}
		i++;
	}
	exit(ft_atoi(node->exec_args[1]) % 256);
}