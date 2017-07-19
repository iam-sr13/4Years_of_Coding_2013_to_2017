#include<iostream>
#include<cstdlib>
using namespace std;

class point
{
	friend ostream& operator<< (ostream& out, point& z);
	friend istream& operator>> (istream& in, point& z);
	
	int x,y;
	
	public:
	point(int a=0,int b=0){x=a; y=b;}
	point(string p)
	{
		int q=p.find(",");
		x=atoi(p.substr(0,q).c_str());
		q++;
		while(p[q]==' ') q++;
		y=atoi(p.substr(q,p.size()).c_str());
		
	}
	
	point operator +(point& z)
	{
		return point(x+z.x,y+z.y);
	}	
};

ostream& operator<< (ostream& out, point& z)
{
	out<<z.x<<", "<<z.y;
	return out;
}
istream& operator>> (istream& in, point& z)
{
	string s;
	cout<<"Enter coordinate in (x, y) form: ";
	getline(cin,s);
	z=point(s);
	return in;
}

int main()
{
	point p1,p2,p3;
	
	cout<<"\nLets play with 2D coordinates....\nSay there are two points p1 and p2.\nNow for p1, ";
	cin>>p1;
	cout<<"\nSimillarly for p2, ";
	cin>>p2;
	
	cout<<"\nYour points:-\np1 = "<<p1<<"\np2 = "<<p2<<endl;
	p3=p1+p2;
	cout<<"\nCoordinates of p1 + p2 = p3 = "<<p3;
	return 0;
}
