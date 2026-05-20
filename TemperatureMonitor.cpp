#include "TemperatureMonitor.h"

#include <Arduino.h>

extern int ALERT_LED;

const unsigned long DEFAULT_INTERVAL = 5000;

const float DEFAULT_THRESHOLD = 30.0;

TemperatureMonitor::TemperatureMonitor(
    ITemperatureSensor* sensor,
    IMessageService* messenger
) {

    this->sensor = sensor;

    this->messenger = messenger;

    interval = DEFAULT_INTERVAL;

    threshold = DEFAULT_THRESHOLD;

    lastRead = 0;
}

void TemperatureMonitor::update() {

    unsigned long currentMillis =
        millis();

    if (currentMillis - lastRead >= interval) {

        lastRead = currentMillis;

        float temp =
            sensor->readTemperature();

        if (isnan(temp)) {

            messenger->send(
                "ERROR: Sensor Read Failed"
            );

            return;
        }

        String status = "NORMAL";

        digitalWrite(
            ALERT_LED,
            LOW
        );

        if (temp > threshold) {

            status = "ALERT";

            digitalWrite(
                ALERT_LED,
                HIGH
            );
        }

        char buffer[100];

        snprintf(
            buffer,
            sizeof(buffer),
            "Temperature: %.2f C | Status: %s",
            temp,
            status.c_str()
        );

        messenger->send(buffer);
    }
}

void TemperatureMonitor::setInterval(
    unsigned long value
) {

    if (value < 500) {

        messenger->send(
            "Invalid Interval"
        );

        return;
    }

    interval = value;
}

void TemperatureMonitor::setThreshold(
    float value
) {

    if (value < -40 || value > 150) {

        messenger->send(
            "Invalid Threshold"
        );

        return;
    }

    threshold = value;
}

unsigned long
TemperatureMonitor::getInterval() {

    return interval;
}

float
TemperatureMonitor::getThreshold() {

    return threshold;
}