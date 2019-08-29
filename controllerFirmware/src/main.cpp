#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <BluetoothSerial.h>

#include "flipscreen.h"
#include "screenprogrammanager.h"

#include "programs/flipmenu.h"
#include "programs/flipclock.h"
#include "programs/flipsilent.h"
#include "programs/fliptetris.h"
#include "programs/fliptetrisAI.h"
#include "programs/flipreset.h"
#include "programs/flipsnake.h"
#include "programs/flipsettingbacklight.h"

#define WIFI_RETRY_COUNT 10000

FlipScreen* sign;
ScreenProgramManager* screenManager;

char* ssid     = "FBI_Security Van #48";
char* password = "Minecraft";

// const char* ssid     = "FCM";
// const char* password = "jsok815ogisk2200";

// /* create a server and listen on port 8088 */
// // WiFiServer server(80);
// // ESP32WebServer server(80);

WiFiUDP udp;
BluetoothSerial bt;

void startWiFiServices() {
  if(WiFi.status() == WL_CONNECTED) {
    if (!MDNS.begin("flipdot1")) {
        Serial.println("Error setting up MDNS responder!");
    }
    MDNS.addService("ctrl", "udp", 12345);

    udp.begin(12345);
  }
}
void stopWiFiServices() {
    // udp.stop();
}

// when wifi doesn't work
void configureWiFi() {

}

void setupWifi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* connecting to WiFi */
  if(strlen(password) == 0)
    WiFi.begin(ssid);
  else
    WiFi.begin(ssid, password);

  /*wait until ESP32 connect to WiFi*/
  int retries = WIFI_RETRY_COUNT;
  while (WiFi.status() != WL_CONNECTED && retries-- > 0) {
      Serial.println(WiFi.status());
      delay(500);
      Serial.print(".");
  }
  Serial.print("Connected to wifi");
  startWiFiServices();
}

void setup() {
  Serial.begin(115200);
  setupWifi();

  // instantiate the sign api
  sign = new FlipScreen();
  sign->clear(BLACK);
  sign->flip();
  // // retrieve the screenManager instance
  // screenManager = ScreenProgramManager::getInstance();
  //
  // // Create the menu
  // std::map<std::string, ScreenProgram*> menu;
  // menu[std::string("Silent")]     = new FlipSilent(sign);
  // menu[std::string("Clock")]      = new FlipClock(sign);
  // // menu[std::string("Reset")]      = new FlipReset(sign);
  // menu[std::string("Tetris")]     = new FlipTetris(sign);
  // menu[std::string("TetrisAI")]   = new FlipTetrisAI(sign);
  // menu[std::string("Snake")]      = new FlipSnake(sign);
  // // menu[std::string("Backlight")]  = new FlipSettingBacklight(sign);
  //
  // sign->write("READY");sign->flip();
  // sign->clear(BLACK);
  // // screenManager->push(new FlipMenu(sign, menu));
  // ((FlipMenu*)(screenManager->peek()))->setProgram("Silent");
}

char s = true;
void loop() {
  // Serial.printf("Loop!");
  static unsigned char packetBuffer[5];
  while (udp.parsePacket()) {
    Serial.printf("Packet!");
    int len = udp.read(packetBuffer, 5);
    if (len > 0) {
      // unsigned int x = (packetBuffer[0] << 8) + packetBuffer[1];
      // unsigned int y = (packetBuffer[2] << 8) + packetBuffer[3];
      // unsigned char c = packetBuffer[4];
      sign->_setDot(10, 10, s);
      s = !s;
    }
  }
}
