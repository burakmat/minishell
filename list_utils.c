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
			free(current->argument != NULL);
		if (current->redirections != NULL)
		free(current->redirections);
		if (current->cmd_path != NULL)
			free(current->cmd_path);
		temp = current;
		current = current->next_node;
		free(temp);
	}
}