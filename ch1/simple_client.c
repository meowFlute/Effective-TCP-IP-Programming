#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "dbg.h"

int main( void )
{
    char buf[1];
    int s, ret;
    struct sockaddr_in peer;

    /* set up values for:
     * - an IPV4 client
     * - on port 7500
     * - connecting to 127.0.0.1
     */
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7500);
    peer.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* obtain a socket */
    s = socket(AF_INET, SOCK_STREAM, 0);
    CHECK(s >= 0, "socket call failed", 1);

    /* connect to the server */
    ret = connect(s, (struct sockaddr *)&peer, sizeof(peer));
    CHECK(ret == 0, "connect call failed", 1);

    /* send a 1 as data */
    ret = send(s, "1", 1, 0);
    CHECK(ret > 0, "send call failed", 1);
    printf("data '1' sent to server successfully\n");

    /* print what you get back */
    ret = recv(s, buf, 1, 0);
    CHECK(ret > 0, "recv call failed", 1);
    printf("data from server: %c\n", buf[0]);

    return 0;
}
