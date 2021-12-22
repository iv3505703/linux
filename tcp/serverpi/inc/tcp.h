#ifndef TCP_H
#define TCP_H

#include "sys/types.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include <unistd.h>
#include <string>

class Tcp {
public:
    Tcp();
    ~Tcp();
    int sendToClient(int sock, const std::string &str);
    void read();
    int sockfd=0;
    int listenConnections();
private:
    void init_server();
    struct sockaddr* saddr;
    struct sockaddr_in* saddr_in;
    struct sockaddr_in* saddr_connected;

    char buff[256];
    socklen_t sock_len;
};

#endif //TCP_H
