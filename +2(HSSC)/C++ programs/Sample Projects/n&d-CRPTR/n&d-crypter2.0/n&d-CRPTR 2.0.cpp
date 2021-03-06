#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#define dec 2.0
#define enc 1
using namespace std;

class file
{
	string fname,data,secured; 		
	public:
		void getd()
		{ 
			cout<<"\n\nPlease enter the respective filename: ";
			cin>>fname;		
		}		
		void store(float task);
		void retrieve(int i);
		void retrieve(double j);
		void encrypt();		
		void decrypt();		
};

void file::encrypt()
{
	int i,c,a,x;	
	secured=data;	
	cout<<"\n\nENCRYPTING....";
	for(i=0;i<data.size();i++) {		
		for(a=0,c=0;c<=127;c++,a++) if(data[i]==(char)c) {data[i]=(char)(2*a);x=1;break;}
		cout<<setprecision(2)<<setw(6)<<(((float)i/data.size())*100)<<"% complete.\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		if(x) continue;
		for(a=0,c=128;c<=255;c++,a++) if(data[i]==(char)c) {data[i]=(char)(2*a+1);x=1;break;}					
	}
	cout<<"100.00% complete.";
	cout<<"\n\nENCRYPTION SUCCESSFULL!";
	getch();
	cout<<"\n\nYour encrypted DATA:=\n\n"<<data;
}		
void file::decrypt()
{
	int i,c,a,x;	
	secured=data;
	cout<<"\n\nDECRYPTING...."; 
	for(i=0;i<data.size();i++) {		
		for(a=0,c=0;c<=127;c++,a++) if(data[i]==(char)(2*a)) {data[i]=(char)c;x=1;break;}
		cout<<setprecision(2)<<setw(6)<<(((float)i/data.size())*100)<<"% complete.\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		if(x) continue;
		for(a=0,c=128;c<=255;c++,a++) if(data[i]==(char)(2*a+1)) {data[i]=(char)c;x=1;break;}		
	}
	cout<<"100.00% complete.";
	cout<<"\n\nDECRYPTION SUCCESSFULL!";
	getch();	
	cout<<"\n\nYour decrypted DATA:=\n\n"<<data;
}	

void file::retrieve(int i)
{	
    cout<<"\n\nLOOKING FOR YOUR FILE....";				
	string tmp;    
	fstream fin;
	fin.open(fname.c_str(), ios_base::in);
	if(!fin) {cerr<<"\n\nFILE NOT FOUND!!!"; exit(0);}
	else cout<<"\n\nRETRIEVING DATA...."; 	
	for(;;) {
		getline(fin,tmp);
		if(fin.eof()) break;	 		
		data+=tmp+"\n";
	}
	fin.close();
	cout<<"\n\nRETRIEVAL SUCCESSFUL!";
	cout<<"\n\nYour DATA to be encrypted:=\n\n"<<data<<"\n";
}
void file::retrieve(double j)
{	
    cout<<"\n\nLOOKING FOR YOUR FILE....";		    
	fstream fin;
	fin.open(fname.c_str(), ios_base::in);
	if(!fin) {cerr<<"\n\nFILE NOT FOUND!!!"; exit(0);}
	else cout<<"\n\nRETRIEVING DATA...."; 	
	getline(fin,data);	
	fin.close();
	cout<<"\n\nRETRIEVAL SUCCESSFUL!";
	cout<<"\n\nYour encrypted DATA:=\n\n"<<data<<"\n";
}
void file::store(float task)
{	
	cout<<"\n\nCREATING YOUR FILE.....";
	string cryptname,tname=fname;			
	fstream fout;	
	if(task==1) {tname.erase(tname.find("."));cryptname=tname+".enc.txt";}
	else {tname.erase(tname.find("."));cryptname=tname+".dec.txt";}
	fout.open(cryptname.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; exit(0);}
	else cout<<"\n\nSTORING DATA....";
	fout<<data;		
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL!";	
}

