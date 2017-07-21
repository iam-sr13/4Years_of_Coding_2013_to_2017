#include<iostream>
#include<sstream>
#include<fstream>
#include<windows.h>
#define sstream stringstream
using namespace std;

string shell(int i)
{
	string n;
	sstream ss;
	ss<<i;
	ss>>n;
	ss.str("");
	return n;
}
string (*orb)(int i)=shell;
string subshell(int i)
{
	string n;	
	switch(i) {
		case 0:n="s";
			break;
		case 1:n="p";
			break;
		case 2:n="d";
			break;
		case 3:n="f";
			break;
		case 4:n="g";
			break;
		case 5:n="h";
			break;
		case 6:n="i";
			break;
		case 7:n="j";
			break;
		default:n="^";
	}
	return n;
}

string ec(int zn)
{
	string n;
	int i,j,k,l,b,o,x;
	for(l=1,x=1;x<=zn;l++) 
		for(b=1;b<=2&&x<=zn;b++)			
			for(i=1;i<=l&&x<=zn;i++) {
				n+=shell(l+i-((b==2)?0:1));					
				n+=subshell(l-i);				
				for(j=i,o=0;j<=2*l-i&&x<=zn;j++)
					for(k=1;k<=2&&x<=zn;k++,o++,x++);
				n+=orb(o)+" ";				
			}
	return n;
}
int numify(char n)
{
	int i;
	sstream ss;
	ss<<n;
	ss>>i;
	ss.str("");
	return i;
}
int shell_no(int e)
{
	int n=0;
	string s=ec(e);
	for(int i=0;i<s.size();i++) {
		if(n<numify(s[i])) n=numify(s[i]);
		while(s[i]!=' ') i++;		
	}
	return n;
}
main()
{
	/*string a,n;
	ifstream fin("ec.txt");
	getline(fin,a);
	fin.close();
	cout<<a;
	*/
	int e;
	ofstream fout("ec.txt");
	for(e=1;e<=5;e++) {
		fout.seekp(0);		
		fout<<ec(e);		
		ShellExecute( 0,"open","windows graphic.exe",0,0,SW_SHOWNORMAL);				
	}
	fout.close();*/	
}

/*string a,n;
	ifstream fin("ec.txt");
	while(1){		
		fin>>n;
		if(fin.eof()) break;
		a+=n+" ";
	} 
	fin.close();
	cout<<a;*/
