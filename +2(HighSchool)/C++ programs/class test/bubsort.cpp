#include<iostream>
#include<cstdlib>
#include<iomanip>
#define s 1
using namespace std;

class list
{
	int* a,*l,n;
	void getd();
	void putd();
	void putd(int i);
	void selsort();
	void swap(int& x,int& y)
	{
		int t;
		t=x;
		x=y;
		y=t;
	}
	public:
	list()
	{
		int c;
		
		cout<<"   WELCOME! To Bublesort Program!";
		for(;;) {
		cout<<"\n\n  MAIN MENU\n1.Create list\n2.See the original list\n3.See the sorted list\n4.Exit\n\nYour Choice: ";
		cin>>c;		
			switch(c) {
				case 1:	getd();
					break;
				case 2:putd();
					break;
				case 3:putd(s);
					break;
				case 4:exit(0);
					break;
			}
		}
		
	}
	~list()
	{
		delete[] a;
		delete[] l;
	}
};

void list::getd()
{
	int i;
	cout<<"\nEnter the size of your list: ";
	cin>>n;
	a=new int[n];
	l=new int[n];
	cout<<"\nPlease enter the elements of your list:\n";
	for(i=0;i<n;i++) {cin>>a[i];l[i]=a[i];}
	selsort();
}
void list::putd()
{
	int i;
	cout<<"\n\nThis is your original list:\n";
	for(i=0;i<n;i++) {
		cout<<a[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}
void list::putd(int i)
{
	cout<<"\n\nThis is your sorted list:\n";	
	for(i=0;i<n;i++) {
		cout<<l[i];
		if(i<n-1) cout<<", ";
		else cout<<".";
	}
}



int main()
{
	list z;
	return 0;
}

void list::selsort()
{
	int i,j,sm,p;
	for(i=0;i<n;i++) {
		sm=l[i+1];
		p=i+1;
		for(j=i+2;j<n;j++) if(sm>l[j]) {sm=l[j]; p=j;}
		if(l[i]>l[p]) swap(l[i],l[p]);
	}
}
