#include "minishell.h"

void	set_flags(t_shell *shell, t_lexout table, t_node *node)
{
	if (*node->flags)
	{
		if (table.illegalflag)
		{
			node->exec_args = malloc(sizeof(char *) * 2);
			node->exec_args[0] = node->flags;
			node->exec_args[1] = NULL;
		}
		else
		{
			node->exec_args = ft_split(table.box2, ' ');
		}
	}
	else
		node->exec_args = NULL;
}

void	set_arguments(t_shell *shell, t_lexout table, t_node *node)
{
	int i;
	int j;
	int k;
	char **tmp;

	tmp = malloc(sizeof(char *) * table.box3null + 1);
	i = 0;
	k = 0;
	while (table.box3null--)
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