/*--------------------------------------------------
HTTP 1.1 Webserver as AccessPoint for ESP8266 
for ESP8266 adapted Arduino IDE

by Stefan Thesen 08/2015 - free for anyone

Does HTTP 1.1 with defined connection closing.
Handles empty requests in a defined manner.
Handle requests for non-exisiting pages correctly.

This demo allows to switch two functions:
Function 1 creates serial output and toggels GPIO2
Function 2 just creates serial output.

Serial output can e.g. be used to steer an attached
Arduino, Raspberry etc.
--------------------------------------------------*/
#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include <ESP8266WiFi.h>

class webserver{
    public:
const char* ssid = "ESP-Accesspoint";
const char* password = "12345678";  // set to "" for open access point w/o passwortd

unsigned long ulReqcount;

WiFiServer server;
webserver();

void setup();

void loop();
};

#endif