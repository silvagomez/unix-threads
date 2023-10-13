#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Short introduction to threads in C.
 *
 */

void	*routine()
{
	printf("Test from threads\n");
}

int	main(int ac, char *ag[])
{
	pthread_t	t1;

	(void)ac;
	(void)ag;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}
