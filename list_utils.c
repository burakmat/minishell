#include "minishell.h"

void clear_all_nodes(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	int		i;
	
	current = head;
	printf("alo %s\n", current->exec_args[1]);
	while (current)
	{
		printf("alo1 %s\n", current->exec_args[1]);
		if (current->command != NULL)
			free(current->command);
	printf("alo2 %s\n", current->exec_args[1]);
		if (current->flags != NULL)
			free(current->flags);
	printf("alo3 %s\n", current->exec_args[1]);
		if (current->argument)
			free(current->argument != NULL);
	printf("alo %s\n", current->exec_args[1]);
		if (current->redirections != NULL)
			free(current->redirections);
	printf("alo %s\n", current->exec_args[1]);
		if (current->cmd_path != NULL)
			free(current->cmd_path);
	printf("alo %s\n", current->exec_args[1]);
		i = 1;
		if (current->exec_args != NULL)
		{
			free(current->exec_args);
		}
	printf("alo %s\n", current->exec_args[1]);
		
		temp = current;
		current = current->next_node;
		free(temp);
	}
}