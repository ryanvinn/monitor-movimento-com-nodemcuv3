#ifndef SENSORS_H
#define SENSORS_H

#include "configs.h"

void setupMotionSensor() {
  pinMode(PIN_MOTION_SENSOR, INPUT);
  Serial.println("Sensor de movimento configurado.");
}

bool readMotionSensor() {
  return digitalRead(PIN_MOTION_SENSOR) == HIGH;
}

#endif
