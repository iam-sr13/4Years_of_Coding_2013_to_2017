#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


getkey()
{
	int ch = getch();

    if ( ch == 0 || ch == 224 )
      ch = 256 + getch();

  return ch;

}


int main()
{
	int c;
	char a;
	do {
		printf("\nENTER any key:");
		c=getkey();
		printf("\n\nThe key has %d scan code.",c);
		a=pas("\n\nTest Again? : ");
	}
	while(a=='y');
	return 0;
}
int pas(char c1[])
{
	char d;
	printf("\n%s",c1);
	scanf(" %c",&d);
	return d;
}
