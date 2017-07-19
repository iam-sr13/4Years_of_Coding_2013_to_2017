//header for basically manipulating cursor positions and string colors
#ifndef _CPOS
#define _CPOS
#include<windows.h>
#include"linked list.hpp"
#define BF FOREGROUND_BLUE 
#define GF FOREGROUND_GREEN
#define RF FOREGROUND_RED 
#define IF FOREGROUND_INTENSITY 
#define BB BACKGROUND_BLUE 
#define GB BACKGROUND_GREEN 
#define RB BACKGROUND_RED 
#define IB BACKGROUND_INTENSITY
#define PF BF|RF
#define YF GF|RF
#define AF BF|GF
#define PB BB|RB
#define YB GB|RB
#define AB BB|GB

#define BD BB|BF
#define GD GB|GF
#define RD RB|RF
#define PD BB|RB|BF|RF
#define YD GB|RB|GF|RF
#define AD BB|GB|BF|GF
#define ID IB|IF

#define WF BF|GF|RF
#define WB BB|GB|RB
#define WD WF|WB 

using namespace std;

struct UD_COORD //defined to extend the usability of COORD
{
    SHORT X;
    SHORT Y;
    void operator=(int x)
    {
    	X=Y=x;
    }
    void operator=(COORD k)
    {
    	X=k.X;
    	Y=k.Y;
    }
    void operator=(UD_COORD k)
    {
    	X=k.X;
    	Y=k.Y;
    }
    bool operator==(COORD z)
    {
    	if(X==z.X && Y==z.Y) return true;
    	else return false;
    }
    bool operator==(UD_COORD z)
    {
    	if(X==z.X && Y==z.Y) return true;
    	else return false;
    }
    bool operator!=(COORD z)
    {
    	if(X!=z.X || Y!=z.Y) return true;
    	else return false;
    }
    bool operator!=(UD_COORD z)
    {
    	if(X!=z.X || Y!=z.Y) return true;
    	else return false;
    }
};
class position // main purpose is to record the positions of what is displayed in screen to mouse control them
{
	public:
	llist<UD_COORD> pos;	
		void push(const COORD& z)
		{
			UD_COORD temp;
			temp=z;
			pos.push(temp);	
			if(pos.size()==2) fill();	//therfore try to record only two positions!!!(to optimze time and memory)			
		}
		void push(const UD_COORD& z)
		{
			pos.push(z);
			if(pos.size()==2) fill();	
		}
		void fill()
		{			
			int x=pos[1].X,y=pos[1].Y;   //refining needed
			for(int i=pos[0].X;i<=x;i++)
				for(int j=pos[0].Y;j<=y;j++) {
					COORD temp={i,j};
					push(temp);                      //earlier if(*this!=temp) push(temp)
				}									
		}
		void flush() //to empty recorded pos
		{
			pos(0);
		}
		bool operator==(const UD_COORD& z)
		{				
			for(int i=0;i<pos.size();i++) if(pos[i]==z) return true;			
			return false;
		}
		bool operator==(const COORD& z)
		{				
			for(int i=0;i<pos.size();i++) if(pos[i]==z) return true;			
			return false;
		}
		bool operator!=(const COORD& z)
		{				
			for(int i=0;i<pos.size();i++) if(pos[i]==z) return false;			
			return true;
		}
		bool operator==(position& z)
		{				
			for(int i=0;i<pos.size();i++) if(pos[i]!=z.pos[i]) 	return false;		
			return true;
		}
		bool operator!=(position& z)
		{				
			for(int i=0;i<pos.size();i++) if(pos[i]!=z.pos[i]) 	return true;		
			return false;
		}
		friend ostream& operator<<(ostream& out, position& pos);		
};
class setcurs //manip of gotoxy
{
	COORD cursor;
	public:		
	setcurs(COORD t) {cursor=t;}
	setcurs(UD_COORD t) {cursor.X=t.X; cursor.Y=t.Y;}
	setcurs(short x, short y){cursor.X=x; cursor.Y=y;}
	friend ostream& operator<<(ostream& out, setcurs cur);	
};
class setcolor //manip to change colorof text and bckgrnd
{
	WORD color;	
	void setcol()
	{
		HANDLE OutputH;
		OutputH = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(OutputH, this->color);
	}
	public:
	setcolor(WORD t) {color=t;}
	friend ostream& operator<<(ostream& out, setcolor col);
	friend ostream& resetcolor(ostream& out);	
};
void gotoxy(short x, short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void gotoxy(COORD z)
{
	COORD pos=z;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
COORD wherexy() //returns present pos of cursor
{
	COORD scpos;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi)) scpos.X=scpos.Y=-1;
	else{
		scpos=csbi.dwCursorPosition;
	}
	return scpos;
}
SHORT cX() {return wherexy().X;}
SHORT cY() {return wherexy().Y;}


ostream& operator<<(ostream& out, position& pos)  // overlded to use as manip
{
	pos.push(wherexy());
	return out;
}
ostream& operator<<(ostream& out, setcurs cur)
{
	gotoxy(cur.cursor);
	return out;
}
ostream& operator<<(ostream& out, setcolor col)
{
	col.setcol();
	return out;
}
ostream& resetcolor(ostream& out)
{
	setcolor col(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	col.setcol();
	return out;
}
#endif
