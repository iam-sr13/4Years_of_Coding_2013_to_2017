#include<iostream>
#include<cstdlib>
using namespace std;

class date
{
	friend ostream& operator<< (ostream& out,date& z);
	friend istream& operator>> (istream& in,date& z);
	unsigned int d,m,y;
	
	int mdays(int m)
	{
		if(m==1||m==3||m==5||m==6||m==8||m==10||m==12) return 31;			
		else if(m!=2) return 30;
		else return 28;
	}
		
	public:
		date(int a=1,int b=1,int c=1)
		{
			d=a;
			m=b;
			y=c;
		}
		date(string s)
		{
			d=atoi(s.substr(0,2).c_str());
			m=atoi(s.substr(3,2).c_str());
			y=atoi(s.substr(6,4).c_str());
		}		
		
		void init(string s)
		{
			d=atoi(s.substr(0,2).c_str());
			m=atoi(s.substr(3,2).c_str());
			y=atoi(s.substr(6,4).c_str());
		}
		
		date operator +(unsigned int n)
		{
			int a=d,b=m,c=y;
			
			a+=n;
			if(a>31 && (m==1||m==3||m==5||m==6||m==8||m==10||m==12)){
				while(a>31){ a-=31; b++;}
			}
			else if(a>30 && m!=2){
				while(a>30){ a-=30; b++;}
			}
			else if(a>28) {
				while(a>28){ a-=28; b++;}
			}			
			if(m>12) {
				while(b>12){ b-=12; c++;}
			}
			
			return date(a,b,c);			
		}
		
		int operator -(date& z)
		{
			int chk=(*this>=z);
			if(chk){
				if(chk==3) return d-z.d;
				if(chk==2) {
					int nod=0;
					for(unsigned int i=z.m; i<=m; i++) nod+=mdays(i);					
					return nod-(z.d)-(mdays(m)-d);
				}
				else{
					int nod=0;
					for(unsigned int i=z.y+1;i<y;i++) nod+=365;
					for(unsigned int i=z.m; i<=12; i++) nod+=mdays(i);
					for(unsigned int i=1; i<=m; i++) nod+=mdays(i);
					return nod-(z.d)-(mdays(m)-d);
				}
			}
			else {
				cout<<"\nOperator - Defined only for , d1>=d2 !!"<<endl;
				return -1;
			}
		}
		
		int operator >=(date& z)
		{
			if(y>z.y) return 1;
			else if(y==z.y && m>z.m) return 2;
			else if(m==z.m && d>=z.d) return 3;
			else return 0;			
		}
	
};

ostream& operator<< (ostream& out,date& z)
{
	out<<z.d<<"/"<<z.m<<"/"<<z.y;
	return out;
}
istream& operator>> (istream& in,date& z)
{
	string s;
	int e=0;
	
	do{
		if(e==1) cout<<"\nWrongFormat!! Please enter date in exact given format (e.g 05/09/2009 ) : ";
		if(e==2) cout<<"\nWrongData!! Zero or Negative values not allowed.. \nPlease Enter again: ";
		if(e==3) cout<<"\nWrongData!! Month has to be <= 12!!\nPlease Enter again: ";
		if(e==4) cout<<"\nWrongData!! Days has to be <= "<<z.mdays(atoi(s.substr(3,2).c_str()))<<"!!\nPlease Enter again: ";
		in>>s;
		
		if(s.substr(2,1)!="/"||s.substr(5,1)!="/") e=1;
		else if(atoi(s.substr(0,2).c_str())<=0||atoi(s.substr(3,2).c_str())<=0||atoi(s.substr(6,4).c_str())<=0) e=2;
		else if(atoi(s.substr(3,2).c_str())>12) e=3;
		else if(atoi(s.substr(0,2).c_str())>z.mdays(atoi(s.substr(3,2).c_str())))	e=4;	
		else e=0;
	}while(e);	
	
	z.init(s);	
	return in;
}

int main()
{	
	unsigned int n;
	date d1,d2,d3;
	cout<<"\nLets play with dates (Format: DD/MM/YYYY).... \nPlease enter any date in prescribed format: ";
	cin>>d1;	
	cout<<"\nNow enter another date: ";
	cin>>d2;
	cout<<"\nYour dates:\nD1= "<<d1<<"\nD2= "<<d2<<endl;
	cout<<"\nEnter any positive integer: "; cin>>n;
	d3=d1+n;
	cout<<"\nD1 + no_of_days = "<<d3<<endl;
	int x= d1-d2;
	if(x>=0){
		cout<<"\nD1-D2 = "<<x;		
	}	
	 
	return 0;
}
