#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <syslog.h>

#define PORT 5000

int main(int argc, char *argv[])
{

    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    char recv_buff[1024];
    memset(recv_buff, '0', sizeof(recv_buff));

    /* init syslog from be */
    setlogmask (LOG_UPTO (LOG_NOTICE));
    openlog ("miniserver", LOG_CONS|LOG_PID|LOG_NDELAY, LOG_LOCAL1);

    /* init socket to get a file descriptor */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    /* configure server to listen message comming from in port 5000 */
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    /* bind and listen */
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 10);

    /* functionnal */
    while (1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        int bytes = read(connfd, recv_buff, sizeof(recv_buff)-1);
	
        if (bytes > 0){
        	close(connfd);
	    	printf("%s\n",recv_buff);
	}
	else{
		printf("%s\n","No bytes received");
	} 
    }

    close(listenfd);
    closelog();
}