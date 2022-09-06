#include "minishell.h"

int main(int argc, char **argv)
{
	t_lexout *first;
	char	*a;

	first = malloc(sizeof(t_lexout));

	while (1)
	{
		first->last = malloc(sizeof(char) * 10000);
		first->box1 = malloc(sizeof(char) * 1000);
		first->box1index = 0;
		a = readline(">>");
		add_history(a);
		lexer(a, first);
		free(first->box1);
	}
	return (0);
}