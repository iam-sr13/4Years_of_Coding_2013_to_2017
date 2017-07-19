#include<iostream>
#include<iomanip>
#include<conio.h>
#include<algorithm>
#define CLR (system("cls"))

using namespace std;

class queue
{
	int* q,front,rear,size,capacity;
	
	public:
		queue(int xcapacity = 10)
		{
			capacity = xcapacity;
			front=rear=size=0;
			q = new int[capacity];
		}
		~queue()
		{
			front=rear=size=capacity=0;
			delete[] q;
		}
		
		int qSize()
		{
			return size;
		}
		bool isEmpty()
		{
			if(size==0) return true; else return false;
		}
		
		void qPush(int x)
		{
			if(rear==capacity){
				cout<<"\nQueue Full!!"<<endl;
				getch();
			} 
			else {
				q[rear++]=x;
				size++;
			}
		}
		void qPop()
		{
			if(size==0) cout<<"\nQueue Empty!!"<<endl;
			else {
				for(int i=0;i<size-1;i++) q[i]=q[i+1];
				rear--;
				size--;
			}
		}
		
		int frontElem()
		{
			return q[front];
		}
		int rearElem()
		{
			return q[rear-1];
		}
		void show()
		{
			for(int i=0;i<size;i++)
			{
				cout<<q[i];
				if(i<size-1) cout<<", ";
				else cout<<".";
			}
		}
};

int main()
{
	int c,n;		
	queue msg;	
	
	do{
		CLR;
		cout<<"\nWELCOME to Queue Program!\n\nYour Queue: "; msg.show(); 
		cout<<"\n\n# Main Menu\n\n1.Insert\n2.Delete\n3.Size\n4.IsEmpty\n5.Front\n6.Rear\n7.Show\n8.Exit\n\nYour Choice: "; cin>>c;
		
		switch(c){
			case 1:{
				cout<<"\nEnter any integer: "; cin>>n;
				msg.qPush(n);				
				break;
			}
			case 2:{
				if(msg.isEmpty()) {
					cout<<"\nQueue Empty!!"<<endl; 
				}
				else{
					n=msg.frontElem();
					msg.qPop();
					cout<<"\nDeleted Element: "<<n<<endl;
				} 
				getch();
				break;
			}
			case 3:{
				cout<<"\nSize: "<<msg.qSize();
				getch();
				break;
			}
			case 4:{
				if(msg.isEmpty()) {
					cout<<"\nQueue Empty!!"<<endl; 
				}
				else cout<<"\nQueue is NOT empty!!"<<endl;
				getch();
				break;
			}
			case 5:{
				cout<<"\nFront Element: "<<msg.frontElem();
				getch();
				break;
			}
			case 6:{
				cout<<"\nRear Element: "<<msg.rearElem();
				getch();
				break;
			}
			case 7:{
				cout<<endl;
				msg.show();
				getch();
				break;
			}
			case 8:{
				break;
			}
			default: cout<<"\nInvalid Choice!!"; getch();
		}		
	}while(c!=8);	
	
	return 0;
}


//cout<<"\nWELCOME to Queue Program!\n Please Enter size of your queue: "; cin>>n;









