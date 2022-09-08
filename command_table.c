#include "minishell.h"

void free_table(t_node *node, t_lexout *table)
{
	if (table->box1[0] == '\0')
		free(node->command);
	if (table->box2[0] == '\0')
		free(node->flags);
	if (table->box3[0] == '\0')
		free(node->argument);
	if (table->box4[0] == '\0')
		free(node->redirections);
}

void create_node(t_shell *shell, t_lexout *table)
{
	static int count;
	static t_node *prev;
	t_node *node;

	node = malloc(sizeof(t_node));
	node->command = table->box1;
	node->flags = table->box2;
	node->argument = table->box3;
	node->redirections = table->box4;
	node->cmd_path = NULL;
	node->next_node = NULL;
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
	free_table(node, table);
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
	if (builtin_check(node->command))
		node->is_builtin = 1;
	/* if node->is_builtin == 1 execute builtin */
	//send node to child
	execute(shell, node);
}

char *search_in_path(t_shell *shell, t_node *node)
{
	int i;
	char **my_path;
	char *searched;

	i = is_there_path(shell);
	if (i == -1)
	{
		shell->err_code = 1;
		print_error(shell);
	}
	else
	{
		my_path = split_path(shell, i);
		i = 0;
		while (my_path[i])
		{
			searched = ft_strjoin_path(my_path[i], node->command);
			if (!access(searched, X_OK))
				return (searched);
			free(searched);
			++i;
		}
		if (!access(node->command, X_OK))
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
		first_path[j] = all_path_copy[0][j];
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
