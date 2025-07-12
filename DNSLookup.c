#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

#include </Users/gjg000/Downloads/NetworkC/hacking.h>

int main(int argc, char *argv[]) {
    struct hostent *host_info;
    struct in_addr *address;

    if(argc < 2) {
        printf("Usage: <hostname>\n");
        exit(1);
    }

    host_info = gethostbyname(argv[1]);
    if(host_info == NULL) {
        printf("Couldn't lookup %s\n", argv[1]);
    } else {
        address = (struct in_addr *) (host_info->h_addr);
        printf("%s has address %s\n", argv[1], inet_ntoa(*address));
    }
}