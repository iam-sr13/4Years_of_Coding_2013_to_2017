#include<iostream>
#include"illpval.hpp"
#define dotry do{try
#define }done  continue;}break;}while(true)

int main()
{
	int n;
	
	do{try{
		std::cout<<"\nEnter a positive no: "; cin>>n;
		if(n<=0) throw illegalParameterValue("Number must be strictly positive, i.e n>0!!");
	}
	catch(IPV e)
	{
		e.msgout();
		
		continue;}break;}while(true);
	
	cout<<"\nThank you for entering "<<n<<endl;
	
	return 0;
}

/*
 
 dotry{
 
 }
 catch(type e)
 {
 
 }done;
 
 */
