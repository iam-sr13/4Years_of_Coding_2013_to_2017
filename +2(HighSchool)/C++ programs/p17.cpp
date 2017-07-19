#include<iostream>
#include<fstream>

using namespace std;

main()
{
	fstream o; int k=1;
	o.open("f2.txt",ios::out);
	o<<"Test1whhhssdh\ntest2wthhets.";
	o.close();
	o.open("f2.txt",ios::in);
	
	char s;
	if(o.eof()) cout<<"e!!";
	while(s!='\n') {
		o.get(s);		
		cout<<"\n "<<s<<" "<<o.tellg()<<" "<<o.tellp();		
		
				
	}
	o.seekg(-20,ios::end);k=0;
	o.get(s);
	cout<<"\n "<<s<<" "<<o.tellg()<<" "<<o.tellp();	
	
	if(o.fail()) cout<<"err!!";
}
