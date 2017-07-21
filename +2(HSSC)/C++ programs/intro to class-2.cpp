#include<iostream>
#include<iomanip>

using namespace std;

class time
{
	int hr,min;
	void add(time a,time b)
	{
		hr=a.hr+b.hr;		
		min=a.min+b.min;
		if (min>59) {
			min-=60;
			hr++;
			if(hr>12)hr-=12;			
		}
	}
	public:
	time(int p=0,int q=0)
	{
		hr=p;
		min=q;
	}
	void putdata(time a,time b)
	{
		add(a,b);
		cout<<"Sum of two times are:\n\n   "<<a.hr<<":"<<a.min<<"\n + "<<b.hr<<":"<<b.min<<"\n  ______\n   "<<hr<<":"<<min<<"\n  ______";
	}	
};

int main()
{
	int x,y;
	cout<<"Welcome to Time addition (12 hr format)!!!!"<<endl<<"\nPlease enter hour and minute part of time 1 seperately:\n\n";
	cin>>x>>y;
	time a(x,y);
	cout<<"\nPlease enter hour and minute part of time 2 seperately:\n\n";
	cin>>x>>y;
	time b(x,y),c;
	c.putdata(a,b);
	return 0;
}


