#ifndef SENSORS_H
#define SENSORS_H

#include "configs.h"
#include <NewPing.h>

NewPing sonar(PIN_DISTANCE_SENSOR_TRIG, PIN_DISTANCE_SENSOR_ECHO, 200);

void setupSensors() {
  pinMode(PIN_MOTION_SENSOR, INPUT);
}

bool readMotionSensor() {
  return digitalRead(PIN_MOTION_SENSOR) == HIGH;
}

float readDistanceSensor() {
  unsigned int distance = sonar.ping_cm();
  if (distance == 0) return -1;
  return distance;
}

#endif
