#include<stdio.h>
#include<conio.h>

int main()
{
	char result;
	printf("Note:-{press enter on your keyboard for next instruction or just do\nwhat the computer says}\n");
	printf("\nHello,I am Shriraj's PC.\n");
	getch();	
	printf("\nNow I am going to show you a magic trick.\n");
	getch();	
	printf("\nIn the following exercise enter 'y' for yes and 'n' for no.\n");
	getch();	
	printf("\nAssume any single digit number in your mind.\nDon't reveal it to me.\n");
	getch();
	printf("\nIs the number assumed by you present in this set?\n{4,7,0,2,5}\n(press 'y' or 'n')\n");

	scanf(" %c",&result);
	
	if (result=='n') {
		printf("\nIs the number assumed by you present in this set?\n{9,6,5,8,1}\n(press 'y' or 'n')\n");
		
		scanf(" %c",&result);
		
		if (result=='n') {
			printf("\nThe number assumed by you is '3'");
		}
			else if (result=='y') {
				printf("\nIs the number assumed by you present in this set?\n{8,5,3,6,1}\n(press 'y' or 'n')\n");
				
				scanf(" %c",&result);
				
				if (result=='n') {
					printf("\nThe number assumed by you is '9'");
				}
				 else if (result=='y') {
					printf("\nIs the number assumed by you present in this set?\n{4,9,6,7,1}\n(press 'y' or 'n')\n");
					 
					scanf(" %c",&result);
				
					if (result=='n') {
					printf("\nThe number assumed by you is '8'");
				}
				else if (result=='y') {
					printf("\nIs the number assumed by you present in this set?\n{1,3,4,9,0}\n(press 'y' or 'n')\n");
					
					scanf(" %c",&result);
				
					if (result=='n') {
					printf("\nThe number assumed by you is '6'");
				}
				else if (result=='y') {
					printf("\nThe number assumed by you is '1'");
				}
			}
		}
	}
}
else if (result=='y') {
	printf("\nIs the number assumed by you present in this set?\n{2,4,6,8,0}\n(press 'y' or 'n')\n");

	scanf(" %c",&result);
	
	if (result=='n') {
		printf("\nIs the number assumed by you present in this set?\n{5,3,2,9,0}\n(press 'y' or 'n')\n");
		
		scanf(" %c",&result);
	
		if (result=='n') {
			printf("\nThe number assumed by you is '7'");
				}
				else if (result=='y') {
					printf("\nThe number assumed by you is '5'");
				}
			}
			else if (result=='y') {
				printf("\nIs the number assumed by you present in this set?\n{9,5,0,3,1}\n(press 'y' or 'n')\n");
				
				scanf(" %c",&result);
				
				if (result=='n') {
					printf("\nIs the number assumed by you present in this set?\n{9,3,8,6,2}\n(press 'y' or 'n')\n");
					
					scanf(" %c",&result);
					
					if (result=='n') {
						printf("\nThe number assumed by you is '4'");
					}
					else if (result=='y') {
						printf("\nThe number assumed by you is '2'");
					}
				}
				else if (result=='y') {
					printf("\nThe number assumed by you is '0'");
					}
				}
			}
			return 0;
		}
