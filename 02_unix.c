#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Short introduction to threads in C.
 * Threads execute at the same time, more or less.
 */

void	*routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("End thread\n");
}

int	main(int ac, char *ag[])
{
	pthread_t	t1, t2;

	(void)ac;
	(void)ag;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return (0);
}
