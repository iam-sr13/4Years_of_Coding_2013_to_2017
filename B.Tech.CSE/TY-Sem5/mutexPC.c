#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

char print[100];

int MAX = 10;
int buff = 0;

pthread_mutex_t lock;

void* producer()
{
	while(true)
	{
		pthread_mutex_lock(&lock);
		if(buff < MAX)
		{		
			buff++;
			sprintf(print, "Produced: %d\n", buff);
			write(1, print, strlen(print));
		}
        pthread_mutex_unlock(&lock);
		//printf("Produced: %d\n", buff);
	}	
}

void* consumer()
{
	while(true)
	{
		pthread_mutex_lock(&lock);
		if(buff > 0)
		{
			buff--;
			sprintf(print, "Consumed: %d\n", buff);
			write(1, print, strlen(print));
		}
        pthread_mutex_unlock(&lock);
		//printf("Consumed: %d\n", buff);
	}	
}

void main(int argc, char** argv)
{	
	pthread_t prodThread;
	pthread_t consThread;
	
	pthread_mutex_init(&lock, NULL);
	pthread_create(&prodThread, NULL, producer, NULL);
	pthread_create(&consThread, NULL, consumer, NULL);
	
	pthread_join(prodThread, NULL);
	pthread_join(consThread, NULL);		
}
