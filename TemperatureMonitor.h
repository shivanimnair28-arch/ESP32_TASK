#ifndef TEMPERATUREMONITOR_H
#define TEMPERATUREMONITOR_H

#include "ITemperatureSensor.h"

#include "IMessageService.h"

class TemperatureMonitor {

  private:

    ITemperatureSensor* sensor;

    IMessageService* messenger;

    unsigned long interval;

    float threshold;

    unsigned long lastRead;

  public:

    TemperatureMonitor(
        ITemperatureSensor* sensor,
        IMessageService* messenger
    );

    void update();

    void setInterval(
        unsigned long value
    );

    void setThreshold(
        float value
    );

    unsigned long getInterval();

    float getThreshold();
};

#endif