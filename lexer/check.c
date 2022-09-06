#include "../lexer.h"

int	isquoteempty(char *last)
{
	int i;

	i = 0;
	if (!last)
		return (0);	
	while (last[i] != '\0')
	{
		if (last[i] != ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}