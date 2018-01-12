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

void* producer(void* id)
{
	while(true)
	{
		sem_wait(&empty);
		//if(buff < MAX)
		{
			pthread_mutex_lock(&lock);		
			buff++;
			sprintf(print, "Produced%d: %d\n", *(int*)id, buff);
			write(1, print, strlen(print));
			pthread_mutex_unlock(&lock);
		}
        sem_post(&full);
		//printf("Produced: %d\n", buff);
	}	
}

void* consumer(void* id)
{
	while(true)
	{
		sem_wait(&full);
		//if(buff > 0)
		{
			pthread_mutex_lock(&lock);
			buff--;
			sprintf(print, "Consumed%d: %d\n", *(int*)id, buff);
			write(1, print, strlen(print));
			pthread_mutex_unlock(&lock);
		}
        sem_post(&empty);
		//printf("Consumed: %d\n", buff);
	}	
}

void main(int argc, char** argv)
{	
	pthread_t p1,p2,p3;
	pthread_t c1,c2,c3;
	int i1=1,i2=2,i3=3;
	
	sem_init(&empty,0,MAX);
	sem_init(&full,0,0);
	pthread_mutex_init(&lock, NULL);
	pthread_create(&p1, NULL, producer, (void*)&i1);
	pthread_create(&c1, NULL, consumer, (void*)&i1);
	pthread_create(&p2, NULL, producer, (void*)&i2);
	pthread_create(&c2, NULL, consumer, (void*)&i2);
	pthread_create(&p3, NULL, producer, (void*)&i3);
	pthread_create(&c3, NULL, consumer, (void*)&i3);
	
	pthread_join(p1, NULL);
	pthread_join(c1, NULL);	
	pthread_join(p2, NULL);
	pthread_join(c2, NULL);
	pthread_join(p3, NULL);
	pthread_join(c3, NULL);	
}









/*#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define BUFF_SIZE 10

sem_t full,empty;
pthread_mutex_t mutex;
int buffer[BUFF_SIZE], counter;
pthread_t tidP[20],tidC[20];
int np, nc;

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
	while(i < np){
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
	while(i < nc){
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
	int n, n1, n2, i;
	initialize();
	printf("Enter number of items to be exchanged: ");
	scanf("%d", &n);
	printf("\nEnter the no of producers: ");
	scanf("%d",&n1);
	printf("\nEnter the no of consumers: ");
	scanf("%d",&n2);
	np = n/n1;
	nc = n/n2;
	for(i=0;i<n1;i++)
		pthread_create(&tidP[i],NULL,producer,&i);
	for(i=0;i<n2;i++)
		pthread_create(&tidC[i],NULL,consumer,&i);
	pthread_exit(NULL);
	return 0;				
}	
*/
