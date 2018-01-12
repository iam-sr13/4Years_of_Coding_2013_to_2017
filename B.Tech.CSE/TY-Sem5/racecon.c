#include <stdio.h>
#include <string.h>
#include <pthread.h>

int flag[2];
int turn;
const int MAX = 500000;
int ans = 0;
 
void lock_init()
{    
    flag[0] = flag[1] = 0;
    turn = 0;
}
 
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

void* func(void *s)
{
    int i = 0;
    int self = (int *)s;
    printf("Thread Entered: %d\n", self);
 
    //lock(self); 
      
    
    for (i=0; i<MAX; i++)
    {
        ans++;
        printf("\n%d", ans);
	}
 
 
    //unlock(self);   
}
 
// Driver code
int main()
{    
    pthread_t p1, p2;
    lock_init();
    
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);
     
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
 
    printf("\nActual Count: %d | Expected Count: %d\n",
                                        ans, MAX*2);
 
    return 0;
}
