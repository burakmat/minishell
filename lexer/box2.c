#include "../minishell.h"

int	secondbox(char *argv, t_lexout *tolex)
{
	int i;
	char *temp;

	temp = malloc(sizeof(char) * 10000);
	i = 0;
	while (tolex->box2runaway != 1 && argv[i] != '\0')
	{
		printf("i %d\n", i);
		if(argv[i] == '"')
		{
			if (!((argv[i - 1] <= 13 && argv[i - 1] >= 9) || argv[i - 1] == 32))
				i += secondboxinquote_mode1(argv + i, tolex);
			else 
				i += secondboxinquote(argv + i, tolex);
		}
		else if (argv[i] == '-')
		{
			if (((argv[i + 1] <= 13 && argv[i + 1] >= 9) || argv[i + 1] == 32))
			{
				tolex->box2runaway = 1;
				return (i);
			}
			tolex->box2[tolex->box2index++] = argv[i++];
		}
		else
			tolex->box2[tolex->box2index++] = argv[i++];
		i += escapespace(argv + i, tolex);
	}
	return (i);
}

int	secondboxinquote(char *argv, t_lexout *tolex)
{
	int i;

	i = 1;
	if (argv[i] == '"')
	{
		i++;
		return(i);
	}
	if (argv[i] != '-')
	{
		tolex->box2runaway = 1;
		return (0);
	}
	else
	{
		if (((argv[i + 1] <= 13 && argv[i + 1] >= 9) || argv[i + 1] == 32))
		{
			if (box2spaceafter(argv, tolex));
			tolex->box2runaway = 1;
			return(0);
		}
		tolex->box2[tolex->box2index++] = argv[i++];
		while (argv[i] != '"')
			tolex->box2[tolex->box2index++] = argv[i++];
	}
	i++;
	return (i);	
}


box2spaceafter(char *argv, t_lexout *tolex)
{
	int i;

	//arkaya bak öne değil
	i = 0;
	while (argv[i] != '"')
		i++;

}

int	secondboxinquote_mode1(char *argv, t_lexout *tolex)
{
	int i;

	i = 1;
	if (argv[i] == '"')
	{
		i++;
		return(i);
	}
	if (argv[i] != '-')
	{
		tolex->box2runaway = 1;
		return (0);
	}
	else
	{
		if (((argv[i + 1] <= 13 && argv[i + 1] >= 9) || argv[i + 1] == 32))
		{
			tolex->box2runaway = 1;
			return(0);
		}
		tolex->box2[tolex->box2index++] = argv[i++];
		while (argv[i] != '"')
			tolex->box2[tolex->box2index++] = argv[i++];
	}
	i++;
	return (i);	
}