#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// girilen path'i siler

	unlink("a.txt"); // a.txt siliyor 
}