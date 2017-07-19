#include<iostream>
#include<fstream>
#include<cstdlib>
#define CLR system("clear");
using namespace std;

void getch(){cin.ignore().ignore();}

class student
{
	friend int pack(student*& db, int& n, string& fname);
	friend int unpack(student*& db, int& n, string& fname);
	friend int search(student* db, int n, int roll);
	friend void modify(student* db, int n, int roll);
	
	string branch, name;
	int rollNo;
	float marks[3];
	
	public:
		student(int roll=0,string r="",string n="",float a=0,float b=0, float c=0) {
			rollNo=roll;
			branch=r;
			name=n;
			marks[0]=a;
			marks[1]=b;
			marks[2]=c;
		}
		student(const student& z) {
			rollNo=z.rollNo;
			branch=z.branch;
			name=z.name;
			for(int i=0;i<3;i++) marks[i]=z.marks[i];
		}
		
		void getData()
		{
			cout<<"\nEnter RollNo: "; cin>>rollNo;
			cout<<"\nEnter Branch: "; cin>>branch; //cin.ignore();
			cout<<"\nEnter Name: "; cin>>name;//getline(cin,name);
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
			cout<<"\nBranch: "<<branch;
			cout<<"\nName: "<<name;
			cout<<"\nScoresheet:-";
			for(int i=0;i<3;i++) cout<<"\nTest "<<i+1<<" : "<<marks[i]<<" %";			
		}		
};

int pack(student*& db, int& n, string& fname)
{
	ofstream fout(fname.c_str());
	if(fout){
		fout<<n;		
		for(int i=0;i<n;i++) {
			fout<<"\n"<<db[i].rollNo;
			fout<<"\n"<<db[i].branch;
			fout<<"\n"<<db[i].name;
			fout<<"\n"<<db[i].marks[0];
			fout<<"\n"<<db[i].marks[1];
			fout<<"\n"<<db[i].marks[2];
			fout<<"\n#";
		}
		return 0;
	}
	else cout<<"\nFile Error!!!"<<endl;
	return -1;
}

int unpack(student*& db, int& n, string& fname)
{
	string buf;
	ifstream fin(fname.c_str());
	if(fin){
		fin>>n;	
		db=new student[n];			
		for(int i=0;i<n;i++) {			
			fin>>db[i].rollNo;
			fin>>db[i].branch;
			fin>>db[i].name;
			fin>>db[i].marks[0];
			fin>>db[i].marks[1];
			fin>>db[i].marks[2];			
			fin>>buf;
		}
		return 0;
	}
	else cout<<"\nFile Not found!!!"<<endl;
	return -1;
}

int search(student* db, int n, int roll)
{
	for(int i=0;i<n;i++){
		if(roll==db[i].rollNo) {							
			return i;
		}
	}
	cout<<"\nRollNo not found!!\nPlease create a new one if youy want!\n";
	return -1;
}

void modify(student* db, int n, int roll)
{
	int index=search(db,n,roll);
	if(index>=0) {
		cout<<"\nPlease enter new data for this student:- ";			
		db[index].getData();
	}		
}	

int main()
{
	int ch=0,n=0;
	student* db=0; 	
	string fname="N/A";
	
	do{
		CLR;
		cout<<"\nWELCOME to Student Database Program....\n\nSTATUS: Current Open Database: "<<fname<<"\n\n#MAIN MENU\n\n1.New Database\n2.Open Existing Database\n3.Display Database\n4.Modify Database\n5.Search Database\n6.Quit\n\nYour Choice: ";
		cin>>ch;
		
		switch(ch) {
			case 1: {
				cout<<"\nEnter name of your database: "; cin>>fname;
				cout<<"\nPlease enter number of students: "; cin>>n;
				db=new student[n];
				cout<<"\n\nPlease enter data one by one..."<<endl;
				for(int i=0;i<n;i++) {
					cout<<"\nFor student "<<i+1<<":-"; 
					db[i].getData();
				}
				pack(db,n,fname);
				break;
			}
			case 2: {
				delete[] db;
				cout<<"\nEnter name of your database: "; cin>>fname;
				unpack(db,n,fname);				
				break;
			}
			case 3: {
				if(fname!="N/A"){
					CLR;
					cout<<"\nYour Student Database:-\n";
					for(int i=0;i<n;i++) {
						cout<<"\n\nStudent "<<i+1; 
						db[i].showData();
					}					
				}
				else cout<<"\nNo database is open, please open or create first!!";
				getch();
				break;
			}
			case 4: {
				if(fname!="N/A"){
					int roll;
					cout<<"\nPlease enter roll no to be modified: "; cin>>roll;
					modify(db,n,roll);
					pack(db,n,fname);				
				}
				else cout<<"\nNo database is open, please open or create first!!";
				getch();
				break;
			}
			case 5: {
				if(fname!="N/A"){
					int roll;
					cout<<"\nPlease enter roll no to be searched: "; cin>>roll;
					int index=search(db,n,roll);
					if(index>=0){
						cout<<"\n\nYour info:"; 
						db[index].showData();
					}					
				}
				else cout<<"\nNo database is open, please open or create first!!";
				getch();
				break;
			}
			case 6: {
				//quit
				break;
			}
			default: cout<<"\nINVALID CHOICE!!\nPlease try again....\n"; getch();
		}
	}while(ch!=6);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*student s[10];
	cout<<"\nLets play with students database....\n\nPlease enter data one by one..."<<endl;
	for(int i=0;i<10;i++) {
		cout<<"\nFor student "<<i+1<<":-"; 
		s[i].getData();
	}
	cout<<"\nYour Student Database:-\n";
	for(int i=0;i<10;i++) {
		cout<<"\nStudent "<<i+1; 
		s[i].showData();
	}*/
	return 0;
}
