#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


void	aloo(char *fonk, char **arg, int x)
{
	int fd[2];
	char *a;
	int c;
	x++;

	char *fonk2 = "/bin/cat";
	char *argv[] = {"bin/cat", NULL};
	char *argv2[] = {"bin/ls", NULL};
	
	
	pipe(fd);
	printf("%d\n", fd[0]);
	printf("%d\n", fd[1]);
	a = malloc(1000);
	int pid2 = fork();
	if(!pid2)
	{
		if(x == 2)
		{
			aloo(fonk2, argv, x);
		}
		execve(fonk, arg, NULL);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid2, 0, 0);
		printf("lala\n");
	}
}

int main()
{
	char *fonk = "/bin/ls";
	char *arg[] = {"bin/ls", NULL}; 
	aloo(fonk, arg, 1);
	return 0;
}