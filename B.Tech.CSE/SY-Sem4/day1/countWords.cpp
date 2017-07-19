/*
*Author: Shriraj Sawant
*Date: 4/1/2017
*Description: See Q.5 in psheet.jpg
*/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
	int words=0;
	string fname="sample.txt", tmp, data;
	fstream fin;
	cout<<"\nWELCOME to basic file handling program 2....\n";
	cout<<"\nThe name of the file to be read is TRIAL.txt ...... "; 
	
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
		
	for(int i=0;i<data.size();i++) {
		if(data[i]==' ') words++; 
	}
	cout<<"\nTotal no. of words = "<<words<<endl;
	
	words=0;
	for(int i=0,j=0;i<data.size();i++) {
		if(isalpha(data[i])) j++;
		else {
			if(j==4) words++;
			j=0;
		} 
	}
	cout<<"\nAnd Total no. of 4 letter words = "<<words<<endl;	
	
	return 0;
}
