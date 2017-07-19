#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void Recur (char *str1, char *str2, char *iStr, int m,
                    int n, int i)
{
    
    if (m==0 && n==0)
        cout<<iStr<<endl; 
    
    if (m != 0)
    {
        iStr[i] = str1[0];
        Recur (str1 + 1, str2, iStr, m-1, n, i+1);
    } 
    
    if (n != 0)
    {
        iStr[i] = str2[0];
        Recur(str1, str2+1, iStr, m, n-1, i+1);
    }
}
 

void printInter (char *str1, char *str2, int m, int n)
{
   
   char *iStr= (char*)malloc((m+n+1)*sizeof(char));   
   iStr[m+n] = '\0';   
   Recur (str1, str2, iStr, m, n, 0);   
   free(iStr);
}
 

int main()
{
	string s1,s2;
	cout<<"\nEnter s1: "; cin>>s1;
	cout<<"\nEnter s2: "; cin>>s2;
    
    printInter ((char*)s1.c_str(), (char*)s2.c_str(), s1.size(), s2.size());
    return 0;
}
