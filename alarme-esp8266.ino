#include "src/configs.h"
#include "src/alarm_logic.h"
#include "src/sensors.h"
#include "src/buzzer.h"

void setup() {
	Serial.begin(115200);
  delay(1000);

  setupSensors();
  setupBuzzer();

	Serial.println("Sistema de alarme iniciado!");
}

void loop() {
  verifyAlarm();
  delay(100);
}

