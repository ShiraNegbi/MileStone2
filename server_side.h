//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_SERVER_SIDE_H
#define MILESTONE2_SERVER_SIDE_H

namespace server_side {
    class Server {
    public:
        virtual void open(int port);
        virtual void stop();
    };
}

#endif //MILESTONE2_SERVER_SIDE_H
