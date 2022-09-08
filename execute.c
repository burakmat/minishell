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
		if (node->previous_node != NULL)
			execute(shell, node->previous_node);
		execve(node->cmd_path, argc, NULL);
	}
	else
	{
		close(fd[0]);
		waitpid(pid, 0 ,0);

	}
	//clear all node;
	// arguman null;
	// pipe;
	// flag split spli
}