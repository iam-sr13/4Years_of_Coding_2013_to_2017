#include <iostream>
#include <string.h>
#include <fstream>
#include <malloc.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct element
{
	int seat_no,avail,window;
	char name[30],contact[10];
	struct element *next,*previous;
};
typedef struct element node;

class bus
{
	node* start;
	public:
	bus(){start=NULL;}
	void creation();
	void book();
	int availability(node*);
	void ticket(int,node*);
	void menu();	
};
void bus:: menu()
{
	int m;
	do {
		cout<<"1:TO LOGIN;\n2:FOR RESERVATION;\n3:TO EXIT;";
		cin>>m;
		switch(m)	{
			case 1:creation();break;
			case 2:book();break;
			default: m=0;
		}
	}
	while(m);
}
void bus::creation()
{
	char bn[10],driver[30],arrival[10],departure[10],journey[30];
	start=(node*)malloc(sizeof(node));	
	node *ptr=start;
	ptr->next=NULL;
	fstream a;
	a.open("issue.dat",ios::out);
	cout<<"enter bus no.=";
	cin.ignore();
	cin.getline(bn,10);
	a<<bn<<endl;
	cout<<"Enter the drivers name=";
	cin.getline(driver,30);
	a<<driver<<endl;
	cout<<"Arrival=";
	cin.getline(arrival,10);
	a<<arrival<<endl;
	cout<<"Departure=";
	cin.getline(departure,10);
	a<<departure<<endl;
	cout<<"Journey=";
	cin.getline(journey,30);
	a<<journey<<endl;
	cout<<"enter the seat number and if it is a window seat enter 1 if not 0 in orderly manner"<<endl;
	cin>>ptr->seat_no>>ptr->window;
	ptr->avail=1; 
	a<<ptr->seat_no<<" "<<ptr->window<<endl;	
	ptr->next=(node*)malloc(sizeof(node));
	for(int i=1;i<5;i++) {
		ptr=ptr->next;
		cin>>ptr->seat_no>>ptr->window;
		ptr->avail=1;
		a<<ptr->seat_no<<" "<<ptr->window<<endl;		
		ptr->next=(node*)malloc(sizeof(node));
	}
	a.close();
}
int bus::availability(node*temp)
{
	if(temp->avail)	return(1);
	else return(0);
}
void bus::book()	
{
	int c,n;
	char nam[30],co[10];
	cout<<"THE SEATS WHITCH ARE AVAILABLE ARE"<<endl;	
	node *ptr=start;
	for(int i=1;i<=5;i++)	{
		if(availability(ptr))		{
			cout<<ptr->seat_no<<endl;
			c++;
		}
		ptr=ptr->next;
	}
	cout<<"enter the no. of seats to be booked"<<endl;
	cin>>n;
	if(n<=c)
	{
		ptr=start;
		for(int i=1;i<=n;i++) {
			for(;ptr!=0;){if(!availability(ptr)) ptr=ptr->next; else break; }
			
			ptr->avail=0;
			cout<<"enter your name and contact no."<<endl;
			cin.ignore();
			cin.getline(nam,30);
			cin.getline(co,10);
			
				strcpy(ptr->name,nam);
				strcpy(ptr->contact,co);			
				ptr=ptr->next;			
			
		}
		ticket(n,start);
	}
	else
	cout<<"NO. OF SEATS TO BE BOOKED ARE MORE THAN AVAILABLE"<<endl;	
}

void bus::ticket(int r,node *ptr)
{
	fstream a;
	char bn[10],driver[30],arrival[10],departure[10],journey[30]; 
	a.open("issue.dat",ios::in);	
	cout<<"ticket to be printed"<<endl;
	cout<<"\t\tRUSHAB & KASHINATH TRAVELS"<<endl;
	cout<<"date:12.01.2015"<<endl;
	while(a.getline(bn,10)&&a.getline(driver,30)&&a.getline(arrival,10)&&a.getline(departure,10)&&a.getline(journey,30))
	{
		cout<<"bus no:"<<bn<<endl;
		cout<<"driver:"<<driver<<endl;
		cout<<"arrival:"<<arrival<<endl;
		cout<<"departure:"<<departure<<endl;
		cout<<"journey:"<<journey<<endl;
	}
	cout<<"***************************************************"<<endl;
	cout<<"|seat no|               name           |contact no|"<<endl;
	for(int i=1;i<=r;i++){
		cout<<"|"<<setw(7)<<ptr->seat_no<<"|"<<setw(30)<<ptr->name<<"|"<<setw(10)<<ptr->contact<<"|"<<endl;
		ptr=ptr->next;
	}
	cout<<"\t\tTHANK YOU"<<endl;
	cout<<"\t\tHAVE A SAFE JOURNEY"<<endl;
	a.close();
}

int main()
{
	bus kashinath;
	kashinath.menu();
	return 0;
}

