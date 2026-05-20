#ifndef UARTMESSENGER_H
#define UARTMESSENGER_H

#include "IMessageService.h"

class UARTMessenger :
    public IMessageService {

  public:

    void send(
        const char* message
    ) override;
};

#endif