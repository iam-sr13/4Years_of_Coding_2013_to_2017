#include<iostream>
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

int main()
{
	int size;	
	
	cout<<"\nLets play with Templates and Array Sorting....\n\nEnter size of your array: ";
	cin>>size;
	int* i=new int[size];	
	
	cout<<"\nNow enter elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>i[j];
	
	cout<<"\nYour array: "; showArr(i,size);
	sortArr(i,size);
	cout<<"\nYour sorted array: "; showArr(i,size);
	
	return 0;
}

/*
 * do{
		err=0;
		cout<<"\nEnter type of your array(int=1, char=2, double=3) : "; cin>>ch;
		switch(ch) {
			case 1: {
				i=new int[size];
				break;
			}
			case 2: {
				i=new char[size];
				break;
			}
			case 3: {
				i=new double[size];
				break;
			}
			default:
			cout<<"\nInvalid Entry!!!\n"; err=1;		
		}
	}while(err);	
 * */
