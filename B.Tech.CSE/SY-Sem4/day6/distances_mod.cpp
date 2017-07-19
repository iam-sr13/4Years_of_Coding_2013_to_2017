#include<iostream>
#include<cmath>
using namespace std;

class DB;
class DM
{	
	friend DM conv(DB db);
	friend DB conv(DM dm);
		
	int mt,cm;
	
	public:
	DM(int m=0,int c=0) {
		getData(m,c);
	}	
	
	void getData(int m=0,int c=0)
	{
		mt=m;
		cm=c;
		while(cm>=100) {
			cm-=100;
			mt++;
		}		
	}
	
	void showData()
	{
		cout<<mt<<"m "<<cm<<"cm";
	}
	
	DM add(DM d2)
	{
		DM r(mt+d2.mt,cm+d2.cm);		
		return r;
	}	
};

class DB
{	
	friend DM conv(DB db);
	friend DB conv(DM dm);	
	
	int ft,in;
	
	public:
	DB(int m=0,int c=0) {
		getData(m,c);
	}

	void getData(int m=0,int c=0)
	{	
		ft=m;
		in=c;
		while(in>=12) {
			in-=12;
			ft++;
		}		
	}
	
	void showData()
	{
		cout<<ft<<"' "<<in<<"''";
	}
	
	DB add(DB d2)
	{
		DB r(ft+d2.ft,in+d2.in);		
		return r;
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

DM conv(DB db)
{
	DM dm(db.ft/3.28,db.in*2.54);	
	return dm;
}
DB conv(DM dm)
{
	DB db(dm.mt*3.28,dm.cm/2.54);	
	return db;
}

struct dist
{
	DM dm;
	DB db;		
};
dist add(DM dm, DB db) 
{
	dist D;
	
	D.dm=dm.add(conv(db));
	D.db=conv(D.dm);
	
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
