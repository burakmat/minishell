#include "minishell.h"

void newProcess(t_shell *shell, t_node *node)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		//check for files if == 1 perror + exit(1)
		///pipes start
		// if (shell->pipes != NULL)
		if (node->previous_node != NULL)
			dup2(shell->pipes[node->id - 1][0], 0);
		if (node->next_node != NULL)
			dup2(shell->pipes[node->id][1], 1);
		if (builtin_check(node->exec_args[0]) != 0) // if command is builtin
			go_to_builtin(shell, node, node->exec_args[0]);
		if (node->cmd_path != NULL)
			execve(node->cmd_path, node->exec_args, NULL);
		exit(0);
		
	}
}



void	execute(t_shell *shell, t_node *node)
{
	int pid;
	int i;
	int status = 0;

	i = -1;
	while (1)
	{
		if (i < shell->totalnode - 1)
		{
			++i;
			usleep(100);
			newProcess(shell, node);		
			node = node->next_node;
		}
		else//main
		{
			while (wait(NULL) > 0) ;
			close_all_node_fd(shell);
			// printf("stat%d\n", status);
			break ;
		}
	}
	//clear all node;
	// arguman null;
	// pipe;
	// flag split spli
}

void	go_to_builtin(t_shell *shell, t_node *node, char *argv)
{
	if (builtin_check(argv) == 1)
		builtin_echo(node);
	if (builtin_check(argv) == 2)
		builtin_echo(node);
	if (builtin_check(argv) == 3)
		builtin_echo(node);
	if (builtin_check(argv) == 4)
		builtin_export(shell, node);
	if (builtin_check(argv) == 5)
		builtin_echo(node);
	if (builtin_check(argv) == 6)
		builtin_echo(node);
	if (builtin_check(argv) == 7)
		builtin_echo(node);
	exit(1);
}