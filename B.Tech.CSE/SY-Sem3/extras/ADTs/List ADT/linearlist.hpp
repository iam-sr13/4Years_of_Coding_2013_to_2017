#ifndef _LinearList_
#define _LinearList_

#include<iostream>
#include"illpval.hpp"
template<class Type>
class LinearList
{
	public:
		virtual ~LinearList() {}
		virtual bool isempty() const = 0;
		virtual int size() const = 0;
		virtual Type& getValue(int) const = 0;
		virtual int getIndex(const Type&) const = 0;
		virtual void erase(int) = 0;
		virtual void insert(int, const Type&) = 0;
		virtual void output(std::ostream& out) const = 0;
};

template<class Type>
void changeLength(Type*& a, int oldLength, int newLength)
{
	if(newLength<0) throw IPV("New length must be >= 0!!");
	Type* tmp = new Type[newLength];
	
	int num=(oldLength<newLength?oldLength:newLength);
	copy(a,a+num,tmp);
	delete[] a;
	a=tmp;	
}
#endif
