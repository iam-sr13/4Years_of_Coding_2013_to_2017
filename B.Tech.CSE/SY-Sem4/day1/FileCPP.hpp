#ifndef _FILEHANDLING_
#define _FILEHANDLING_
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class File
{
	string fname,data;		
	public:	
		void getfname(string);
		void display();
		void create();		
		void retrieve();	
		void store();	
};
void File::display()
{	
	cout<<"\n\nYour data is:\n\n"<<data;
}
void File::create()
{
	fstream fout;
	string input;	
	fout.open(fname.c_str(), ios::out);
	if(!fout) {cerr<<"\n\n ERROR!! FILE CAN'T BE CREATED!!!"; exit(0);}
	cout<<"\n\n~Your Filespace:     ("<<fname<<")\n\n";
	cin.ignore();
	getline(cin,input);
	fout<<input;
	fout.close();
	cout<<"\nFile is closed.";
}
void File::getfname(string f)
{ 
	fname=f;				
}

void File::retrieve()
{
	cout<<"\n\nLOOKING FOR YOUR FILE....";	
	string tmp;  	    
	fstream fin;
	fin.open(fname.c_str(), ios::in);
	if(!fin) {cerr<<"\n\nFILE NOT FOUND!!!"; exit(0);}
	else cout<<"\n\nRETRIEVING DATA....";
	for(;;) {
		getline(fin,tmp);
		data+=tmp;
		if(fin.eof()) break;
		data+="\n";		
	}
	fin.close();
	cout<<"\n\nRETRIEVAL SUCCESSFUL!";
	cout<<"\n\nYour DATA:=         (press any key)\n\n";	
	getch();
	cout<<data<<"\n";	
}
void File::store()
{	
	cout<<"\n\nCREATING YOUR FILE.....";				
	fstream fout;	
	fout.open(fname.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; exit(0);}
	else cout<<"\n\nSTORING DATA....";
	fout<<data;		
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL!";	
}
#endif
