#include<iostream>
#include<algorithm>
#include<conio.h>
#include<sstream>
#include"adtlist.hpp"
#define CLR (system("cls"))

using namespace std;

class llist : public ADTList
{
	friend ostream& operator<<(ostream& out,llist& l);
	friend istream& operator>>(istream& in,llist& l);
	protected:
		int* element;
		int length, capacity;
	public:
		//constructor and destructor
		llist(int c=10)
		{
			element = NULL;
			operator()(c);
		}
		~llist() {
			delete[] element;
		}
		//ADTfunctions
		bool isempty() const;
		int size() const;
		int& getValue(int) const;
		int getIndex(const int&) const;
		void erase(int);
		void insert(int, const int&);
		void ins(int&);
		void output(std::ostream& out) const;
		//extra functions
		bool chkindex(int p,int x=0) const{
			if(p<0 || p>=length+x) {
				stringstream s;
				s<<"Index 'i' must be greater than or equal to 0 and less than or equal to "<<length<<" !";
				string str;
				getline(s,str);				
				throw IPV(str.c_str());
				return false;
			}
			else return true;
		}
		void operator()(int c)
		{
			if(c<1) throw IPV("Capacity must be a positive integer!");
			else {
				capacity=c;
				length=0;
				if(element!=NULL) delete[] element;
				element=new int[capacity];
			}
		}		
};

bool llist::isempty() const
{
	return !length;
}
int llist::size() const
{
	return length;
}
int& llist::getValue(int p) const
{
	if(chkindex(p))	return element[p];
	else return element[0];	
}
int llist::getIndex(const int& val) const
{
	int indx=(int)(find(element,element+length,val)-element);
	if(indx==length) return -1;
	else return indx;
}
void llist::erase(int p)
{
	if(chkindex(p)) {
		copy(element+p+1,element+length,element+p);
		length--;
		if(length<=(capacity/2)) changeLength(element,capacity,capacity/2),capacity/=2;
	}
}
void llist::insert(int p,const int& x)
{
	if(chkindex(p,1)) {
		if(length==capacity) changeLength(element,capacity,capacity*2),capacity*=2;		
		copy_backward(element+p,element+length,element+length+1);
		element[p]=x;			
		length++;
	}
}
void llist::ins(int& x)
{
	if(length==capacity) changeLength(element,capacity,capacity*2),capacity*=2;		
	element[length++] = x;
}
void llist::output(ostream& out) const
{
	for(int i=0;i<length;i++) {
		out<<element[i];
		if(i<length-1) out<<", ";
		else out<<".";
	}
}

ostream& operator<<(ostream& out,llist& l)
{
	l.output(out);
	return out;
}
istream& operator>>(istream& in,llist& l)
{
	int t;
	in>>t;
	l.ins(t);
	return in;
}


int main()
{
	int c,el,pos;
	llist mylist;
	
	do{try{ 
		cout<<"\nWELCOME to LinearList Program!\n\nCREATING YOUR LIST....\n\nPlease enter no. of elements: ";
		cin>>c;
		mylist(c);		
	}
	catch(IPV e)
	{		
		e.msgout();
		getch();
		CLR;
		continue;
	}break;}while(true); 
	
	cout<<"\nNow enter values one by one:\n";
	for(int i=0;i<c;i++) cin>>mylist;
	
	do{
		CLR;
		cout<<"\nWELCOME to LinearList Program!\n\n#Main Menu:\n\nYour List: "<<mylist<<"\n\n1.Insert Element\n2.Erase Element\n3.Quit\n\nYour choice: ";
		cin>>c;
		
		switch(c) {
			case 1:{
				cout<<"\nPlease enter any integer value: "; cin>>el;
				cout<<"\nPlease enter position: "; cin>>pos;
				try{mylist.insert(pos,el);}
				catch(IPV e){
					e.msgout();
					getch();
				}
				
				break;
			}
			case 2:{
				cout<<"\nPlease enter position: "; cin>>pos;
				try{mylist.erase(pos);}
				catch(IPV e){
					e.msgout();
					getch();
				}
				
				break;
			}
			case 3:{				
				break;
			}
			default: cout<<"\nWrongChoice!!";getch();				
		}		
	}while(c!=3);
	
	return 0;
}
