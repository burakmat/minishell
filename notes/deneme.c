#include<stdio.h>
#include <stdlib.h>
#include<unistd.h> 
int main()
{   
    char *s;

	s = malloc(1000);
	free(s);
	s = malloc(100000);
	system("leaks a.out");
    return 0;
}