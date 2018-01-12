#include <iostream>
#include <iomanip>
using namespace std;

int m,n;
int *Available = 0;	
int **Max = 0;	
int **Allocation = 0;
int **Need = 0;	

void showMatrix(int** a)
{
	cout<<"   ";
	for(int i=0; i<m; i++)
		  cout<<"R"<<i<<" "; 
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"P"<<i<<" ";
		for(int j=0; j<m; j++)
			cout<<setw(2)<<a[i][j]<<" ";
		cout<<endl;
	}
}

bool isSafe()
{
	//calc need
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)		
			Need[i][j] = Max[i][j] - Allocation[i][j];
			
	int work[m];
	for(int i=0; i<m; i++)
	{
		work[i] = Available[i];
	}
	
	bool finish[n];
	for(int i=0; i<n; i++)
	{
		finish[i] = false;
	}
	
	int safeSeq[n];
	
	int count = 0;
    while (count < n)
    {
        bool found = false;
        for (int p = 0; p < n; p++)
        {           
            if (finish[p] == 0)
            {                
                int j;
                for (j = 0; j < m; j++)
                    if (Need[p][j] > work[j])
                        break;
                 
                if (j == m)
                {                    
                    for (int k = 0 ; k < m ; k++)
                        work[k] += Allocation[p][k]; 
                    
                    safeSeq[count++] = p;                     
                    finish[p] = 1; 
                    found = true;
                }
            }
        }
 
        if (found == false)
        {
            cout<<"\nWarning!! System is not in safe state!!";
            return false;
        }
    }
 
    cout << "\nSystem is in safe state.\nRequired Safe sequence is: ";
    for (int i = 0; i < n ; i++)
        cout <<"P"<< safeSeq[i] << " ";
 
    return true;
}

int main()
{	
	cout<<"\nWelcome to Banker's Algorithm Safety Simulation!"<<endl;
	cout<<"\nPlease enter total no. of processes: ";
	cin>>n;
	cout<<"\nPlease enter total no. of resource types: ";
	cin>>m;
	
	Available = new int[m];
	
	Max = new int*[n];
	for(int i=0; i<n; i++) Max[i] = new int[m];
	
	Allocation = new int*[n];
	for(int i=0; i<n; i++) Allocation[i] = new int[m];
	
	Need = new int*[n];
	for(int i=0; i<n; i++) Need[i] = new int[m];
	
	cout<<"\nNow for each of the resource types Ri, enter no. of available instances: ";
	for(int i=0; i<m; i++) 
	{
		cout<<"\nR"<<i<<" : ";
		cin>>Available[i];
	}
	
	cout<<"\nNow for each of the process Pi, enter max. demand of instances per resource type Rj: ";
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)
		{
			cout<<"\nP"<<i<<"R"<<j<<" : ";
			cin>>Max[i][j];
		}
		
	cout<<"\nNow for each of the process Pi, enter no. of currently allocated instances per resource type Rj: ";
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)
		{
			cout<<"\nP"<<i<<"R"<<j<<" : ";
			cin>>Allocation[i][j];
		}	
		
	cout<<"\nFollowing are your input data: "<<endl<<"\nAvailable[i] : ";
	for(int j=0; j<m; j++) cout<<Available[j]<<" ";
	
	cout<<"\n\nMax[i][j] : \n";
	showMatrix(Max);
	
	cout<<"\n\nAllocation[i][j] : \n";
	showMatrix(Allocation);
	
	isSafe();
	
	return 0;
}
