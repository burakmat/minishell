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
			if (builtin_check(node->exec_args[0]) != 0) // if command is builtin
				go_to_builtin(shell, node, node->exec_args[0]);
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
	show_env(shell);
	exit(1);
}