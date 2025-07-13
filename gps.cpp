#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include "config.h"
#include "gps.h"

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);  // UART1 (RX = 17, TX = 18 default)

float currentSpeed = 0.0;
bool gpsFix = false;

void initGPS() {
  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
}

void updateGPS() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    currentSpeed = gps.speed.kmph();
  }

  if (gps.location.isValid() && gps.hdop.isValid()) {
    gpsFix = gps.hdop.hdop() < 3.0; // good fix if HDOP < 3.0
  }
}

float getSpeed() {
  return currentSpeed;
}

unsigned long getGPSTime() {
  if (gps.time.isValid()) {
    return gps.time.value(); // hhmmsscc (hh:mm:ss:centi)
  }
  return 0;
}

bool isGPSFixed() {
  return gpsFix;
}
