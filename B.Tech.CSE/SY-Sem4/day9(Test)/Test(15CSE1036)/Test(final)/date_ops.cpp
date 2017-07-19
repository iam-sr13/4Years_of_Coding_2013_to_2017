/*
*Date: 15/03/2017  
*Name: Shriraj Sawant
*Roll No: 15CSE1036
*Description: Test q.1
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

class date
{
	friend ostream& operator<< (ostream& out,date& z);
	friend istream& operator>> (istream& in,date& z);
	unsigned int d,m,y;
	
	public:
	int mdays(int m, int y=1)
	{
		if(m==0||m==1||m==3||m==5||m==6||m==8||m==10||m==12) return 31;			
		else if(m!=2) return 30;
		else if(y%4==0) return 29;
		else return 28;
	}
		
	public:
		date(int a=1,int b=1,int c=1)
		{
			init(a,b,c);
		}
		date(string s)
		{
			init(s);
		}		
		
		void init(int a=1,int b=1,int c=1)
		{
			d=a;
			m=b;
			y=c;
		}
		void init(string s)
		{
			d=atoi(s.substr(0,2).c_str());
			m=atoi(s.substr(3,2).c_str());
			y=atoi(s.substr(6,4).c_str());
		}
		
		date operator +(int n)
		{
			int a=d,b=m,c=y;
			
			a+=n;
			if(a<=0){
				while(a<=0) { 
					a+=mdays(b-1,c); b--;
					if(b==0){ b+=12; c--;}
				}				
				return date(a,b,c);
			}
			else{
				while(a>mdays(b,c)) { 
					a-=mdays(b,c); b++;
					if(b>12){ b-=12; c++;}
				}				
				return date(a,b,c);
			}						
		}
		
		int operator -(date& z)
		{
			int chk=(*this>=z);
			if(chk){
				if(chk==3) return d-z.d;
				if(chk==2) {
					int nod=0;
					for(unsigned int i=z.m; i<=m; i++) nod+=mdays(i,z.y);					
					return nod-(z.d)-(mdays(m,d)-d);
				}
				else{
					int nod=0;
					for(unsigned int i=z.y+1;i<y;i++) nod+=365;
					for(unsigned int i=z.m; i<=12; i++) nod+=mdays(i,z.y);
					for(unsigned int i=1; i<=m; i++) nod+=mdays(i,y);
					return nod-(z.d)-(mdays(m,y)-d);
				}
			}
			else {
				//cout<<"\nOperator - Defined only for , d1>=d2 !!"<<endl;
				return -(z-(*this));
			}
		}
		
		int operator >=(date& z)
		{
			if(y>z.y) return 1;
			else if(y==z.y && m>z.m) return 2;
			else if(y==z.y && m==z.m && d>=z.d) return 3;
			else return 0;			
		}
		bool operator==(date& z){if(d==z.d && m==z.m && y==z.y) return true; else return false;}
	
};

ostream& operator<< (ostream& out,date& z)
{
	out<<setw(2)<<setfill('0')<<z.d<<"/"<<setw(2)<<setfill('0')<<z.m<<"/"<<z.y;
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
		if(e==4) cout<<"\nWrongData!! Days has to be <= "<<z.mdays(atoi(s.substr(3,2).c_str()),atoi(s.substr(6,4).c_str()))<<"!!\nPlease Enter again: ";

		in>>s;
		e=0;
		
		if(s[2]!='/' || s[5]!='/') e=1;
		else if(atoi(s.substr(0,2).c_str())<=0 || atoi(s.substr(3,2).c_str())<=0 || atoi(s.substr(6,4).c_str())<=0) e=2;
		else if(atoi(s.substr(3,2).c_str())>12) e=3;
		else if(atoi(s.substr(0,2).c_str()) > z.mdays(atoi(s.substr(3,2).c_str()), atoi(s.substr(6,4).c_str())))	e=4;		
	}while(e);	
	
	z.init(s);	
	return in;
}

int main()
{	
	int n;
	date d1,d2,d3;	
	
	cout<<"\nLets play with dates (Format: DD/MM/YYYY).... \nPlease enter any date in prescribed format: ";
	cin>>d1;	
	cout<<"\nNow enter another date: ";
	cin>>d2;
	cout<<"\nYour dates:\nD1= "<<d1<<"\nD2= "<<d2<<endl;
	int x= d1-d2;
	cout<<"\nNow for calculating d1-d2; The difference x=d1-d2 is such that if we add x to d2, we will get d1.\n(i.e d1=x+d2)\n....\n....\n";
	if(x>=0){
		cout<<"\nD1-D2 = "<<x;		
	}
	else{
		cout<<"\n'Operator -' is correctly used only for , d1>=d2 !!\n(Note:- Though negative days doesn't exist, the correct difference in this case is: "<<x<<" !!)"<<endl;
	}	
	cout<<"\nNow for adding n=no_of_days to D1 & D2,\nenter any integer n: "; cin>>n;
	d3=d1+n;
	cout<<"\nD1 + no_of_days = "<<d3<<endl;
	d3=d2+n;
	cout<<"\nD2 + no_of_days = "<<d3<<endl;		
	 
	return 0;
}
