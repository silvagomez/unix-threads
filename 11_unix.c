
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*
 * How to pass arguments to threads in C.
 *
 * free(arg) is deallocating 'a'
 * the free must be in routine because if done in the main 'a' will be freed 
 * before other thread running at the same time try to print. 
 */

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	idx = *(int*)arg;
	printf("%d ", primes[idx]);
	free(arg);
}

int	main(int ac, char *ag[])
{
	pthread_t	th[10];
	int			i;
	int			*a;

	(void)ac;
	(void)ag;
	for (i = 0; i < 10; i++)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(th + i, NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (2);
	}
	return (0);
}
