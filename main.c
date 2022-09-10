
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
		totalnode(a, &tolex);//finds total node
		lexer(a, &tolex, &shell);//all nodes ready
		//node control
		create_pipes(&shell);//1
		execute(&shell, shell.head);//if box1 and box4 == NULL then free(node)
		clear_all_nodes(shell.head);//1
		free_all_path(shell.free_.my_path);//1
		free_shell_pipes(&shell);
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
