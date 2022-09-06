#include "../minishell.h"

int	thirdbox(char *argv, t_lexout *tolex)
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


int	doublequote(char *argv, t_lexout *tolex)
{
	char	*quoteemptych;
	int		l;
	int		k;

	quoteemptych = malloc(sizeof(char) * 1000);
	k = 0;
	k++;
	l = 0;
	printf("chec %s\n", argv);
	while (argv[k] != '"')
	{
		quoteemptych[l] = argv[k]; 
		k++;
		l++;
	}
	if (isquoteempty(quoteemptych))
		tolex->last = ft_strjoin(tolex->last, quoteemptych);
	k++;
	return (k);
}

int	notquote(char *argv, t_lexout *tolex)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char) * 1000);
	i = 0;
	printf("şurası %s\n", argv);
	while (argv[i] != '"' && argv[i] != ' ' && argv[i] != '\0')
	{
		temp[i] = argv[i];
		i++;
	}
	tolex->last = ft_strjoin(tolex->last, temp);
	return (i);
}