#include "minishell.h"

void create_node(t_shell *shell, t_lexout *table)
{
	static int count;
	static t_node *prev;
	t_node *node;

	if (table->currentnode == 0)
		count = 0;
	node = malloc(sizeof(t_node));
	node->command = table->box1;
	node->flags = table->box2;
	node->argument = table->box3;
	node->redirections = table->box4;
	node->illegalflag = table->illegalflag;
	node->null_num = table->box3null;
	node->illegalcommand = table->illegalcommand;
	node->cmd_path = NULL;
	node->next_node = NULL;
	node->exec_args = NULL;
	if (count)
	{
		prev->next_node = node;
		node->previous_node = prev;
	}
	else
	{
		shell->head = node;
		node->previous_node = NULL;
	}
	prev = node;
	++count;
	if (count == table->totalnode)
		shell->tail = node;
}

int	builtin_check(char *command) //add functions
{
	if (ft_strncmp_exact(command, "echo", ft_strlen(command)) || ft_strncmp_exact(command, "/bin/echo", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "cd", ft_strlen(command)) || ft_strncmp_exact(command, "/usr/bin/cd", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "pwd", ft_strlen(command)) || ft_strncmp_exact(command, "/bin/pwd", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "export", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "unset", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "env", ft_strlen(command)) || ft_strncmp_exact(command, "/usr/bin/env", ft_strlen(command)))
		;//
	else if (ft_strncmp_exact(command, "exit", ft_strlen(command)))
		;//
	else
		return (0);
	return (1);
}

void	stage_command(t_shell *shell, t_node *node)
{
	char *abs_path;
	/*if (builtin_check(node->command))
		node->is_builtin = 1;
	if node->is_builtin == 1 execute builtin */
	//send node to child
	if (node->command == NULL && node->redirections != NULL && !node->illegalcommand)
	{
		printf("şimdilik boş\n"); //sadece pipe yapılacak execute girme	
	}
	else if (node->command != NULL || node->illegalcommand)
	{
		execute(shell, node);
		clear_all_nodes(shell->head);
		free_all_path(shell->free_.my_path);
	}
	else
		free(node);
}

void	free_all_path(char **path)
{
	int i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

char *search_in_path(t_shell *shell, t_node *node)
{
	int i;
	char *searched;


	i = is_there_path(shell);
	if (i == -1)
	{
		shell->err_code = 1;
		print_error(shell, node);
	}
	else
	{
		shell->free_.my_path = split_path(shell, i);
		i = 0;
		while (shell->free_.my_path[i])
		{
			searched = ft_strjoin_path(shell->free_.my_path[i], node->command);
			if (!access(searched, X_OK) && node->command != NULL)
				return (searched);
			free(searched);
			++i;
		}
		if (!access(node->command, X_OK) && node->command != NULL)
			return (node->command);
		return (NULL);
	}
}

char **split_path(t_shell *shell, int ind)
{
	char **copy_path;

	copy_path = ft_split(shell->env[ind], ':');
	edit_first_path(copy_path);
	return (copy_path);
}

void **edit_first_path(char **all_path_copy)
{
	char *first_path;
	int i;
	int j;

	i = ft_strlen(all_path_copy[0]);
	i -= 5;
	first_path = malloc(i + 1);
	j = 0;
	while (j < i)
	{
		first_path[j] = all_path_copy[0][j + 5];
		++j;
	}
	first_path[i] = '\0';
	free(all_path_copy[0]);
	all_path_copy[0] = first_path;
}

int	is_there_path(t_shell *shell)
{
	int i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5))
			return (i);
		++i;
	}
	return (-1);
}
