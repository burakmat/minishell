#include "minishell.h"

void clear_all_nodes(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	current = head;
	while (current)
	{
		free(current->command);
		free(current->flags);
		free(current->argument);
		free(current->redirections);
		if (current->cmd_path)
			free(current->cmd_path);
		temp = current;
		current = current->next_node;
		free(temp);
	}
}