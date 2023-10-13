#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
 * Difference between processes and threads.
 *
 * Processes file.
 * 
 * 1. Processes can have/contain multiple threads in a single process,
 * but threads can not have/contain multiple process in a single thread.
 * 2. Second difference is the space address. When forking we duplicate all
 * variables to child/parent, but with threads all variables are in the same
 * space, all threads can access to them.
 */

int	main(int ac, char *ag[])
{
	int	x;
	int pid;

	x = 2;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		x++;
	sleep(2);
	printf("Value of x: %d\n", x);
	if (pid != 0)
	{
		wait(NULL);
	}
	return (0);
}
