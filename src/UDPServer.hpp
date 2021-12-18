#ifndef UDP_SERVER_HPP
#define UDP_SERVER_HPP

#include <Arduino.h>
#include <WiFiUdp.h>

#include "WiFiConnection.hpp"

struct DrivingData {
    int vehicleAngle; 
    int vehicleAcceleration;
};

struct ServerData {
    const char* SSID;
    const char* PW;
    const bool mode;
    unsigned int portNo;
};

class UdpServer : WiFiSetup {
public:
    UdpServer();
    UdpServer(const char* SSID, const char* PW, const bool mode, unsigned int portNo);
    UdpServer(ServerData serverData);
    void setup(unsigned int portNo);
    void client_status();
    void printReceivedMessage();
    DrivingData returnReceivedMessage();
    int splitmsg(char m_receivedPacket[],int from, int to);
private:
    WiFiUDP m_server;
    char m_receivedPacket[255];
};

#endif  // UDP_SERVER_HPP
