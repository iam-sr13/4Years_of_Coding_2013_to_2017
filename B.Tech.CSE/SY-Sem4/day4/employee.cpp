#include<iostream>

using namespace std;

class EMPLOYEE
{
	int number;
	string name;
	float basic, DA, IT, netSalary;
	
	public:
		EMPLOYEE() {
			number=0;
			name="";
			basic=DA=IT=netSalary=0;
		}
		void getData()
		{
			cout<<"\nEnter Employee Number: "; cin>>number; cin.ignore();
			cout<<"\nEnter Name: "; getline(cin, name);
			do{
				cout<<"\nEnter your Basic Salary: "; cin>>basic;
			}while(basic<0);
			DA=basic*0.52;			
			IT=(basic+DA)*0.3;
			netSalary=basic+DA-IT;
		}
		void showData()
		{
			cout<<"\nEmployee Details:- "<<endl;
			cout<<"\nName: "<<name<<"\nEmployee Number: "<<number<<"\nBasic: "<<basic<<"\nDA: "<<DA<<"\nIT: "<<IT<<"\nNet Salary: "<<netSalary<<endl;
		}
};

int main()
{
	int n;
	
	cout<<"\nLets handle some employee database....."<<endl;
	cout<<"\nEnter no. of Employees: "; cin>>n;
	EMPLOYEE edata[n];
	
	for(int i=0; i<n; i++) {
		cout<<"\nFor Employee "<<i+1<<" :-\n";
		edata[i].getData();
	}
	
	cout<<"\nThe Employee Database is as follows:- "<<endl;
	for(int i=0; i<n; i++) {		
		edata[i].showData();
		cout<<endl;
	}
	
	return 0;
}
