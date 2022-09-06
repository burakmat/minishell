#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *argv[] = {"/bin/ls", "-a", "-b", NULL};

	execve("/bin/ls", argv, NULL);
	return 0;
}