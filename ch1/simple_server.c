#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include "dbg.h"

int main(void)
{
    char buf[1];
    int s, s1, ret;
    struct sockaddr_in local;

    /* set up values for: 
     * - an IPV4 server 
     * - on port 7500 
     * - accepting connections from any IP address 
     */
    local.sin_family = AF_INET;
    local.sin_port = htons(7500);
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    
    /* obtain a socket */
    s = socket(AF_INET, SOCK_STREAM, 0);
    CHECK(s >= 0, "socket call failed", 1);
    
    /* bind to the socket with the info we set up in the struct */
    ret = bind(s, (struct sockaddr *)&local, sizeof(local));
    CHECK(ret >= 0, "bind call failed", 1);

    /* set the socket to listening for connections */
    ret = listen(s, 5);
    CHECK(ret == 0, "listen call failed", 1);

    /* wait for and accept a client connection on a new socket */
    s1 = accept(s, NULL, NULL);
    CHECK(s1 >= 0, "accept call failed", 1);

    /* read data into buf */
    ret = recv(s1, buf, 1, 0);
    CHECK(ret > 0, "recv call failed", 1);
    printf("data from client: %c\n", buf[0]);

    ret = send(s1, "2", 1, 0);
    CHECK(ret > 0, "send call failed", 1);
    printf("data '2' sent to client successfully\n");

    return 0;
}
