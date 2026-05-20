#ifndef ITEMPERATURESENSOR_H
#define ITEMPERATURESENSOR_H

class ITemperatureSensor {

  public:

    virtual float readTemperature() = 0;
};

#endif