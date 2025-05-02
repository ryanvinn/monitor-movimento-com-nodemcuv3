#include "src/configs.h"
#include "src/alarm_logic.h"
#include "src/motion_sensor.h"
#include "src/buzzer.h"

void setup() {
	Serial.begin(BAUD_RATE);
  delay(1000);
  Serial.println();

  setupMotionSensor();
  setupBuzzer();

  Serial.println("Sistema de segurança iniciado!");
}

void loop() {
  verifyAlarm();
  delay(100);
}

