#include "CommandHandler.h"

#include <Arduino.h>

CommandHandler::CommandHandler(
    TemperatureMonitor* monitor
) {

    this->monitor = monitor;
}

void CommandHandler::process() {

    if (Serial.available()) {

        String cmd =
            Serial.readStringUntil('\n');

        cmd.trim();

        if (cmd.startsWith(
            "SET_INTERVAL="
        )) {

            unsigned long val =
                cmd.substring(13).toInt();

            monitor->setInterval(val);

            Serial.println(
                "Interval Updated"
            );
        }

        else if (cmd.startsWith(
            "SET_THRESHOLD="
        )) {

            float val =
                cmd.substring(14).toFloat();

            monitor->setThreshold(val);

            Serial.println(
                "Threshold Updated"
            );
        }

        else if (
            cmd == "GET_CONFIG"
        ) {

            Serial.println(
                "Current Configuration"
            );

            Serial.print(
                "Interval: "
            );

            Serial.print(
                monitor->getInterval()
            );

            Serial.println(
                " ms"
            );

            Serial.print(
                "Threshold: "
            );

            Serial.print(
                monitor->getThreshold()
            );

            Serial.println(
                " C"
            );
        }

        else {

            Serial.println(
                "Invalid Command"
            );
        }
    }
}