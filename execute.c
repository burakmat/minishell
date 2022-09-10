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
			//if no prev current, else go next
			//check for files if == 1 perror + exit(1)
			//nulls if (node->command == NULL && node->redirections != NULL && !node->illegalcommand) escape execve
			//if box1 == null && box4==null then free node, exit(1);
			if(node->cmd_path == NULL)
				exit(0);
			execve(node->cmd_path, node->exec_args, NULL);
		}
		else if (i < shell->totalnode - 1)
		{
			free_all_path(shell->free_.my_path);
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
