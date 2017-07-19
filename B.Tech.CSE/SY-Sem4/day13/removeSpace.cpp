#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string fname,buffer;
	
	cout<<"\nPlease enter filename: ";
	cin>>fname;
	
	fin.open(fname.c_str());
	fout.open(("Modified"+fname).c_str());	
	
	if(fin) {
		cout<<"\nProcessing file....";
		while(fin>>buffer) {
			fout<<buffer<<" ";
		}
		cout<<"\nFile Processed!!\nFile generated: "<<("Modified"+fname);
	}
	else cout<<"\nFile not found...!!!";
	fin.close();
	fout.close();
	
	return 0;
}
