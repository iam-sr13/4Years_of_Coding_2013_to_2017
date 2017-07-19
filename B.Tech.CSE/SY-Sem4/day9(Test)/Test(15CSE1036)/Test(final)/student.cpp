/*
*Date: 15/03/2017  
*Name: Shriraj Sawant
*Roll No: 15CSE1036
*Description: Test q.2
*/
#include<iostream>

using namespace std;

class student
{
	string rollNo, name;
	float marks[3];
	
	public:
		student(string r="",string n="",float a=0,float b=0, float c=0) {
			rollNo=r;
			name=n;
			marks[0]=a;
			marks[1]=b;
			marks[2]=c;
		}
		student(const student& z) {
			rollNo=z.rollNo;
			name=z.name;
			for(int i=0;i<3;i++) marks[i]=z.marks[i];
		}
		
		void getData()
		{
			cout<<"\nEnter RollNo: "; cin>>rollNo; cin.ignore();
			cout<<"\nEnter Name: "; getline(cin,name);
			cout<<"\nNow enter marks for 3 tests (M.O.=Marks Obtained, M.M.=Max Marks): \n";
			for(int i=0;i<3;i++) {
				float max;
				do{
					cout<<"\nTest "<<i+1<<" M.M: "; cin>>max;
					if(max<=0) cout<<"\nM.M. is a positive quantity!!Try Again!!";
				}while(max<=0);
				do{
					cout<<"\nTest "<<i+1<<" M.O: "; cin>>marks[i];
					if(marks[i]<0 || marks[i]>max) cout<<"\nM.O must be >= 0 or <= M.M. !!Try Again!!";
				}while(marks[i]<0 || marks[i]>max);
				marks[i]*=100/max;
			}
		}
		void showData()
		{
			cout<<" Data:-";
			cout<<"\nRollNo: "<<rollNo;
			cout<<"\nName: "<<name;
			for(int i=0;i<3;i++) cout<<"\nTest "<<i+1<<" : "<<marks[i];
			cout<<"\nAverage(Best of Two): "<<average()<<endl;
		}
		
		float average()
		{
			if(marks[0]>marks[1]) {
				if(marks[1]>marks[2]) {
					return (marks[0]+marks[1])/2;
				}
				else {
					return (marks[0]+marks[2])/2;
				}
			}
			else{
				if(marks[0]>marks[2]) {
					return (marks[0]+marks[1])/2;
				}
				else {
					return (marks[1]+marks[2])/2;
				}
			}
		}
};

int main()
{
	student s[10];
	cout<<"\nLets play with students database....\n\nPlease enter data one by one..."<<endl;
	for(int i=0;i<10;i++) {
		cout<<"\nFor student "<<i+1<<":-"; 
		s[i].getData();
	}
	cout<<"\nYour Student Database:-\n";
	for(int i=0;i<10;i++) {
		cout<<"\nStudent "<<i+1; 
		s[i].showData();
	}
	return 0;
}
