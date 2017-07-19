#include<iostream>
#include<cstdlib>
#define CLR system("clear") 

using namespace std;

void getch(){cin.ignore().ignore();}

template<class T>
class Queue
{
	T* q;
	int n,front,rear;	
	
	public:
	Queue(int x=0) {
		n=x;
		front=rear=0;
		if(n>0){
			q=new T[n];
		}
	}
	~Queue() {
		if(n>0) delete[] q;
		n=0;
		front=rear=0;
	}
	void renew(int x)
	{
		if(n>0) delete[] q;
		n=x;
		front=rear=0;
		if(n>0){
			q=new T[n];
		}
	}
	
	void enqueue(T x)
	{
		if(rear<n) {
			q[rear]=x;
			rear++;
		}
		else{
			throw "QUEUE OVERFLOW!!";
		}
	}
	T dequeue()
	{
		if(rear>0) {
			for(int i=1;i<n;i++) q[i-1]=q[i];
			rear--;
			cout<<"\nPopped value: "<<q[front];
			return q[front];
		}
		else{
			throw "QUEUE UNDERFLOW!!";
		}
	}
	
	int size(){return rear;}
	void show()
	{
		cout<<"{ ";
		for(int i=0;i<rear;i++){
			cout<<q[i];
			if(i<rear-1) cout<<" <- ";
		} 
		cout<<" }";
	}	
};

template<class T>
ostream& operator <<(ostream& out, Queue<T>& z)
{
	z.show();
	return out;
}

int main()
{
	int n,ch;
	string typ;
	
	cout<<"\nLets play with queues....\nEnter the max size of your queue: "; cin>>n;
	
	do{
		CLR;
		cout<<"\n#MAIN MENU\n\n1.Type\n2.Quit\n\nYour choice: "; cin>>ch;
		
		switch(ch){
			case 1: {
				cout<<"\n1.Int\n2.Double\n\nYour choice: "; cin>>ch;
				switch(ch){
					case 1: {
						int x;						
						Queue<int> z(n);
						
						do{
							CLR;
							cout<<"\n#QUEUE MENU\n\nYour Queue: "<<z<<"\n\n1.Enqueue\n2.Dequeue\n3.Back\n\nYour choice: "; cin>>ch;
							switch(ch) {
								case 1:{
									cout<<"\nEnter any integer: "; cin>>x;
									try{z.enqueue(x);}
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 2:{
									try{z.dequeue(); }
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 3:{
									break;
								}
								default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
							}
						}while(ch!=3);
						
						break;
					}
					case 2: {
						double x;
						Queue<double> z(n);
						
						do{
							CLR;
							cout<<"\n#QUEUE MENU\n\nYour Queue: "<<z<<"\n\n1.Enqueue\n2.Dequeue\n3.Back\n\nYour choice: "; cin>>ch;
							switch(ch) {
								case 1:{
									cout<<"\nEnter any integer: "; cin>>x;
									try{z.enqueue(x);}
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 2:{
									try{z.dequeue();}
									catch(char const* e){cout<<endl<<e<<endl; getch();}
									break;
								}
								case 3:{
									break;
								}
								default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
							}
						}while(ch!=3);
						
						break;
					}
					
					default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
				}
				break;
			}
			case 2: {
				break;
			}
			default: cout<<"\nINVALID CHOICE!! Please try again....\n"; getch();
		}
	}while(ch!=2);		
	
	return 0;
}
