#include "minishell.h"

void	set_flags(t_shell *shell, t_node *node)
{
	if (*node->flags)
	{
		if (node->illegalflag)
		{
			node->exec_args = malloc(sizeof(char *) * 2);
			node->exec_args[0] = node->flags;
			node->exec_args[1] = NULL;
		}
		else
		{
			node->exec_args = ft_split(node->flags, ' ');
			printf("exec_args: %s\n", node->exec_args[0]);
		}
	}
	else
		node->exec_args = NULL;
}

void	set_arguments(t_shell *shell, t_node *node)
{
	int i;
	int j;
	int k;
	char **tmp;

	tmp = malloc(sizeof(char *) * node->null_num + 1);
	i = 0;
	k = 0;
	while ((node->null_num)--)
	{
		j = 0;
		while (node->argument[i + j])
		{
			++j;
		}
		if (j)
		{
			tmp[k] = malloc(j + 1);
			j = 0;
			while (node->argument[i + j])
			{
				tmp[k][i + j] = node->argument[i + j];
				++j;
			}
			tmp[k][i + j] = '\0';
		}
		i += j + 1;
		++k;
	}
	if (j)
		tmp[k] = NULL;
	else
		free(tmp);
	//add tmp to node.exec_args
}


void	set_node(t_shell *shell, t_node *node)
{
	node->cmd_path = search_in_path(shell, node);
	set_flags(shell, node);
}