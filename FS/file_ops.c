#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 100

int main(void)
{
	int fin, fout;
	int n;
	char buf[SIZE];
	fin = open("foo", O_RDONLY | O_CREAT, 0644);
	if(fin < 0)
	{
		perror("foo");
		exit(1);
	}
	
	fout = open("bar", O_WRONLY | O_CREAT, 0644);
	if(fin < 0)
	{
		perror("bar");
		exit(1);
	}
	while((n = read(fin, buf, SIZE)) > 0)
	{
		write(fout, buf, n);
	}
	
	lseek(fout, SIZE, SEEK_END);
	write(fout, "XXXXX", 5);
	
	close(fin);
	close(fout);

	return 0;
}
