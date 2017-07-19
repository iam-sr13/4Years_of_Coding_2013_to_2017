#include <stdio.h>
#include <malloc.h>
#include <string.h>

int scans(char* a) //My own funct for dynamic string size....just one prereq,malloc pointer before passing it to this function.
{
	int i=1;
	char c;
	
	for(; scanf("%c",&c),c!='\n'; i++,realloc(a,i))	a[i-1]=c;	
	a[i-1]=0;
	
	return i-1; //returns size of array a.			
}

int main()
{
    char *a,*b;
	a=(char*)malloc(1); 
	b=(char*)malloc(1);    
    
    printf("\nPlease enter any sentence: ");
    scans(a);    
    printf("\nPlease enter another sentence: ");
    //fflush(stdin);
    realloc(a,strlen(a)+scans(b));
    
    strcat(a,b);
    printf("\nThe concatenated statement is: %s",a);    
    
    free(a),free(b);
    getch();     
    return 0;
}
