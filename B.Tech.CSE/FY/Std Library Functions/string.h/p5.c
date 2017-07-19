#include <stdio.h>
#include<malloc.h>
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
    int n;
    char *a,*b;
    a=(char*)malloc(1);
        
    printf("\nPlease enter any sentence: ");
    b=(char*)malloc(scans(a));
    printf("\nType no. of characters to be copied from your sentence: ");
    scanf("%d",&n);
    strncpy(b,a,n);   
    printf("\nYou typed: %s.\nCopied: %s.",a,b);
    
    free(a),free(b);
    getch();     
    return 0;
}
