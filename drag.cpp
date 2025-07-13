#include "config.h"
#include "gps.h"
#include "imu.h"
#include "drag.h"

bool dragRunning = false;
unsigned long dragStartTime = 0;

float last60Time = 0.0;
float last100Time = 0.0;
bool reached60 = false;
bool reached100 = false;

void initDrag() {
  dragRunning = false;
  last60Time = 0.0;
  last100Time = 0.0;
}

void startDragRace() {
  dragRunning = true;
  dragStartTime = millis();
  reached60 = false;
  reached100 = false;
  last60Time = 0.0;
  last100Time = 0.0;
}

void handleDragRace() {
  if (!dragRunning) return;

  float speed = getSpeed();

  if (speed > 5.0 && dragStartTime == 0) {
    dragStartTime = millis();  // auto start if speed > 5
  }

  if (!reached60 && speed >= DRAG_0_60_KMH) {
    last60Time = (millis() - dragStartTime) / 1000.0;
    reached60 = true;
  }

  if (!reached100 && speed >= DRAG_0_100_KMH) {
    last100Time = (millis() - dragStartTime) / 1000.0;
    reached100 = true;
    dragRunning = false;  // Stop drag run
  }
}

float getLastDragTime(int targetSpeed) {
  if (targetSpeed == 60) return last60Time;
  if (targetSpeed == 100) return last100Time;
  return 0.0;
}