int main()
{
	file encode;
	int ch;
	char ch2;
	cout<<"                                  WELCOME!\n                                 __________\n\n                        This is n&d-CRPTR v2.0\n\n{NOTE:- PLEASE place the file to be encrypted or decrypted in this software's directory!}\n\n";               
	cout<<"Choose your option (1,2 or 3):\n\n1. ENCRYPT\n2. DECRYPT\n3. EXIT\n";
	cout<<"\nYour Choice: ";
	cin>>ch;
	switch(ch) {
		case 1:	encode.getd();
				encode.retrieve(enc);
				cout<<"\n\nPress enter to start encryption!";
				getch();
				encode.encrypt();
				cout<<"\n\nWant to store the encrypted copy? (y/n)"<<"\nYour Choice: ";
				cin>>ch2;
				if(ch2=='n') (exit(0));
				encode.store(enc);	
			break;
		case 2: encode.getd();
				encode.retrieve(dec);
				cout<<"\n\nPress enter to start decryption!";
				getch();
				encode.decrypt();
				cout<<"\n\nWant to store the decrypted copy? (y/n)"<<"\nYour Choice: ";
				cin>>ch2;
				if(ch2=='n') (exit(0));
				encode.store(dec);				
			break;
		case 3: exit(0);			
	}
	cout<<"\n\nPress enter to exit!";				
	getch();
	return 0;
}

//Rough work:=
//char alpha,numer,auth,schar;line 31,57.
/*for(alpha='A',auth=1,j=1;j<=26;j++,alpha++,auth++) if(data[i]==alpha) {data[i]=(2*auth);x=1;break;}
		if(x) continue;
		for(alpha='a',auth=1,j=1;j<=26;j++,alpha++,auth++) if(data[i]==alpha) {data[i]=(2*auth-1);x=1;break;}
		if(x) continue;
		for(numer='0',j=1;j<=10;j++,numer++,auth++) if(data[i]==numer) {data[i]=(2*auth);x=1;break;}
		if(x) continue;
		cout<<"\n...."<<setw(3)<<((i/data.size())*100)<<"% complete."<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		for(schar=32;schar<=47;schar++,auth++) if(data[i]==schar) {data[i]=(2*auth-1);x=1;break;}
		if(x) continue;
		for(schar=58;schar<=64;schar++,auth++) if(data[i]==schar) {data[i]=(2*auth);x=1;break;}
		if(x) continue;
		for(schar=91;schar<=96;schar++,auth++) if(data[i]==schar) {data[i]=(2*auth-1);x=1;break;}
		if(x) continue;
		for(schar=123;schar<=126;schar++,auth++) if(data[i]==schar) {data[i]=(2*auth);x=1;break;}*/	//line 32
/*for(alpha='A',auth=1,j=1;j<=26;j++,alpha++,auth++) if(data[i]==(2*auth)) {data[i]=alpha;x=1;break;}
		if(x) continue;
		for(alpha='a',auth=1,j=1;j<=26;j++,alpha++,auth++) if(data[i]==(2*auth-1)) {data[i]=alpha;x=1;break;}
		if(x) continue;
		for(numer='0',j=1;j<=10;j++,numer++,auth++) if(data[i]==(2*auth)) {data[i]=numer;x=1;break;}
		if(x) continue;
		cout<<"\n...."<<setw(3)<<((i/data.size())*100)<<"% complete."<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		for(schar=32;schar<=47;schar++,auth++) if(data[i]==(2*auth-1)) {data[i]=schar;x=1;break;}
		if(x) continue;
		for(schar=58;schar<=64;schar++,auth++) if(data[i]==(2*auth)) {data[i]=schar;x=1;break;}
		if(x) continue;
		for(schar=91;schar<=96;schar++,auth++) if(data[i]==(2*auth-1)) {data[i]=schar;x=1;break;}
		if(x) continue;
		for(schar=123;schar<=126;schar++,auth++) if(data[i]==(2*auth)) {data[i]=schar;x=1;break;}*/	//line 47

