//...this is my practical last minute refresher.....
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class student
{
	public:	 
	int GRno,rollno;
	char name[30];
	float percent;
	void getd()
	{
		cout<<"\n\nPlease enter the following details:\n";
		cout<<"\nGR number: ";
		cin>>GRno;
		cout<<"\nName: ";
		cin>>name;
		cout<<"\nPercentage: ";
		cin>>percent;
	}
	void putd()
	{
		cout<<"\n"<<setw(7)<<GRno<<" | "<<setw(6)<<rollno<<" | "<<setw(20)<<name<<" | "<<setw(7)<<percent<<" % |";
	}
};

void swap(student *x,student *y)
	{
		student t;
		t=*x;
		*x=*y;
		*y=t;
	}

main()
{
	student *a,*b,*c;
	int m,n,i,j,k,r=4601;
	
	cout<<"           WELCOME! Student DaTaBaSe v1.0\n\nData 1:-";
	cout<<"\n\nPlease enter the total no. of students: ";
	cin>>m;
	a=new student[m];
	cout<<"\nNow please enter required data as instructed!\n";
	for(i=0;i<m;i++)
	{
		cout<<"\nFor Student "<<i+1<<" :-";
		a[i].getd();
	}
	
	cout<<"\n\nData 2:-\n\nPlease enter the total no. of students: ";
	cin>>n;
	b=new student[n];
	c=new student[m+n];
	cout<<"\nNow please enter required data as instructed!\n";
	for(i=0;i<n;i++)
	{
		cout<<"\nFor Student "<<i+1<<" :-";
		b[i].getd();
	}
	
	for(i=0,j=0,k=0;i<m && j<n;) 
		if(strcmp(a[i].name,b[i].name)<0) c[k++]=a[i++];
			else c[k++]=b[j++];
	if(i==m) for(;j<n;) c[k++]=b[j++];
	if(j==n) for(;i<m;) c[k++]=a[i++];
	

	
	cout<<"\n\nYour Database:-\n\n";
	cout<<"_____________________________________________________\n";
	cout<<"  Rank  | Roll No|   Student's Name     | Percent   |\n";
	cout<<"_____________________________________________________\n";
	cout<<"        |        |                      |           |";	
	for(i=0;i<m+n;i++)
	{
		c[i].rollno=r++;		
		c[i].putd();
	}
	cout<<"\n_____________________________________________________";
}
