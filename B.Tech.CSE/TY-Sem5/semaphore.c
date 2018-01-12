#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <semaphore.h>

char print[100];

int MAX = 10;
int buff = 0;
pthread_mutex_t lock;
sem_t empty, full;

void* producer()
{
	while(true)
	{
		sem_wait(&empty);
		//if(buff < MAX)
		{
			pthread_mutex_lock(&lock);		
			buff++;
			sprintf(print, "Produced: %d\n", buff);
			write(1, print, strlen(print));
			pthread_mutex_unlock(&lock);
		}
        sem_post(&full);
		//printf("Produced: %d\n", buff);
	}	
}

void* consumer()
{
	while(true)
	{
		sem_wait(&full);
		//if(buff > 0)
		{
			pthread_mutex_lock(&lock);
			buff--;
			sprintf(print, "Consumed: %d\n", buff);
			write(1, print, strlen(print));
			pthread_mutex_unlock(&lock);
		}
        sem_post(&empty);
		//printf("Consumed: %d\n", buff);
	}	
}

void main(int argc, char** argv)
{	
	pthread_t prodThread;
	pthread_t consThread;
	
	sem_init(&empty,0,MAX);
	sem_init(&full,0,0);
	pthread_mutex_init(&lock, NULL);
	pthread_create(&prodThread, NULL, producer, NULL);
	pthread_create(&consThread, NULL, consumer, NULL);
	
	pthread_join(prodThread, NULL);
	pthread_join(consThread, NULL);		
	
	sem_destroy(&empty);
	sem_destroy(&full);
}


/*#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define BUFF_SIZE 10

sem_t full,empty;
pthread_mutex_t mutex;

int buffer[BUFF_SIZE], counter;

void initialize()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,BUFF_SIZE);
	counter=0;
}

void write(int item)
{
	buffer[counter++]=item;
}

int read()
{
	return(buffer[--counter]);
}

void* producer(void *arg) {
	int i = 0;
	while(i < *(int *)arg){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		printf("Producer has produced item: %d\n",i);
		write(i);
		i++;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	printf("DONE PRODUCING\n");
}

void* consumer(void *arg) {
	int i = 0, stuff;
	while(i < *(int *)arg){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		stuff=read();
		printf("Consumer has consumed item: %d\n",stuff);
		i++;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	printf("DONE CONSUMING\n");
}

int main(){
	int n = 0;
	initialize();
	pthread_t producerThread;
	pthread_t consumerThread;
	printf("Enter number of items to be exchanged: ");
	scanf("%d", &n);
	pthread_create(&producerThread, NULL, producer, &n);
	pthread_create(&consumerThread, NULL, consumer, &n);
	pthread_exit(NULL);
	return 0;				
}	*/
