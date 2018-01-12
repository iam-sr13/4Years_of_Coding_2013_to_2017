//ls

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	char *cur_dir = NULL;
	DIR *dp = NULL;
	
	struct dirent *dptr = NULL;
	
	 //for pwd
	if(argc == 1)
	{
		cur_dir = getenv("PWD");
		if(cur_dir == NULL)
		{
			printf("Could not get Present Working Directory! Please try again!");
			return -1;
		}
		dp = opendir(cur_dir);
		if(dp == NULL)
		{
			printf("Could not open Present Working Directory! Please try again!");
			return -2;
		}
		while((dptr = readdir(dp)) != NULL)
			printf("%s ", dptr->d_name);
		printf("\n");
		
		closedir(dp);
	}

	else if(argc == 2)
	{
		cur_dir = argv[1];
		dp = opendir(cur_dir);
		if(dp == NULL)
		{
			printf("Could not open Present Working Directory!");
			return -3;
		}
		while((dptr = readdir(dp)) != NULL)
			printf("%s\n", dptr->d_name);
		printf("\n");
		
		closedir(dp);
	}

	else
	{
		printf("Wrong input!");
		return -4;
	}
	return 0;
}
