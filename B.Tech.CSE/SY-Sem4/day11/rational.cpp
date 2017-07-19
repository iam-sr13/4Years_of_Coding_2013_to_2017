#include<iostream>

using namespace std;

class rational
{
	friend ostream& operator<< (ostream& out, rational& z);
	friend istream& operator>> (istream& in, rational& z);
	
	double numerator,denominator;
	
	void intify()
	{		
		for(;;){
			if( (numerator-(int)numerator)>0 || (denominator-(int)denominator)>0 )  {
				numerator*=10;
				denominator*=10;
			}
			else break;
		}
	}
	
	public:
	rational(double x=0,double y=1){numerator=x; denominator=y;}	
	void reduce()
	{
		intify();
		long long int n=numerator,d=denominator,m=min(n,d);
				
		for(int i=m; i>0; i--) {
			if(n%i==0 && d%i==0) {
				n/=i;
				d/=i;
				break;
			}
		}
		numerator=n;
		denominator=d;		
	}
	
	rational operator +(rational& z)
	{
		rational r(numerator*z.denominator + z.numerator*denominator, denominator*z.denominator);
		r.reduce();
		
		return r;
	}
};

ostream& operator<< (ostream& out, rational& z)
{
	out<<z.numerator<<" / "<<z.denominator;
	return out;
}
istream& operator>> (istream& in, rational& z)
{
	do{
		try{
			cout<<"\nEnter Numerator: "; in>>z.numerator;
			cout<<"Enter Denominator: "; in>>z.denominator;
			if(z.denominator==0) throw 0;
		}
		catch(int e){
			cout<<"\nInvalid Input!!\nDenominator can't be zero!!\nPlease try again...."<<endl;
			continue;
		}
		break;
	}while(true);
	return in;
}

int main()
{
	rational r1,r2,r3;
	
	cout<<"\nLets play with rationals....\n\nSay there are 2 rational numbers, r1 and r2.\nNow for r1:-";
	cin>>r1;
	cout<<"\nSimillarly for r2:-";
	cin>>r2;
	
	cout<<"\nYour rationals:-\nr1 = "<<r1<<"\nr2 = "<<r2;
	r1.reduce();
	r2.reduce();
	cout<<"\nYour reduced rationals:-\nr1 = "<<r1<<"\nr2 = "<<r2;
	r3=r1+r2;
	cout<<"\nNow r3 = r1 + r2 = "<<r3;
	
	return 0;
}
