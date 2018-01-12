//mv

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("Wrong input format!");
		return -1;
	}
	
	int source_file = open(argv[1], O_RDONLY);
	if(source_file == -1)
	{
		printf("Could not open the source file!\n");
		return -2;
	}
	
	struct stat source_perm;	
	mode_t bits = 0;
	
	if(stat(argv[1], &source_perm) < 0)
		printf("Could not obtain permissions!\n");
		
	bits = source_perm.st_mode;
	int dest_file = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, bits);
	char buffer[256];
	int count = 0;
	
	while((count = read(source_file, buffer, 256)) > 0)
		write(dest_file, buffer, count);
		
	close(source_file);
	close(dest_file);
	
	remove(argv[1]);
    return 0;
}
