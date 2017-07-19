#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

class int_list
{
	int* a,n;
	void bubsort();
	void selsort();
	void insort();
	void getd();
	void putd();
	void swap(int &x,int &y)
	{
		int t;
		t=x;
		x=y;
		y=t;
	}
	void copylist(int*p,int*q)
	{
		int i;
		for(i=0;i<n;i++) p[i]=q[i];		
	}	
	public:
	int_list()
	{
		char ch;
		int c;
		cout<<"\n    WELCOME! to multi sort program!";
		for(;;) {
			cout<<"\n\n MAIN MENU \n\n1. Create list\n2. See the list\n3. See bubble sorted list\n4. See selection sorted list\n5. See insertion sorted list\n6. Exit\n\nYour Choice: ";
			cin>>c;
			switch(c) {
				case 1: cout<<"\nPlease enter the size of your list: ";
						cin>>n;
						a=new int[n];
						getd();
					break;
				case 2: putd();
					break;
				case 3: bubsort();
					break;
				case 4: selsort();
					break;
				case 5: insort();
					break;
				case 6: exit(0);
					break;					
			}
		}
	}
	~int_list()
	{
		delete[] a;
	}	
};

void int_list::insort()
{
	int i,j,x,t[n];
	copylist(t,a);
	for(i=1;i<n;i++) {
		x=t[i];
		for(j=i-1;(x<t[j] && j>=0);j--) t[j+1]=t[j];
		t[j+1]=x;
	}	
	cout<<"\nThis is your sorted list:\n";
	for(i=0;i<n;i++) {
		cout<<t[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}

void int_list::bubsort()
{
	int i,j,t[n];
	copylist(t,a);
	for(i=1;i<n;i++) for(j=0;j<n-i;j++) if(t[j]>t[j+1]) swap(t[j],t[j+1]);	
	cout<<"\nThis is your sorted list:\n";
	for(i=0;i<n;i++) {
		cout<<t[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}

void int_list::selsort()
{
	int i,j,sm,p,t[n];
	copylist(t,a);
	for(i=0;i<n-1;i++) {
		sm=t[i+1];
		p=i+1;
		for(j=i+2;j<n;j++) 
			if(sm>t[j]) {
				sm=t[j];
				p=j;
			}
		if(t[i]>t[p]) swap(t[i],t[p]);
	}	
	
	cout<<"\nThis is your sorted list:\n";
	for(i=0;i<n;i++) {
		cout<<t[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}

void int_list::getd()
{
	int i;
	cout<<"\nPlease enter the elements of your list:\n";
	for(i=0;i<n;i++) cin>>a[i];	
}
void int_list::putd()
{
	int i;
	cout<<"\nThis is your list:\n";
	for(i=0;i<n;i++) {
		cout<<a[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}

main()
{
	int_list z;	
}
