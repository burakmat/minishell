#include "../minishell"

void	ft_pwd(t_data *data)
{
	ft_putendl_fd(getcwd(data->cwd, sizeof(char *)), 1);
}
