//
//  VZSocket.hpp
//  Lungan
//
//  Created by Victor Zhang on 12/4/16.
//  Copyright © 2016 Victor Studio. All rights reserved.
//

#ifndef VZSocket_hpp
#define VZSocket_hpp

#include <iostream>

namespace VZNetwork {
    class VZSocket
    {
    public:
        VZSocket();
        ~VZSocket();
        
        int init();
        int connectToServer(std::string *ipaddr, unsigned short port);
        int sendMessage(void *message, unsigned long long msglen);
        int recvMessage(void **recvMessage, unsigned long long msgLen);
        void closeSocket();
        
    private:
        int socket_instance;
        
    };
}

#endif /* VZSocket_hpp */
