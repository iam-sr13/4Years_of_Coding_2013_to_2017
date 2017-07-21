#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#define from 1
using namespace std;

class list
{
	vector<string> name;
	protected: 
		void input(string what);
		void retrieve(string filename);
	public:	
		int get_size_of_list()
		{
			return name.size();
		}
		string get_name(int i)
		{
			string o=name[i];
			return o;
		}
		void display(string what);
		void display(int i,string filename);
		void store_in(string filename);
		list(string what)
		{
			input(what);
		}
		list(int i,string filename)
		{
			retrieve(filename);
		}			
};

void list::input(string what)
{
	int i,c=0;
	string n;
	cout<<"\nPlease enter the names of "<<what<<" one by one seperated by comma and space:-\n(after the last name, enter a fullstop. for e.g firstname, second, ....,lastname.)\n\n";
	for(i=0;;i++)
	{
		cin>>n;
		if(n.find(".")!=string::npos) { n.erase(n.find(".")); c=1;}
			else { n.erase(n.find(","));}
		name.push_back(n);
		if(c) break;
	}	
}
void list::display(string what)
{
	int i,n=name.size();
	cout<<"\n\nFollowing are "<<what<<" :\n\n";
	for(i=0;i<n;i++) {
		cout<<name[i];
		if(i<n-1) cout<<", ";
			else cout<<".";
	}
}
void list::display(int i,string filename){
	
	retrieve(filename);
	display("contents of "+filename);
}
void list::retrieve(string filename)
{
	int i;		
	string n;
	fstream fin;
	fin.open(filename.c_str(), ios_base::in);
	for(i=0;;i++) {
		fin>>n;
		if(fin.eof()) break;
		name.push_back(n);
	}
	fin.close();
}
void list::store_in(string filename)
{
	int i,n=name.size();	
	fstream fout;
	fout.open(filename.c_str(), ios::out);
	for(i=0;i<n;i++) fout<<name[i]<<endl;	
	fout.close();	
}

main()
{
	cout<<"          WELCOME! to favourite 'Countries' & their 'Capitals'\n          ____________________________________________________\n";
	list countries("the countries"), capitals("their respective capitals");		
	countries.store_in("COUNTRY.txt");
	capitals.store_in("CAPITAL.txt");
	list countries2(from,"COUNTRY.txt"), capitals2(from,"CAPITAL.txt");
	int i;
	cout<<endl;
	cout<<"_____________________________________________________________\n";
	cout<<"                              |                              \n";
	cout<<"             COUNTRY          |          CAPITAL             \n";
	cout<<"______________________________|______________________________\n";
	for(i=0;i<countries2.get_size_of_list();i++) {
		cout<<"         "<<setw(10)<<countries2.get_name(i)<<"           |"<<"       "<<setw(10)<<capitals2.get_name(i)<<endl;
	}
	cout<<"_____________________________________________________________\n\n";		
}
