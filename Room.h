//
// Created by jleveau on 06/06/18.
//

#ifndef SERVER_ROOM_H
#define SERVER_ROOM_H


#include <vector>
#include "Client.h"

#define CLIENT_DOES_NOT_EXIST 1
#define ROOM_IS_EMPTY 2
#define MAX_SIZE_REACHED 3
#define NB_PLAYER_PER_ROOM 2

class Room {
public:
    Room(int nb_clients);

    int addClient(Client* client);
    int removeClient(Client* client);
    std::vector<Client*>* getClients();
    bool roomIsFull();

private:
    std::vector<Client*> *clients;
    int max_nb_clients;
};


#endif //SERVER_ROOM_H
