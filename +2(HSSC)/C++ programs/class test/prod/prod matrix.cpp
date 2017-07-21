#include<iostream>
#define null 0
using namespace std;

class matrix
{
	int  **a,r,c;	
	void dmalloc_matrix();
	void nullify();			
	public:
		void scan();	
		void disp();
		matrix(){}		
		matrix(int m,int n, int x=1) {
			int i,j;
			r=m;
			c=n;
			dmalloc_matrix();
			nullify();
			if(x) {
				cout<<"\nPlease enter the elements of your matrix:\n";
			for(i=0;i<r;i++) 
				for(j=0;j<c;j++)
					cin>>*(*(a+i)+j);
			}													
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
			this->r=B.r;
			this->c=B.c;
			dmalloc_matrix();
			for(i=0;i<this->r;i++) 
				for(j=0;j<this->c;j++)
					this->a[i][j]=B.a[i][j];
		}
		matrix operator*(const matrix &B)
		{
			int i,j,k;
			matrix C(this->r,B.c,null);
			for(i=0;i<(this->r);i++) 
				for(k=0;k<(B.c);k++)
					for(j=0;j<(this->c);j++)
						C.a[i][k]+=this->a[i][j]*B.a[j][k];
			return C;			
		}					
};

void matrix::nullify()
{
	int i,j;
	for(i=0;i<r;i++) 
		for(j=0;j<c;j++)
			a[i][j]=0;
}

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
	for(i=0;i<r;i++) 
		for(j=0;j<c;j++)
			cin>>*(*(a+i)+j);
}

void matrix::disp()
{	
	int i,j;
	cout<<endl;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++)
			cout<<" "<<*(*(a+i)+j);
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int m,n,p;
	cout<<"Welcome to the Product Matrix Program!\n\n(Note:- Product matrix(M1 x M2) is defined only when columns(M1)=Rows(M2))\n\nPlease enter the no. of rows and columns for M1: ";
	cin>>m>>n;
	cout<<"\n\nPlease enter the no. of rows and columns for M2: ";
	cin>>n>>p;
	cout<<"\n\nFor M1:-\n";
	matrix M1(m,n);
	cout<<"\n\nFor M2:-\n";
	matrix M2(n,p),P(m,p,null);
	P=M1*M2;
	cout<<"\n\nM1=";
	M1.disp();
	cout<<"\n\nM2=";
	M2.disp();
	cout<<"\n\nM1*M2=P=";
	P.disp();	
	return 0;	
}
