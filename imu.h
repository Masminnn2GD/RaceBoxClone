#ifndef IMU_H
#define IMU_H

void initIMU();
void updateIMU();
void calibrateIMU(float gxOffset, float gyOffset);

float getGX();  // Akselerasi X (G)
float getGY();  // Akselerasi Y (G)

#endif
