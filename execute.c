#include "minishell.h"

void	execute(t_shell *shell, t_node *node)
{
	int fd[2];
	int pid;

	set_node(shell, node);

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		if (node->previous_node != NULL)
			execute(shell, node->previous_node);
		if(node->cmd_path == NULL)
			exit(0);
		execve(node->cmd_path, node->exec_args, NULL);
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
