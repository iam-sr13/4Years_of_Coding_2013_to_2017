#include<iostream>
#include<cstdio>
#include<cstdlib>
#define CLR (system("cls"))

using namespace std;

void Add(int* a,int n)
{
	int z;
	cout<<"\nEnter the element value: ";
	cin>>z;
	a[n]=z;
}
int Delete(int* a,int n)
{
	return a[n];
}


int main()
{
	int max,sz=0,n,chk;	
	cout<<"\nWelcome to Array Manipulation Program....\n\nPlease enter MAX size 'N' of your array: ";
	cin>>max;
	int a[max];
	
	do {
		CLR;
		chk=1;		
		
		cout<<"\n #MAIN MENU\n____________\n\nYour Array: ";
		for(int i=0;i<sz;i++) {
			cout<<a[i];
			if(i<(sz-1)) cout<<",";
			else cout<<".";
		}
		cout<<"\n\n1. Add element\n2. Delete element\n3. Compute no. of elemnts\n4. Check if array is empty!\n5. Exit\n\n=> Your choice: ";
		cin>>n;
		switch(n) {
			case 1: if(sz==max) cout<<"\nArray Overflow!";					
					else {
						Add(a,sz);
						sz++;
				    }				
				break;
			case 2: if(sz==0) cout<<"\nArray underflow!!";					
					else {
						sz--;
						cout<<"\nElement Deleted: "<<Delete(a,sz);						
					}
					getchar(),getchar();					
				break;
			case 3: cout<<"\nTotal no. of elements is "<<sz<<endl;
					getchar(),getchar();
				break;
			case 4:if(sz==0) cout<<"\nArray is empty!";
					else cout<<"\nArray is not empty!";
					getchar(),getchar();
				break;
			case 5: chk=0;
				break;
			default: cout<<"\n\nException Thrown!!\nUnknown Choice!!\n\nPlease enter a valid Choice (1-5)!!"<<endl;
					 getchar(),getchar();
		} 
		
	}while(chk);
	
	return 0;
}
