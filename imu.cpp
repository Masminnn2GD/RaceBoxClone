#include <Wire.h>
#include <MPU6050.h>
#include "config.h"
#include "imu.h"

MPU6050 mpu;

float gx = 0.0, gy = 0.0;
float gxOffset = DEFAULT_GX_OFFSET;
float gyOffset = DEFAULT_GY_OFFSET;

void initIMU() {
  Wire.begin(MPU_SDA, MPU_SCL);
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 not connected!");
  } else {
    Serial.println("MPU6050 ready.");
  }

  delay(500);
}

void updateIMU() {
  mpu.getAcceleration();
  gx = mpu.getAccelerationX() / 16384.0 - gxOffset;  // 1g = 16384 LSB
  gy = mpu.getAccelerationY() / 16384.0 - gyOffset;
}

void calibrateIMU(float gxCal, float gyCal) {
  gxOffset = gxCal;
  gyOffset = gyCal;
}

float getGX() {
  return gx;
}

float getGY() {
  return gy;
}
