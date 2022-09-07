
#include "../minishell.h"
void	readbox3(char *argv)
{
	int i;

	i = 0;
	printf("thirdbox ");
	while (i < 20)
		printf("%c-", argv[i++]);
}