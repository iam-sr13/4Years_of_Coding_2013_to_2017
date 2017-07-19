#include<iostream>
#include<cmath>

using namespace std;

class Octal
{
	friend ostream& operator<<(ostream& out, Octal& z);
	
	int o;
	
	int dtoct(int o) const;
	int octod(int o) const;
	
	public:
		Octal(int n=0){			
				o=dtoct(n);			
		}
		Octal(const Octal& z) {
			o=z.o;
		}
		
		int integer() const {return octod(o);}
		
		Octal operator+ (const Octal& z) const
		{			 
			return Octal(octod(o)+z.integer());
		}
		int operator+ (int x) const
		{
			return octod(o)+x; //returns the integer value after adding an octal and int.
		}
		int operator=(const Octal& z)
		{
			o=z.o;
			return z.integer();
		}
		int operator=(int x)
		{
			o=dtoct(x);	
			return x;
		}
};

ostream& operator<<(ostream& out, Octal& z)
{
	cout<<"O"<<z.o;
	return out;
}

int Octal::dtoct(int o) const
{
	if(o>=0) {
		int d=0,n=0;
		for(int i=1;o>0 ;o/=8,i*=10) {
			d=o%8;
			n+=d*i;
		}
		return n;
	}
	else{
		o=-o;
		int d=0,n=0;
		for(int i=1;o>0 ;o/=8,i*=10) {
			d=o%8;
			n+=d*i;
		}
		return -n;
	}	
}

int Octal::octod(int o) const
{
	if(o>=0) {
		int d=0,n=0;
		for(int i=0;o>0;o/=10,i++) {
			d=o%10;
			n+=d*pow(8,i);
		}
		return n;
	}
	else{
		o=-o;
		int d=0,n=0;
		for(int i=0;o>0;o/=10,i++) {
			d=o%10;
			n+=d*pow(8,i);
		}
		return -n;
	}	
}

int main()
{
	int n,k;
	
	cout<<"\nHi lets play with octal numbers!!\nPlease enter any integer: ";
	cin>>n;
	Octal h(n);
	
	cout<<"\nYour number in Octal h = "<<h<<" which is "<<h.integer()<<" in integer."<<endl;
	cout<<"\nNow enter another integer k = ";
	cin>>k;
	cout<<"\nTherefore y = h + k = "<<h+k;
	
	return 0;
}
