#include <Arduino.h>
#include "vehicle.hpp"
//#include "speaker.hpp"

#define WIFI_CLIENT 0
#define AP 1
#define LOCALPORT 8888
#define SERVO_GPIO_PIN 2
VehicleData RCCarSpecification = { SERVO_GPIO_PIN };
ServerData RCCarServer = { "rccar", "123456789", AP, LOCALPORT };
//Speaker mySpeaker;
// Vehicle RCCar(RCCarSpecification, RCCarServer);

void setup() {

  Serial.begin(115200);  // baud rate for serial interface communication
  Serial.println("Start NodeMCU 1.0 ESP-12E");  // start message
  Vehicle::shared()->setup(RCCarSpecification, RCCarServer);
  // Vehicle RCCar(RCCarSpecification, RCCarServer);
  // WiFiSetup::setup("ESP8266_AP", "conti_rccar", AP);
  // myServer.setup(8888);
  // RCCar.setup(RCCarSpecification, RCCarServer);

}

void loop() {

  // myServer.printReceivedMessage();
  // webserver();
  Vehicle::shared()->maneuver();  // do maneuver

}
