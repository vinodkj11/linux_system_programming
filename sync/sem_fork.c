#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <assert.h>
#define SEM_NAME "mysem"

int main(int argc, char **argv)
{
    int fd, i, nloop; 
    char *ptr = NULL;
    sem_t  *mutex;
    if (argc != 3)
    {
       printf("usage: bin  <filename to open no.of loops>");
       exit(0);
    }
     nloop=atoi(argv[2]); 
      /* open file, initialize to 0, map into memory */
     fd = open(argv[1], O_RDWR | O_CREAT, 0666);
     printf("fd %d\n",fd);
     write(fd,"0",nloop); 
     ptr = (char*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
     assert(ptr != NULL);
     printf("mmap %p\n",ptr);
     close(fd);
     /* create, initialize, and unlink semaphore */
     mutex = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
     printf("Sem created\n");
     sem_unlink(SEM_NAME);
     setbuf(stdout, NULL);       /* stdout is unbuffered */
     pid_t pid = fork();
     if(pid == 0){          /* child */
     for (i = 0; i < nloop; i++) {
	     printf("In child mutex count: %d\n", *(int *)mutex);
         sem_wait(mutex);
//	 *ptr = '1' + i;
         printf("child reading:%c\n",*ptr);
	 ptr++;
         sem_post(mutex);
	     printf("In child mutex count: %d\n", *(int *)mutex);
     }
     exit(0);
     }
     if (pid != 0) {      
     /*parent*/
     for (i = 0; i < nloop; i++) {
	     printf("In parent mutex count: %d\n", *(int *)mutex);
        sem_wait(mutex);
	*ptr = 'a'+i;
        printf("parent written: %c\n",*ptr); 
	ptr++;
        sem_post(mutex);
	     printf("In parent mutex count: %d\n", *(int *)mutex);
     }
     exit(0);
    }
    return 0;
}
