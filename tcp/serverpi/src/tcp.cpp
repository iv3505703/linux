#include "tcp.h"
#include <iostream>

Tcp::Tcp() {
    init_server();
}
Tcp::~Tcp(){
    delete saddr_in;
    delete saddr_connected;
}

int Tcp::sendToClient(int sock,const std::string& str) {
    return send(sock, (const char*)str.data(), str.length(), 0);
}

void Tcp::read() {
    recvfrom(sockfd, &buff[0], sizeof(buff), 0, (sockaddr*)saddr_in, &sock_len);
    for(int i = 0; i<10; i++) {
        std::cout << buff[i] << " ";
    }
}
int Tcp::listenConnections() {
    return listen(sockfd, 1);
}
void Tcp::init_server() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    saddr_in = new struct sockaddr_in;
    saddr_connected = new struct sockaddr_in;
    std::cout << " saddr_in "<< saddr_in << " sockfd="<< sockfd << std::endl;
    saddr_in->sin_addr.s_addr = inet_addr("192.168.0.103");
    //saddr_in->sin_addr.s_addr = inet_addr("192.168.0.106");
    saddr_in->sin_family = AF_INET;
    saddr_in->sin_port = htons(55555);
    sock_len = sizeof(sockaddr_in);
    std::cout<<"socklen="<<sock_len<<std::endl;
    int b = bind(sockfd, (const sockaddr*)saddr_in, sock_len);
    if(b == -1) {
        std::cout<< "Error bind" << std::endl;
    }
    listenConnections();
    int connectedSockFD = 0;
    //while(1) {
    socklen_t saddr_connected_len = sizeof(saddr_connected);
        connectedSockFD = accept(sockfd, (sockaddr*)saddr_connected, &saddr_connected_len);
    //    if(connectedSockFD !=0 && connectedSockFD != -1) break;
    //}
    std::cout << "connectedSockFD = " << connectedSockFD << std::endl;
    std::cout << "Connected IP:" << saddr_connected->sin_addr.s_addr << "\n";
    sendToClient(connectedSockFD, "Was Connected");
    char buff[1540] = {0};
    while(1) {
        int size = recv(connectedSockFD, buff, sizeof(buff), 0);
        if(size > 0) {
            std::cout << "size=" << size << std::endl;
            for(int i=0; i<size;i++) {
                std::cout<<buff[i];
            }
            //for(auto& i : buff) {
            //    std::cout << i;
            //}
            if(buff[0] == 'G') {
                sendToClient(connectedSockFD, "GET reply");
            }
            if(buff[0] == 'e' && buff[1] == 'x' && buff[2] == 'i' && buff[3] == 't') {
                close(connectedSockFD);
                _exit(0);
            }
        }        
    }
}
