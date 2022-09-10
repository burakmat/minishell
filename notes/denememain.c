#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *argv[] = {NULL, NULL};

	execve("as", argv, NULL);
	return 0;
}