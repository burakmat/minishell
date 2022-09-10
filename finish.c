#include "minishell.h"

void	print_error(t_shell *shell, t_node *node)
{
	if (shell->err_code == 1)
		;//NO PATH IN ENV
	else if (shell->err_code == 2)
		write(2, ": command not found\n", 20);
	else if (shell->err_code == 3)
	{
		write(2, node->command, ft_strlen(node->command));
		write(2, ": command not found\n", 20);
	}
}
