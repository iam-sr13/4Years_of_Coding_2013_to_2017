//This program displays table of operators.
//by Shriraj

#include<stdio.h>
int main()
{
	int a,b;

	printf("\nPlease enter any two integers: \n");
	scanf(" %d %d",&a,&b);
        printf("\n\n**************************************************************");
	printf("\n Operator\t Precedence\t Associativity\t Examples");
	printf("\n**************************************************************");
	printf("\n   ()    \t     1     \t    L->R      \t    -    ");
	printf("\n ++(prfx)");
	printf("\n --(prfx)");
	printf("\n--------------------------------------------------------------");
	printf("\n   + ");
	printf("\n   - ");
	printf("\n (pofx)++\t     2     \t    R->L      \t    -    ");
	printf("\n (pofx)-- ");
	printf("\n   ~  ");
	printf("\n sizeof()");
	printf("\n--------------------------------------------------------------");
if(!b) {printf("\n   /     \t           \t              \t %d/%d is not defined",a,b);} 
else   {printf("\n   /     \t           \t              \t %d/%d is %d",a,b,a/b);}
	printf("\n   *     \t     3     \t    L->R      \t %d*%d is %d",a,b,a*b);
if(!b) {printf("\n   %%     \t           \t              \t %d %% %d is not defined",a,b);}
else   {printf("\n   %%     \t           \t              \t %d %% %d is %d",a,b,a%b);}
	printf("\n--------------------------------------------------------------");
	printf("\n   +     \t     4     \t    L->R      \t %d+%d is %d",a,b,a+b);
	printf("\n   -     \t           \t              \t %d-%d is %d",a,b,a-b);             
	printf("\n--------------------------------------------------------------");
	printf("\n   <<    \t     5     \t    L->R      \t %d<<%d is %d",a,b,a<<b);
	printf("\n   >>    \t           \t              \t %d>>%d is %d",a,b,a>>b);
	printf("\n--------------------------------------------------------------");
	printf("\n   <     \t           \t              \t %d<%d is %d",a,b,a<b);
	printf("\n   >     \t     6     \t    L->R      \t %d>%d is %d",a,b,a>b);
	printf("\n   <=    \t           \t              \t %d<=%d is %d",a,b,a<=b);
	printf("\n   >=    \t           \t              \t %d>=%d is %d",a,b,a>=b);
	printf("\n--------------------------------------------------------------");
	printf("\n   ==    \t     7     \t    L->R      \t %d==%d is %d",a,b,a==b);
        printf("\n   !=    \t           \t              \t %d!=%d is %d",a,b,a!=b);
	printf("\n--------------------------------------------------------------");
	printf("\n   &     \t     8     \t    L->R      \t %d&%d is %d",a,b,a&b);
	printf("\n--------------------------------------------------------------");
	printf("\n   ^     \t     9     \t    L->R      \t %d^%d is %d",a,b,a^b);
	printf("\n--------------------------------------------------------------");
	printf("\n   |     \t    10     \t    L->R      \t %d|%d is %d",a,b,a|b);
	printf("\n--------------------------------------------------------------");
	printf("\n   &&    \t    11     \t    L->R      \t %d&&%d is %d",a,b,a&&b);
	printf("\n--------------------------------------------------------------");
	printf("\n   ||    \t    12     \t    L->R      \t %d||%d is %d",a,b,a||b);
	printf("\n--------------------------------------------------------------");
	printf("\n   ?:    \t    13     \t    R->L      \t (%d>%d)?%d:%d is %d",a,b,a,b,a>b?a:b);
	printf("\n--------------------------------------------------------------");
	printf("\n  = ");
	printf("\n  += ");
	printf("\n  -= ");
	printf("\n  %%=     \t    14     \t    R->L      \t     - ");
	printf("\n  *= ");
	printf("\n  /= ");
	printf("\n  &= ");
	printf("\n  ^= ");
	printf("\n  |= ");
	printf("\n <<= ");
	printf("\n >>= ");
	printf("\n--------------------------------------------------------------");
	printf("\n  ,       \t    15     \t   L->R       \t     - ");
	printf("\n--------------------------------------------------------------\n\n");

	return 0;
} 





       
