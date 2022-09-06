#include "../minishell.h"


int	ft_strlen(char *s1)
{
	int a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*last;
	int		b;

	a = 0;
	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	while (b > a)
	{
		last[a] = s1[a];
		a++;
	}
	a = 0;
	while (ft_strlen(s1) + ft_strlen(s2) > a)
	{
		last[b + a] = s2[a];
		a++;
	}
	printf("join %s\n", last);
	free(s1);
	free(s2);
	return (last);
}

int	escapespace(char *argv)
{
	int i;

	i = 0;
	while (argv[i] == ' ')
		i++;
	
	return (i);
}
