#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

char print[100];

int MAX = 10;
int buff = 0;

pthread_mutex_t lock;

void* producer(void* id)
{
	while(true)
	{
		pthread_mutex_lock(&lock);
		if(buff < MAX)
		{		
			buff++;
			sprintf(print, "Produced%d: %d\n", *(int*)id, buff);
			write(1, print, strlen(print));
		}
        pthread_mutex_unlock(&lock);
		//printf("Produced: %d\n", buff);
	}	
}

void* consumer(void* id)
{
	while(true)
	{
		pthread_mutex_lock(&lock);
		if(buff > 0)
		{
			buff--;
			sprintf(print, "Consumed%d: %d\n", *(int*)id, buff);
			write(1, print, strlen(print));
		}
        pthread_mutex_unlock(&lock);
		//printf("Consumed: %d\n", buff);
	}	
}



void main(int argc, char** argv)
{	
	pthread_t p1,p2,p3;
	pthread_t c1,c2,c3;
	int i1=1,i2=2,i3=3;
	
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


/*#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int count = 0;
int buffer[1000];
int front = -1, rear = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t empty = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t full = PTHREAD_MUTEX_INITIALIZER;


void* produce(void* size)
{
	int buffSize = *(int*)size;
	//while(1)
	{
		int i = 0;
		while(i < buffSize)
		{
			if(count == buffSize)
			{
				printf("Buffer full! Count = %d\n", count);
				pthread_mutex_lock(&full);
			}
			else
			{
				pthread_mutex_lock(&lock);
				buffer[rear] = i;
				if(front == -1)
					front = rear;
				printf("Produced %d    Count = %d\n", buffer[rear], 1+count);
				rear = (rear + 1) % buffSize;
				count++;
				pthread_mutex_unlock(&lock);
				pthread_mutex_unlock(&empty);
				i++;
			}
		}
	}
}
void* consume(void* size)
{
	int buffSize = *(int*)size;
	//while(1)
	{	
		int i = buffSize;
		while(i > 0)
		{
			if(count == 0)
			{
				printf("Buffer empty! Count = %d\n", count);
				pthread_mutex_lock(&empty);
			}

			else
			{
				pthread_mutex_lock(&lock);
				printf("Consumed %d    Count = %d\n", buffer[front], count-1);
				if((front + 1) % buffSize == rear)
					front = -1;
				else
					front = (front + 1) % buffSize;
				count--;
				pthread_mutex_unlock(&lock);
				pthread_mutex_unlock(&full);
				i--;
			}
		}
	}
}
void main(int argc, char** argv)
{
	int buffSize, n_each;
	printf("Buffer Size (> 0): ");
	scanf("%u", &buffSize);
	pthread_t producer1Thread;
    pthread_t producer2Thread;
    pthread_t producer3Thread;
	pthread_t consumer1Thread;
	pthread_t consumer2Thread;
	pthread_t consumer3Thread;
	n_each = buffSize / 3;
	pthread_create(&producer1Thread, NULL, produce, &n_each);
    pthread_create(&consumer1Thread, NULL, consume, &n_each);
	pthread_create(&producer2Thread, NULL, produce, &n_each);
    pthread_create(&consumer2Thread, NULL, consume, &n_each);
    pthread_create(&producer3Thread, NULL, produce, &n_each);
	pthread_create(&consumer3Thread, NULL, consume, &n_each);
	pthread_exit(NULL);
	pthread_exit(NULL);
}*/
