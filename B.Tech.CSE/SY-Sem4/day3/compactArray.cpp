#include<iostream>
using namespace std;

template<class T>
void compactArr(T* a, int& size, int f, int l)
{
	int j=f;
	for(int i=l+1; i<size; i++,j++) {
		a[j]=a[i];		
	}
	size-=l-f+1;
}

template<class T>
void showArr(T* a, int size)
{
	for(int i=0; i<size; i++) {
		cout<<a[i];
		if(i<size-1) cout<<", ";
		else cout<<"."<<endl;
	}
}

int main()
{
	int f,l,size,err=0;
	
	cout<<"\nLets compact some arrays.....\n";	
	
	cout<<"\n#For INT type:-\nEnter size of array: ";
	cin>>size;
	int* i=new int[size];	
	cout<<"\nEnter int elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>i[j];
	do {
		err=0;
		cout<<"\nNow enter first & last index (starts@ '0') of subarray to be deleted: "; 
		cin>>f>>l;
		if(f<0 || f>=size || l<f || l>=size){ err=1; cout<<"\nINVALID INDEX!! Try again...."<<endl; }
	}while(err);
	cout<<"\nYour array: "; showArr(i,size);
	compactArr(i,size,f,l);
	cout<<"\nYour compacted array: "; showArr(i,size);	
	
	cout<<"\n#For CHAR type:-\nEnter size of array: ";
	cin>>size;
	char* c=new char[size];
	cout<<"\nEnter char elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>c[j];	
	do {
		err=0;
		cout<<"\nNow enter first & last index (starts@ '0') of subarray to be deleted: "; 
		cin>>f>>l;
		if(f<0 || f>=size || l<f || l>=size){ err=1; cout<<"\nINVALID INDEX!! Try again...."<<endl; }
	}while(err);
	cout<<"\nYour array: "; showArr(c,size);
	compactArr(c,size,f,l);
	cout<<"\nYour compacted array: "; showArr(c,size);
	
	cout<<"\n#For DOUBLE type:-\nEnter size of array: ";
	cin>>size;		
	double* d=new double[size];
	cout<<"\nEnter double elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>d[j];	
	do {
		err=0;
		cout<<"\nNow enter first & last index (starts@ '0') of subarray to be deleted: "; 
		cin>>f>>l;
		if(f<0 || f>=size || l<f || l>=size){ err=1; cout<<"\nINVALID INDEX!! Try again...."<<endl; }
	}while(err);
	cout<<"\nYour array: "; showArr(d,size);
	compactArr(d,size,f,l);
	cout<<"\nYour compacted array: "; showArr(d,size);
	
	
	return 0;
}
