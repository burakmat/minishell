#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *argv[] = {"/bin/cat","-b", "pipedeneme.c", NULL};

	execve("/bin/cat", argv, NULL);
	return 0;
}