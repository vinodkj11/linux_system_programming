#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgQ.h"

int main(void)
{
	struct msgbuf msg;
	int type[3] = {1,2,1};
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
		memset(&msg, 0, sizeof(msg));
		if(msgrcv(msgid, &msg, sizeof(msg.mtext)+1, type[i], 0) < 0)
			perror("msgrcv failed");
		printf("%s msg of type: %d received\n",msg.mtext, msg.mtype);
	}
	msgctl(key, IPC_RMID, NULL);

	return 0;
}
