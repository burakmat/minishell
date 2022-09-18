#include "minishell.h"

void	create_pipes()
{
	int i;

	if (shell.pipes == NULL && shell.totalnode > 1)
	{
		shell.pipes = malloc(sizeof(int *) * shell.totalnode);//null pointer included, need to be freed after
		i = 0;
		while (i < shell.totalnode - 1)
		{
			shell.pipes[i] = malloc(sizeof(int) * 2);
			pipe(shell.pipes[i]);
			++i;
		}
		shell.pipes[i] = NULL;
	}
}

void close_unnecessary_fd(t_node *node)
{
	int i;

	i = 0;
	(void)node;
	while (shell.pipes && shell.pipes[i])
	{
		close(shell.pipes[i][0]);
		close(shell.pipes[i][1]);
		++i;
	}
}

void close_all_node_fd()
{
	int i;
	t_node *node;

	node = shell.head;
	while (node)
	{
		i = 0;
		while (shell.pipes && shell.pipes[i])
		{
			close(shell.env[i][0]);
			close(shell.pipes[i][1]);
			++i;
		}
		node = node->next_node;
	}
}