#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include "config.h"
#include "gps.h"
#include "imu.h"
#include "drag.h"

unsigned long lastLogTime = 0;
File logFile;
String currentFolder = "";

void initSDLogger() {
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card failed!");
    return;
  }
  Serial.println("SD Card initialized.");

  // Buat folder berdasarkan tanggal (jika GPS tersedia)
  if (isGPSFixed()) {
    int y = gps.date.year();
    int m = gps.date.month();
    int d = gps.date.day();

    char folder[32];
    sprintf(folder, "/%04d-%02d-%02d", y, m, d);
    currentFolder = String(folder);

    if (!SD.exists(currentFolder)) {
      SD.mkdir(currentFolder);
    }

    String filePath = currentFolder + "/log.csv";
    if (!SD.exists(filePath)) {
      logFile = SD.open(filePath, FILE_WRITE);
      logFile.println("Time,Speed,GX,GY,0-60,0-100");
      logFile.close();
    }
  }
}

void logToSD() {
  if (millis() - lastLogTime < LOG_INTERVAL_MS || !isGPSFixed()) return;
  lastLogTime = millis();

  if (currentFolder == "") return;

  String filePath = currentFolder + "/log.csv";
  File file = SD.open(filePath, FILE_APPEND);
  if (!file) return;

  char timeStr[16];
  sprintf(timeStr, "%02d:%02d:%02d",
          gps.time.hour(), gps.time.minute(), gps.time.second());

  float speed = getSpeed();
  float gx = getGX();
  float gy = getGY();
  float drag60 = getLastDragTime(60);
  float drag100 = getLastDragTime(100);

  file.print(timeStr);
  file.print(",");
  file.print(speed, 1);
  file.print(",");
  file.print(gx, 2);
  file.print(",");
  file.print(gy, 2);
  file.print(",");
  file.print(drag60, 2);
  file.print(",");
  file.println(drag100, 2);

  file.close();
}
