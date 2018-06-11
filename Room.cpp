//
// Created by jleveau on 06/06/18.
//

#include <algorithm>
#include "Room.h"

using namespace std;

Room::Room(int nb_clients)  {
    this->clients = new vector<Client*>();
    this->max_nb_clients = nb_clients;
}

int Room::addClient(Client *client) {
    if (this->clients->size() < this->max_nb_clients) {
        this->clients->push_back(client);
        return 0;
    } else {
        return MAX_SIZE_REACHED;
    }
}

int Room::removeClient(Client *client) {
    if (this->clients->size() > 0) {
        //find the client
        const vector<Client *, allocator<Client *>>::iterator &elem = std::find(this->clients->begin(), this->clients->end(), client);
        if (elem != this->clients->end()) {
            //remove the client
            this->clients->erase(elem);
        }
        else {
            return CLIENT_DOES_NOT_EXIST;
        }
    }
    else {
        return ROOM_IS_EMPTY;
    }

}

bool Room::roomIsFull() {
    return this->clients->size() == this->max_nb_clients;
}

std::vector<Client *>* Room::getClients() {
    return this->clients;
}
