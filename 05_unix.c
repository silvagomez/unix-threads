#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 * What are race conditions?
 *
 * With i < 100, we got 200 mails.
 * With i < 1000000, we got? A race condition...
 * What happen behind scene with mail++?
 * 		mail++;
 * 		- read mails.
 *		- increment.
 *		- write mails.
 *		Each thread incremented the mails variable once.
 *
 * To see the race conditions compile:
 * cc -S 05_unix.c
 */

int mails = 0;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
		mails++;
}

int	main(int ac, char *ag[])
{
	pthread_t	p1, p2;

	(void)ac;
	(void)ag;
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_join(p1, NULL) != 0)
		return (3);
	if (pthread_join(p2, NULL) != 0)
		return (4);
	printf("Number of mails: %d\n", mails);
	return (0);
}
