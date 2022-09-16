#include "minishell.h"

void newProcess(t_shell *shell, t_node *node)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		//check for files if == 1 perror + exit(1)
		//redirections
		set_input_redirections(shell, node, check_input_redirections(shell, node));
		set_output_redirections(shell, node);
		///pipes start
		// if (shell->pipes != NULL)
		if (node->previous_node != NULL && node->in == 0)
			dup2(shell->pipes[node->id - 1][0], 0);
		if (node->next_node != NULL && node->out == 0)
			dup2(shell->pipes[node->id][1], 1);
		close_all_node_fd(shell);
		if (builtin_check(node->exec_args[0]) != 0) // if command is builtin
			go_to_builtin(shell, node, node->exec_args[0]);
		if (node->cmd_path != NULL)
			execve(node->cmd_path, node->exec_args, NULL);
		exit(0);
		
	}
}

void	execute(t_shell *shell, t_node *node)
{
	int i;

	i = -1;
	while (1)
	{
		if (i < shell->totalnode - 1)
		{
			++i;
			if (node->exec_args && builtin_check(node->exec_args[0]) == 7)
				builtin_exit();
			if (node->exec_args && builtin_check(node->exec_args[0]) == 2)
				builtin_cd(shell, node);
			if (node->exec_args && builtin_check(node->exec_args[0]) == 5)
				edit_unset(shell, node);	
			if (node->exec_args && builtin_check(node->exec_args[0]) == 4)
				re_malloc_env(shell, node, i);
			newProcess(shell, node);
			if (node->next_node != NULL) //node->exec_args error vermesin diye
				node = node->next_node;
		}
		else//main
		{
			close_all_node_fd(shell);
			while (wait(NULL) > 0) ;
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
		;//cd bir şey koymaya gerek yok gibi
	if (builtin_check(argv) == 3)
		builtin_pwd();//pwd
	if (builtin_check(argv) == 4 && node->exec_args[1] == NULL)
		builtin_export(shell);
	if (builtin_check(argv) == 5)
		;//printf("bir şey koymaya gerek yok gibi\n")
	if (builtin_check(argv) == 6)
		builtin_env(shell);
	if (builtin_check(argv) == 7)
		;//exit
	exit(1);
}