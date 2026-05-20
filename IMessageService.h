#ifndef IMESSAGESERVICE_H
#define IMESSAGESERVICE_H

class IMessageService {

  public:

    virtual void send(
        const char* message
    ) = 0;
};

#endif