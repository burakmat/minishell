#include "../minishell.h"

void	ft_bad_arg(t_data *data)
{
	if (ft_strncmp(data->arg[0], "exit", 4) != 0)
		printf("command not found : %s\n", data->arg[0]);
}
