/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.1 in psheet.jpg
*/
#include<iostream>
#include<cstdlib>
using namespace std;

struct Date
{
	int day,month,year;	
};

bool compare(const Date& d1,const Date& d2)
{
	if(d1.day==d2.day && d1.month==d2.month && d1.year==d2.year) return true;
	else return false;
}

int main()
{
	string s;
	Date d1,d2;
	
	cout<<"\nLet's Compare some dates!!!\n\n(NOTE: Format should be dd/mm/yyyy) ";
	
	cout<<"\n\nEnter Date 1: ";
	cin>>s;		
	d1.day=atoi(s.substr(0,2).c_str());
	d1.month=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
	d1.year=atoi(s.substr(6,4).c_str());	
	cout<<"\nNow Enter Date 2: ";
	cin>>s;			
	d2.day=atoi(s.substr(0,2).c_str());
	d2.month=atoi(s.substr(3,2).c_str());    //start at pos '3' of string and extract substring of length '2'
	d2.year=atoi(s.substr(6,4).c_str());	
	
	if(compare(d1,d2)) cout<<"\nBoth are EQUAL!!"<<endl;
	else cout<<"\nBoth are UNEQUAL!!"<<endl;
	
	return 0;
}
