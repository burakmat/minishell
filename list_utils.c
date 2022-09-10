#include "minishell.h"

void clear_all_nodes(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	
	current = head;
	while (current)
	{
		if (current->command != NULL)
			free(current->command);
		if (current->flags != NULL)
			free(current->flags);
		if (current->argument)
			free(current->argument);
		if (current->redirections != NULL)
			free(current->redirections);
		if (current->cmd_path != NULL)
			free(current->cmd_path);
		freeexec_args(current);
		temp = current;
		current = current->next_node;
		free(temp);
	}
}

void	freeexec_args(t_node *node)
{
	int	i;

	i = 0;
	if (node->exec_args)	
		{
			while (node->exec_args[i])
			{
				free(node->exec_args[i]);
				i++;
			}
			free(node->exec_args);
		}
}

void free_shell_pipes(t_shell *shell)//called in stage command
{
	int i;

	if (shell->pipes != NULL)
	{
		i = 0;
		while (shell->pipes[i])
		{
			free(shell->pipes[i]);
			++i;
		}
		free(shell->pipes[i]);//null pointer
		free(shell->pipes);
		shell->pipes = NULL;
	}
}