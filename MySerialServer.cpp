//
// Created by shira on 1/9/19.
//

#include "MySerialServer.h"

using namespace std;

void MySerialServer::open(int port, ClientHandler clientHandler) {
    this->s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "Bad!" << endl;
    }

    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    this->currentSocket = accept(s, (struct sockaddr*)&client, &clilen);
    if (currentSocket < 0)	{
        if (errno == EWOULDBLOCK)	{
            cout << "timeout!" << endl;
            exit(2);
        }	else	{
            perror("other error");
            exit(3);
        }
    }
}

void MySerialServer::stop() {
    cout << currentSocket << endl;
    cout << s << endl;
    close(currentSocket);
    close(s);
}
