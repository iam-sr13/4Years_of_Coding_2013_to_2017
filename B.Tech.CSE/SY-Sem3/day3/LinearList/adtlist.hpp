#ifndef _ADTList_
#define _ADTList_

#include<iostream>
#include"illpval.hpp"

class ADTList
{
	public:
		virtual ~ADTList() {}
		virtual bool isempty() const = 0;
		virtual int size() const = 0;
		virtual int& getValue(int) const = 0;
		virtual int getIndex(const int&) const = 0;
		virtual void erase(int) = 0;
		virtual void insert(int, const int&) = 0;
		virtual void output(std::ostream& out) const = 0;
};

//template<class Type>
void changeLength(int*& a, int oldLength, int newLength)
{
	if(newLength<0) throw IPV("New length must be >= 0!!");
	int* tmp = new int[newLength];
	
	int num=(oldLength<newLength?oldLength:newLength);
	copy(a,a+num,tmp);
	delete[] a;
	a=tmp;	
}
#endif
