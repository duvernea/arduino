/*
  Web client

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13 (Digital I/O

 */
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp2.h>
#include <util.h>
#include <SPI.h>
#include <EEPROM.h>
#include <stdio.h>


byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x02, 0xD1 };
char server[] = "www.google.com";    // uses DNS
int EEPROM_COUNTER = 0;

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 1, 255);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }

  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /index.html HTTP/1.1");
    // client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  // print out what is stored in EEPROM:
  Serial.println("setup() running. Data stored in EEPROM:");
  int addr = 0;
  for (addr=0; addr<1024; addr++) {
    char c = EEPROM.read(addr);
    Serial.print(c); 
  }
  
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    // 1024 bytes EEPROM on the
    if (EEPROM_COUNTER < 1024) {
//      char buffer[20];
//      sprintf(buffer, "EEPROM COUNTER %i", EEPROM_COUNTER);
//      Serial.println(buffer);
      EEPROM.write(EEPROM_COUNTER, c);
    }
    EEPROM_COUNTER++;
    // Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}

