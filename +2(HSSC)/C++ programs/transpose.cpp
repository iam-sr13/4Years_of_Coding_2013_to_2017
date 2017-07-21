#include<iostream>
using namespace std;

class matrix
{
	int  **a,**t,m,n;		
	void scan2arr(int r,int c,int **x);
	void disp2arr(int r,int c,int **x);
	void get_data();
	//void dmalloc_matrix(int r,int c,int **x);			
	public:
		void put_data();
		
		matrix() {
			get_data();											
		}
		
		~matrix() {
			int i;
			for(i=0;i<m;i++) delete[] a[i];
			for(i=0;i<n;i++) delete[] t[i];
			delete[] a;
			delete[] t;	
		}	
};

/*void matrix::dmalloc_matrix(int r,int c,int **x)
{
	int i;
	x=new int* [r];
	for(i=0;i<r;i++) x[i]=new int[c];
}*/

void matrix::put_data()
{
	int i,j;
	for(i=0;i<m;i++) for(j=0;j<n;j++) *(t[j]+i)=*(a[i]+j);
	cout<<"\nThis is your "<<m<<" x "<<n<<" matrix :\n";
	disp2arr(m,n,a);
	cout<<"\nAnd this is its transpose:\n";
	disp2arr(n,m,t);
}

void matrix::get_data()
{	
	cout<<"\nPlease enter the no. of rows and columns required for your matrix: ";
	cin>>m>>n;
	int i;
	a=new int* [m];
	for(i=0;i<m;i++) a[i]=new int[n];
	
	t=new int* [n];
	for(i=0;i<n;i++) t[i]=new int[m];
	//dmalloc_matrix(m,n,a);
	//dmalloc_matrix(n,m,t);
	cout<<"\nPlease enter the elements of your matrix:\n";
	scan2arr(m,n,a);
}

void matrix::scan2arr(int r,int c,int **x)
{
	int i,j;
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			cin>>*(x[i]+j);
}
void matrix::disp2arr(int r,int c,int **x)
{	
	int i,j;
	cout<<endl;
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			cout<<" "<<*(x[i]+j);
		cout<<endl;
	}
}

main()
{
	matrix z;
	z.put_data();	
}
