#include "minishell.h"


void	sig_int(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

// t_shell shell;

int main(int argc, char **argv, char **env)
{
	t_lexout tolex;
	// t_shell shell;
	char	*a;

	(void)argc;
	(void)argv;
	shell.env = duplicate_env(env);
	shell.pipes = NULL;
	signal(SIGINT, &sig_int);
	while (1)
	{
		fillboxesstatic(&tolex);
		a = readline("MEGAshell>>");
		add_history(a);
		if (a == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		if (*a != '\0')//same??
		{
			totalnode(a, &tolex);//finds total node
			a = dollar_sign(a);//$ yap
			lexer(a, &tolex);//all nodes ready
			if (shell.err_code < 4 && shell.head->command == NULL && shell.head->redirections == NULL) //same??--only difference ">> | pwd .."
				free(shell.head);
			else if (shell.err_code >= 6)//need an error case for first character pipe |
			{
				print_error(NULL);
				clear_all_nodes(shell.head);
			}
			else if (shell.err_code == 4 || shell.err_code == 5)
				print_error(NULL);
			else
			{
				create_pipes();//1
				execute(shell.head);
				clear_all_nodes(shell.head);//1
				free_shell_pipes();
			}
		}
		free(a);
		// system("leaks minishell");
	}
	return (0);
}


void	fillboxes(t_lexout *tolex)
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
}

void	fillboxesstatic(t_lexout *tolex)
{
	shell.err_code = 0;
	tolex->currentnode = 0;
	tolex->totalnode = 0;
	shell.readline_index = 0;
}
