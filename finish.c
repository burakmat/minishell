#include "minishell.h"

void	print_error(t_shell *shell, t_node *node)
{
	if (shell->err_code == 1)
		;//NO PATH IN ENV
	else if (shell->err_code == 2)
		perror(node->command);
}
