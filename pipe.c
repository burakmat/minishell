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