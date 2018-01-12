#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#define   BUF_SIZE   100

char print[BUF_SIZE];

int turn = 0;
bool flag[2] = {0, 0};

int MAX = 10;
int buff = 0;

// Executed before entering critical section
void lock(int self)
{
    // Set flag[self] = 1 saying you want to acquire lock
    flag[self] = 1;     
    turn = 1-self;
    
    while (flag[1-self]==1 && turn==1-self) ;
}
 
// Executed after leaving critical section
void unlock(int self)
{    
    flag[self] = 0;
}

void* producer()
{
	int self = 0;
	while(true)
	{
		lock(self);
		if(buff < MAX)
		{		
			buff++;
			sprintf(print, "Produced: %d\n", buff);
			write(1, print, strlen(print));
		}
        unlock(self);
		//printf("Produced: %d\n", buff);
	}	
}

void* consumer()
{
	int self = 1;
	while(true)
	{
		lock(self);
		if(buff > 0)
		{
			buff--;
			sprintf(print, "Consumed: %d\n", buff);
			write(1, print, strlen(print));
		}
        unlock(self);
		//printf("Consumed: %d\n", buff);
	}	
}

int main()
{
	pthread_t p1, p2;  
    
	pthread_create(&p1, NULL, producer, NULL);
	pthread_create(&p2, NULL, consumer, NULL);
		 
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);	
	
	return 0;
}
 
