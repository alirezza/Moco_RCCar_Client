#ifndef WEBSERRVER_HPP
#define WEBSERVER_HPP

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


class Webserver
{
    public:
        static Webserver *web() {
        if (!instance) {
            instance = new Webserver();
        }
        return instance;
    };
    Webserver();
    void setup();
    void handle();
    private:
    static Webserver *instance;
    void handleNotFound();
    void handleRoot();
    
};
#endif