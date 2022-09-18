#include "../minishell.h"

void	builtin_cd(t_node *node)
{
	if (node->exec_args[1] != NULL && node->exec_args[1][0] != '~')
		find_env_path(node);
	else if (node->exec_args[1] == NULL  || (node->exec_args[1][0] == '~' && node->exec_args[1][1] == '\0'))
		edit_envt_path();
	else if (node->exec_args[1] != NULL && node->exec_args[1][0] == '~')
		extra_env_path(node);
}


void	find_env_path(t_node *node)
{
	int	i;
	char *s;

	i = 0;
	s = malloc(sizeof(char) * 1000);
	while (shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "PWD", 3))
		{
			if (chdir(node->exec_args[1]) < 0)
				perror(node->exec_args[1]);
			getcwd(s, 1000);
			free(shell.env[i]);
			s = ft_strjoin_env("PWD=", s);
			shell.env[i] = s;
			break ;
		}
		i++;		
	}
}

void	extra_env_path(t_node *node)
{
	char	*temp;
	int		i;
	char	*dup;

	i = 0;
	temp = malloc(sizeof(char) * 1000);
	while (shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "HOME=", 5))
			dup = ft_strdup_env(shell.env[i]);
		i++;
	}
	i = 0;
	while (shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "PWD=", 4))
		{
			if (node->exec_args[1][0] == '~' && (node->exec_args[1][1] == '/' || node->exec_args[1][1] == '\0'))
				chdir(dup);
			free(dup);
			if ((ft_strlen(node->exec_args[1]) > 2 || node->exec_args[1][1] == '~') && chdir(node->exec_args[1] + 2) < 0)
				perror(node->exec_args[1]);
			getcwd(temp, 1000);
			temp = ft_strjoin_env("PWD=", temp);
			free(shell.env[i]);
			shell.env[i] = temp;
			break ;
		}
		i++;		
	}
}

void	edit_envt_path()
{
	char *temp;
	int		i;
	char	*dup;

	i = 0;
	temp = malloc(sizeof(char) * 1000);
	while (shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "HOME=", 5))
			dup = ft_strdup_env(shell.env[i]);
		i++;
	}
	i = 0;
	while (shell.env[i])
	{
		if (ft_strncmp(shell.env[i], "PWD=", 4))
		{
			chdir(dup);
			free(dup);
			getcwd(temp, 1000);
			temp = ft_strjoin_env("PWD=", temp);
			free(shell.env[i]);
			shell.env[i] = temp;
			break ;
		}
		i++;		
	}
}