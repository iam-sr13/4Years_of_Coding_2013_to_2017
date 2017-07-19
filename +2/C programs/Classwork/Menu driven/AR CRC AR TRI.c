#include<stdio.h>
int main()
{
	int c,r,b,h;
	float a;
	do{
		printf("\n1:Area of Circle\n2:Area of Triangle\n0:Exit");
		printf("\n Enter your choice:");
		scanf("%d",&c);
		if(c==1){
			printf("\n Enter radius:");
			scanf("%d",&r);
			a=22*r*r/7.0;
			printf("\n Ar of circle=%f",a);
		}
		else if(c==2) {
			printf("\n Enter base & height:");
			scanf("%d %d",&b,&h);
			a=b*h/2.0;
			printf("\n Ar of triangle=%f",a);
		}
		else if(c!=0) {
			printf("\n INCORRECT CHOICE!!");
			printf("\n PROGRAM WILL END...\n");
		}
	}while(c!=0&&c<3);
	return 0;
}
			
	
