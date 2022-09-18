#include "../minishell.h"

void	edit_unset(t_node *node)
{
	int i;
	int	len;
	char *temp;
	int a;

	i = 1;
	len = 0;
	while (shell.env[len])
		len++;
	while (node->exec_args[i] != NULL)
	{
		if (builtin_exist(node->exec_args[i]) >= 0)
		{
			a = builtin_exist(node->exec_args[i]);
			temp = shell.env[a];
			shell.env[a] = shell.env[len - 1];
			free(temp);
			shell.env[len - 1] = NULL;
			build_new_env();
		}
		i++;
	}
}

int	builtin_exist(char *argv)
{
	int i;

	i = 0;	
	while (shell.env[i])
	{
		if (ft_strncmp_builtin(shell.env[i], argv, ft_strlen(argv)))
			return (i);
		i++;
	}
	return (-1);
}

void	build_new_env()
{
	int i;
	char **temp;

	i = 0;
	while (shell.env[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (shell.env[i])
	{
		temp[i] = shell.env[i];
		i++;
	}
	temp[i] = NULL;
	free(shell.env);
	shell.env = temp;
}