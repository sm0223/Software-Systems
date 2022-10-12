#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
  
int main()
{
    key_t key;
    int msgid;
  
    // ftok to generate unique key
    key = ftok("messageFile", 65);
  
    msgid = msgget(key, 0766 | IPC_CREAT);
    message.mesg_type = 1;
  
    printf("Write Data : ");
    fgets(message.mesg_text, 10, stdin);
  
    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data send is : %s \n", message.mesg_text);
  
    return 0;
}
