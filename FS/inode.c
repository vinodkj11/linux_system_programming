#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	struct stat st;
	char *cdir = getcwd(NULL, 0);
	printf("%s\n",cdir);
	int ret = stat(cdir, &st);

	if(ret == 0)
	{
		printf("MODE: %d\n", st.st_mode);
	}
	return 0;
}
