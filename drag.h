#ifndef DRAG_H
#define DRAG_H

void initDrag();
void startDragRace();
void handleDragRace();

float getLastDragTime(int targetSpeed);  // 60 or 100 km/h

#endif
