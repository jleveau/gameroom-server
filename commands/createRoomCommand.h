//
// Created by jleveau on 06/06/18.
//

#ifndef SERVER_CREATEROOMCOMMAND_H
#define SERVER_CREATEROOMCOMMAND_H


#include "CommandItf.h"
#include "../Room.h"

class createRoomCommand : public CommandItf {
public:
    createRoomCommand(std::vector<Room *> *rooms);

    void execute() override;

private:
    std::vector<Room*>* rooms;

};


#endif //SERVER_CREATEROOMCOMMAND_H

