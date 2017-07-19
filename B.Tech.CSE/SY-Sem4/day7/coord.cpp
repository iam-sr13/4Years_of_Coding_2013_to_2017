#include<iostream>
#include<cmath>

using namespace std;

class polar;

class rectangle
{
	friend polar conv(rectangle R);
	
	double x,y;
	
	public:
	rectangle(double X=0,double Y=0) {x=X; y=Y;}
	double mag() { return sqrt(x*x+y*y);}
	double angle() { return atan2(y,x);}
	void show() {cout<<"(X,Y) = ("<<x<<","<<y<<")";}
	
	rectangle operator+(rectangle R)
	{
		rectangle z;
		z.x=x+R.x;
		z.y=y+R.y;
		
		return z;
	}
	bool operator<(rectangle R)
	{
		if(mag()<R.mag()) return true;
		else return false;
	}
};

class polar
{
	friend rectangle conv(polar P);
	
	double r,t;
	
	public:
	polar(double R=0,double T=0) {r=R; t=T;}
	double distX() {return r*cos(t);}
	double distY() {return r*sin(t);}
	void show() {cout<<"(R,@) = ("<<r<<","<<t<<")";}
	
	polar operator+(polar P)
	{
		rectangle z(distX() + P.distX(), distY() + P.distY());			
		return conv(z);
	}
	bool operator<(polar P)
	{
		if(r<P.r) return true;
		else return false;
	}
};

rectangle conv(polar P)
{
	rectangle R(P.distX(),P.distY());
	return R;
}
polar conv(rectangle R)
{
	polar P(R.mag(),R.angle());	
	return P;
}

ostream& operator <<(ostream& out, rectangle d)
{
	d.show();
	return out;
}
ostream& operator <<(ostream& out, polar d)
{
	d.show();
	return out;
}

int main()
{
	double a,b;
	cout<<"\nLets play with coordinates...!!"<<endl;
	cout<<"\nEnter rectangular coord R1(x,y)= "; cin>>a>>b;
	rectangle R1(a,b);
	cout<<"\nEnter rectangular coord R2(x,y)= "; cin>>a>>b;
	rectangle R2(a,b);
	cout<<"\nEnter polar coord P1(R,@)= "; cin>>a>>b;
	polar P1(a,b);
	cout<<"\nEnter polar coord P2(R,@)= "; cin>>a>>b;
	polar P2(a,b);
	
	cout<<"\nYour Coordinates:"<<endl;
	cout<<"\nR1 = "<<R1<<" = "<<conv(R1);
	cout<<"\nR2 = "<<R2<<" = "<<conv(R2);
	cout<<"\nP1 = "<<P1<<" = "<<conv(P1);
	cout<<"\nP2 = "<<P2<<" = "<<conv(P2)<<endl;
	
	cout<<"\nHere, ";
	if(R1<R2) cout<<"\nR1 < R2"<<endl;
	else cout<<"\nR1 >= R2"<<endl;
	
	if(P1<P2) cout<<"\nP1 < P2"<<endl;
	else cout<<"\nP1 >= P2"<<endl;	
	
	cout<<"\nR3 = R1 + R2 = "<<R1+R2<<endl;
	cout<<"\nP3 = P1 + P2 = "<<P1+P2<<endl;	
	
	return 0;
}
