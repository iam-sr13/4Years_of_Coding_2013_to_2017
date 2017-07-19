#include<iostream>

using namespace std;

class MATRIX
{
	friend MATRIX multiply(MATRIX& m1, MATRIX& m2);
	friend void matrixAdd(MATRIX& m1, int n);
	
	int** a,n;
	
	public:
	MATRIX(int dim=0) {		
		n=dim;
		a=0;
		if(n>0) 
		{
			a=new int*[n];
			for(int i=0;i<n;i++) a[i]=new int[n];
			
			nullify();
		}
	}
	~MATRIX() {
		for(int i=0;i<n;i++) delete[] a[i];
		delete[] a;
	}
	
	void init(int dim=0) 
	{
		if(a) this->~MATRIX();
		n=dim;
		a=0;
		if(n>0) 
		{
			a=new int*[n];
			for(int i=0;i<n;i++) a[i]=new int[n];
			
			nullify();
		}
	}
	void getData()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
	}
	void showData()
	{
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	void nullify()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
	}	
	void operator= (MATRIX m)
	{		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				this->a[i][j] = m.a[i][j];
	}
	MATRIX operator* (MATRIX& m)
	{
		return multiply(*this,m);
	}	
	/*MATRIX operator+ (int n)
	{
		matrixAdd(*this,n);
		return *this;
	}	*/
};

MATRIX multiply(MATRIX& m1, MATRIX& m2)
{
	MATRIX c(m1.n);
	for(int i=0;i<m1.n;i++)
		for(int j=0;j<m2.n;j++)
			for(int k=0;k<c.n;k++)
				c.a[i][k]+=m1.a[i][j]*m2.a[j][k];
	
	return c;
}
void matrixAdd(MATRIX& m1, int n)
{
	for(int i=0;i<m1.n-1;i++)
		for(int j=i+1;j<m1.n;j++) m1.a[i][j]+=n;
}

int main()
{
	int n;
	
	do{
	cout<<"\nLets play with matrices...\n\nEnter the dimension(+ve only): "; cin>>n;
	}while(n<0);
	
	MATRIX m1(n),m2(n),m3(n);
	
	cout<<"\nNow please enter matrix element for M1:\n"; m1.getData();
	cout<<"\nNow please enter matrix element for M2:\n"; m2.getData();
	cout<<"\nYour matrices:-\n\nM1="<<endl; m1.showData();
	cout<<"\nM2="<<endl; m2.showData();	
	m3=m1*m2;	
	cout<<"\nM3 = M1 * M2 ="<<endl; m3.showData();
	cout<<"\nNow enter any integer 'n' to be added to upper triangular of M1: "; cin>>n;
	matrixAdd(m1,n);
	cout<<"\nmatrixAdd(m1,n)="<<endl; m1.showData();		
	
	return 0;
}
