#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("Arrays.txt","w+");

	int l=0;int j;
	int i;int k;	
	for(j=0;j<3;j++)
	{
		printf("Enter the length of the name\n");
		scanf("%d",&l);
		
		char A[l];
        	printf("Enter the name\n");
		for(i=0;i<l;i++)
			scanf(" %c",&A[i]);
		for(k=0;k<l;k++)
			fprintf(fp,"%c",A[k]);
		fprintf(fp,"\nsize of array - %lu bytes\n", sizeof(A));
	}
}
