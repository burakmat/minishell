#include "../minishell.h"

char	*ft_strjoin_builtin(char *s1, char *s2)
{
	int		a;
	char	*last;
	int		b;

	a = 0;
	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!last)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&last[b], s2, ft_strlen(s2) + 1);
	free(s1);
	return (last);
}