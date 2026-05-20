#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "TemperatureMonitor.h"

class CommandHandler {

  private:

    TemperatureMonitor* monitor;

  public:

    CommandHandler(
        TemperatureMonitor* monitor
    );

    void process();
};

#endif