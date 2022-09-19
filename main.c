/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:31 by bmat              #+#    #+#             */
/*   Updated: 2022/09/19 21:41:16 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

void	sig_int(int sig)
{
	(void)sig;
	if (g_shell.totalnode == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		printf("\n");
		rl_redisplay();
	}
}

char	*main_process(char *a, t_lexout *tolex)
{
	totalnode(a, tolex, &g_shell);
	a = dollar_sign(a, &g_shell);
	g_shell.exit_status = 0;
	lexer(a, tolex, &g_shell);
	if (g_shell.err_code < 4 && g_shell.head->command == NULL \
		&& g_shell.head->redirections == NULL)
		free(g_shell.head);
	else if (g_shell.err_code >= 6)
	{
		print_error(&g_shell, NULL);
		clear_all_nodes(g_shell.head);
	}
	else if (g_shell.err_code == 4 || g_shell.err_code == 5)
		print_error(&g_shell, NULL);
	else
	{
		create_pipes(&g_shell);
		execute(&g_shell, g_shell.head);
		clear_all_nodes(g_shell.head);
		free_shell_pipes(&g_shell);
	}
	return (a);
}

int	main(int argc, char **argv, char **env)
{
	t_lexout	tolex;
	char		*a;

	(void)argc;
	(void)argv;
	g_shell.env = duplicate_env(env);
	g_shell.pipes = NULL;
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		fillboxesstatic(&tolex, &g_shell);
		a = readline("MEGAshell>> ");
		add_history(a);
		if (a == NULL)
		{
			printf("\033[A");
			printf("MEGAshell>> exit\n");
			exit(0);
		}
		if (*a != '\0')
			a = main_process(a, &tolex);
		free(a);
	}
	return (0);
}

void	fillboxes(t_lexout *tolex, t_shell *shell)
{
	tolex->box1 = malloc(sizeof(char) * 1000);
	tolex->box2 = malloc(sizeof(char) * 1000);
	tolex->box3 = malloc(sizeof(char) * 1000);
	tolex->box4 = malloc(sizeof(char) * 1000);
	tolex->box2runaway = 0;
	tolex->box1index = 0;
	tolex->box2index = 0;
	tolex->box3index = 0;
	tolex->box3space = 0;
	tolex->box3null = 0;
	tolex->box4index = 0;
	tolex->box4space = 0;
	tolex->illegalflag = 0;
	tolex->boxwasin = 0;
	tolex->illegalcommand = 0;
	shell->totalnode = 0;
	(void)shell;
}

void	fillboxesstatic(t_lexout *tolex, t_shell *shell)
{
	shell->err_code = 0;
	tolex->currentnode = 0;
	tolex->totalnode = 0;
	shell->readline_index = 0;
	shell->exit_status_before = 0;
	shell->totalnode = 0;
}
