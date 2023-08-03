#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    int input = 9000;
    int htonl_convert = htonl(input);
    int htons_convert = htons(input);
    int ntohl_convert = ntohl(input);
    int ntohs_convert = ntohs(input);
        // uint32_t htonl(uint32_t hostlong)
        // uint16_t htons(uint16_t hostshort)
        // uint32_t ntohl(uint32_t netlong)
        // uint16_t ntohs(uint16_t netshort)
    printf("input 9000\nsize %ld\nhtonl: %d\nhtons: %d\nntohl: %d\nntohs: %d\n",sizeof(input),htonl_convert,htons_convert,ntohl_convert,ntohs_convert );
    return 0;
}