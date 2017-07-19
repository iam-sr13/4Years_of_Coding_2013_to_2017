#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define CLR (system("cls"))

int getkey()
{
	int ch = getch();

    if ( ch == 0 || ch == 224 )
      ch = 256 + getch();

  return ch;	
}

void swap(int *a,int *b)
{
	int t;
	
	t=*a;
	*a=*b;
	*b=t;
}

void file(int d) 
{	 
    FILE *fptr; 
    char name[20];         
    
    fptr = fopen ("hall of fame2.txt", "a");
    if (fptr == NULL) 
    { 
      printf("\n\nFile does not exists \n"); 
      return; 
    } 
    printf("\nEnter your name: "); 
    scanf("%s",&name);
    if(1) fprintf(fptr,"\n\t\t\t******HALL OF FAME******\n\n NAME\t\t\t\tRANKING\t\t\t\tMoves\n ____\t\t\t\t_______\t\t\t\t_____\n\n");	   
    
    fprintf(fptr, "\n>) %s\t\t\t\t",name);    
    switch(d) {
    	case 1:fprintf(fptr,"Novice");
    			break;
    	case 2:fprintf(fptr,"Impresso");
    			break;
    	case 3:fprintf(fptr,"Hell Fire"); 
    			break;
    }
	 
	printf("\n\nCheck out the Hall of Fame menu for seeing the people \nwho had won this game.");	      
    fclose(fptr);    
 }
 
void fileop() 
{ 
    FILE *fptr; 
    char ch;
    CLR;
    fptr = fopen ("hall of fame2.txt", "r"); 
    if (fptr == NULL) 
    { 
      printf("\n\nCannot open file\n"); 
      exit(0); 
    } 
    ch = fgetc(fptr); 
    while (ch != EOF) 
    { 
      printf ("%c", ch); 
      ch = fgetc(fptr); 
    } 
    fclose(fptr); 
    printf("\n\nPress enter to return to main menu");
    getch();
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

void arracc(int *a,int *n)
{
	int i;
	*n=ipas("\nEnter the size of the array: ");	
	for(i=0;i<*n;i++) {
		printf("\n\nEnter the %d element of the array: ",i+1);
		scanf(" %d",(a+i));
	}
	printf("\n\nThis is your array: ");
	for(i=0;i<*n-1;i++) printf("%d,",*(a+i));
	printf("%d.",*(a+*n-1));
}

void selsort(int n,int *a)
{	
	int i,j,k,sml,pos;
	for(i=0;i<n-1;i++) {
		pos=i+1;
		sml=*(a+pos);		
		for(j=i+2;j<n;j++) 	if(*(a+j)<sml) { sml=*(a+j); pos=j;}
		if(*(a+i)>*(a+pos)) {
			k=*(a+i);
			*(a+i)=*(a+pos);
			*(a+pos)=k;
		}
	}
}

void linear_sort(int n,int *a)
{
	int i,j;
	for(i=0;i<n-1;i++) 
		for(j=i+1;j<n;j++) 
			if(*(a+i)>*(a+j))
		    swap((a+i),(a+j));
}

void binsearch(int n,int x,int *a)
{
	int low,high,mid;
	for(low=0,high=n-1;low<=high;) {
		mid=(low+high)/2;
		if(*(a+mid)==x) {			
			printf("\nThe no. %d is present at the location %d.",x,mid+1);
			break;
		}
		else if(x>*(a+mid))
			low=mid+1;
			else 
			high=mid-1;
	}
	if(low>high) printf("\nNOT FOUND!!");
}

void disparr(int n,int *a)
{
	int i;
	for (i=0;i<n;i++)
		printf("\n %d",*(a+i));
}

void scanarr(int n,int *a)
{
	int i;
	for (i=0;i<n;i++) 
		scanf("%d", &a[i]);
}

void dispcount(char c[],int n,int *a)
{
	int i,j,k;
	printf("\n%s",c);
	for(i=0,k=1;i<n-1;i++) { 
		for(j=i+1;j<n;j++) 
			if(*(a+i)==*(a+j)) {
				k++;
				i++;
			}
		printf("\n\n==> The number '%d' has occured '%d' times in the array.",*(a+i),k);
		k=1;
	}
}

void scan2arr(int r,int c,int *a)
{
	int i,j;
	for(i=0;i<=r-1;i++) 
		for(j=0;j<=c-1;j++)
			scanf(" %d",(a+i*c+j));
}
void disp2arr(int r,int c,int *a)
{	
	int i,j;
	printf("\n");
	for(i=0;i<=r-1;i++) {
		for(j=0;j<=c-1;j++)
			printf(" %d",*(a+i*c+j));
		printf("\n");
	}
}


