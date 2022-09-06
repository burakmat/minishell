#include "minishell.h"

void create_node(t_shell *shell, t_lexout table)
{
	static int count;
	static t_node *prev;
	t_node *node;

	node = malloc(sizeof(t_node));
	node->command = table.box1;
	node->flags = table.box2;
	node->argument = table.box3;
	node->redirections = table.box4;
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
}