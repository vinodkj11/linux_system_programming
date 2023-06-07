#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgQ.h"

int main(void)
{
	struct msgbuf msg[3] = {
		{1,"MSG1"},
		{1,"MSG11"},
		{2, "MSG2"}
		};
	key_t key;
	int msgid;
	key = ftok(pathname, proj_id); 
	msgid = msgget(key, 0666|IPC_CREAT);
	if(msgid < 0)
	{
		printf("Failed to create msgq %d\n",errno);
		exit(0);
	}

	for(int i = 0; i<3; i++)
	{
		if(msgsnd(msgid, (void*)&msg[i], strlen(msg[i].mtext) + 1, 0) < 0)
			perror("msgsend");
		else
			printf("%s msg of type: %ld sent\n",msg[i].mtext, msg[i].mtype);
	}
	msgctl(key, IPC_RMID, NULL);

	return 0;
}
