#include "UARTMessenger.h"

#include <Arduino.h>

void UARTMessenger::send(
    const char* message
) {

    Serial.println(message);
}