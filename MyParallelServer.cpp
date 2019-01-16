//
// Created by shira on 1/16/19.
//

#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    bool first_client_served = false;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    if (sockfd < 0) {
        perror("Cannot open socket.");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)port));
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Cannot bind server connection.");
        exit(1);
    }
    bool time_out = false;
    while (time_out == false) {
        if (first_client_served) {
            timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        }
        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
        first_client_served = true;
        if (newsockfd < 0) {
            perror("timeout!");
            time_out = true;
        } else {
            auto args = new ServerInfo(clientHandler, port, newsockfd);
            pthread_t* pthread = new pthread_t;
            this->threads.push_back(pthread);
            pthread_create(pthread, &attr, MyParallelServer::handle ,(void*)(args));
        }
    }
    pthread_attr_destroy(&attr);
    stop();
}

void MyParallelServer::stop() {
    void* stat;
    auto iter = this->threads.begin();
    while (iter != this->threads.end()) {
        pthread_join((*(*iter)), &stat);
        free((*iter));
        iter++;
    }
}

void *MyParallelServer::handle(void* arguments) {
    auto * args = (ServerInfo*) arguments;
    int input = args->getSocketID();
    int output = input;
    args->getClientHandler()->handleClient(input, output);
}
