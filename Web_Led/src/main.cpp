#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"

const char* ssid = "ESP_Mal"; 
const char* password = "12345678";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleLedOn() {
  digitalWrite(LED_BUILTIN, LOW); 
  Serial.println("LED Wlaczony");
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println("LED Wylaczony");
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.println();
  Serial.print("Tworzenie sieci...");
  

  WiFi.softAP(ssid, password);

  Serial.print("Nazwa sieci: ");
  Serial.println(ssid);
  Serial.print("Adres IP strony: ");
  Serial.println(WiFi.softAPIP()); 

  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);

  server.begin();
  Serial.println("Serwer HTTP uruchomiony");
}

void loop() {
  server.handleClient();
}