#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include "projet.h"

#define PORT 5000
#define CESARKEY 4

int main(int argc, char *argv[])
{
    int sockfd = 0;
    char Buffer[1024];
    char *send_buff;
    struct sockaddr_in serv_addr;

    /* read arguments */
    if(argc != 3)
    {
	printf("Error with client\n");
        printf("Usage:'ip' 'message'\n");
        return 1;
    }
    
    /* put args in buffer to be send */
    send_buff = argv[2];
    

    /* init socket to get a file descriptor */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    /* socket configuration to talk on port 5000 */
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    }

    /* connect to server */
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    }
	
    /* encrypt data */	
    cesar_crypt(CESARKEY,send_buff);
    
    /* send data */
    int bytes = write(sockfd, send_buff,1024);

    if(bytes < 0)
    {
        printf("\n Send error \n");
    }
    
    /* received an answer */
    recv(sockfd,Buffer,1024,0);
    printf("Server answer is : %s\n",Buffer);
    

    /* close socket */
    close(sockfd);

    return 0;
}
