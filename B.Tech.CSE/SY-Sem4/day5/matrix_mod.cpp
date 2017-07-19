#include<iostream>

using namespace std;

class matrix
{
	int  r,c;
	double **a;	
	void dmalloc_matrix();
	void nullify();
	void identity();	
			
	public:			
		matrix(int m=0, int n=0, int i=0) {
			a=0;
			r=m;
			c=n;
			if(r&&c) {
				dmalloc_matrix();
				if(i) identity();
				else nullify();
			}															
		}		
		~matrix() {
			int i;
			for(i=0;i<r;i++) delete[] a[i];			
			delete[] a;			
		}
		void setData(int m=0,int n=0) 
		{
			if(a) this->~matrix();
			matrix(m,n);
		}
		void getData()
		{
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					cin>>a[i][j];
		}
		void showData()
		{
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) cout<<a[i][j]<<" ";
				cout<<endl;
			}			
		}
		void matrixUpAdd(int n)
		{
			for(int i=0;i<r-1;i++)
				for(int j=i+1;j<c;j++) a[i][j]+=n;
		}
		matrix multiply(const matrix& m1)
		{
			int i,j,k;
			matrix C(r,m1.c);
			for(i=0;i<r;i++) 
				for(k=0;k<m1.c;k++)
					for(j=0;j<c;j++)
						C.a[i][k]+=a[i][j]*m1.a[j][k];			
			return C;
		}		
		matrix add(const matrix& m)
		{
			matrix z(r,c);
			for(int i=0;i<r;i++) 
				for(int j=0;j<c;j++) 
					z.a[i][j]=a[i][j]+m.a[i][j];
			return z;			
		}	
		//Operators...
		matrix operator=(const matrix& B)
		{
			r=B.r;
			c=B.c;
			dmalloc_matrix();	
			for(int i=0;i<r;i++) 
				for(int j=0;j<c;j++)
					this->a[i][j]=B.a[i][j];	
			return *this;		
		}
		matrix operator*(const matrix& m)
		{
			return multiply(m);			
		}
		matrix operator +(const matrix& m)
		{	
			return add(m);
		}
		double* operator[] (int i) const
		{
			return a[i];
		}
		bool operator == (const matrix& m)
		{
			for(int i=0;i<r;i++) 
				for(int j=0;j<c;j++)
					if(this->a[i][j] != m[i][j]) return false;
			return true;
		}						
};

void matrix::nullify()
{
	int i,j;
	for(i=0;i<r;i++) 
		for(j=0;j<c;j++)
			a[i][j]=0;
}
void matrix::identity()
{
	int i,j;
	for(i=0;i<r;i++) 
		for(j=0;j<c;j++)
			if(i!=j) a[i][j]=0;
			else a[i][j]=1;
}

void matrix::dmalloc_matrix()
{
	int i;
	a=new double*[r];
	for(i=0;i<r;i++) a[i]=new double[c];
}

int main()
{	
	matrix TP(2,2), R(2,2,1), R_1(2,2);
	cout<<"\nNow please enter matrix element:\n"; TP.getData();
	
	cout<<"\nYour initial matrix: \n"; TP.showData();
	cout<<"\nYour initial R matrix: \n"; R.showData();
	
	while(true) {
		//R_1=R;	
		TP=TP*TP;		
		cout<<"\nYour steady state matrix: \n"; TP.showData();
		//if(R_1==R) break;		
	}
	
	cout<<"\nYour steady state matrix: \n"; R.showData();	
	
	/*cout<<"Welcome to the Matrix Program!\n\n(Note:- Product matrix(M1 x M2) is defined only when columns(M1)=Rows(M2))\n\nPlease enter the no. of rows and columns for M1:\n";
	cin>>m>>n;
	cout<<"\nPlease enter the no. of rows and columns for M2:\n";
	cin>>o>>p;
		
	matrix M1(m,n),M2(o,p); 
	cout<<"\nNow please enter matrix element for M1:\n"; M1.getData();
	cout<<"\nNow please enter matrix element for M2:\n"; M2.getData();
	cout<<"\nYour matrices:-\n\nM1="<<endl; M1.showData();
	cout<<"\nM2="<<endl; M2.showData();	
    
    if(m!=o || n!=p) cout<<"\nSum M1+M2 is not defined!!";
    else {
		matrix S=M1+M2;
		cout<<"\nS = M1 + M2 ="<<endl; S.showData();
	}
	if(n!=o) cout<<"\nProduct M1*M2 is not defined!!";
	else {
		matrix P=M1*M2;
		cout<<"\nP = M1 * M2 ="<<endl; P.showData();
	}
	if(m!=n) cout<<"\nUpper triangular matrix is not defined for M1, only defined for sqaure matrix!!"<<endl;
	else {
		cout<<"\nNow enter any integer 'n' to be added to upper triangular of M1: "; cin>>n;
		M1.matrixUpAdd(n);
		cout<<"\nmatrixUpAdd(M1,n)="<<endl; M1.showData();
	}	*/
		
	return 0;	
}
