/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.1 in psheet.jpg
*/
#include<iostream>
#include<cstdlib>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out,Date& d);
	friend istream& operator>>(istream& in,Date& d);
	
	int day,month,year;
	public:
		Date(){
			day=1;
			month=1;
			year=2017;
		}
		int getData(int,int,int);
		void getData(string);
		void showData();
		bool operator==(const Date&);
};

void Date::getData(string s)
{
	int d,m,y;
	d=atoi(s.substr(0,2).c_str());
	m=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
	y=atoi(s.substr(6,4).c_str());		
	getData(d,m,y);			
}
int Date::getData(int d, int m, int y)
{
	if(d>31||d<=0 || m>12||m<=0 || y<=0) return 1;
	if((m==4||m==6||m==9||m==11) && d>30) return 2;
	if(m==2 && d>28 && y%4!=0) return 2;
	if(m==2 && d>29 && y%4==0) return 3;
	
	day=d;
	month=m;
	year=y;
	return 0;
}
void Date::showData()
{
	if(day<=9) cout<<"0";
	cout<<day<<"/";
	if(month<=9) cout<<"0";
	cout<<month<<"/"<<year;
}
bool Date::operator==(const Date& d)
{
	if(this->day==d.day && this->month==d.month && this->year==d.year) return true;
	else return false;
}

ostream& operator<<(ostream& out,Date& d)
{
	d.showData();
	return out;
}
istream& operator>>(istream& in,Date& dat)
{
	int d,m,y,err=1;
	string s;
	do {
		cout<<"\n\nEnter Date : ";
		cin>>s;
		if(s[2]!='/' || s[5]!='/') {cout<<"\nINCORRECT FORMAT!! Please try again!";continue;}
		
		d=atoi(s.substr(0,2).c_str());    //extract substring from '0' position of length '2' then convert its content to an integer as it is  
		m=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
		y=atoi(s.substr(6,4).c_str());
		
		err=dat.getData(d,m,y);
		if(err==1) cout<<"\nINCORRECT Day or Month or Year!! Please try again!";	
		if(err==2) cout<<"\nINCORRECT Day!! Please try again!";
		if(err==3) cout<<"\nINCORRECT Data!! Please try again!";	
	}while(err);
	return in;
}

int main()
{	
	Date d1,d2;
	
	cout<<"\nLet's Compare some dates!!!\n\n(NOTE: Format should be dd/mm/yyyy) ";
	cin>>d1;
	cout<<"\nNow again...";
	cin>>d2;	
	
	if(d1==d2) cout<<"\nBoth are EQUAL!!"<<endl;
	else cout<<"\nBoth are UNEQUAL!!"<<endl;
	
	return 0;
}

/*
 * do {
		cout<<"\n\nEnter Date 1: ";
		cin>>s;
		if(s[2]!='/' || s[5]!='/') {cout<<"\nINCORRECT FORMAT!! Please try again!";continue;}
		
		d=atoi(s.substr(0,2).c_str());    //extract substring from '0' position of length '2' then convert its content to an integer as it is  
		m=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
		y=atoi(s.substr(6,4).c_str());
		
		err=d1.getData(d,m,y);
		if(err) cout<<"\nINCORRECT DATA!! Please try again!";	
	}while(err);
	
	do {
		cout<<"\n\nNow Enter Date 2: ";
		cin>>s;
		if(s[2]!='/' || s[5]!='/') {cout<<"\nINCORRECT FORMAT!! Please try again!";continue;}
		
		d=atoi(s.substr(0,2).c_str());
		m=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
		y=atoi(s.substr(6,4).c_str());
		
		err=d2.getData(d,m,y);
		if(err) cout<<"\nINCORRECT DATA!! Please try again!";	
	}while(err);
 * */
