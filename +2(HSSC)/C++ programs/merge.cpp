#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

class list
{
	int *A,*B,*C,m,n;
	void swap(int *x,int *y)
	{
		int t;
		t=*x;
		*x=*y;
		*y=t;
	}
	void merge();
	//void sort(int* a,int m);
	void getd();
	void putd();
	public:
		list() {
			getd();
			//sort(A,m); sort(B,n);
			sort(A,A+m);
			sort(B,B+n);
			merge();
			putd();			
		}
		~list() {
			delete[] A;
			delete[] B;
			delete[] C;
		}
};

void list::merge()
{
	int i,j,k;
	for(i=0,j=0,k=0;i<m && j<n;) 
		if(A[i]<B[j]) C[k++]=A[i++];
			else C[k++]=B[j++];
	if(i==m) for(;j<n;) C[k++]=B[j++];
	if(j==n) for(;i<m;) C[k++]=A[i++];
}

/*void list::sort(int* a,int x)
{
	int i,j;
	for(i=1;i<x;i++) for(j=0;j<=x-i-1;j++) if(*(a+j)>*(a+j+1)) swap((a+j),(a+j+1));	
}*/

void list::getd()
{
	int i;
	cout<<"\nPlease Enter the following details for merging the two lists: \n";
	cout<<"\nEnter the size of your list 1: ";
	cin>>m;
	A=new int[m];
	cout<<endl;
	for(i=0;i<m;i++) {cout<<"\nEnter the "<<i+1<<" th element of list 1: "; cin>>A[i];}
	cout<<"\n\n\nEnter the size of your list 2: ";
	cin>>n;	
	B=new int[n];
	cout<<endl;
	for(i=0;i<n;i++) {cout<<"\nEnter the "<<i+1<<" th element of list 1: "; cin>>B[i];}
	C=new int[m+n];		
}

void list::putd()
{
	int i;
	cout<<"\n\nYour two lists are:-\n";
	cout<<"\nList 1: ";
	for(i=0;i<m;i++) {cout<<A[i];if(i<m-1) cout<<", "; else cout<<".";}
	cout<<"\nList 2: ";
	for(i=0;i<n;i++) {cout<<B[i];if(i<n-1) cout<<", "; else cout<<".";}
	cout<<"\n\nAnd the merged list i.e \nList 1 + List 2: ";
	for(i=0;i<(m+n);i++) {cout<<C[i];if(i<(m+n)-1) cout<<", "; else cout<<".";}	
}

main()
{
	list ilist;
}

