#include <iostream>
#include "Server.h"

int main() {
    int port = 3004;
    Server* server = new Server();
    server->run(port);

    delete server;

    return 0;
}