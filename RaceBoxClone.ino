#include "config.h"
#include "ui.h"
#include "gps.h"
#include "imu.h"
#include "sdlogger.h"
#include "drag.h"

void setup() {
  Serial.begin(115200);
  initUI();         // OLED & tombol
  showLoadingScreen();

  initGPS();        // Serial GPS
  initIMU();        // MPU6050
  initSDLogger();   // microSD
  initDrag();       // Mode drag race
}

void loop() {
  updateGPS();         // Parsing GPS
  updateIMU();         // Baca akselerasi

  updateUI();          // Tampilkan info ke OLED
  handleButtons();     // Navigasi menu

  handleLapLogic();    // Deteksi start/stop lap
  handleDragRace();    // Drag 0–60, 0–100 km/h

  logToSD();           // Logging CSV
}
