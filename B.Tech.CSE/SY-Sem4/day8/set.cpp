#include<iostream>

using namespace std;

class SET
{
	friend istream& operator>>(istream& in, SET& s);
	friend ostream& operator<<(ostream& out, SET& s);
	
	int* a,n;	
	int size;
	
	public:
	
	SET(unsigned int x=0) {
		size=0;
		n=x;
		a=new int[n];		
		for(int i=0;i<n;i++) a[i]=0;
	}
	SET(const SET& z) {			
		size=z.size;
		n=z.size;		
		a=new int[n];		
		for(int i=0;i<n;i++) a[i]=z.a[i];
	}
	~SET(){
		delete[] a;
		a=0;
		n=0;
		size=0;
	}
	void renew(int x=1) 
	{
		delete[] a;
		size=0;
		n=x;		
		a=new int[n];
		for(int i=0;i<n;i++) a[i]=0;
	}
	
	int len(){return size;}
	void getData()
	{
		int x;
		for(int i=0;i<n;i++) {
			cin>>x;
			if(push(x)) {
				cout<<"\nDuplicate Value!!\nPlease enter fresh value!!\n";
				i--;				
			}
		}
	}
	void showData()
	{
		cout<<"{";
		for(int i=0;i<size;i++) {
			cout<<a[i];
			if(i<size-1) cout<<", ";
		}
		cout<<"}";
	}
	int push(int x)
	{		
		for(int i=0;i<size;i++) if(a[i]==x) {return 1;}
		a[size++]=x;
		return 0;
	}
	
	SET operator =(const SET& z)
	{		
		renew(z.size);
		size=z.size;
		for(int i=0;i<size;i++) a[i]=z.a[i];
						
		return *this;
	}
	SET operator +(const SET& s2)
	{
		SET s3(n+s2.n);
		
		for(int i=0;i<size;i++) s3.push(a[i]);
		for(int i=0;i<s2.size;i++) s3.push(s2.a[i]);
		
		SET s4=s3;		
		return s4;
	}	
	
	SET operator *(const SET& s2)
	{		
		SET s3(n);
			
		for(int i=0;i<size;i++)
			for(int j=0;j<s2.size;j++) 
				if(s2.a[j]==a[i]) {
					s3.push(a[i]);
					break;
				}
		
		SET s4=s3;			
		return s4;
	}
};

istream& operator>>(istream& in, SET& s)
{
	s.getData();
	return in;
}
ostream& operator<<(ostream& out, SET& s)
{
	s.showData();
	return out;
}

int main()
{
	int m,n;
	cout<<"\nLets play with sets...\n\nEnter size for two sets s1 and s2: "; cin>>m>>n;
	SET s1(m),s2(n),s3,s4;
	cout<<"\nEnter s1 elements:-\n"; cin>>s1;
	cout<<"\nEnter s2 elements:-\n"; cin>>s2;
	
	s3=s1+s2;
	s4=s1*s2;
	
	cout<<"\nYour Sets:-\ns1 = "<<s1<<"\ns2 = "<<s2<<endl;
	cout<<"\nNow s1 U s2 = s1 + s2 = "<<s3<<endl;
	cout<<"\nSimilarly s1 ^ s2 = s1 * s2 = "<<s4<<endl;	
	 
	return 0;
}
