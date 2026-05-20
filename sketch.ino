#include "BMP180Sensor.h"

#include "UARTMessenger.h"

#include "TemperatureMonitor.h"

#include "CommandHandler.h"

BMP180Sensor sensor;

UARTMessenger messenger;

TemperatureMonitor monitor(
    &sensor,
    &messenger
);

CommandHandler commandHandler(
    &monitor
);

int ALERT_LED = 25;

void setup() {

    Serial.begin(115200);

    pinMode(
        ALERT_LED,
        OUTPUT
    );

    delay(1000);

    Serial.println(
        "Starting System..."
    );

    if (!sensor.begin()) {

        Serial.println(
            "Sensor startup failed"
        );

        while (true);
    }

    Serial.println(
        "System Started"
    );
}

void loop() {

    commandHandler.process();

    monitor.update();
}