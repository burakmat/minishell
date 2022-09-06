#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv, char **envp)
{
	int forpipe[2];
	char *a;
	int fd; 

	pipe(forpipe);
	fd = open("a", O_RDONLY);
	dup2(fd, 0); // stdin == fd 
	dup2(1, forpipe[1]); // stdout == forpipe[1];

	a = malloc(1000);
	write(forpipe[1], "ahmet", 5);
	read(0, a, 5);
	printf("%s\n", a);
	return 0;
}