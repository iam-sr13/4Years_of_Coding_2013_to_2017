#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX 9
pthread_mutex_t lock1,lock2;

typedef struct {
	int size;
	int q[10];
} queue;
void push(queue* qu, int n)
{
	if(qu->size < MAX)qu->q[(qu->size)++] = n;
}
void pop(queue* qu)
{
	if(qu->size > 0)qu->q[--(qu->size)];
}
queue q1,q2;

char print[50];
void disp(char* s, int i, int j)
{
	sprintf(print, s, i, j);
	write(1, print, strlen(print));
}

void* producer(void* id)
{
	int pid = *(int*)id;	
	
	while(1)
	{		
		if(q1.size < MAX)
		{
			pthread_mutex_lock(&lock1);
			push(&q1,pid);			
			disp("\nProducer[%d]: pushed to Q1(%d)",pid, q1.size);
				if(q2.size< MAX)
			{
				pthread_mutex_lock(&lock2);
				push(&q2,pid);
				disp("\nProducer[%d]: pushed to Q2(%d)",pid, q2.size);
				pthread_mutex_unlock(&lock2);
			}			
			pthread_mutex_unlock(&lock1);
		}			
		while(!(q1.size<MAX) && !(q2.size<MAX));			
	}
	
	return id;
}

void* consumer(void* id)
{
	int cid = *(int*)id;	
	
	while(1)
	{
			if(q2.size>0)
			{
				pthread_mutex_lock(&lock2);
				pop(&q2);
				
				if(q1.size>0)
				{
					pthread_mutex_lock(&lock1);
					pop(&q1);			
					disp("\nConsumer[%d]: popped from Q1(%d)",cid, q1.size);			
					pthread_mutex_unlock(&lock1);
				}	
				
				disp("\nConsumer[%d]: popped from Q2(%d)",cid, q2.size);			
				pthread_mutex_unlock(&lock2);
			}		
			
		while(!(q1.size>0) && !(q2.size>0));		
	}
	
	return id;
}

int main()
{
	printf("\nMultiple Producer Consumer Simulation!!\n\n");
	q1.size = 0;
	q2.size = 0;
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);
	
	int i1=0,i2=1,i3=2,i4=3,i5=4;
	pthread_t p[5], c[5];	
	
		pthread_create(&p[0], NULL, producer, (void*)&i1);
		pthread_create(&p[1], NULL, producer, (void*)&i2);
		pthread_create(&p[2], NULL, producer, (void*)&i3);
		pthread_create(&p[3], NULL, producer, (void*)&i4);
		pthread_create(&p[4], NULL, producer, (void*)&i5);
		
		pthread_create(&c[0], NULL, consumer, (void*)&i1);
		pthread_create(&c[1], NULL, consumer, (void*)&i2);
		pthread_create(&c[2], NULL, consumer, (void*)&i3);
		pthread_create(&c[3], NULL, consumer, (void*)&i4);
		pthread_create(&c[4], NULL, consumer, (void*)&i5);			
	
	pthread_join(p[0], NULL);
	pthread_join(p[1], NULL);
	pthread_join(p[2], NULL);
	pthread_join(p[3], NULL);
	pthread_join(p[4], NULL);
	
	pthread_join(c[0], NULL);	
	pthread_join(c[1], NULL);
	pthread_join(c[2], NULL);
	pthread_join(c[3], NULL);
	pthread_join(c[4], NULL);
	
	 
	return 0;
}

