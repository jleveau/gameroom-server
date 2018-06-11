//
// Created by jleveau on 04/06/18.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <cstdlib>
#include <netinet/in.h>
#include <zconf.h>
#include <cstring>
#include "iostream"
#include "Server.h"

using namespace std;

void error(string msg)
{
    cerr << (msg) << " : " << strerror(errno);
    exit(1);
}

int Server::run(int port) {
    this->create(port);
    //listen up to 5 connection
    listen(this->serversocket_fd,5);


    acceptClient();

    int client = this->clientsockets_fd->front();
    string message = this->receiveData(client);

    if (message == "create") {

    }

    this->sendData(client, "bien reçu !" + message );
    this->closeConnection(client);
}

Server::Server() {
    this->clientsockets_fd = new vector<int>();
}

void Server::closeConnection(int clientsocket_fd) {
    close(clientsocket_fd);
}

Server::~Server() {
    delete clientsockets_fd;
}

string Server::receiveData(int clientsocket_fd) {
    char buffer[256];
    bzero(buffer,256);
    int n = read(clientsocket_fd,buffer,255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    string res = string(buffer);
    return res;
}

void Server::sendData(int clientsocket_fd, string message) {
    int n = write(clientsocket_fd, message.c_str(), message.length());

    if (n < 0) {
        error("ERROR writing to socket");
    }
}

void Server::create(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    //IPv4,
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //empty the serv_addr memory segment
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    this->serversocket_fd = sockfd;
}

void Server::acceptClient() {
    struct sockaddr_in cli_addr;
    __socklen_t clilen = sizeof(cli_addr);
    int client_socket_fd = accept(this->serversocket_fd, (struct sockaddr *) &cli_addr, &clilen);

    if (client_socket_fd < 0) {
        error("ERROR on accept");
    }
    this->clientsockets_fd->push_back(client_socket_fd);
}

