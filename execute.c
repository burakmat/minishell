#include "minishell.h"

void	execute(t_shell *shell, t_node *node)
{
	int pid;
	int i;

	i = 0;
	pid = fork();
	while (1)
	{
		if (!pid)//child
		{
			//check for files if == 1 perror + exit(1)
			///pipes start
			if (shell->pipes != NULL)
			{
				close_unnecessary_fd(shell, node);
				//need dup
			}
			///pipes end

			if (node->cmd_path != NULL)
				execve(node->cmd_path, node->exec_args, NULL);
			else
				exit(1);
		}
		else if (i < shell->totalnode - 1)
		{
			node = node->next_node;
			++i;
			pid = fork();//pid = fork
		}
		else//main
		{
			waitpid(pid, 0 ,0);
			break ;
		}
	}
	//clear all node;
	// arguman null;
	// pipe;
	// flag split spli
}
