#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
void sortArr(T* a, int size)
{
	T temp;
	for(int i=0; i<size; i++) {
		for(int j=0; j<size-i-1; j++) {
			if(a[j]>a[j+1]) {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
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

int comp(const void* k, const void* i) {
	if(*(int*)k<*(int*)i) return -1;
	else if(*(int*)k==*(int*)i) return 0;
	else return 1;
}

int main()
{
	int size,key;	
	int* s;
	cout<<"\nLets play with bsearch function....\n\nEnter size of your array: ";
	cin>>size;
	int* a=new int[size];	
	
	cout<<"\nNow enter elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>a[j];
	
	cout<<"\nYour array: "; showArr(a,size);
	sortArr(a,size);
	cout<<"\nYour sorted array: "; showArr(a,size);
	
	cout<<"\nNow enter key to search: "; cin>>key;
	s=(int*) bsearch(&key,a,size,sizeof(int),comp);
	if(s==0) cout<<"\nNOT FOUND!!!";
	else cout<<"\nFOUND!!";	
	
	return 0;
}
