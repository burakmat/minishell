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
			node->exec_args = malloc(sizeof(char *) * 2);
			node->exec_args[0] = ft_strdup(node->command); // bu mantıken lazım
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

void	set_arguments(t_shell *shell, t_node *node)
{
	int i;
	int j;
	char **tmp;
	char **argument;

	if (node->argument != NULL)
	{
		j = 0;
		while (node->exec_args[j])
			++j;
		argument = ft_split(node->argument, ' ');//argümanlar arası boşluk değil null var
		i = 0;
		while (argument[i] != NULL)
			++i;
		tmp = malloc(sizeof(char *) * (i + j + 1));
		i = 0;
		while (node->exec_args[i])
		{
			tmp[i] = ft_strdup(node->exec_args[i]);
			++i;
		}
		freeexec_args(node);
		j = 0;
		while (argument[j] != NULL)
		{
			tmp[i + j] = argument[j];
			++j;
		}
		tmp[i + j] = argument[j];
		free(argument);
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

void	set_node(t_shell *shell, t_node *node)
{
	node->cmd_path = search_in_path(shell, node);
	if(node->illegalcommand == 1)
	{
		shell->err_code = 2;
		print_error(shell, node);
	}
	else if (node->cmd_path == NULL && node->command != NULL)//instead of node->redirections == NULL (export patlıyor aga)
	{
		shell->err_code = 3;
		print_error(shell, node);
	}
	free_all_path(node->my_path);
	if (node->command == NULL)
		return ;
	set_path_name_to_execargs(node);
	set_flags(shell, node);
	set_arguments(shell, node);
}