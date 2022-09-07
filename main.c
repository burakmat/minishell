
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_lexout tolex;
	t_shell shell;
	char	*a;

	shell.env = env;
	while (1)
	{
		fillboxes(&tolex, &shell);
		a = readline(">>");
		add_history(a);
		lexer(a, &tolex, &shell);
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
}