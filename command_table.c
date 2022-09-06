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
	free_table(node, &table);
}