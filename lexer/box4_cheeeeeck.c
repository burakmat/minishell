/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box4_cheeeeeck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:41:17 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/16 12:30:55 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void box4_check(t_lexout *tolex)
{
	int i;
	int a;
	char *temp;

	i = 0;
	temp = malloc(sizeof(char) * 1000);
	while (tolex->box4 && tolex->box4[i] != '\0')
	{
		a = 0;
		while (tolex->box4[i] != ' ' && tolex->box4[i] != '\0')
			temp[a++] = tolex->box4[i++];
		temp[a] = '\0';
		box4_go_to_check(temp);
		free(temp);
		temp = malloc(sizeof(char) * 1000);
		if (tolex->box4[i] != '\0')
			i++;
	}
	free(temp);
}

void	box4_go_to_check(char *argv)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (argv[i])
	{
		while (!(argv[i] != '<' && argv[i] != '>') && argv[i] != '\0')
		{
			i++;
			a++;
		}
		if (argv[i] != '\0')
			i++;
	}
	if (a == i)
		shell.err_code = 8;
}