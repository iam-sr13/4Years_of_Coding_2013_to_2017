#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define s 1
using namespace std;

class int_list
{
	int* a,n;
	void getd()
	{
		int i;
		cout<<"\nPlease enter the elements of your list:\n";
		for(i=0;i<n;i++) cin>>a[i];	
	}
	void putd()
	{
		int i;
		cout<<"\nThis is your list:\n";
		for(i=0;i<n;i++) {
			cout<<a[i];
			if(i<n-1) cout<<", ";
			else cout<<".";
		}
	}
	void putd(int i)
	{
		cout<<"\nThis is your sorted list:\n";
		selsort();
		for(i=0;i<n;i++) {
			cout<<a[i];
			if(i<n-1) cout<<", ";
			else cout<<".";
		}
	}
	void swap(int *x,int *y)
	{
		int t;
		t=*x;
		*x=*y;
		*y=t;
	}
	void selsort();
	public:
	int_list()
	{
		char ch;
		int c;
		cout<<"\n    WELCOME! to selection sort program!";
		for(;;) {
			cout<<"\n\n MAIN MENU \n\n1. Create list\n2. See the list\n3. See the sorted list\n4. Exit\n\nYour Choice: ";
			cin>>c;
			switch(c) {
				case 1: cout<<"\nPlease enter the size of your list: ";
						cin>>n;
						a=new int[n];
						getd();
					break;
				case 2: putd();
					break;
				case 3: putd(s);
					break;
				case 4: exit(0);
					break;					
			}
		}
	}
	~int_list()
	{
		delete[] a;
	}
};

void int_list::selsort()
{
	int i,j,s1,p;
	for(i=0;i<n;i++) {
		s1=a[i+1];
		p=i+1;
		for(j=i+2;j<n;j++) 
			if(s1>a[j]) {
				s1=a[j];
				p=j;
			}
		if(a[i]>a[p]) swap(a+i,a+p);
	}
}

main()
{
	int_list z;	
}



