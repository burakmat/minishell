#include "minishell.h"
#include <signal.h>


void receiver(int sig)
{
	char *buffer;
	// write(1, "signal", 6);
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		exit(sig);
	}

}

void cocuk()
{
	char *buffer = "merhaba";
	int fd;

	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, &receiver);
	// signal(SIGQUIT, &receiver);
	write(1, ">>", 2);
	fd = dup(1);
	close(1);
	buffer = readline(NULL);
	if (buffer == NULL)
		exit(1);
	dup2(fd, 1);
	if (*buffer != '\0')
		printf("%s\n", buffer);
	exit(0);
}


void do_nut(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("quit\n");
		exit(0);
	}
	else if (sig == SIGINT)
		return ;
}

int main()
{
	int fd;
	int pipes[2];
	char *arg[] = {"which", "which", NULL};
	char a = 26;
	char *buffer;
	int i = 0;
	int e;
	e = 0;
	// pipe(pipes);
	// signal(SIGINT, SIG_DFL);

	while (1)
	{
		// printf("stop!!\n");
		// sleep(5);
		fd = fork();
		if (!fd)
		{
			cocuk();
		}
		else
		{
			signal(SIGINT, &do_nut);
			signal(SIGQUIT, &do_nut);
			wait(&e);
			if (WEXITSTATUS(e) == 1)
			{
				printf("exit\n");
				break;
			}
		}
	}





	// while (i++ < 5)
	// {
	// 	buffer = readline(">>");
	// 	write(pipes[1], buffer, ft_strlen(buffer));
	// }
	// close(pipes[1]);
	// dup2(pipes[0], 0);
	// close(pipes[0]);
	// dup2(fd, 0);







	// int pid[10];
	// int i = 0;
	
	// pid[i] = fork();
	// while (1)
	// {
	// 	if (!pid[i])
	// 	{
	// 		write(1, "giriş\n", 7);
	// 		return (0);
	// 	}
	// 	else if (i < 10)
	// 	{
	// 		i++;
	// 		pid[i] = fork();
	// 	}
	// 	else
	// 	{
	// 		break;
	// 	}
	// }
	// while (wait(NULL) > 0) ;
	// while(1);
}