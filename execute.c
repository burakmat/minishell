#include "minishell.h"

void	execute(t_shell *shell, t_node *node)
{
	int fd[2];
	int pid;

	char *argc[] = {node->exec_args[0], NULL};
	// node->cmd_path = search_in_path(shell, node);
	set_node(shell, node);
	// printf("0: %s\n", node->exec_args[0]);
	// printf("1: %s\n", node->exec_args[1]);
	pipe(fd);
	pid = fork();
	if (!pid)
	{
		if (node->previous_node != NULL)
			execute(shell, node->previous_node);
		if(node->cmd_path == NULL)
			exit(0);
		// printf("node->cmd_path: %s, node->exec_args[0]: %s, node->exec_args[1]: %s\n", node->cmd_path, node->exec_args[0], node->exec_args[1]);
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
