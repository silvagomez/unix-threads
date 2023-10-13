#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Difference between processes and threads.
 *
 * Threads file.
 * 
 * 1. Processes can have/contain multiple threads in a single process,
 * but threads can not have/contain multiple process in a single thread.
 * 2. Second difference is the space address. When forking we duplicate all
 * variables to child/parent, but with threads all variables are in the same
 * space, all threads can access to them.
 */

int	x = 2;

void	*routine()
{
	x += 2;
	sleep(2);
	printf("Value of x: %d\n", x);
}

void	*routine_2()
{
	sleep(2);
	printf("Value of x: %d\n", x);
}

int	main(int ac, char *ag[])
{
	pthread_t	t1, t2;

	(void)ac;
	(void)ag;
	printf("THREADS FILE\n");
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine_2, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return (0);
}
