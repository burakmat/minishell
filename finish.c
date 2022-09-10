#include "minishell.h"

void	print_error(t_shell *shell)
{
	if (shell->err_code == 1)
		;//NO PATH IN ENV
	else if (shell->err_code == 2)
		;//UNKNOWN COMMAND: NULL
	printf("error\n");
}
