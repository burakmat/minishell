#include "../minishell.h"

int	isthere_flag(char *flag)
{
	if (flag[0] == '-' && flag[1] == 'n' && flag[2] == '\0')
		return (2);
	return (1);
}


void	builtin_echo(t_node *node)
{
	int	a;
	char *temp;

	temp = malloc(sizeof(char) * 1000);
	a = isthere_flag(node->exec_args[1]);
	while (node->exec_args[a] != NULL)
	{
		printf("%s", node->exec_args[a]);
		a++;
	}
	if (isthere_flag(node->exec_args[1]) == 1)
		printf("\n");
}