#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "webserver.hpp"

ESP8266WebServer server(80);
const int led = 13;
const char* serverIndex = "<form method='POST' action='/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>";
const char* host = "esp8266-webupdate";
void Webserver::setup(){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.println("");
  WiFi.softAP("ESP8266_AP", "conti_rccar");

  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  //server.on("/", handleRoot());

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

 // server.onNotFound(handleNotFound());

  server.begin();
  Serial.println("HTTP server started");
}
void Webserver::handle(){
  server.handleClient();
}
Webserver:: Webserver() {};
Webserver *Webserver::instance = 0;

void Webserver::handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}

void Webserver::handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}