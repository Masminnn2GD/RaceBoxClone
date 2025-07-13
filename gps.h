#ifndef GPS_H
#define GPS_H

void initGPS();
void updateGPS();

float getSpeed();            // km/h
unsigned long getGPSTime();  // timestamp
bool isGPSFixed();

#endif
