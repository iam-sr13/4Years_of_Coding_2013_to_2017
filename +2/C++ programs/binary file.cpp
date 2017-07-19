#include<iostream>
#include<fstream>
#define Roll (1)
#define Name ('a')
#define Percent (2.0)

using namespace std;

class student
{
	int roll;
	char name[30];
	float percent;
	public:
	int get(int x)
	{
		return roll;			
	}	
	char* get(char x)
	{
		return name;			
	}	
	float get(double x)
	{
		return percent;		
	}	
	void getd()
	{
		cout<<"\n\nPlease enter the following details:\n";
		cout<<"\nRoll number: ";
		cin>>roll;
		cout<<"\nName: ";
		cin>>name;
		cout<<"\nPercentage: ";
		cin>>percent;
	}
	void putd()
	{
		cout<<"\n\nThis is your data:\n\n";
		cout<<"\nRoll number: "<<roll;		
		cout<<"\nName: "<<name;		
		cout<<"\nPercentage: "<<percent<<" %"<<endl;		
	}	
};
void create()
{
	int n;
	student z;
	fstream fout;
	fout.open("school.dat",ios::out|ios::binary);	
	cout<<"\nEnter no. of students: ", cin>>n;
	for(int i=1;i<=n;i++) {
		z.getd();
		fout.write((char*)&z,sizeof(z));
	}
	fout.close();
}
void show()
{
	student z;
	fstream fin;
	fin.open("school.dat",ios::in|ios::binary);
	while(fin.read((char*)&z,sizeof(z))) {
		if(z.get(Percent)>50)z.putd();
	}
	fin.close();
}

main()
{
	create();
	show();
}
