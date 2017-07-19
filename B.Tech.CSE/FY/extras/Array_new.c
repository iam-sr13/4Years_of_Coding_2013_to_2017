#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("Arrays_new.txt","w+");
	char A[25];
	int l=0;int j;
	int i;int k;	
	for(j=0;j<3;j++)
	{
		printf("Enter the length of the name\n");
		scanf("%d",&l);
		

        	printf("Enter the name\n");
		for(i=0;i<l;i++)
			scanf(" %c",&A[i]);
		for(k=0;k<l;k++)
			fprintf(fp,"%c",A[k]);
		fprintf(fp,"\nsize of array - %lu bytes\n", sizeof(A));
	}
}
