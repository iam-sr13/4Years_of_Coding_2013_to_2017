#include<iostream>

using namespace std;

class STUDENT
{
	string USN,name;
	float test[3];	
	
	float getavg() 
	{
		float sum=0;
		for(int i=0; i<3; i++) sum+=test[i];
		return sum/=3;
	}
	public:
		STUDENT() {
			USN=name="";			
		}
		void getData()
		{
			cout<<"\nEnter USN: "; cin>>USN; cin.ignore();
			cout<<"\nEnter Name: "; getline(cin,name);
			for(int i=0; i<3; i++) {
				do {
					cout<<"\nEnter Test '"<<i+1<<"' marks (Max=100): "; cin>>test[i];
					if(test[i]<0 || test[i]>100) {cout<<"\nINVALID ENTRY!!"; continue;}
					else {break;}			
				}while(true);				
			}
		}
		void showData()
		{
			cout<<"\nStudent Details:- "<<endl;
			cout<<"\nUSN: "<<USN<<"\nName: "<<name;
			for(int i=0; i<3; i++) {
				cout<<"\nTest '"<<i+1<<"' marks: "<<test[i];
			}
			cout<<"\nAverage marks: "<<getavg()<<endl;
		} 
};

int main()
{
	STUDENT sdata[10];
	
	cout<<"\nLets play with some student databases....\n\nEnter Data for 10 students as follows:-"<<endl;
	
	for(int i=0; i<2; i++) {
		cout<<"\nFor Student "<<i+1<<" :-\n";
		sdata[i].getData();
	}	
	cout<<"\nThe Student Database is as follows:- "<<endl;
	for(int i=0; i<2; i++) {		
		sdata[i].showData();
	}	
	
	return 0;
}
