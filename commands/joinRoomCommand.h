//
// Created by jleveau on 06/06/18.
//

#ifndef SERVER_JOINROOMCOMMAND_H
#define SERVER_JOINROOMCOMMAND_H


#include "../Room.h"
#include "CommandItf.h"

class joinRoomCommand : public CommandItf{

    public:
    joinRoomCommand(Room *room, Client *client);

    void execute() override;

    private:
    Room* room;
    Client* client;
};


#endif //SERVER_JOINROOMCOMMAND_H
