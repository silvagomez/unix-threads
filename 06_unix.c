#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
 * What is a mutex in C?
 *
 * Lock - Unlock
 * Protect against other threads executing it at the same time.
 * If any point a thread is executing this code, there is not gonna be other
 * thread that could execute this same line of code, simply because there is a 
 * mutex arount it.
 *
 * 	pthread_mutex_lock(&mutex); 
 * 	mails++;
 * 	pthread_mutex_unlock(&mutex);
 */

int mails = 0;
//int lock = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		/* THE IDEA
		if (lock == 1)dd
			//wait until the lock is 0
		lock = 1;
		mails++;
		lock = 0;
		*/
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int ac, char *ag[])
{
	pthread_t	p1, p2, p3, p4;

	(void)ac;
	(void)ag;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_create(&p3, NULL, &routine, NULL) != 0)
		return (3);
	if (pthread_create(&p4, NULL, &routine, NULL) != 0)
		return (4);
	if (pthread_join(p1, NULL) != 0)
		return (5);
	if (pthread_join(p2, NULL) != 0)
		return (6);
	if (pthread_join(p3, NULL) != 0)
		return (7);
	if (pthread_join(p4, NULL) != 0)
		return (8);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
