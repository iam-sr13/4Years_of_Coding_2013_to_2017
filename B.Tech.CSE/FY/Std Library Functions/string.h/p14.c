#include <stdio.h>
#include <malloc.h>

int scans(char* a) //My own funct for dynamic string size....just one prereq,malloc pointer before passing it to this function.
{
	int i=1;
	char c;
	
	for(; scanf("%c",&c),c!='\n'; i++,realloc(a,i))	a[i-1]=c;	
	a[i-1]=0;
	
	return i-1; //returns size of array a.			
}

int strncmp(char* s1,char* s2,int n)
{
	int i=0;
	for(;s1[i]==s2[i] && s1[i]!='\0' && i<n-1;i++);
	return ((s1[i]>s2[i])?1:(s1[i]<s2[i]?-1:0));
}

int main()
{
    char *a,*b;    
    a=(char*)malloc(1);
    b=(char*)malloc(1);  
    int n;
    
    printf("\nPlease enter any sentence: ");
    scans(a);    
    
    printf("\nPlease enter another sentence: ");    
    scans(b);
	printf("\nNow enter the no. of characters of first sentence to be compared with second one: ");
	scanf("%d",&n);    
    
    printf("\nThe value of strncmp is: %d",strncmp(a,b,n));    
    
    free(a),free(b);
    getch();     
    return 0;
}
