//
// Created by jleveau on 06/06/18.
//

#include "joinRoomCommand.h"


void joinRoomCommand::execute() {
    this->room->addClient(this->client);
}

joinRoomCommand::joinRoomCommand(Room *room, Client *client) : room(room), client(client) {}

