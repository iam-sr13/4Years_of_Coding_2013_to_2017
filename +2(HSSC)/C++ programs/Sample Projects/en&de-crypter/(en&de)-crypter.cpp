#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#define from 1
#define dec 2.0
#define enc 3
using namespace std;
class code
{
	protected: 
		string dat;
		
	public:
		void input();
		void retrieve(string filename);
		void display(string what);
		void display(int i,string filename);
		void store_in(string filename);		
};

class encrp:public code
{
	string encdat;
	public:
	void store_in(int i, string filename);
	
	void encrypt()
	{
		int i;
		string temp=dat; 
		cout<<"\nENCRYPTING....";
		for(i=0;i<temp.size();i++) {
			if(temp[i]=='a') {temp[i]='c';continue;}
			if(temp[i]=='b') {temp[i]='d';continue;}
			if(temp[i]=='c') {temp[i]='e';continue;}
			if(temp[i]=='d') {temp[i]='f';continue;}
			if(temp[i]=='e') {temp[i]='g';continue;}
			if(temp[i]=='f') {temp[i]='h';continue;}
			if(temp[i]=='g') {temp[i]='i';continue;}
			if(temp[i]=='h') {temp[i]='j';continue;}
			if(temp[i]=='i') {temp[i]='k';continue;}
			if(temp[i]=='j') {temp[i]='l';continue;}
			if(temp[i]=='k') {temp[i]='m';continue;}
			if(temp[i]=='l') {temp[i]='n';continue;}
			if(temp[i]=='m') {temp[i]='o';continue;}
			if(temp[i]=='n') {temp[i]='p';continue;}
			if(temp[i]=='o') {temp[i]='q';continue;}
			if(temp[i]=='p') {temp[i]='r';continue;}
			if(temp[i]=='q') {temp[i]='s';continue;}
			if(temp[i]=='r') {temp[i]='t';continue;}
			if(temp[i]=='s') {temp[i]='u';continue;}
			if(temp[i]=='t') {temp[i]='v';continue;}
			if(temp[i]=='u') {temp[i]='w';continue;}
			if(temp[i]=='v') {temp[i]='x';continue;}
			if(temp[i]=='w') {temp[i]='y';continue;}
			if(temp[i]=='x') {temp[i]='z';continue;}
			if(temp[i]=='y') {temp[i]='a';continue;}
			if(temp[i]=='z') {temp[i]='b';continue;}
			
			if(temp[i]=='A') {temp[i]='D';continue;}
			if(temp[i]=='B') {temp[i]='E';continue;}
			if(temp[i]=='C') {temp[i]='F';continue;}
			if(temp[i]=='D') {temp[i]='G';continue;}
			if(temp[i]=='E') {temp[i]='H';continue;}
			if(temp[i]=='F') {temp[i]='I';continue;}
			if(temp[i]=='G') {temp[i]='J';continue;}
			if(temp[i]=='H') {temp[i]='K';continue;}
			if(temp[i]=='I') {temp[i]='L';continue;}
			if(temp[i]=='J') {temp[i]='M';continue;}
			if(temp[i]=='K') {temp[i]='N';continue;}
			if(temp[i]=='L') {temp[i]='O';continue;}
			if(temp[i]=='M') {temp[i]='P';continue;}
			if(temp[i]=='N') {temp[i]='Q';continue;}
			if(temp[i]=='O') {temp[i]='R';continue;}
			if(temp[i]=='P') {temp[i]='S';continue;}
			if(temp[i]=='Q') {temp[i]='T';continue;}
			if(temp[i]=='R') {temp[i]='U';continue;}
			if(temp[i]=='S') {temp[i]='V';continue;}
			if(temp[i]=='T') {temp[i]='W';continue;}
			if(temp[i]=='U') {temp[i]='X';continue;}
			if(temp[i]=='V') {temp[i]='Z';continue;}
			if(temp[i]=='W') {temp[i]='A';continue;}
			if(temp[i]=='X') {temp[i]='B';continue;}
			if(temp[i]=='Y') {temp[i]='C';continue;}
			if(temp[i]=='Z') {temp[i]='D';continue;}
			
			if(temp[i]==' ') {temp[i]='@';continue;}
			if(temp[i]==',') {temp[i]='%';continue;}
			if(temp[i]=='.') {temp[i]='$';continue;}
			if(temp[i]=='!') {temp[i]='^';continue;}
		}
		encdat=temp;
		cout<<"\nENCRYPTION SUCCESSFULL!";		
	}	
};

class decrp:public code
{
	string decdat;
	public:
				
