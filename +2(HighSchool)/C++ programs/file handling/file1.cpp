#include<iostream>
#include<fstream>

using namespace std;

void create(char fname[])
{
	ofstream fout(fname);
	int i,n;
	char s[80];
	cout<<"\nEnter the total no. of names: ";
	cin>>n;
	cin.ignore();
	for(i=1;i<=n;i++) {
		cin.getline(s,80);
		fout<<s<<endl;
	}
	fout.close();
}
void show(char fname[])
{
	char s[80];
	cout<<"\n\nThis is contents of "<<fname<<" :\n";
	ifstream fin(fname);
	while(fin.getline(s,80)) {
		cout<<endl<<s;
	}
	fin.close();
}
void copy(char *f2,char *f1,int linenum=0)
{
	fstream fin,fout;
	char s[80];
	fin.open(f1,ios::in);
	fout.open(f2,ios::out);
	if(linenum) {for(int i=1;fin.getline(s,80);i++) if(i!=linenum) fout<<s<<endl;}	
	else while(fin.getline(s,80)) fout<<s<<endl;	
	fin.close();
	fout.close();	
}
void delcont(char *fname)
{	
	int n;
	char temp[]="temp.txt";
	cout<<"\n\nPlease enter the no. of line whose content is to be deleted: ",cin>>n;	
	copy(temp,fname,n);
	copy(fname,temp);
}
int main()
{
	char *name=new char[20];
	cout<<"\nEnter filename(max 20 char): ";
	cin>>name;	
	create(name);
	show(name);
	delcont(name);
	show(name);	
	delete name;
	return 0;
}

