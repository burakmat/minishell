#include "minishell.h"

void	create_pipes(t_shell *shell)
{
	int i;

	if (shell->pipes == NULL && shell->totalnode > 1)
	{
		shell->pipes = malloc(sizeof(int *) * shell->totalnode);//null pointer included, need to be freed after
		i = 0;
		while (i < shell->totalnode - 1)
		{
			shell->pipes[i] = malloc(sizeof(int) * 2);
			pipe(shell->pipes[i]);
			++i;
		}
		shell->pipes[i] = NULL;
	}
}

void close_unnecessary_fd(t_shell *shell, t_node *node)
{
	int i;

	i = 0;
	while (shell->pipes[i])
	{
		if (i != node->id - 1 && i != node->id)
		{
			close(shell->pipes[i][0]);
			close(shell->pipes[i][1]);
		}
		else if (i == node->id)
			close(shell->pipes[i][0]);
		else if(i == node->id - 1)
			close(shell->pipes[i][1]);
		++i;
	}
}