#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv, char **envp)
{
	char *a;
	int fd; 

	char *ar[] = {"-l", NULL};
	fd = open("a", O_RDWR);
	int fd2 = open("b", O_RDONLY);
	int pid;


	if (!(pid = fork()))
	{
		dup2(fd, 1); // stdin == fd 
		execve("/bin/ls", ar, NULL);
	}
	else
	{
		waitpid(pid, 0, 0);
	}
	a = malloc(100);
	if (!(pid = fork()))
	{
		read(fd, a, 5);
		write(1, a, 5);
	}
	else
	{
		waitpid(pid, 0, 0);
	}
	
	return 0;
}