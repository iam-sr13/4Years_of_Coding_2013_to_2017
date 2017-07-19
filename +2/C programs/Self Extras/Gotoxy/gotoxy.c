#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	int x,y;
	char r;
	do {
		x=ipas("\nEnter x: ");
		y=ipas("\nEnter y: ");
		gotoxy (x,y);
		getch();
		r=cpas("\n\n\nAgain? (y/n)\n\nYour Choice: ");
	}
	while(r=='y');
	return 0;
}

int ipas(char c[])
{
	int d;
	printf("\n%s",c);
	scanf(" %d",&d);
	return d;
}

int cpas(char c[])
{
	char d;
	printf("\n%s",c);
	scanf(" %c",&d);
	return d;
}	
