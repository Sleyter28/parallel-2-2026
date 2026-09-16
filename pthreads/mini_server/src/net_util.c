//
// Created by Sleyter Angulo on 9/14/26.
//

#include "../includes/net_util.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "../../../../../../../Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_endian.h"


int nu_listen(unsigned short port, int backlog)
{
    int file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (file_descriptor < 0)
    {
        perror("socket");
        return -1;
    }

    int yes = 1;
    if (setsockopt(file_descriptor, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
    {
        perror("setsockopt");
        return -1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(file_descriptor, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind");
        close(file_descriptor);
        return -1;
    }

    if (listen(file_descriptor, backlog) < 0)
    {
        perror("listen");
        close(file_descriptor);
        return -1;
    }

    return file_descriptor;
}

int nu_write_all(int file_descriptor, const void* buffer, size_t size)
{
}

ssize_t nu_drain_request(int file_descriptor)
{
}

int nu_send_response(int file_descriptor, unsigned long connection_id)
{
}
