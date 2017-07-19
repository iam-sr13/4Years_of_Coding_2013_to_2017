#include<iostream>
#include<string.h>
using namespace std;

class date
{
	private:
		int day, month, year;
		int totalDays[12];
	public:
		date()
		{
			day = 1;
			month = 1;
			year = 0;
			for(int i = 0; i < 12; i++)
				totalDays[i] = 30 + (i % 2 == 0);
			totalDays[1]--;
			totalDays[7]++;
			totalDays[8]--;
			totalDays[9]++;
			totalDays[10]--;
			totalDays[11]++;
		}
		
		date(const date &d)
		{
			day = d.day;
			month = d.month;
			year = d.year;
			for(int i = 0; i < 12; i++)
				totalDays[i] = d.totalDays[i];
		}

		void getData();	
		int operator- (date);
		date operator+ (int);
		bool operator== (const date& d2)
		{
			return d2.day == day && d2.month == month && d2.year == year;
		}	
	
		bool operator> (const date& d)
		{
			if(year > d.year)
				return 1;
			else if(month > d.month)
				return 1;
			else if(day > d.day)
				return 1;
			else
				return 0;
		}

		date operator= (const date& d)
		{
			day = d.day;
			month = d.month;
			year = d.year;
			for(int i = 0; i < 12; i++)
				totalDays[i] = d.totalDays[i];
			return *this;
		}

		friend ostream& operator<<(ostream& , const date& );
};

void date :: getData()
{
	string d;
	bool errorFlag = 0;
	do
	{
		errorFlag = 0;
		cout<<"Date: ";
		cin>>d;
		if((d.size() != 10) || ((d.size() == 10) && (d[2] != '/' || d[5] != '/')))
		{
			errorFlag = 1;
			cout<<"Wrong date format! It should be dd/mm/yyyy\n";
		}
		else
		{
			year = (d[6] - 48) * 1000 + (d[7] - 48) * 100 + (d[8] - 48) * 10 + d[9] - 48;
			//Negative year implies BC
			if(year % 4 != 0)
				totalDays[1]--;

			month = (d[3] - 48) * 10 + d[4] - 48;
			if(month > 12 || month <= 0)
			{
				errorFlag = 1;
				cout<<"Month should be between 1 to 12. Try Again!\n";
			}

			else
			{
				day = (d[0] - 48) * 10 + d[1] - 48;
				if(day <= 0 || day > totalDays[month - 1])
				{
					errorFlag = 1;
					cout<<"Day should be in range 1 to "<<totalDays[month - 1]<<". Try Again!\n";
				}
			}
			if(errorFlag == 1 && year % 4 != 0)
				totalDays[1]++;		
		}
	}while(errorFlag);
}

int date :: operator- (date d2)
{
	int noOfDays = 0;
	if(*this > d2 || *this == d2)
	{
		while(!(*this == d2))
		{
			d2.day++;
			if(d2.day > d2.totalDays[d2.month - 1])
			{
				d2.day = 1;
				d2.month++;
				if (d2.month > 12)
				{
					d2.month %= 12;
					d2.year++;
					if(d2.year % 4 == 1)
						d2.totalDays[1]--;
					else if(d2.year % 4 == 0)
						d2.totalDays[1]++;
				}
			}
			noOfDays++;
		}
		return noOfDays;
	}
	cout<<"Date 1 less than Date 2. Try Again!\n";
	return -1;
}

date date :: operator+ (int noOfDays)
{
	date d = *this;

	while(noOfDays != 0)
	{
		if(noOfDays > 0)
		{
			d.day++;
			if(d.day > d.totalDays[d.month - 1])
			{
				d.day = 1;
				d.month++;
				if (d.month > 12)
				{
					d.month %= 12;
					d.year++;
					if(d.year % 4 == 1)
						d.totalDays[1]--;
					else if(d.year % 4 == 0)
						d.totalDays[1]++;
				}
			}
			noOfDays--;
		}
		else
		{
			d.day--;
			if(d.day == 0)
			{
				d.month--;
				if (d.month == 0)
				{
					d.month = 12;
					d.year--;
					if(d.year % 4 == 3)
						d.totalDays[1]--;
					else if(d.year % 4 ==0)
						d.totalDays[1]++;
				}
				d.day = d.totalDays[d.month - 1];
			}
			noOfDays++;
		}
	}
	return d;
}

ostream& operator<<(ostream& output, const date& d)
{
	output<<"Date: "<<d.day<<" / "<<d.month<<" / "<<d.year<<endl;
	return output;
}

int main()
{
	date d1, d2, d3;
	d1.getData();
	cout<<"Date 1 ";
	cout<<d1<<endl;

	//cout<<"Date 2 should be less than date 1\n";
	d2.getData();
	cout<<"Date 2 ";
	cout<<d2<<endl;

	int noOfDays = d1 - d2, numDays = 0;
	if(noOfDays >= 0)
	{
		cout<<"Number of Days: "<<noOfDays<<endl<<endl;
		cout<<"Numer of days to be added: ";
		cin>>numDays;
		d3 = d1 + numDays;
		cout<<"Date 3 ";
		cout<<d3<<endl;
	}
	return 0;
}
