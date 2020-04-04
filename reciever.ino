
#include <SPI.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <WiFiClientSecure.h>

#ifndef STASSID
#define STASSID "Redmi N4"
#define STAPSK  "fornanduonly"
#endif
const char* ssid     = "Redmi N4";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "fornanduonly";     // The password of the Wi-Fi network
const char* host="https://api.thingspeak.com/update?api_key=RIKQNT10X69QURWE&field2=0";
const int httpsPort=80;
void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(500);
    Serial.print('.');
  }
 
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return; }

while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}

void loop() {
//  Serial.println("hello");
 // HTTPClient http;
}
 
/*  http.begin("http://jsonplaceholder.typicode.com/users/1");
   int httpcode = http.GET();
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    if(httpcode>0)
          {
    String payload = http.getString();
Serial.println(payload);
http.end();} 
           }
  delay(30000);}*/
