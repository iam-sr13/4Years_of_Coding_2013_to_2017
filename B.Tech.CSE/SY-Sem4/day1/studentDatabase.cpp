/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.2 in psheet.jpg
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
//#include<conio.h>
#define CLR (system("clear"))
using namespace std;

enum Gender{male,female,na};

void getch()
{
	char c;
	cout<<endl<<"Do you want to continue? (y/n) : ";
	cin>>c;	
}

struct Student
{
	static int size;
	string id,name;
	Gender sex;
	float quiz1,quiz2,midsem,final;
	
	void getData()
	{
		int sx;
		cout<<"\nPlease enter correct data for successful registration!!"<<endl;
		
		cout<<"\nEnter ID: "; cin>>id; cin.ignore(),cin.clear();
		cout<<"\nEnter Name: "; getline(cin,name);		
		do {
			cout<<"\nEnter Sex(Male=0,Female=1,N/A=2): "; cin>>sx;
			if(sx<0 || sx>2) {cout<<"\nINVALID ENTRY!!"; continue;}
			else { sex=(Gender)sx; break;}			
		}while(true);
		do {
			cout<<"\nEnter Quiz1 marks (Max=25): "; cin>>quiz1;
			if(quiz1<0 || quiz1>25) {cout<<"\nINVALID ENTRY!!"; continue;}
			else {break;}			
		}while(true);
		do {
			cout<<"\nEnter Quiz2 marks (Max=25): "; cin>>quiz2;
			if(quiz2<0 || quiz2>25) {cout<<"\nINVALID ENTRY!!"; continue;}
			else {break;}			
		}while(true);
		do {
			cout<<"\nEnter MidSem marks (Max=50): "; cin>>midsem;
			if(midsem<0 || midsem>50) {cout<<"\nINVALID ENTRY!!"; continue;}
			else {break;}			
		}while(true);
		do {
			cout<<"\nEnter Final marks (Max=100): "; cin>>final;
			if(final<0 || final>100) {cout<<"\nINVALID ENTRY!!"; continue;}
			else {break;}			
		}while(true);		
		
		cout<<"\nThank you for registration!! \n\nYou will be redirected to Main Menu..."<<endl; getch();		
	}
	void showData()
	{
		cout<<"\nStudent Details: "<<endl;
		cout<<"\nID: "<<id<<"\nName: "<<name<<"\nSex: ";
		if(sex==0) cout<<"Male"; else if(sex==1) cout<<"Female"; else cout<<"N/A";
		cout<<"\nQuiz1 marks: "<<quiz1<<"\nQuiz2 marks: "<<quiz2<<"\nMidSem marks: "<<midsem<<"\nFinal marks: "<<final<<"\nTotal Marks: "<<total()<<endl; getch();
	}
	float total(){return quiz1+quiz2+midsem+final;}
	float avg(){return total()/20;}
};
int Student::size=0;

int main()
{
	Student sdb[20];
	int c;
	
	do{
		CLR;
		cout<<"\nWELCOME to Student Database Program!\n\n#Main Menu:\n\n1) Add Student Record\n2) Delete Student Records\n3) Update Student Records\n4) View All Student Records\n5) Calculate Average\n6) Student with Max Total\n7) Student with Min Total\n8) Find Student by ID\n9) Sort by Total\n10) Quit\n\nYour choice: ";
		cin>>c;
		
		switch(c) {
			case 1:{				
				CLR;
				if(Student::size>=20){cout<<"\nDatabase is FULL!!"; getch(); }
				else{
					sdb[Student::size].getData();				
					Student::size++;
				} 						
				break;
			}
			case 2:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				CLR;
				
				for(int i=0; i<Student::size; i++) {
					cout<<"\n"<<i+1<<") "<<sdb[i].name;
				}
				cout<<"\n\nYour Choice: "; cin>>c;
				
				for(int i=c; i<Student::size; i++) {
					sdb[i-1]=sdb[i];
				}
				
				Student::size--;			
				break;
			}
			case 3:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				CLR;
				
				for(int i=0; i<Student::size; i++) {
					cout<<"\n"<<i+1<<") "<<sdb[i].name;
				}
				cout<<"\n\nYour Choice: "; cin>>c;
				
				sdb[c-1].getData();				
				break;
			}
			case 4:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				do{
					CLR;					
					for(int i=0; i<Student::size; i++) {
						cout<<"\n"<<i+1<<") "<<sdb[i].name;
					}
					cout<<"\n\n"<<Student::size+1<<") Go Back"<<endl;
					cout<<"\nYour Choice: "; cin>>c;
					if(c==Student::size+1) break;
					sdb[c-1].showData(); 
				}while(c!=Student::size+1);				
				break;
			}
			case 5:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				do{
					CLR;
					for(int i=0; i<Student::size; i++) {
						cout<<"\n"<<i+1<<") "<<sdb[i].name;
					}
					cout<<"\n\n"<<Student::size+1<<") Go Back"<<endl;
					cout<<"\nYour Choice: "; cin>>c;
					if(c==Student::size+1) break;
					cout<<"\nGPA: "<<sdb[c-1].avg(); getch();
				}while(c!=Student::size+1);				
				break;
			}
			case 6:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				CLR;
				
				int pos=0,total=0;
				for(int i=0; i<Student::size; i++) {
					if(sdb[i].total()>total) {pos=i; total=sdb[i].total();}	
				}
				cout<<"\nStudent with MAX Total: "<<sdb[pos].name<<" with Total = "<<total;	getch();			
				break;
			}
			case 7:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				CLR;
				int pos=0,total=200;
				for(int i=0; i<Student::size; i++) {
					if(sdb[i].total()<total) {pos=i; total=sdb[i].total();}	
				}
				cout<<"\nStudent with MIN Total: "<<sdb[pos].name<<" with Total = "<<total;	getch();					
				break;
			}
			case 8:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				CLR;
				int i;
				string id;
				cout<<"\nEnter ID: "; cin>>id;
				for(i=0; i<Student::size; i++) {
					if(sdb[i].id==id) {sdb[i].showData(); break;}	
				}
				if(i==Student::size) {
					cout<<"\nStudent NOT FOUND!! or INVALID ID!!"<<endl; 
					getch();
				}				
				break;
			}
			case 9:{
				if(Student::size<=0) {cout<<"\nDatabase is EMPTY!!"; getch(); break;}
				int i,j;
				Student t;
				for(i=1;i<Student::size;i++)
					for(j=0;j<Student::size-i;j++)
						if(sdb[j].total()<sdb[j+1].total())
							{
								t=sdb[j];
								sdb[j]=sdb[j+1];
								sdb[j+1]=t;
							}
				cout<<"\nDatabase is successfully sorted!! Please check in view tab!!"; getch();													
				break;
			}
			case 10:{				
				break;
			}
			default: cout<<"\nWrongChoice!!";getch();				
		}		
	}while(c!=10);
	
	return 0;
}




