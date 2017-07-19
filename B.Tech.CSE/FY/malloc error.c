//Sample code for error of malloc ....by shriraj
/*Here i simply allocate memory to a pointer inside another function and assign values to each.
Then it prints values correctly in getdata() i.e the function in which i allocate it.
But when i return to main, the program stops if i try to print. i.e when i return to main
the allocated memory must have got free somehow. But why?
Doesn't malloc uses heap which must remain active throughout program?
Or does it uses stack? (which seems to be reason for this error according to me.)

Please help me Ma'am....*/

#include<stdio.h>
#include<malloc.h>

void putdata(int*,int);
int* getdata(int);

int main()
{
	int *a,n;
		
	printf("\nPlease enter the size of your list: ");
	scanf("%d",&n);
	
	a=getdata(n);
	
	printf("\n\nNow printing inside main()\n");		
	putdata(a,n);	
	
	return 0;
}

int* getdata(int n)
{	
	int *a,i;
	
	a=(int*)malloc(n*sizeof(int));
	
	printf("\nPlease enter the elements of your list:\n");
	for(i=0;i<n;i++) scanf("%d",a+i);	
	
	printf("\nNow printing inside getdata()\n");
	putdata(a,n);
	
	return a;
}

void putdata(int* a,int n)
{
	int i;
	printf("\nThis is your list:\n");
	for(i=0;i<n;i++) {
		printf("%d",a[i]);
		if(i<n-1) printf(", ");
		else printf(".");
	}
}


