#include "minishell.h"
#include <signal.h>


int main()
{
	int fd;
	char *arg[] = {"cat", "-e", NULL};
	char a = 26;
	fd = open("a", O_RDWR | O_TRUNC, 0777);
	close(fd);

	// dup2(fd, 0);
	// execve("/bin/cat", arg, NULL);







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