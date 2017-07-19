/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.4 in psheet.jpg
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	string rname, wname, tmp, data;
	fstream fin,fout;
	cout<<"\nWELCOME to basic file handling program....\n";
	cout<<"\nPlease enter name of the file to be read: "; 
	cin>>rname;
	
	cout<<"\n\nLOOKING FOR YOUR FILE....";	
	fin.open(rname.c_str(), ios::in);
	if(!fin) {cerr<<"\n\nFILE NOT FOUND!!!"; exit(0);}
	else cout<<"\n\nRETRIEVING DATA....";
	for(;;) {
		getline(fin,tmp);
		data+=tmp;
		if(fin.eof()) break;
		data+="\n";		
	}
	fin.close();
	cout<<"\n\nRETRIEVAL SUCCESSFUL!"<<endl<<"Your data: "<<data<<endl;
		
	for(int i=0,pos=0;i<data.size();i=pos+2) {
		pos=data.find(" a ", i);
		if(pos==string::npos) break;
		data[pos+1]=' ';
	}
	
	for(int i=0,pos=0;i<data.size();i=pos+3) {
		pos=data.find(" an ", i);
		if(pos==string::npos) break;
		data[pos+1]=' ';
		data[pos+2]=' ';
	}
	
	for(int i=0,pos=0;i<data.size();i=pos+4) {
		pos=data.find(" the ", i);
		if(pos==string::npos) break;
		data[pos+1]=' ';
		data[pos+2]=' ';
		data[pos+3]=' ';
	}
	
	cout<<endl<<"Processed data: "<<data<<endl;
	
	cout<<"\nNow Please enter name of the file to be saved for the edited text: "; 
	cin>>rname;
	cout<<"\n\nCREATING YOUR FILE.....";		
	fout.open(rname.c_str(), ios::out);
	if(!fout) { cerr<<"\n\nERROR!\nFILE CAN'T BE OPENED!"; exit(0);}
	else cout<<"\n\nSTORING DATA....";
	fout<<data;		
	fout.close();
	cout<<"\n\nSTORAGE SUCCESSFULL!";
	return 0;
}
