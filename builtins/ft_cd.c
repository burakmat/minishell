#include "../minishell.h"

void	ft_cd_second(char *arg)
{
		if (chdir(arg) != 0)
			perror(arg);
}

void	ft_cd(t_data *data)
{
	char	*s;
	int		i;

	s = 0;
	i = 0;
	if (!data->arg[1] || ft_strchr(data->arg[1], '~'))
	{
		while (data->env_in[++i])
		{
			if (ft_strncmp(data->env_in[i], "HOME", 4) == 0)
			{
				s = ft_strdup(data->env_in[i]);
				break;
			}
		}
	}
	if (data->arg[1])
	{
		if (chdir(ft_strchr(s, '=') + 1))
			perror(data->arg[1]);
		free(s);
	}
	else if (data->arg[1] && data->arg[1][0] == '~' && data->arg[1][1] == '/')
		ft_cd_second(ft_strjoin(ft_strchr(s, '=') + 1, data->arg[1] + 1));
	else if (data->arg[1])
	{
		if (chdir(data->arg[1]))
				perror(data->arg[1]);
	}
}
