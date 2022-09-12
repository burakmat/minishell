#include "../minishell.h"

void	re_malloc_env(t_shell *shell, int formalloc, t_node *node)
{
	char **temp;
	int a;
	int b;
	char ***adress;//BUNU ÇALIŞTIRMAYI DENE

	a = 0;
	while (shell->env[a])
		a++;
	temp = malloc((a + formalloc + 1)* sizeof(char *));
	a = 0;
	b = 0;
	while (shell->env[a])
	{
		temp[a] = malloc(sizeof(char) * (ft_strlen(shell->env[a])));
		temp[a] = shell->env[a];
		a++;
	}
	adress = &shell->env;
	*adress = temp;
	// shell->env = temp;
	add_env(shell, node, a);
}

void	add_env(t_shell *shell, t_node *node, int a)
{
	int	i;

	i = 1;
	while (node->exec_args[i])
	{
		shell->env[a] = ft_strdup(node->exec_args[i]);
		i++;
		a++;
	}
	shell->env[a] = NULL;
}

void	builtin_export(t_shell *shell, t_node *node)
{
	int a;

	a = 1;
	while (node->exec_args[a])
		a++;
	re_malloc_env(shell, a, node);
}