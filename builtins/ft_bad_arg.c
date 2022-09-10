#include "../minishell.h"

void	ft_bad_arg(t_shell *shell)
{
	if (ft_strncmp(shell->data->arg[0], "exit", 4) != 0)
		printf("command not found : %s\n", shell->data->arg[0]);
}
