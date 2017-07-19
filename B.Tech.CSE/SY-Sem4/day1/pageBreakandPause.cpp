/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.6 in psheet.jpg
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
//#include<conio.h>
using namespace std;

void getch()
{
	cin.ignore();
}


int main()
{
	int lines=0;
	string fname="newsample.txt", tmp, data;
	fstream fin;
	cout<<"\nWELCOME to basic file handling program 3....\n";
	cout<<"\nThe name of the file to be read is NOTES.txt ...... "; 
	
	cout<<"\n\nLOOKING FOR YOUR FILE....";	
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
	cout<<"\n\nRETRIEVAL SUCCESSFUL!"<<endl<<"Your data: "<<data<<endl;
	
	for(unsigned int i=0;i<data.size();i++) {
		cout<<data[i];
		if(data[i]=='\n') lines++;
		if(lines==5) {
			lines=0;
			cout<<"\n\n---------------------PAGE BREAK------------------------------------\n\nPlease insert new page and press return key!!\n\n"; getch();
		} 
	}
	
	return 0;
}
