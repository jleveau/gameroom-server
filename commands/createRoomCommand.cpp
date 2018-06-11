//
// Created by jleveau on 06/06/18.
//

#include "createRoomCommand.h"



void createRoomCommand::execute() {
    Room* new_room = new Room(NB_PLAYER_PER_ROOM);
    this->rooms->push_back(new_room);
}

createRoomCommand::createRoomCommand(std::vector<Room *> *rooms) : rooms(rooms) {}
