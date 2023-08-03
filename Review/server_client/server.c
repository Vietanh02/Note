#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
//include error lib
#include<errno.h>
int main(int argc, char* argv[])
{
    //error code , return -1 -> no error
    int res = -1;
    //create socket
    int sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sock != -1){
        printf("Socket create in: %d \n",sock);
    }else{
        printf("Failed to create socket: %d-%s\n",errno,strerror(errno));
        perror("socket() failed");
    }

    // bind a socket to address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htonl(9000);
    res = bind(sock,(struct sockaddr *)&server,sizeof(server));
    if(res!=-1){
        printf("Bind success, socket %d is in use with port %d\n",sock,server.sin_port);
    }else{
        printf("Failed to bind socket: %d-%s\n",errno,strerror(errno));
        perror("bind() failed");
    }

}