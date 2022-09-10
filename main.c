
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_lexout tolex;
	t_shell shell;
	char	*a;

	shell.env = env;
	shell.pipes = NULL;
	while (1)
	{
		fillboxesstatic(&tolex);
		a = readline(">>");
		add_history(a);
		if (*a != '\0')
		{
			totalnode(a, &tolex);//finds total node
			lexer(a, &tolex, &shell);//all nodes ready
			if (shell.head->command == NULL && shell.head->redirections == NULL)
				free(shell.head);
			else
			{
				create_pipes(&shell);//1
				execute(&shell, shell.head);
				clear_all_nodes(shell.head);//1
				free_shell_pipes(&shell);
			}
		}
			free(a);
			system("leaks minishell");
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
	tolex->currentnode = 0;
	tolex->totalnode = 0;
}
