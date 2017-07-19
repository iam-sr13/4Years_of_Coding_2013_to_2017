#ifndef _ILLPVAL_
#define _ILLPVAL_

#include <iostream>
using namespace std;

class illegalParameterValue
{
	string message;
	
	public:
		illegalParameterValue() : message("Illegal Parameter Detected!") {}
		illegalParameterValue(string message) {
			this->message=message;
		}
		void msgout()
		{
			cout<<message<<endl;
		}
};

typedef illegalParameterValue IPV;

#endif
