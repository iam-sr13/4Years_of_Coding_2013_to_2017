#include<iostream>

using namespace std;

class Student
{
	friend float average(Student* z, int s, bool all);
			
	protected:
	string USN,name;
	unsigned int age;
	static int nos;	
	
	public:
	virtual int sem()=0;	
	Student(string u="", string n="", unsigned int a=0) {
		USN=u;
		name=n;
		age=a;
		nos++;
	} 
	~Student(){nos--;}	
	
	virtual int getNos() {return nos;}
	virtual void setData()
	{
		cout<<"\nEnter USN: "; cin>>USN; cin.ignore();
		cout<<"\nEnter Name: "; getline(cin,name);
		cout<<"\nEnter age: "; cin>>age;
	}
	virtual void showData()
	{
		cout<<"\nUSN: "<<USN<<"\nName: "<<name<<"\nAge: "<<age<<endl;
	}
};
int Student::nos=0;

class UGStudent:public Student
{
	//friend float average(UGStudent* z, int sem, bool all);
	
	int semester;
	float fees, stipend;
	static int noug;	
	
	public:
	UGStudent(string u="", string n="", unsigned int a=0, unsigned int s=0, float f=0):Student(u,n,a) 
	{
		semester=s;
		fees=f;
		stipend=0;
		noug++;
	}
	~UGStudent(){noug--;}	
	
	int getNos(){return noug;} 
	int sem(){return semester;}
	
	void setData()
	{
		Student::setData();
		cout<<"\nEnter Semester: "; cin>>semester; 
		cout<<"\nEnter Fees: "; cin>>fees;
		
	}
	void showData()
	{
		cout<<"\nUGStudent Details:-\n"<<endl;
		Student::showData();
		cout<<"\nSemester: "<<semester<<"\nFees: Rs "<<fees<<"/-\nStipend: Rs "<<stipend<<"/-"<<endl;
	}	
};
int UGStudent::noug=0;

class PGStudent:public Student
{
	//friend float average(PGStudent* z, int sem, bool all);
	
	int semester;
	float fees, stipend;
	static int nopg;
	
	public:
	PGStudent(string u="", string n="", unsigned int a=0, unsigned int s=0, float f=0):Student(u,n,a) 
	{
		semester=s;
		fees=f;
		stipend=10000;
		nopg++;
	}
	~PGStudent(){nopg--;}	

	int getNos(){return nopg;} 
	int sem(){return semester;}
	
	void setData()
	{
		Student::setData();
		cout<<"\nEnter Semester: "; cin>>semester; 
		cout<<"\nEnter Fees: "; cin>>fees;
		
	}
	void showData()
	{
		cout<<"\nPGStudent Details:-\n"<<endl;
		Student::showData();
		cout<<"\nSemester: "<<semester<<"\nFees: Rs "<<fees<<"/-\nStipend: Rs "<<stipend<<"/-"<<endl;
	}	
};
int PGStudent::nopg=0;

float average(Student* z, int s=1, bool all=false)
{
	float a=0,n=z->getNos(),nsem=0;
	for(int i=0; i<n ;i++) {
		if((z[i].sem()==s) || all) {
			nsem++;
			a+=z[i].age;
		}
	}	
	return a/nsem+all*((a/n)-(a/nsem));
}

int main()
{
	int ug,pg;	
	
	cout<<"\nLets play with student database.....\n\nEnter no. of UG & PG students seperately: "; cin>>ug>>pg;
	UGStudent u[ug];
	PGStudent p[pg];
	cout<<"\nNow enter UG student details one by one:-\n";
	for(int i=0; i<ug;i++) {cout<<"\nFor student "<<i+1<<" :\n"; u[i].setData();}
	cout<<"\nSimilarly, Now enter PG student details one by one:-\n";
	for(int i=0; i<pg;i++) {cout<<"\nFor student "<<i+1<<" :\n"; p[i].setData();}
	cout<<"\nYour Database:-\n";
	for(int i=0; i<ug;i++) u[i].showData();
	for(int i=0; i<pg;i++) p[i].showData();
	
	cout<<"\nNow semester wise age averages are as follows:-\n\nFor UG:-\n";
	for(int i=1;i<=8;i++) {cout<<"\nSemester "<<i<<" average age: "<<average(u,i);}
	cout<<"\n\nFor PG:-\n";
	for(int i=1;i<=8;i++) {cout<<"\nSemester "<<i<<" average age: "<<average(p,i);}
	cout<<"\n\nAverage age of UG: "<<average(u,1,1);
	cout<<"\nAverage age of PG: "<<average(p,1,1);
	cout<<"\nAverage age of Student: "<<(average(p,1,1)+average(u,1,1))/p->Student::getNos();
	return 0;
}
