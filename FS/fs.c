#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#define sDIR 100

int main(void)
{
	char buf[sDIR];
	DIR *dir;
	struct dirent *dirent;

	printf("Current Dir is: %s\n", getcwd(buf, sDIR));
	dir = opendir(buf);
	
	while((dirent = readdir(dir)) != NULL)
			{
		printf("Directory Name: %s\n Length of Dir:%d\n  type : %c\n", dirent->d_name, dirent->d_reclen, dirent->d_type);
		printf("inode: %u\n", dirent->d_ino);
	}

	return 0;
}
