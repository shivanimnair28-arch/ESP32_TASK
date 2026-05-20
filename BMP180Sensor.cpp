#include "BMP180Sensor.h"

#include <Arduino.h>

BMP180Sensor::BMP180Sensor() {

}

bool BMP180Sensor::begin() {

    Wire.begin(21, 22);

    delay(100);

    bool status = bmp.begin();

    if (!status) {

        Serial.println(
            "BMP180 initialization failed"
        );

        return false;
    }

    Serial.println(
        "BMP180 initialized"
    );

    return true;
}

float BMP180Sensor::readTemperature() {

    return bmp.readTemperature();
}