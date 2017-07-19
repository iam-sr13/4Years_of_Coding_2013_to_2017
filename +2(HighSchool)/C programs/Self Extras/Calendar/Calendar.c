#include<stdio.h>
int main()
{
	int d,m,y,c,n,dr,mr,yr,R,a,cd;
	char cho;
	do {
	printf("\n Enter the century from which you want to find what the day is:");
	scanf("%d",&c);	
	printf("\n Enter the date in dd/mm/yy format:");
	scanf("%d/%d/%d",&d,&m,&y);
	dr=d%7;
	mr=(m==1?1:(m==2?4:(m==3?4:(m==4?0:(m==5?2:(m==6?5:(m==7?0:(m==8?3:(m==9?6:(m==10?1:(m==11?4:(m==12?6:m))))))))))));
	yr=(y+(y/4))%7;
	a=19;
	cd=-1;
	n=(a)+(c*cd);
	R=dr+mr+yr+n;
	if(R<0) {
		R%=7;
		R+=7;
	}
	else if(R>0) {
		R%=7;
	}
	if(R==0||R==7) {
		printf("\n The day on %d/%d/%d is Saturday\a.",d,m,y);
	}
	else if(R==1) {
		printf("\n The day on %d/%d/%d is Sunday\a.",d,m,y);
	}
	else if(R==2) {
		printf("\n The day on %d/%d/%d is Monday\a.",d,m,y);
	}
	else if(R==3) {
		printf("\n The day on %d/%d/%d is Tuesday\a.",d,m,y);
	}
	else if(R==4) {
		printf("\n The day on %d/%d/%d is Wednesday\a.",d,m,y);
	}
	else if(R==5) {
		printf("\n The day on %d/%d/%d is Thursday\a.",d,m,y);
	}
	else if(R==6) {
		printf("\n The day on %d/%d/%d is Friday\a.",d,m,y);
	}
	printf("\n\nGame Over!\nDo you want to play Again? (y/n)\nReply: ");
	scanf(" %c",&cho);
	
	}while (cho=='y');
	return 0;	
}
