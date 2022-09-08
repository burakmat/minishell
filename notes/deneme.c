#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("a.txt", O_WRONLY);
	dup2(fd, 1);
	write(fd, "aslan", 5);
	write(1, "aslan", 5);
	printf("osman");
	return 0;
}