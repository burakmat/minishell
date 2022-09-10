#include "../minishell.h"

void	ft_cd_second(char *arg)
{
		if (chdir(arg) != 0)
			perror(arg);
}

void	ft_cd(t_shell *shell)
{
	char	*s;
	int		i;

	s = 0;
	i = 0;
	if (!shell->data->arg[1] || ft_strchr(shell->data->arg[1], '~'))
	{
		while (shell->data->env_in[++i])
		{
			if (ft_strncmp(shell->data->env_in[i], "HOME", 4) == 0)
			{
				s = ft_strdup(shell->data->env_in[i]);
				break;
			}
		}
	}
	if (shell->data->arg[1])
	{
		if (chdir(ft_strchr(s, '=') + 1))
			perror(shell->data->arg[1]);
		free(s);
	}
	else if (shell->data->arg[1] && shell->data->arg[1][0] == '~' && shell->data->arg[1][1] == '/')
		ft_cd_second(ft_strjoin(ft_strchr(s, '=') + 1, shell->data->arg[1] + 1));
	else if (shell->data->arg[1])
	{
		if (chdir(shell->data->arg[1]))
				perror(shell->data->arg[1]);
	}
}
