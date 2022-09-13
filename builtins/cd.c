#include "../minishell.h"

void	builtin_cd(t_shell *shell , t_node *node)
{
	if (node->exec_args[1] != NULL)
		find_env_path(shell, node);
	if (node->exec_args[1] == NULL)
		edit_envt_path(shell);
}

void	find_env_path(t_shell *shell, t_node *node)
{
	int	i;
	char *s;

	i = 0;
	s = malloc(sizeof(char) * 1000);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PWD", 3))
		{
			chdir(node->exec_args[1]);
			getcwd(s, 1000);
			free(shell->env[i]);
			s = ft_strjoin_env("PWD=", s);
			shell->env[i] = s;
			break ;
		}
		i++;		
	}
}

void	edit_envt_path(t_shell *shell)
{
	char *temp;
	int		i;
	char	*dup;

	i = 0;
	temp = malloc(sizeof(char) * 100);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "HOME=", 5))
			dup = ft_strdup_env(shell->env[i]);
		i++;
	}
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PWD=", 4))
		{
			chdir(dup);
			getcwd(temp, 100);
			free(temp);
			temp = ft_strjoin_env("PWD=", dup);
			free(shell->env[i]);
			shell->env[i] = temp;
			break ;
		}
		i++;		
	}
}