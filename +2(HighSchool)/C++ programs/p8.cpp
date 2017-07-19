#include<iostream>

using namespace std;

main()
{
	int i,c,a;
	
    //for(i=1;i<=26;i++,a++) cout<<a<<endl;	
	

	for(a=0,c=0;c<=127;c++,a++) {cout<<"'"<<(char)(2*a)<<"'"<<" ";}
		
    for(a=0,c=127;c<=255;c++,a++) {cout<<"'"<<(char)(2*a-1)<<"'"<<" ";}	
}

