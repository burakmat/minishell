
#include "minishell.h"

int main(int argc, char **argv)
{
	t_lexout tolex;
	t_errorcode error;
	t_shell shell;
	char	*a;

	while (1)
	{
		fillboxes(&tolex);
		a = readline(">>");
		add_history(a);
		lexer(a, &tolex, &shell);
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
	tolex->box4index = 0;
	tolex->error.illegalflag = 0;
}