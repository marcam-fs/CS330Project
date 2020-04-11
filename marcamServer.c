#include "marcamOS.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 512

void OOPS(string message)
{
    perror(message);
    exit(1);
}

int main()
{
    //Define socket information
    struct sockaddr_in bba;
    struct hostent *hp;
    int slen;
    int s;
    int rfd;
    char ch[MAXLINE];
    int numChar = MAXLINE;
    int port;

    //Print hostname & portnumber to client
    char portnum[20];
    char hostname[20];
    printf("Hostname: ");
    scanf("%s", hostname);


}