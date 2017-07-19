#include<stdio.h>
int main()
{		
	int choice,pos,n,x,i,j,k,a[n];	
	char replay;
	reset:
	do {
		choice=ipas("Welcome to ins and del program on array!\n\n\n1)Insertion \n\n2)Insertion(position) \n\n3)Deletion \n\n4)Selection Sorting\n\nYour choice: ");
		switch(choice) {
			case 1: printf("\n\nNote: Please enter array in ascending order!\n\n");
					
					n=ipas("\nEnter the size of the array: ");
					for(i=0;i<n;i++) {
						printf("\n\nEnter the %d element of the array: ",i+1);
						scanf(" %d",(a+i));
					}
					printf("\n\nThis is your array: ");
					for(i=0;i<n-1;i++) printf("%d,",*(a+i));
					printf("%d.",*(a+n-1));
					reset2:
					x=ipas("\nEnter the value you want to insert in your array: ");
					for(i=n-1;a[i]>=x && i>=0;i--) a[i+1]=a[i];
					a[i+1]=x;
					n++;
					printf("\nThis is the new array: ");
	                for(i=0;i<n;i++) printf("\n%d.",*(a+i));
					replay=cpas("\nWant to insert one more element? : ");
					if(replay=='y') goto reset2;					
					break;
			case 2: 
					n=ipas("\nEnter the size of the array: ");
					for(i=0;i<n;i++) {
						printf("\n\nEnter the %d element of the array: ",i+1);
						scanf(" %d",(a+i));
					}
					printf("\n\nThis is your array: ");
					for(i=0;i<n-1;i++) printf("%d,",*(a+i));
					printf("%d.",*(a+n-1));
					reset3:
					x=ipas("\nEnter the value you want to insert in your array: ");					
					pos=ipas("\nEnter the position where you want to insert the element: ");
					for(i=n-1;i>=pos-1;i--) a[i+1]=a[i];
					a[i+1]=x;
					n++;
					printf("\nThis is the new array: ");
					for(i=0;i<n;i++) printf("\n%d.",*(a+i));
					replay=cpas("\nWant to insert one more element? : ");
					if(replay=='y') goto reset3;					
					break;
			case 3:
					n=ipas("\nEnter the size of the array: ");
					for(i=0;i<n;i++) {
						printf("\n\nEnter the %d element of the array: ",i+1);
						scanf(" %d",(a+i));
					}
					printf("\n\nThis is your array: ");
					for(i=0;i<n-1;i++) printf("%d,",*(a+i));
					printf("%d.",*(a+n-1));
					reset4:
					x=ipas("\nEnter the value you want to delete from your array: ");
					for(i=0;i<n;i++) {
						if(a[i]==x) for(j=i;j<n;j++) a[j]=a[j+1];
						break;
					}
					n--;
					printf("\nThis is the new array: ");
					for(i=0;i<n;i++) printf("\n%d.",*(a+i));
					replay=cpas("\nWant to delete one more element? : ");
					if(replay=='y') goto reset4;
					break;
			case 4:
					n=ipas("\nEnter the size of the array: ");
					for(i=0;i<n;i++) {
						printf("\n\nEnter the %d element of the array: ",i+1);
						scanf(" %d",(a+i));
					}
					printf("\n\nThis is your array: ");
					for(i=0;i<n-1;i++) printf("%d,",*(a+i));
					printf("%d.",*(a+n-1));
					for(i=0;i<n-1;i++) 												
						 for(j=i+1;j<n;j++) if(a[i]>a[j]) {						
												k=a[i];
												a[i]=a[j];
												a[j]=k;
											}
						
												
					printf("\nThis is the sorted array: ");
					for(i=0;i<n;i++) printf("\n%d.",*(a+i));
					break;
			default: printf("\nInvalid Choice!!"); goto reset;
		}
		replay=cpas("Again?: ");	
	}
	while(replay=='y');
	return 0;
}

int ipas(char c[])
{
	int scan;
	printf("\n%s",c);
	scanf(" %d",&scan);
	return scan;
}

int cpas(char c[])
{
	char scan;
	printf("\n%s",c);
	scanf(" %c",&scan);
	return scan;
}
