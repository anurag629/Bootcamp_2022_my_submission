#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <sys/time.h>

#define TRUE 1

using namespace std;

int main(int argc, const char *argv[])
{
    int clientSocket[50];
    int PORT;
    int max_sd;
    int max_clients = 50;
    int std;
    int activity;
    int newSocket;
    int valread;
    int i;
    int sd;
    int addrlen;
    int opt = TRUE;

    fd_set readfds;
    char buffer[1024];
    const char *message = "You have connected to server.....\n";

    cout << "Please enter port number : ";
    cin >> PORT;

    for (i = 0; i < max_clients; i++)
    {
        clientSocket[i] = 0;
    }

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        cerr << "Could not ccreate a socket!" << endl;
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
    {
        cerr << "setsockopt" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);

    if (bind(serverSocket, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        cerr << "bind failed" << endl;
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 3) == 0)
    {
        cout << "Server is ready for clients to connect on port number " << PORT << endl;
    }

    addrlen = sizeof(addr);

    while (TRUE)
    {
        // clear the socket
        FD_ZERO(&readfds);

        // add master socket to set
        FD_SET(serverSocket, &readfds);
        max_sd = serverSocket;

        // add child socket to set
        for (i = 0; i < max_clients; i++)
        {
            sd = clientSocket[i];

            // if valid socket descriptor then add to read list
            if (sd > 0)
            {
                FD_SET(sd, &readfds);
            }

            // higest file descriptor  number, need it for the select function
            if (sd > max_sd)
            {
                max_sd = sd;
            }
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR))
        {
            cout << "select error" << endl;
        }

        if (FD_ISSET(serverSocket, &readfds))
        {
            if ((newSocket = accept(serverSocket, (struct sockaddr *)&addr, (socklen_t *)&addrlen)) < 0)
            {
                cerr << "Accept" << endl;
            }
            cout << "New connection, socket fd : " << newSocket << " ip is : " << inet_ntoa(addr.sin_addr) << " port : " << PORT << endl;
            if (send(newSocket, message, strlen(message), 0) != strlen(message))
            {
                cerr << "Send Error" << endl;
            }

            for (i = 0; i < max_clients; i++)
            {
                if (clientSocket[i] == 0)
                {
                    clientSocket[i] = newSocket;
                    break;
                }
            }
        }

        for (i = 0; i < max_clients; i++)
        {
            sd = clientSocket[i];
            if (FD_ISSET(sd, &readfds))
            {
                memset(buffer, 0, 1024);
                int bytesRecieved = recv(sd, buffer, 1024, 0);
                if (bytesRecieved == -1)
                {
                    cerr << "Error in recieving " << endl;
                    break;
                }
                if (bytesRecieved == 0)
                {
                    close(sd);
                    clientSocket[i] = 0;
                    cout << "Client Disconnected" << endl;
                    break;
                }
                else
                {
                    if (bytesRecieved > 0)
                    {
                        cout << "Client [" << i << "]: " << string(buffer, 0, bytesRecieved) << endl;
                    }
                    for (i = 0; i < max_clients; i++)
                    {
                        sd = clientSocket[i];
                        if (sd != 0)
                        {
                            send(sd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}