/* Data */
 struct message{
   char record[12];
  }p_snd,p_rcv ;

/* Creating Pipe and Initiating fork() */
    int pid, p[2];
     pipe(p);
     pid=fork();
     printf(“Using descriptors are:%2d %2d \n”,p[0],p[1] ); 
/* Creating Semaphore*/
   #include<sys/sem.h>
   struct sembuf  semb;
     int semid;
     if(semid=semget(10,0,IPC_CREAT|0666))==-1)
     {   
              perror(“Error”);
              exit(0);       
     }  
    /* Set value to Semaphore */
     semctl (semid,0,SETVAL,1);

/*writing data into pipe in parent */ 
     int  i;                                
     if(pid!=0)  {
           semb.sem_num=0;
           semb.sem_op=-1;
           semb.flag=0;
           semop(semid,&semb,1);         / *LOCKED  */
	for( i =1; i<4; i++) 
	{
      printf(“ Enter Different Strings \n” );
      scanf(“%s”,p_snd.record);
      write(p[1] ,&p_snd, sizeof(struct record))   
	}
    semb.sem_num=0;
    semb.sem_op=1;
    semb.flag=SEM_UNDO;
    semop(semid,&semb,1); 
  }              /*RELEASED*/                           

/* Receiving  data in child process */
  else {
    sleep(2);
    semb.sem_num=0;
    semb.sem_op=-1;
    semb.flag=0;
    semop(semid,&semb,1);      /*LOCKED */
    for( i =1; i<4; i++)
    {
		read(p[0], &p_rcv, sizeof(struct record)) ; 
		printf(“Received data is: %s \n“,p_rcv.record); 
    }                      
    semb.sem_num=0;
    semb.sem_op=1;
    semb.flag=SEM_UNDO;   / * Automatically RELEASED */
   } 

