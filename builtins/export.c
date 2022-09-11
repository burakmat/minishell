#include "../minishell.h"

void	re_malloc_env(t_shell *shell, int formalloc, t_node *node)
{
	char **temp;
	int a;
	int b;

	a = 0;
	while (shell->env[a])
		a++;
	temp = malloc((a + formalloc)* sizeof(char *));
	a = 0;
	b = 0;
	while (shell->env[a])
	{
		temp[a] = malloc(sizeof(char) * (ft_strlen(shell->env[a]) + 1));
		temp[a] = shell->env[a];
		a++;
	}
	printf("lala2233\n");
	//free(shell->env);//
	shell->env = temp;
	printf("lala2233\n");
	add_env(shell, node, a);
	printf("lala253\n");
}

void	add_env(t_shell *shell, t_node *node, int a)
{
	int	i;

	i = 1;
	while (node->exec_args[i])
	{
		shell->env[a] = node->exec_args[i];
		i++;
		a++;
	}
}

void	builtin_export(t_shell *shell, t_node *node)
{
	int a;

	a = 1;
	while (node->exec_args[a])
		a++;
	re_malloc_env(shell, a, node);


	a = 0;
	while (shell->env[a])
	{
		printf("declare -x %s\n", shell->env[a]);
		a++;
	}
}