	void store_in(float i, string filename);	
	void decrypt()
	{
		int i;
		string temp=dat;
		cout<<"\nDECRYPTING...."; 
		for(i=0;i<temp.size();i++) {
			if(temp[i]=='c') {temp[i]='a';continue;}
			if(temp[i]=='d') {temp[i]='b';continue;}
			if(temp[i]=='e') {temp[i]='c';continue;}
			if(temp[i]=='f') {temp[i]='d';continue;}
			if(temp[i]=='g') {temp[i]='e';continue;}
			if(temp[i]=='h') {temp[i]='f';continue;}
			if(temp[i]=='i') {temp[i]='g';continue;}
			if(temp[i]=='j') {temp[i]='h';continue;}
			if(temp[i]=='k') {temp[i]='i';continue;}
			if(temp[i]=='l') {temp[i]='j';continue;}
			if(temp[i]=='m') {temp[i]='k';continue;}
			if(temp[i]=='n') {temp[i]='l';continue;}
			if(temp[i]=='o') {temp[i]='m';continue;}
			if(temp[i]=='p') {temp[i]='n';continue;}
			if(temp[i]=='q') {temp[i]='o';continue;}
			if(temp[i]=='r') {temp[i]='p';continue;}
			if(temp[i]=='s') {temp[i]='q';continue;}
			if(temp[i]=='t') {temp[i]='r';continue;}
			if(temp[i]=='u') {temp[i]='s';continue;}
			if(temp[i]=='v') {temp[i]='t';continue;}
			if(temp[i]=='w') {temp[i]='u';continue;}
			if(temp[i]=='x') {temp[i]='v';continue;}
			if(temp[i]=='y') {temp[i]='w';continue;}
			if(temp[i]=='z') {temp[i]='x';continue;}
			if(temp[i]=='a') {temp[i]='y';continue;}
			if(temp[i]=='b') {temp[i]='z';continue;}
	
			if(temp[i]=='D') {temp[i]='A';continue;}
			if(temp[i]=='E') {temp[i]='B';continue;}
			if(temp[i]=='F') {temp[i]='C';continue;}
			if(temp[i]=='G') {temp[i]='D';continue;}
			if(temp[i]=='H') {temp[i]='E';continue;}
			if(temp[i]=='I') {temp[i]='F';continue;}
			if(temp[i]=='J') {temp[i]='G';continue;}
			if(temp[i]=='K') {temp[i]='H';continue;}
			if(temp[i]=='L') {temp[i]='I';continue;}
			if(temp[i]=='M') {temp[i]='J';continue;}
			if(temp[i]=='N') {temp[i]='K';continue;}
			if(temp[i]=='O') {temp[i]='L';continue;}
			if(temp[i]=='P') {temp[i]='M';continue;}
			if(temp[i]=='Q') {temp[i]='N';continue;}
			if(temp[i]=='R') {temp[i]='O';continue;}
			if(temp[i]=='S') {temp[i]='P';continue;}
			if(temp[i]=='T') {temp[i]='Q';continue;}
			if(temp[i]=='U') {temp[i]='R';continue;}
			if(temp[i]=='V') {temp[i]='S';continue;}
			if(temp[i]=='W') {temp[i]='T';continue;}
			if(temp[i]=='X') {temp[i]='U';continue;}
			if(temp[i]=='Y') {temp[i]='V';continue;}
			if(temp[i]=='Z') {temp[i]='W';continue;}
			if(temp[i]=='A') {temp[i]='X';continue;}
			if(temp[i]=='B') {temp[i]='Y';continue;}
			if(temp[i]=='C') {temp[i]='Z';continue;}
			
			if(temp[i]=='@') {temp[i]=' ';continue;}
			if(temp[i]=='%') {temp[i]=',';continue;}
			if(temp[i]=='$') {temp[i]='.';continue;}
			if(temp[i]=='^') {temp[i]='!';continue;}	
		}
		decdat=temp;
		cout<<"\nDECRYPTION SUCCESSFULL!";
	}
};

void code::input()
{	
	cout<<"\nPlease enter your data for encryption:\n\n";
	cin.ignore();	
	getline(cin,dat);
}

void code::display(string what)
{	
	cout<<"\n\nFollowing are "<<what<<" :\n\n"<<dat;
}

void code::display(int i,string filename){
	
	retrieve(filename);
	display("contents of "+filename);
}

void code::retrieve(string filename)
{	
    cout<<"\nLOOKING FOR YOUR FILE....";    
	fstream fin;
	fin.open(filename.c_str(), ios_base::in);
	if(!fin) {cerr<<"\n\nFILE NOT FOUND!!!\n\n{HELP:- File to be decrypted should be named as 'encrypted.txt'}";}
	else cout<<"\n\nRETRIEVING DATA...."; 
	getline(fin,dat);
	fin.close();
}
void code::store_in(string filename)
{	
	cout<<"\nCREATING YOUR FILE.....";	
	fstream fout;
	fout.open(filename.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; }
	else cout<<"\n\nSTORING DATA....";
	fout<<dat;	
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL";	
}

void encrp::store_in(int i,string filename)
{	
	cout<<"\nCREATING YOUR FILE.....";	
	fstream fout;
	fout.open(filename.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; }
	else cout<<"\n\nSTORING DATA....";
	fout<<encdat;	
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL";	
}

void decrp::store_in(float i,string filename)
{	
	cout<<"\nCREATING YOUR FILE.....";	
	fstream fout;
	fout.open(filename.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; }
	else cout<<"\n\nSTORING DATA....";
	fout<<decdat;	
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL";	
}

int main()
{
	int ch;
	encrp a;
	decrp b;
	cout<<"1.Encryption.\n2.Decryption";
	cout<<"\n\nChoose:";
	cin>>ch;
	switch(ch) {
		case 1: a.input();
				a.encrypt();
				a.store_in(enc,"encrypted.txt");
			    break;
			    
		case 2: b.retrieve("encrypted.txt");
				b.decrypt();
				b.store_in(dec,"decrypted.txt");
			break;
	}	
	return 0;
}
