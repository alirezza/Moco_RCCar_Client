#include "WiFiConnection.hpp"

WiFiSetup::WiFiSetup(const char* SSID, const char* PW, const bool mode) {
    
    if (mode) {
        // setup ESP8266 as WiFi Access Point
        WiFi.mode(WIFI_STA);
        bool wifiSuccess = WiFi.softAP(SSID, PW);  // at least 8 characters for PW
        if (wifiSuccess) {
            Serial.println("AP created!");
            Serial.printf("IP adress: %s \n", WiFi.softAPIP().toString().c_str());
        } else {
            Serial.println("AP not created...");
        } 
        WiFi.begin();
    } else {
        // connecting to WiFi Router
        WiFi.begin(SSID, PW);
        Serial.print("Connecting"); 
        while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(500);
        }
        Serial.println('\n');
        Serial.println("Connection established!"); 
        Serial.print("IP address:\t");
        Serial.println(WiFi.localIP());
    }
}
