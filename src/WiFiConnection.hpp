#ifndef WIFI_SETUP_HPP
#define WIFI_SETUP_HPP

#include <Arduino.h>
#include <ESP8266WiFi.h>

class WiFiSetup {
    
public:
    WiFiSetup(const char* SSID, const char* PW, const bool mode);  // mode - 0: WiFi Client, 1: Access Point
};

#endif  // WIFI_SETUP_HPP
