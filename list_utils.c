#include "minishell.h"

void clear_all_nodes(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	int		i;
	
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
		i = 0;
		if (current->exec_args)
		{
			while (current->exec_args[i])
			{
				free(current->exec_args[i]);
				i++;
			}
			free(current->exec_args);
		}
		temp = current;
		current = current->next_node;
		free(temp);
	}
}