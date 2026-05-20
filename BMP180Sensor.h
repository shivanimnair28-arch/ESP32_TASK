#ifndef BMP180SENSOR_H
#define BMP180SENSOR_H

#include <Adafruit_BMP085.h>

#include "ITemperatureSensor.h"

class BMP180Sensor : public ITemperatureSensor {

  private:

    Adafruit_BMP085 bmp;

  public:

    BMP180Sensor();

    bool begin();

    float readTemperature() override;
};

#endif