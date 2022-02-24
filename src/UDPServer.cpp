#include "UDPServer.hpp"
#include <sstream>

void UdpServer::setup(unsigned int portNo) {
  m_server.begin(portNo);
}

UdpServer::UdpServer(ServerData serverData) 
  : WiFiSetup::WiFiSetup(serverData.SSID, serverData.PW, serverData.mode) {
    m_server.begin(serverData.portNo);
}

UdpServer::UdpServer(const char* SSID, const char* PW, const bool mode, unsigned int portNo) : 
  WiFiSetup::WiFiSetup(SSID, PW, mode) {

  m_server.begin(portNo);

}

void UdpServer::printReceivedMessage() { 
  // client_status();  //if connected, blink LED
  int packetSize = m_server.parsePacket();

  if (packetSize) {

    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, m_server.remoteIP().toString().c_str(), m_server.remotePort());
    int len = m_server.read(m_receivedPacket, 255);

    if (len > 0) {

      m_receivedPacket[len] = '\0';
      Serial.printf("Packet message: %s\n", m_receivedPacket);

      // if (String(m_receivedPacket) == "hello") {
      //   blinkLED();
      // }
    }
    // // send back a reply, to the IP address and port we got the packet from
    // udpServer.beginPacket(udpServer.remoteIP(), udpServer.remotePort());
    // udpServer.write(replyPacket);
    // udpServer.endPacket();
  }
}

DrivingData UdpServer::returnReceivedMessage() {
  int packetSize = m_server.parsePacket();
  
  DrivingData newData ;
  if (packetSize) {
    
    int len = m_server.read(m_receivedPacket, 255);
    
    if (len > 0) {
      m_receivedPacket[len] = '\0';
      int angle = splitmsg(m_receivedPacket,4,7);
      int accel = splitmsg(m_receivedPacket,0,3);
      angle = angle * 2 + 90;
      Serial.printf("Packet message: %s\n", m_receivedPacket);
      //Serial.println(accel);
      newData = { .vehicleAngle = angle,
                  .vehicleAcceleration = accel};
    }
  
    
  }
  
  return newData;
}

void UdpServer::client_status() {

  unsigned char number_client;
  struct station_info *stat_info;

  struct ip4_addr *IPaddress;
  IPAddress address;
  int i=1;

  number_client= wifi_softap_get_station_num();
  stat_info = wifi_softap_get_station_info();

  Serial.print(" Total Connected Clients are = ");
  Serial.println(number_client);

  while (stat_info != NULL) {

  IPaddress = &stat_info->ip;
  address = IPaddress->addr;

  Serial.print("client= ");

  Serial.print(i);
  Serial.print(" IP adress is = ");
  Serial.print((address));
  Serial.print(" with MAC adress is = ");

  Serial.print(stat_info->bssid[0],HEX);Serial.print(" ");
  Serial.print(stat_info->bssid[1],HEX);Serial.print(" ");
  Serial.print(stat_info->bssid[2],HEX);Serial.print(" ");
  Serial.print(stat_info->bssid[3],HEX);Serial.print(" ");
  Serial.print(stat_info->bssid[4],HEX);Serial.print(" ");
  Serial.print(stat_info->bssid[5],HEX);Serial.print(" ");

  stat_info = STAILQ_NEXT(stat_info, next);
  i++;
  Serial.println();
  }

  delay(500);

}

int UdpServer::splitmsg(char m_receivedPacket[],int from,int to){
  std::stringstream strtoint;
  char resultchar[(to-from)+1];
  for (int i = 0; from <= to; i++)
  {
    resultchar[i] = m_receivedPacket[from];
    from++;
  }
  int result;
  strtoint << resultchar;
  strtoint >> result;
  return result;
};
