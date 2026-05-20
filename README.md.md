ESP32 Intelligent Temperature Monitoring System



A modular embedded temperature monitoring system developed using the ESP32 microcontroller and BMP180 sensor. The project continuously monitors ambient temperature, provides real-time serial communication updates, and triggers hardware-based LED alerts whenever the temperature exceeds a configurable threshold.



The system is designed using abstraction-oriented embedded architecture, where sensor handling, monitoring logic, command processing, and messaging services are separated into independent modules for improved scalability and maintainability. Runtime configuration support allows users to dynamically modify monitoring intervals and alert thresholds through UART serial commands.



Developed and simulated using the Wokwi platform, this project demonstrates practical implementation of embedded systems concepts including I2C communication, GPIO interfacing, real-time monitoring, modular firmware design, and hardware-software integration.





\*\*\*\*\*\*\*\*\*Features\*\*\*\*\*\*\*\*



\* Real-time temperature monitoring

\* UART communication

\* Threshold-based LED alerts

\* Configurable interval and threshold

\* Modular architecture

\* Sensor abstraction

\* Messaging abstraction

\* Wokwi simulation support





\*\*\*\*\*\*\*\*System Architecture\*\*\*\*\*\*\*\*



@ Sensor Abstraction



The temperature sensing functionality is abstracted using the ITemperatureSensor interface.

This allows the monitoring logic to remain independent of the physical sensor implementation.



Currently, the system uses the BMP180Sensor module, but the architecture allows easy replacement with other sensors such as:



BME280

DHT22

LM35

external I2C temperature sensors



@Monitoring Module



The TemperatureMonitor module acts as the core system controller.



It is responsible for:



periodically reading temperature data,

comparing readings against the configured threshold,

controlling the alert LED,

and forwarding system messages through the messaging service.



@Command Handler



The CommandHandler module processes UART serial commands received from the user.



It enables runtime configuration of:



temperature threshold,

monitoring interval,

and system configuration retrieval.



@ UART Messaging



The project uses a messaging abstraction layer through the IMessageService interface.



Currently, the UARTMessenger module is implemented to transmit:



temperature readings,

system status,

configuration updates,

and error messages



through UART serial communication.







\*\*\*\*\*\*\*\*\*\*\*\*\*\*Circuit Connections\*\*\*\*\*\*\*\*\*\*

@BMP 180 SENSOR



|BMP180|ESP32|
|-|-|
|VCC|3V3|
|GND|GND|
|SDA|GPIO21|
|SCL|GPIO22<br />|



@LED CONNECTION



|LED|Connection|
|-|-|
|GPIO PIN|GPIO25|
|Resistor|220 ohm|
|lED(+ive)|connected to resistor|
|led (-ve)|connected to gnd|







@pull-up resistor



|Connection|Value|
|-|-|
|SDA->3.3V|4.7 kOHM|
|SCL->3.3V|4.7O kOHM|





@ESP32 Power Connections



|Esp32 pin|Purpose|
|-|-|
|3V3|Sensor power supply|
|GND|Common ground connection|





\*\*\*\*\*\*\*\*\*\*\*\*\*\*Circuit Diagram\*\*\*\*\*\*\*\*\*\*\*













!\[Circuit Diagram](dia1)



@Stimulated result





!\[Circuit Diagram](dia6)



@When threshold updated to 20



!\[Circuit Diagram](dia5)



!\[Circuit Diagram](dia4)





Note : when temperature reading is greater than threshold, LED triggers



!\[Circuit Diagram](dia3)



















