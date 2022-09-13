#include "../minishell.h"

void	builtin_exit()
{
	printf("exit\n");
	exit(0);
}