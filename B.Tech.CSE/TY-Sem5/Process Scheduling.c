#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)

struct process
{
	int pid, burst_time, priority;	
};

unsigned int getMinTime(struct process* processes, int* completed, const unsigned int numProcesses)
{
	unsigned int i = 0, index = -1;
	unsigned int min = 1<<10;
	for(; i < numProcesses; i++)
	{
		index = min > processes[i].burst_time && !completed[i]? i : index;
		min = min > processes[i].burst_time && !completed[i]? processes[i].burst_time : min;
	}
	return index;
}

unsigned int getMinPriority(struct process* processes, int* completed, const unsigned int numProcesses)
{
	unsigned int i = 0, index = -1;
	unsigned int min = 1<<10;
	for(; i < numProcesses; i++)
	{
		index = min > processes[i].priority && !completed[i]? i : index;
		min = min > processes[i].priority && !completed[i]? processes[i].priority : min;
	}
	return index;
}

void printBar(const unsigned int fill, const unsigned int size)
{
	int i;
	printf("|");
	for(i = 0; i < size; i++)
		printf("%d", fill);
	printf("|");
}

void setBurstTime(struct process* processes, const unsigned int numProcesses)
{
	int i;
	for(i = 0; i < numProcesses; i++)
	{
		processes[i].pid = i;
		printf("Burst time for Process %d: ", i);
		scanf("%d", &processes[i].burst_time);
	}
}

void setPriority(struct process* processes, const unsigned int numProcesses)
{
	int i;
	for(i = 0; i < numProcesses; i++)
	{
		printf("Priority for Process %d: ", i);
		scanf("%d", &processes[i].priority);
	}
}

void FCFS(const struct process* const processes, const unsigned int numProcesses)
{
	int i, j;
	for(i = 0; i < numProcesses; i++)
	{
		printBar(processes[i].pid, processes[i].burst_time);
	}
}	


void SJF(struct process* processes, unsigned int numProcesses)
{
	int i=0, j=0;
	int *completed = (int*)malloc(numProcesses * sizeof(int));

	for(; i < numProcesses; i++)
		completed[i] = 0;
	for(i = 0; i < numProcesses; i++)
	{
		int index = getMinTime(processes, completed, numProcesses);
		printBar(processes[index].pid, processes[index].burst_time);
		completed[index] = 1;
	}
	free(completed);
}

void Priority(struct process* processes, unsigned int numProcesses)
{
	int i=0, j=0;
	int *completed = (int*)malloc(numProcesses * sizeof(int));

	for(; i < numProcesses; i++)
		completed[i] = 0;
	for(i = 0; i < numProcesses; i++)
	{
		int index = getMinPriority(processes, completed, numProcesses);
		printBar(processes[index].pid, processes[index].burst_time);
		completed[index] = 1;
	}
	free(completed);
}


void RoundRobin(struct process* processes, unsigned int numProcesses, unsigned int TQ)
{
	int i=0, j=0, overProgs = 0;
	int *completed = (int*)malloc(numProcesses * sizeof(int));

	for(; i < numProcesses; i++)
		completed[i] = 0;
	while(overProgs < numProcesses)
	{
		i=0;
		for(; i < numProcesses; i++)
		{
			if(!completed[i])
			{
				printBar(processes[i].pid, min(processes[i].burst_time, TQ));		
				
				processes[i].burst_time -= min(processes[i].burst_time, TQ);
				if(processes[i].burst_time <0) processes[i].burst_time = 0;
				if(processes[i].burst_time==0)
				{				
					completed[i] = 1;
					overProgs++;
				}
			}
		}
	}
	free(completed);
}

int main(int *argc, char** argv)
{
	int numProc = 0;
	printf("Please enter total no. of processes: ");
	scanf("%d", &numProc);

	struct process* processes = (struct process*)malloc(numProc * sizeof(struct process));
	
	setBurstTime(processes, numProc);
	setPriority(processes, numProc);
	
	printf("\nFollowing are the respective Gantt Charts:-\n\nFCFS: ");
	FCFS(processes, numProc);
	printf("\n");
	printf("\nSJF: ");
	SJF(processes, numProc);
	printf("\n");
	printf("\nPrior: ");
	Priority(processes, numProc);
	printf("\n");
	printf("\nRR: ");
	RoundRobin(processes, numProc, 5);
	free(processes);
	
	return 0;
}
