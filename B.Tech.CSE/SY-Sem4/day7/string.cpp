#include<iostream>
#include<cstring>

using namespace std;

class STRING
{
	friend ostream& operator <<(ostream& out, STRING s);
	
	char* s;
	int sz;
	
	public:
		STRING(char* s1="") {
			sz=strlen(s1);
			s=new char[sz+1];
			strcpy(s,s1);
		}
		
		STRING (const STRING& st) {
			sz=st.size();
			s=new char[sz+1];
			strcpy(s,st.s);
		}
		~STRING() {
			delete[] s;
			sz=0;
		}
		int size() const {return sz;}		
		
		STRING operator +(const STRING& st)
		{
			STRING z(strcat(s,st.s));			
			return z;
		}
};

ostream& operator <<(ostream& out, STRING st)
{
	cout<<st.s;
	return out;
}

int main()
{
	cout<<"\nWelcome to STRING operator overloading!!"<<endl;
	
	STRING s1="NIT";
	cout<<s1<<endl;
	
	STRING s2="GOA";
	cout<<s2<<endl;
	
	STRING s3=s1+s2;
	cout<<s3<<endl;
	
	return 0;
}







/*STRING operator =(char* s1) {
			sz=strlen(s1);
			s=new char[sz+1];
			strcpy(s,s1);
			
			return *this;
		}*/
