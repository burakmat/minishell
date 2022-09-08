#include "minishell.h"

void	execute(t_shell *shell, t_node *node)
{
	int fd[2];
	int pid;

	char *argc[] = {node->flags, NULL};
	node->cmd_path = search_in_path(shell, node);
	pipe(fd);
	pid = fork();
	if (!pid)
	{
		if (shell->head->previous_node != NULL)
			execute(shell, node->next_node);
		execve(shell->head->cmd_path, argc, NULL);
	}
	else
	{
		waitpid(pid, 0 ,0);
	}
	//clear all node;
	// arguman null;
	// pipe;
	// flag split spli
}