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
#include <SD.h>


byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x02, 0xD1 };
char server[] = "www.google.com";    // uses DNS
int EEPROM_COUNTER = 0;
File myFile;
bool SDcardFound;

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
  // disable w5500 SPI
  // digitalWrite(10,HIGH);

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }

  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println("connecting...");

  // disable w5500 SPI wile setting up SD
  // digitalWrite(10,HIGH);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    SDcardFound = false;
  } else {
    Serial.println("initialization done.");
    SDcardFound = true;
  }

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
  Serial.println("\nData stored in EEPROM:\n");
  int addr = 0;
  for (addr=0; addr<1024; addr++) {
    char c = EEPROM.read(addr);
    Serial.print(c); 
  }
  Serial.println("\nEnd of Data stored in EEPROM:\n");

  if (SD.exists("index.txt")) {
    Serial.println("\n\nindex.txt exists. file contents: \n");
   // read from the file until there's nothing else in it:
     myFile = SD.open("index.txt");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
    // SD.remove("index.txt");
    Serial.println("Removing index.txt...");
  } else {
    Serial.println("index.txt doesn't exist.");
  }
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    // 1024 bytes EEPROM - write first 1024 chars
    if (EEPROM_COUNTER < 1024) {
      EEPROM.write(EEPROM_COUNTER, c);
      EEPROM_COUNTER++;
    }
    // write the result to SD card
    if (SDcardFound) {
      myFile = SD.open("index.txt", FILE_WRITE);
      myFile.write(c);
      myFile.close();
    }
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

