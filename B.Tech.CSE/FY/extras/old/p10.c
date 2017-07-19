//This program displays table of operators.
//by Shriraj

#include<stdio.h>
int main()
{
	int a,b;
	FILE *fp;
	fp=fopen("operator.txt","w+");

	printf("\nPlease enter any two integers: \n");
	scanf(" %d %d",&a,&b);
        fprintf(fp,"\n\n**************************************************************");
	fprintf(fp,"\n Operator\t Precedence\t Associativity\t Examples");
	fprintf(fp,"\n**************************************************************");
	fprintf(fp,"\n   ()    \t     1     \t    L->R      \t    -    ");
	fprintf(fp,"\n ++(prfx)");
	fprintf(fp,"\n --(prfx)");
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   + ");
	fprintf(fp,"\n   - ");
	fprintf(fp,"\n (pofx)++\t     2     \t    R->L      \t    -    ");
	fprintf(fp,"\n (pofx)-- ");
	fprintf(fp,"\n   ~  ");
	fprintf(fp,"\n sizeof()");
	fprintf(fp,"\n--------------------------------------------------------------");
if(!b) {fprintf(fp,"\n   /     \t           \t              \t %d/%d is not defined",a,b);} 
else   {fprintf(fp,"\n   /     \t           \t              \t %d/%d is %d",a,b,a/b);}
	fprintf(fp,"\n   *     \t     3     \t    L->R      \t %d*%d is %d",a,b,a*b);
if(!b) {fprintf(fp,"\n   %%     \t           \t              \t %d %% %d is not defined",a,b);}
else   {fprintf(fp,"\n   %%     \t           \t              \t %d %% %d is %d",a,b,a%b);}
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   +     \t     4     \t    L->R      \t %d+%d is %d",a,b,a+b);
	fprintf(fp,"\n   -     \t           \t              \t %d-%d is %d",a,b,a-b);             
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   <<    \t     5     \t    L->R      \t %d<<%d is %d",a,b,a<<b);
	fprintf(fp,"\n   >>    \t           \t              \t %d>>%d is %d",a,b,a>>b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   <     \t           \t              \t %d<%d is %d",a,b,a<b);
	fprintf(fp,"\n   >     \t     6     \t    L->R      \t %d>%d is %d",a,b,a>b);
	fprintf(fp,"\n   <=    \t           \t              \t %d<=%d is %d",a,b,a<=b);
	fprintf(fp,"\n   >=    \t           \t              \t %d>=%d is %d",a,b,a>=b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   ==    \t     7     \t    L->R      \t %d==%d is %d",a,b,a==b);
        fprintf(fp,"\n   !=    \t           \t              \t %d!=%d is %d",a,b,a!=b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   &     \t     8     \t    L->R      \t %d&%d is %d",a,b,a&b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   ^     \t     9     \t    L->R      \t %d^%d is %d",a,b,a^b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   |     \t    10     \t    L->R      \t %d|%d is %d",a,b,a|b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   &&    \t    11     \t    L->R      \t %d&&%d is %d",a,b,a&&b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   ||    \t    12     \t    L->R      \t %d||%d is %d",a,b,a||b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n   ?:    \t    13     \t    R->L      \t (%d>%d)?%d:%d is %d",a,b,a,b,a>b?a:b);
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n  = ");
	fprintf(fp,"\n  += ");
	fprintf(fp,"\n  -= ");
	fprintf(fp,"\n  %%=     \t    14     \t    R->L      \t     - ");
	fprintf(fp,"\n  *= ");
	fprintf(fp,"\n  /= ");
	fprintf(fp,"\n  &= ");
	fprintf(fp,"\n  ^= ");
	fprintf(fp,"\n  |= ");
	fprintf(fp,"\n <<= ");
	fprintf(fp,"\n >>= ");
	fprintf(fp,"\n--------------------------------------------------------------");
	fprintf(fp,"\n  ,       \t    15     \t   L->R       \t     - ");
	fprintf(fp,"\n--------------------------------------------------------------\n\n");
	fclose(fp);
	printf("\n\nYour output is saved to file named 'operator.txt'.\n\n");
	return 0;
} 





       
