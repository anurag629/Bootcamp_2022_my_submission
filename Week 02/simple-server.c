/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    int client, server;
    int portNum = atoi(argv[1]);
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockadde_in server_addr;
    socklen_t size;

    // Creating socket connection

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        cout << "\n Error in creating socket...." << endl;
        exit(1);
    }

    cout << "\n Socket server has been created...." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    // Binding the socket using socket() function

    if (bind(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        cout << "Error in binding connection, the socket hasalready been established....." << endl;
        return -1;
    }
}
