#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cerr << "ERROR, no port provided";
        return -1;
    }

    // create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket";
        return -1;
    }

    // bind the socket to a ip / port

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (struct sockaddr *)&hint, sizeof(hint)) == -1)
    {
        cerr << "Can't bind to IP/ port";
        return -1;
    }

    // mark the socket for listining ip

    if (listen(listening, SOMAXCONN) == -1)
    {
        cerr << "Can't listen";
    }
    // accept a call

    // close the listening socket
    // while receiing display massege, echo message
    // close socket
}