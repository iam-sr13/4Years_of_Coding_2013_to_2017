//cat

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	char *buffer;
	size_t len = 0;
	if(argc == 1)
	{
		while(getline(&buffer, &len, stdin) != -1)
			printf("%s", buffer);
	}
	int arg_count = argc;
	while(arg_count-- > 1)
	{
		int source_file = open(argv[argc - arg_count], O_RDONLY);
		if(source_file == -1)
		{
			printf("Could not open the source file!\n");
			return -2;
		}
		char buffer[256];
		int count = 0;
		while((count = read(source_file, buffer, 256)) > 0)
		{
			int i = 0;
			for(; i < count; i++)
				printf("%c", buffer[i]);
		}
	}
	return 0;
}

