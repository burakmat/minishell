#include "minishell.h"

void	print_error(t_shell *shell, t_node *node)
{
	if (shell->err_code == 1)
		;//NO PATH IN ENV
	else if (shell->err_code == 2)//UNKNOWN COMMAND: NULL
	{
		write(2, ": command not found\n", 20);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 3)//UNKNOWN COMMAND: NON-NULL
	{
		write(2, node->command, ft_strlen(node->command));
		write(2, ": command not found\n", 20);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 4)
	{
		write(2, "syntax error '|'\n", 18);	
		shell->exit_status = 258;
	}
	else if (shell->err_code == 5)
	{
		write(2, "quote hasn't been closed\n", 26);
		shell->exit_status = 127;
	}
	else if (shell->err_code == 6)
	{
		write(2, "syntax error '|'\n", 18);
		shell->exit_status = 258;
	}
	else if (shell->err_code == 8)
	{
		write(2, "syntax error \"redirection need a string\"\n", 42);
		shell->exit_status = 258;
	}
}
