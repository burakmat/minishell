#include "minishell.h"

void	set_flags(t_shell *shell, t_node *node)
{
	int i;
	char **flags;
	char **tmp;

	if (node->flags != NULL)//if there is flag
	{
		if (node->illegalflag == 1)//if flag is illegal
		{
			if (node->exec_args == NULL)//if there is no command
			{
				node->exec_args = malloc(sizeof(char *) * 2);
				node->exec_args[0] = node->flags;
				node->exec_args[1] = NULL;
			}
			else//if there is a command
			{
				tmp = malloc(sizeof(char *) * 3);
				tmp[0] = node->exec_args[0];
				tmp[1] = node->flags;
				tmp[2] = node->exec_args[1];
				free(node->exec_args);
			}
		}
		else//if flags are legal
		{
			if (node->exec_args == NULL)//if there is no command
			{
				;//ERROR?!??? is it possible??
			}
			else//if there is command
			{
				free(node->exec_args[1]);//null at the end
				free(node->exec_args);//all list
				node->exec_args = NULL;//for safety
				flags = ft_split(node->flags, ' ');//HAS ALWAYS SPACE????
				i = 0;
				while (flags[i])
					++i;
				tmp = malloc(sizeof(char *) * i + 2);
				tmp[0] = node->command;//command might be cmd_path
				i = -1;
				while (flags[++i])
					tmp[i + 1] = flags[i];
				tmp[i + 1] = flags[i];
				node->exec_args = tmp;
				free(flags);
			}
		}
	}
}

void	set_arguments(t_shell *shell, t_node *node)//CHECK NULLS FROM HERE
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

void	set_path_name_to_execargs(t_node *node)
{
	if (node->command)
	{
		node->exec_args = malloc(sizeof(char *) + 1);
		node->exec_args[0] = node->command;//might be path, depends on execve
		node->exec_args[1] = NULL;
	}
}

void	set_node(t_shell *shell, t_node *node)
{
	
	node->cmd_path = search_in_path(shell, node);
	if (node->cmd_path == NULL && node->illegalcommand)
	{
		shell->err_code = 2;
		print_error(shell);
	}
	set_path_name_to_execargs(node);
	//set_flags(shell, node);

}