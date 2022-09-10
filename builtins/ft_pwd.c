#include "../minishell.h"

void	ft_pwd(t_shell *shell)
{
	ft_putendl_fd(getcwd(shell->data->cwd, sizeof(char *)), 1);
}
