#include<iostream>
using namespace std;

int main()
{
	unsigned int i=0,l=0;
	string s,t;
	
	cout<<"\nThis is a test program for strings, please enter any one line sentence: "<<endl;
	getline(cin,s);	
	for(;i<s.size();i++) if(isalpha(s[i])) break;
	for(;i<s.size();i++) if(isspace(s[i])||ispunct(s[i])) break;
	for(;i<s.size();i++) if(isalpha(s[i])) break;	
	for(;i<s.size();i++) {
		if(isalpha(s[i])||s[i]=='\'') l++,t.push_back(s[i]);
		else break;
	}
	char a[l+4];
	for(i=0;i<l;i++) a[i]=t[i];
	a[i++]='(';
	a[i++]=(char)l+48;
	a[i++]=')';
	a[i]='\0';
	cout<<"\nThe second word is: "<<a;
	
	return 0;
}

/*if(s.find(' ') < s.find('\t')) {
		t=s.substr(s.find(' ')+1);
		if(t.find(' ') < t.find('\t'))	s=t.substr(0,t.find(' '));
		else s=t.substr(0,t.find('\t'));
		cout<<s<<"("<<s.size()<<")"<<endl;
	}
	else{
		t=s.substr(s.find('\t')+1);		
		if(t.find(' ') < t.find('\t'))	s=t.substr(0,t.find(' '));
		else s=t.substr(0,t.find('\t'));
		cout<<s<<"("<<s.size()<<")"<<endl;
	}*/
	
	/*char *a=new char[s.size()+5];
	unsigned int i;
	for(i=0;i<s.size(); i++) {
		a[i]=s[i];
	}	
	a[i++]='(';
	a[i++]=(char)s.size();
	a[i]=')';*/
