#include "minishell.h"
#include <signal.h>


void receiver(int sig)
{
	char *buffer;
	// write(1, "signal", 6);
	if (sig == SIGINT)
	{
		exit(0);
	}

}

void cocuk()
{
	char *buffer = "merhaba";
	int fd;

	// signal(SIGQUIT, SIG_DFL);
	// signal(SIGQUIT, &receiver);
	signal(SIGINT, &receiver);
	write(1, ">>", 2);
	fd = dup(1);
	close(1);
	buffer = readline(NULL);
	if (buffer == NULL)
		exit(1);
	dup2(fd, 1);
	if (*buffer != '\0')
		printf("buffer: %s\n", buffer);
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

void sinyal(int sig)
{
	int pid;
	char c = 26;
	int fd;
	fd = dup(1);
	close(1);
	pid = fork();
	if (!pid)
	{
		dup2(fd, 1);
		write(1, &c, 1);
		printf("cock\n");
	}
	else
	{

		exit(0);
	}
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
	signal(SIGINT, &sinyal);

while (1)
{

	buffer = readline("shell>>");

	printf("-%s-\n", buffer);
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