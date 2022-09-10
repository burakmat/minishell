#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *argv[] = {"as", NULL};

	execve(NULL, argv, NULL);
	return 0;
}