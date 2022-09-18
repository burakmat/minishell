#include "minishell.h"

void	set_flags(t_node *node)
{
	int i;
	char **flags;
	char **tmp;

	if (node->flags != NULL)
	{
		if (node->illegalflag == 1)
		{
			node->exec_args = malloc(sizeof(char *) * 3);
			node->exec_args[0] = ft_strdup(node->command);
			node->exec_args[1] = ft_strdup(node->flags);
			node->exec_args[2] = NULL;
		}
		else//if flags are legal
		{
			free(node->exec_args[1]);//null at the end
			free(node->exec_args[0]);//command duplicate
			free(node->exec_args);//all list
			node->exec_args = NULL;//for safety
			flags = ft_split(node->flags, ' ');//HAS ALWAYS SPACE????
			i = 0;
			while (flags[i])
				++i;
			tmp = malloc(sizeof(char *) * (i + 2));
			tmp[0] = ft_strdup(node->command);//command might be cmd_path
			i = 0;
			while (flags[i] != NULL)
			{
				tmp[i + 1] = flags[i];
				i++;
			}
			tmp[i + 1] = flags[i];
			node->exec_args = tmp;
			free(flags);
		}
	}
}

void	set_arguments(t_node *node)
{
	int i;
	int j;
	int k;
	char **tmp;

	if (node->argument != NULL)
	{
		i = 0;
		while (node->exec_args[i])
			++i;
		tmp = malloc(sizeof(char *) * (i + node->null_num + 1));
		i = -1;
		while (node->exec_args[++i] != NULL)//**env new = &env    *new = tmp
			tmp[i] = node->exec_args[i];
		tmp[i + node->null_num] = node->exec_args[i];
		k = 0;
		j = 0;
		while (k < node->null_num)
		{
			tmp[i] = ft_strdup(&node->argument[j]);
			while (node->argument[j] != '\0')
				++j;
			++j;
			++i;
			++k;
		}
		free(node->exec_args);
		node->exec_args = tmp;
	}
}

void	set_path_name_to_execargs(t_node *node)
{
	if (node->command)
	{
		node->exec_args = malloc(sizeof(char *) + 1);
		node->exec_args[0] = ft_strdup(node->command);
		node->exec_args[1] = NULL;
	}
}

void	set_node(t_node *node)
{
	node->cmd_path = search_in_path(node);
	if (node->command != NULL)
		node->is_builtin = builtin_check(node->command);
	if(node->illegalcommand == 1 && node->is_builtin == 0)
	{
		shell.err_code = 2;
		print_error(node);
	}
	else if (node->cmd_path == NULL && node->command != NULL && node->is_builtin == 0)//instead of node->redirections == NULL (export patlıyor aga)
	{
		shell.err_code = 3;
		print_error(node);
	}
	free_all_path(node->my_path);
	if (node->command == NULL)
		return ;
	if (node->illegalflag != 1) //problem solver
		set_path_name_to_execargs(node);
	set_flags(node);
	set_arguments(node);
}