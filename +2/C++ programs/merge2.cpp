#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

class list
{
	int *data,n;
	void swap(int *x,int *y)
	{
		int t;
		t=*x;
		*x=*y;
		*y=t;
	}	
	public:		
		void putd();
		void getd();
		int size() {return n;}
		list merge(list &q);
		list(int g) {
			n=g;
			data=new int[n];					
		}
		~list() {
			delete[] data;			
		}
		list operator+(list &q)
		{
			return merge(q);			
		}
};

list list::merge(list &q)
{
	int i,j,k;
	list z(this->size()+q.size());
	for(i=0,j=0,k=0;((i<this->size()) && (j<q.size()));) 
		if(this->data[i]<q.data[j]) z.data[k++]=this->data[i++];
			else z.data[k++]=q.data[j++];
	if(i==this->size()) for(;j<q.size();) z.data[k++]=q.data[j++];
	if(j==q.size()) for(;i<this->size();) z.data[k++]=this->data[i++];
	return z;
}

void list::getd()
{
	int i;	
	for(i=0;i<n;i++) {cout<<"\nEnter the "<<i+1<<" th element: "; cin>>data[i];}
	//sort(data,data+n);		
}

void list::putd()
{
	int i;
	cout<<"Your list is:-\n\n";	
	for(i=0;i<n;i++) {cout<<data[i];if(i<n-1) cout<<", "; else cout<<".";}	
	cout<<endl<<endl;	
}

main()
{
	int l,m;
	cout<<"Enter the size of 2 lists: ";
	cin>>l>>m;
	list A(l),B(m),C(l+m);
	cout<<"\nFor List 1:\n";
	A.getd();
	cout<<"\nFor List 2:\n";
	B.getd();

	C=A+B;
	cout<<"\nList 1:\n";
	A.putd();
	cout<<"\nList 2:\n";
	B.putd();
	cout<<"\nList 3:\n";
	C.putd();
	
}

