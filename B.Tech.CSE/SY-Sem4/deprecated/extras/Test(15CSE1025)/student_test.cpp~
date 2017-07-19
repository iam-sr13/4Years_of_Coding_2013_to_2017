#include<iostream>
#include<string.h>
using namespace std;
#define NO_OF_STUDENTS 3

void swap(int &num1, int &num2)
{
	num1 += num2;
	num2 -= num2;
	num1 -= num2; 
}

class student
{
	private:
		string rollNo, name;
		float testMarks[3], betterAvg;
	public:
		student()
		{
			testMarks[0] = testMarks[1] = testMarks[2] = 0;
			betterAvg = 0;
		}
		
		void getData();			
		void printData()
		{
			cout<<"Roll No.: "<<rollNo<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Average (out of 100): "<<betterAvg<<endl<<endl;
		}

		void getAvg()
		{
			for(int i = 0; i < 2; i++)
			{
				for(int j = 0; j < 2 - i; j++)
				{
					if(testMarks[j] > testMarks[j+1])
						swap(testMarks[j], testMarks[j+1]);
				}
			}
			
			betterAvg = (testMarks[1] + testMarks[2]) / 2;
		}		
};


void student :: getData()
{
	//ROLL_NO
	cout<<"Roll No.: ";
	cin>>rollNo;
	//NAME
	cout<<"Name: ";
	cin>>name;
	//Test marks
	for(int i = 0; i < 3; i++)
	{
		float totalMarks = 0;
		do
		{	
			cout<<"Total Marks of test "<<i + 1<<" : ";
			cin>>totalMarks;
			if (totalMarks <= 0)
				cout<<"Total Marks is a positive quantity! Try Again!"<<endl;
		}while(totalMarks <= 0);
			
		do
		{	
			cout<<"Obtained Marks of test "<<i + 1<<" : ";
			cin>>testMarks[i];
			if (testMarks[i] < 0 || testMarks[i] > totalMarks)
				cout<<"Obtained Marks is a non-negative quantity! Try Again!"<<endl;
		}while(testMarks[i] < 0 || testMarks[i] > totalMarks);
	
		testMarks[i] = 100 * testMarks[i] / totalMarks;
	}

	getAvg();
}
int main()
{
	//NO_OF_STUDENTS is 10
	student studentData[NO_OF_STUDENTS];
	
	for(int i = 0; i < NO_OF_STUDENTS; i++)
	{
		cout<<"Enter Details of student "<<i + 1<<endl;
		studentData[i].getData();
	}

	for(int i = 0; i < NO_OF_STUDENTS; i++)
	{
		cout<<"Details of student "<<i + 1<<endl;
		studentData[i].printData();
	}
	return 0;
}
