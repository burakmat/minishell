#include "minishell.h"


void	sig_int(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

int main(int argc, char **argv, char **env)
{
	t_lexout tolex;
	t_shell shell;
	char	*a;

	(void)argc;
	(void)argv;
	shell.env = duplicate_env(env);
	shell.pipes = NULL;
	signal(SIGINT, &sig_int);
	while (1)
	{
		fillboxesstatic(&tolex, &shell);
		a = readline("MEGAshell>>"); 
		add_history(a);
		if (a == NULL)
		{
			printf("exit");
			exit(0);
		}
		if (*a != '\0')//same??
		{
			totalnode(a, &tolex, &shell);//finds total node
			a = dollar_sign(a, &shell);//$ yap
			lexer(a, &tolex, &shell);//all nodes ready
			if (shell.err_code < 4 && shell.head->command == NULL && shell.head->redirections == NULL) //same??--only difference ">> | pwd .."
				free(shell.head);
			else if (shell.err_code >= 6)//need an error case for first character pipe |
			{
				print_error(&shell, NULL);
				clear_all_nodes(shell.head);
			}
			else if (shell.err_code == 4 || shell.err_code == 5)
				print_error(&shell, NULL);
			else
			{
				create_pipes(&shell);//1
				execute(&shell, shell.head);
				clear_all_nodes(shell.head);//1
				free_shell_pipes(&shell);
			}
		}
		free(a);
		// system("leaks minishell");
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
	tolex->box3null  = 0;
	tolex->box4index = 0;
	tolex->box4space = 0;
	tolex->illegalflag = 0;
	tolex->boxwasin = 0;
	tolex->illegalcommand = 0;
	(void)shell;
}

void	fillboxesstatic(t_lexout *tolex, t_shell *shell)
{
	shell->err_code = 0;
	tolex->currentnode = 0;
	tolex->totalnode = 0;
	shell->readline_index = 0;
}
