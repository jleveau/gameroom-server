//
// Created by jleveau on 04/06/18.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include <vector>
#include "Room.h"


class Server {

    private:
    int serversocket_fd;
    std::vector<int> *clientsockets_fd;



    void create(int port);

    void acceptClient();

    void sendData(int clientsocket_fd, std::string message);

    std::string receiveData(int clientsocket_fd);

    void closeConnection(int clientsocket_fd);

    Room createRoom(int nb_max_player);


    public:
    Server();
    virtual ~Server();

    int run(int port);

};


#endif //SERVER_SERVER_H
