#include<iostream>
using namespace std;

class matrix
{
	int  **a,r,c;	
	void dmalloc_matrix();
	//void nullify();			
	public:
		void scan();	
		void disp();
		matrix()
		{
			//nullify();
		}		
		matrix(int m,int n) {
			int i,j;
			r=m;
			c=n;
			dmalloc_matrix();
			cout<<"\nPlease enter the elements of your matrix:\n";
			for(i=0;i<=r-1;i++) 
				for(j=0;j<=c-1;j++)
					cin>>*(*(a+i)+j);										
		}		
		~matrix() {
			int i;
			for(i=0;i<r;i++) delete[] a[i];			
			delete[] a;			
		}
		//Operators...
		void operator=(const matrix &B)
		{
			int i,j;
			r=B.r;
			c=B.c;
			dmalloc_matrix();
			for(i=0;i<=r-1;i++) 
				for(j=0;j<=c-1;j++)
					a[i][j]=B.a[i][j];
		}
		/*matrix operator*(const matrix &B)
		{
			for(i=0;i<=r-1;i++) 
				for(j=0;j<=c-1;j++)
		}
		*/			
};

void matrix::dmalloc_matrix()
{
	int i;
	a=new int*[r];
	for(i=0;i<r;i++) a[i]=new int[c];
}

void matrix::scan()
{	
	int i,j;
	cout<<"\nPlease enter the no. of rows and columns required for your matrix: ";
	cin>>r>>c;
	dmalloc_matrix();	
	cout<<"\nPlease enter the elements of your matrix:\n";
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			cin>>*(*(a+i)+j);
}

void matrix::disp()
{	
	int i,j;
	cout<<endl;
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			cout<<" "<<*(*(a+i)+j);
		cout<<endl;
	}
	cout<<endl;
}

main()
{
	matrix a,z;
	a.scan();
	z=a;
	a.disp();
	z.disp();
		
}
