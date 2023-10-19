#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*
 * Get return value from a thread.
 */

void	*roll_dice()
{
	int	value;
	int	*result = malloc(sizeof(int));

	value = (rand() % 6) + 1;
	//printf("%d\n", value);
	printf("Thread result: %p\n", result);
	*result = value;
	return ((void*) result);
}

int	main(int ac, char *ag[])
{
	pthread_t	th[4];
	int			i;
	int			*res;

	(void)ac;
	(void)ag;
	srand(time(NULL));
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(th + i, NULL, &roll_dice, NULL) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n", i);
	}
	for (i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], (void**)&res) != 0)
			return (2);
		printf("Main res: %p\n", res);
		printf("Result: %d\n", *res);
		free(res);
	}
	return (0);
}
