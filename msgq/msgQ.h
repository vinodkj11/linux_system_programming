
#define pathname "./msgq"
#define proj_id 0x1234
struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char mtext[10];    /* message data */
};
