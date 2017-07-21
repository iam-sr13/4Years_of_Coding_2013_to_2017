#include<stdio.h>
int n;
print(char c[])
{
	printf("%s",c);
}
scan()
{
	scanf(" %d",&n);
}
disp(char c)
{
	printf("%c",c);
}
int main()
{
	int i,j,k;
	print("Enter Value: ");
	scan();
	for(i=1;i<=n;i++) {
		for(k=1;k<=n-i;k++) disp(' ');
		for(j=1;j<=2*i-1;j++) disp('*');
		printf("\n");
	}
	return 0;
}
	
	
