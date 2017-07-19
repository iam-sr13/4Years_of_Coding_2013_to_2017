#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int myprintf(char* a, ...)
{
	int n=0,i,j,k;
	char cp[10];
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='%' && a[i+1]=='d') n++;
	}
	
	va_list p;
	va_start(p,n);
	
	i=0;
	
	for(k=0;k<n;k++)
	{
		while(a[i]!='%')
		{
			putc(a[i],stdout);
			i++;
		}
		
		j=va_arg(p,int);
		
		puts(j);
		
		i=i+2;
		
	}
	
	va_end(p);
}

int main()
{
	int m=1309;
	
	myprintf("\nThe no. is %d.",m);
	
	return 0;
	
}
