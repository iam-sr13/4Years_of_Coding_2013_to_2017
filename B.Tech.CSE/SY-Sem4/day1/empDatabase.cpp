/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.3 in psheet.jpg
*/
#include<iostream>
#include"Date.hpp"

using namespace std;

struct Employee
{
	int ecode;
	string name;
	Date doj;
};

bool compDate(Date cur, Date emp)
{
	if((cur.y()-emp.y())>3) return 1;
	else if((cur.y()-emp.y())==3) {
		if((cur.m()-emp.m())>0) return 1;
		else if((cur.m()-emp.m())==0) {
			if((cur.d()-emp.d())>=0) return 1;
		}
	}
	return 0;
}

int main()
{
	int n;
	Date curDate;
	cout<<"\nLets Play with Employee Database!!!"<<endl;
	cout<<"\nEnter the no. of employees: ";
	cin>>n;
	Employee emp[n];
	cout<<"\nNow enter employee data one by one....\n";
	for(int i=0;i<n;i++) {
		cout<<"\nFor employee "<<i+1<<" :- "<<endl;
		cout<<"\nEnter Employee code (numeric) : "; cin>>emp[i].ecode;
		cout<<"\nEnter Employee Name : "; cin>>emp[i].name;
		cout<<"\nFor Date of joining (dd/mm/yyyy) :-"; cin>>emp[i].doj;
	} 
	cout<<"\nThank you for entering details...\n\nNow for current date:- "; 
	cin>>curDate;
	cout<<"\nEmployees whose tenure is more than or equal to 3 years are as follows:-"<<endl;
	for(int i=0;i<n;i++) {
		if(compDate(curDate,emp[i].doj)) cout<<"\n=> "<<emp[i].name;
	} 
	return 0;
}
