cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 11)

add_executable(server main.cpp Server.cpp Server.h Room.cpp Room.h Client.cpp Client.h commands/CommandItf.h commands/createRoomCommand.cpp commands/createRoomCommand.h commands/joinRoomCommand.cpp commands/joinRoomCommand.h)