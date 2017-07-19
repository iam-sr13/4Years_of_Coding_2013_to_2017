#include<iostream>
#include<iomanip>
#include<cstdlib>
#define CLR (system("clear"))

using namespace std;

class Vector
{
	float* v;
	int dim;
	
	public:
	Vector(int d=0) {
		init(d);
	}
	Vector(Vector& vec) {
		init(vec.dim);
		for(int i=0;i<vec.dim;i++) {
			v[i]=vec.v[i];
		}
	}
	~Vector() {
		delete[] v;
	}
	
	void init(int d=0)
	{
		dim=d;
		v=0;
		if(dim) {
			v=new float[dim];
		}
	}	
	void getData(float* a,int sz)
	{
		init(sz);
		for(int i=0;i<sz;i++) {
			v[i]=a[i];
		}
	}
	void create()
	{
		int d;		
		cout<<"\nPlease enter dimension: "; cin>>d;
		init(d);
		cout<<"\nNow please enter vector values one by one:\n";
		for(int i=0;i<dim;i++) {
			cin>>v[i];
		}
	}
	void modify(float a,int i)
	{
		if(i<0 || i>=dim) cout<<"\nInvalid component!!\n";
		else v[i]=a;
	}
	void multiscalar(int n)
	{
		for(int i=0;i<dim;i++) {
			v[i]*=n;
		}
	}
	void showData()
	{
		cout<<" _  _"<<endl;
		for(int i=0;i<dim;i++) {
			if(i<dim-1)cout<<"| "<<setw(2)<<v[i]<<" |"<<endl;
			else cout<<"|_"<<setw(2)<<v[i]<<"_|"<<endl;
		}		
	}
	float dot(Vector &vec)
	{
		float r=0;
		int sz=(dim<vec.dim)?dim:vec.dim;		
		for(int i=0;i<sz;i++) {
			r+=v[i]*vec.v[i];
		}
		return r;
	}
	bool normalto(Vector &vec)
	{
		if(dot(vec)==0) return true;
		else return false;
	}
	void operator =(Vector &vec)
	{
		init(vec.dim);
		for(int i=0;i<vec.dim;i++) {
			v[i]=vec.v[i];
		}
	}
};

ostream& operator <<(ostream& out, Vector d)
{
	d.showData();
	return out;
}

int main()
{
	int ch,i;
	float f;
	Vector v1,v2;
	do {
		CLR;
		cout<<"\nWelcome to VECTORS program...!!\n\n#MAIN MENU\n\n1. Create Vectors\n2. Modify Vectors\n3. Multiply Scalar\n4. Display Vectors\n5. Dot Product\n6. Perpendicular\n7. Quit\n\nYour Choice: ";
		cin>>ch;
		switch(ch) {
			case 1:{
				cout<<"\nFor v1:\n";
				v1.create();
				cout<<"\nFor v2:\n";
				v2.create();
				break;
			}
			case 2:{
				CLR;
				cout<<"\n1. v1 \n2. v2 \n3. Back\n\nYour Choice: "; cin>>ch;
				switch(ch) {
					case 1: {
						cout<<"\nEnter new value: ";cin>>f;
						cout<<"\nEnter component index: ";cin>>i;						
						v1.modify(f,i);
						break;
					}
					case 2: {
						cout<<"\nEnter new value: ";cin>>f;
						cout<<"\nEnter component index: ";cin>>i;						
						v2.modify(f,i);
						break;
					}
					case 3: {
						break;
					}
					default: cout<<"\n\nINVALID CHOICE!!\n\n"; cin.ignore();
				}
				break;
			}
			case 3:{
				CLR;
				cout<<"\n1. v1 \n2. v2 \n3. Back\n\nYour Choice: "; cin>>ch;
				switch(ch) {
					case 1: {
						cout<<"\nEnter a scalar: "; cin>>i;
						v1.multiscalar(i);
						break;
					}
					case 2: {
						cout<<"\nEnter a scalar: "; cin>>i;
						v1.multiscalar(i);
						break;
					}
					case 3: {
						break;
					}
					default: cout<<"\n\nINVALID CHOICE!!\n\n"; cin.ignore();
				}
				break;
			}
			case 4:{
				cout<<"\nYour Vectors:\nv1=\n"<<v1<<"\nv2=\n"<<v2; cin.ignore().ignore();				
				break;
			}
			case 5:{
				cout<<"\nv1.v2= "<<v1.dot(v2); cin.ignore().ignore();
				break;
			}
			case 6:{
				if(v1.normalto(v2)) cout<<"\nv1 is perpendicular to v2!!";
				else cout<<"\nv1 is not perpendicular to v2!!";
				cin.ignore().ignore();
				break;
			}
			case 7:{
				break;
			}
			default: cout<<"\n\nINVALID CHOICE!!\n\n"; cin.ignore();
		}
	}while(ch!=7);
	return 0;
}
