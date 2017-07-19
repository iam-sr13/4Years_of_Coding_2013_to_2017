#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string fname,buffer;
	vector<string> stack;
	
	cout<<"\nPlease enter filename: ";
	cin>>fname;
	
	fin.open(fname.c_str());
	fout.open(("Reversed_"+fname).c_str());	
	
	if(fin) {
		cout<<"\nProcessing file....";
		while(fin>>buffer) {
			stack.push_back(buffer);
		}
		for(int i=stack.size()-1; i>=0; i--) {
			fout<<stack[i]<<" ";
		}
		cout<<"\nFile Processed!!\nFile generated: "<<("Reversed_"+fname);
	}
	else cout<<"\nFile not found...!!!";
	fin.close();
	fout.close();
	
	return 0;
}
