#include "../minishell.h"

int	secondbox(char *argv, t_lexout *tolex)
{
	int	i;
	int l;
	char *temp;

	temp = malloc(1000);
	tolex->last = malloc(sizeof(char) * 10000);
	i = 0;
	l = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '"')
		{
			i += doublequote(argv + i, tolex);
		}
		else if (argv[i] == ' ')
			i++;
		else if (argv[i] != '"' && argv[i] != ' ')
		{
			i += notquote(argv + i, tolex);
		}
		printf("i %d\n", i);

	}
	printf("burası %s\n", tolex->last);


	return 0;
}

