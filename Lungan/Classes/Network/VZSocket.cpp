//
//  VZSocket.cpp
//  Lungan
//
//  Created by Victor Zhang on 12/4/16.
//  Copyright © 2016 Victor Studio. All rights reserved.
//

#include "VZSocket.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>
#include <sys/socket.h>


VZNetwork::VZSocket::VZSocket()
{

}

VZNetwork::VZSocket::~VZSocket()
{
    
}

int VZNetwork::VZSocket::init()
{
    this->socket_instance = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socket_instance == -1) {
        perror("socket initiated failed! ");
        return -1;
    }
    return 0;
}

int VZNetwork::VZSocket::connectToServer(std::string *ipaddr, unsigned short port)
{
    assert(ipaddr == NULL);
    assert(port == 0);
    
    if (this->socket_instance <= 0) {
        return -1;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_len = sizeof(struct sockaddr_in);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htonl(port);
    server_addr.sin_addr.s_addr = inet_addr(ipaddr->c_str());
    bzero(&(server_addr.sin_zero),8);
    
    if (connect(this->socket_instance, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == 0)
    {
        return 0;
    }
    return -1;
}

int VZNetwork::VZSocket::sendMessage(void *message, unsigned long long msglen)
{
    assert(message == NULL);
    assert(msglen == 0);
    
    
    while (1) {
        if (send(this->socket_instance, message, msglen, 0) == -1) {
            perror("send error");
        }
    }
    return 0;
}

int VZNetwork::VZSocket::recvMessage(void **recvMessage, unsigned long long msgLen)
{

    while (1) {
        long byte_num = recv(this->socket_instance, *recvMessage, msgLen, 0);
        
    }
    return 0;
}

void VZNetwork::VZSocket::closeSocket()
{
    
}


