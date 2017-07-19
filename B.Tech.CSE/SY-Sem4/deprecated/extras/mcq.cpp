#include<iostream>
using namespace std;
/*struct a
{
	int count;
};
struct b
{
	int* value;
};

struct c:public a,public b
{
};
*/

class Top
{
	public: 
	Top(){cout<<"\nstartTop\n"; MyMemory();}
	virtual void MyMemory(){cout<<"mymem()"<<endl;}
	void Disk(){cout<<"disk()"<<endl;}
	void Erased(){cout<<"erased()"<<endl;}
	void thisExam(){Erased(); MyMemory();}
	virtual ~Top(){}
};
class Bottom:public Top
{
	public: 
	void MyMemory(){cout<<"mymemBot()"<<endl;}
	void Disk(){cout<<"diskBot()"<<endl;}
	void virtual Erased(){cout<<"erasedBot()"<<endl;}
	void thisExam(){Erased(); MyMemory();}	
};

/*class class1
{
	public: int a;
};

class1& func(int a)
{
	class1* p=new class1();
	return p;
}*/

/*class top
{
	public:
		int a;
		top(int x){a=x;}
};
class bottom:public top
{
	public:
		int b;
		bottom():top(5){a=0;b=0;}
};*/

/*class base
{
	int arr[10];
};

class b1:public base{};
class b2:public base{};
class derived:public b1,public b2{};*/

/*class top
{
	public:
		
		top(){cout<<"\nstartTop";}
		~top(){cout<<"\nendTop";}
};
class bottom:public top
{
	public:
		bottom(){cout<<"\nstartBot";}
		~bottom(){cout<<"\nendBot";}
};
class test
{
	public:
	bottom deal;
	test(){cout<<"\nstartTest";	}
};*/

/*class A
{
	public:
		A(){this->foo();}
		virtual void foo()=0;//{cout<<"\nA::foo()";}
};
class B:public A
{
	public:
		B(){this->foo();}
		virtual void foo(){cout<<"\nB::foo()";}
};*/

int main()
{

	/*cout<<sizeof(base)<<" "<<sizeof(b1)<<" "<<sizeof(b2)<<" "<<sizeof(derived)<<" ";*/	
	
	Top* ob=new Bottom;
	ob->MyMemory();
	ob->Disk();
	ob->thisExam();
	
	Top obj=*(new Bottom);
	obj.MyMemory();
	obj.Disk();
	obj.thisExam();
	
	/*Top ob2;
	Bottom ob3;	
	
	bottom bar;
	cout<<bar.a<<bar.b;*/
	
	
	
	return 0;
}
