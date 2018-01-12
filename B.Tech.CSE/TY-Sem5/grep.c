//grep

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[100];
    char *newline;
    int count = 0, occ = 0;

    
    if (argc < 3) {
      printf("Not enough command line parameters given!\n");
      return 3;
    } 

    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
      printf("File could not be opened, found or whatever, errno is %d\n",errno);
      return 3;
    } 


    while (fgets(fline, 100, fp) != NULL) {
        count++;
        if ((newline = strchr(fline, '\n')))
            *newline = '\0';
        if (strstr(fline, argv[2]) != NULL) {
            
            printf("%s %d %s\n", argv[1], count, fline);
            occ++;
        }
    }
    
    printf("\n Occurence= %d \n", occ);

    return 1;
}


/* #include <stdio.h>
#define MAXLINE 1000 // maximum input line length 

int Getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";   // pattern to search for 

// find all lines matching pattern 
int main()
{
    char line[MAXLINE];
    int found = 0;
    while (Getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

// getline:  get line into s, return length 
int Getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// strindex:  return index of t in s, -1 if none 
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
} */
