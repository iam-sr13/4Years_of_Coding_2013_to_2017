#include<iostream>
#include<cmath>
using namespace std;

class DM
{
	friend class DB;	
	int mt,cm;
	
	public:
	DM(int m=0,int c=0) {
		getData(m,c);
	}
	DM(float d) {
		getData(d);	
	}	
	/*int mt_(){return mt;}	
	int cm_(){return cm;}*/
	void getData(int m=0,int c=0)
	{
		if(c<0 || c>100) {
			cerr<<"\nInvalid Parameter!! centimeters should be >=0 or <=100 "<<endl;
			c=0;
		}
		mt=m;
		cm=c;
		
	}
	void getData(float d)
	{
		mt=(int)d;
		if(d<0) {
			int c= (abs(d)-abs((int)d))*100;
			cm=c;
		} else {
			int c= (d-(int)d)*100;
			cm=c;
		}			
	}
	void showData()
	{
		cout<<mt<<"m "<<cm<<"cm";
	}
	
};

class DB
{
	friend class DM;	
	int ft,in;
	
	public:
	DB(int m=0,int c=0) {
		getData(m,c);
	}
	DB(float d) {
		getData(d);
	}
	DB(DM z) {		
		float d=(z.mt_()*3.28)+z.cm_()/2.54/100;
		getData(d);	
	}
	/*int ft_(){return ft;}	
	int in_(){return in;}*/
	int getData(int m=0,int c=0)
	{
		if(c<0 || c>12) {
			cerr<<"\nInvalid Parameter!! inches should be >=0 or <=12 "<<endl;
			return -1;
		}
		ft=m;
		in=c;		
		return 0;
	}
	void getData(float d)
	{
		ft=(int)d;
		if(d<0) {
			int c= (abs(d)-abs((int)d))*100;
			in=c;
		} else {
			int c= (d-(int)d)*100;
			in=c;
		}		
	}
	void showData()
	{
		cout<<ft<<"' "<<in<<"''";
	}
	
	DB add(DB d2)
	{
		DB r;		
		r.ft=ft+d2.ft;
				
		int i=in+d2.in;
		while(i>=12) {
			i-=12;
			r.ft++;
		}
		r.in=i;
		
		return i;
	}
};

ostream& operator <<(ostream& out, DM dm)
{
	dm.showData();
	return out;
}
ostream& operator <<(ostream& out, DB db)
{
	db.showData();
	return out;
}

struct dist
{
	DM dm;
	DB db;		
};

dist add(DM dm, DB db) 
{
	dist D;
	
	DB db2(dm),r;		
	r=db.add(db2);	
	D.db=r;	
		
	float d=(r.ft_()/3.28)+r.in_()*2.54/100;
	DM dm2(d);
	D.dm=dm2;
	
	return D;
}

int main()
{
	int a,b;	
	do{
		cout<<"\nLets play with distances!!\nPlease enter length in meters with cm part(>=0 & <=100) seperately: ";
		cin>>a>>b;
	}while(b<0 || b>100);	
	DM dm(a,b);	
	do{
		cout<<"Now,\nPlease enter length in feets with inches part(>=0 & <=12) seperately: ";
		cin>>a>>b;
	}while(b<0 || b>12);
	DB db(a,b);
	
	cout<<"\nYour distances:-\ndm= "<<dm<<"\ndb= "<<db<<endl; 
	
	dist res=add(dm,db);
	
	cout<<"\nNow, dm + db = "<<res.dm<<" = "<<res.db;
	
	return 0;
}
