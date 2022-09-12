#include "../minishell.h"

void	re_malloc_env(t_shell *shell, t_node *node, int i)
{
	char **temp;
	int a;
	int b;

	a = 0;
	b = 1;
	i = 0;
	while (node->exec_args[b])
	{
		if (env_dup_check(shell, node->exec_args[b]) == 0 && is_env_valid(node->exec_args[b]) == 1)
			i++;
		b++;
	}
	while (shell->env[a])
		a++;
	temp = malloc((a + i + 1) * sizeof(char *));
	a = 0;
	b = 0;
	while (shell->env[a])
	{
		temp[a] = shell->env[a];
		a++;
	}
	temp[a + i] = NULL;
	free(shell->env);
	shell->env = temp;
	printf("control 1\n");
	add_env(shell, node, a);
	printf("control 2\n");
	different_value(shell, node);
	printf("control 3\n");
}

void	different_value(t_shell *shell, t_node *node)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (node->exec_args[i])
	{
		printf("value\n");
		b = env_dup_check(shell, node->exec_args[i]);
		printf("value\n");
		if (b != 0 && is_env_valid(node->exec_args[i]) == 1 && is_last_equal(node->exec_args[i]) == 1)
		{
			free(shell->env[b]);
			shell->env[b] = ft_strdup(node->exec_args[i]);
		}
		i++;
	}
}

int is_last_equal(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '=' && argv[i] != '\0')
		i++;
	if (argv[i] == '=')
		return (1);
	return (0);	
}

int	env_dup_check(t_shell *shell, char *argv)
{
	int i;
	int a;
	int b;
	int d;

	i = 0;
	a = 0;
	b = 0;
	d = 0;
	while (argv[a] != '=' && argv[a] != '\0')
		a++;
	printf("a değeri %d\n", a);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], argv, a) == 0)
			b++;
		if (ft_strncmp(shell->env[i], argv, a) == 1)
			d = i;
		i++;
	printf("i değeri %d\n", i);
	}
	if (b == i)
		return (d);
	return (d);
}

void	add_env(t_shell *shell, t_node *node, int a)
{
	int	i;

	i = 1;
	while (node->exec_args[i])
	{
		if (env_dup_check(shell, node->exec_args[i]) == 0 && is_env_valid(node->exec_args[i]) == 1)
		{
			shell->env[a] = ft_strdup(node->exec_args[i]);
			a++;
		}
		i++;
	}
}

int		is_env_valid(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '=' && argv[i] != '\0')
		i++;
	if (i == 0)
	{
		printf("not a valid identifier\n");
		return (0);
	}
	return (1);
}

void	builtin_export(t_shell *shell, t_node *node)
{
	(void) node;
	(void) shell;
	show_env(shell);
}