#include <stdio.h>
#include <malloc.h>

void scans(char* a) //My own funct for dynamic string size....just one prereq,malloc pointer before passing it to this function.
{
	int i=1;
	char c;
	
	for(; scanf("%c",&c),c!='\n'; i++,realloc(a,i))	a[i-1]=c;	
	a[i-1]=0;			
}

int strlen(char* a)
{
    int c;
    for(c=0;a[c]!='\0';c++);
    return c;
}

int main()
{
    char *a;
    a=(char*)malloc(1);
    
    printf("\nPlease enter any sentence: ");
    scans(a);       
    printf("\n'%s' is your sentence and its length is '%d'.",a,strlen(a));
    
    free(a);
    getch();     
    return 0;
}
