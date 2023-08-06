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
        exit(1);
    }

    // bind a socket to address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(9000);
    res = bind(sock,(struct sockaddr *)&server,sizeof(server));
    if(res!=-1){
        printf("Bind success, socket %d is in use with port %d\n",sock,server.sin_port);
    }else{
        printf("Failed to bind socket: %d-%s\n",errno,strerror(errno));
        perror("bind() failed");
        exit(1);
    }

    //put socket in listen mode-- wait connection from client
    res = listen(sock, 10);
    if(res!=-1){
        printf("Waiting for new client connect ...., socket %d is in use with %d stack in queue\n",sock,10);
    }else{
        printf("Failed to listen socket: %d-%s\n",errno,strerror(errno));
        perror("listen() failed");
        exit(1);
    }

    // accept connect from client
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    int client = accept(sock,(struct sockaddr *)&client_addr,&client_addr_len);
    if(client !=-1){
        printf("Connecting to client success, client %d is connected with %s stack in queue\n",client,inet_ntoa(client_addr.sin_addr)-1);
    }else{
        printf("Failed to accept connect socket: %d-%s\n",errno,strerror(errno));
        perror("accept() failed");
        exit(1);
    }

    // Nhan du lieu tu client
    char buf[256];
    res = recv(client, buf, sizeof(buf), 0);
    if  (res <= 0){
        printf("recv() failed.\n");
        exit(1);
    }

    



}