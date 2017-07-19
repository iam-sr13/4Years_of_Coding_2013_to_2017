#include<iostream>

using namespace std;
int sz;

void Delete(int* a, int p)
{
	if(p==sz-1) sz--;
	else
	{
		for(int i=p;i<sz-1;i++)
			a[i]=a[i+1];
		sz--;
	}
}

void purge(int* a)
{
	for(int i=0;i<sz-1;i++)
		for(int j=i+1;j<sz;)
			if(a[i]==a[j]) {
				Delete(a,j);
			}
			else j++;
}

int main()
{
	int *a;
	
	cout<<"\nEnter size: ";cin>>sz;
	a=new int[sz];
	
	cout<<"\nEnter values:\n";
	for(int i=0;i<sz;i++) cin>>a[i];
	
	cout<<"\nYour array: ";
	for(int i=0;i<sz;i++) {
		cout<<a[i];
		if(i<sz-1) cout<<',';
		else cout<<'.';
	}
	
	cout<<"\nYour purged array: ";
	purge(a);
	for(int i=0;i<sz;i++) {
		cout<<a[i];
		if(i<sz-1) cout<<',';
		else cout<<'.';
	}
	
	return 0;
}
