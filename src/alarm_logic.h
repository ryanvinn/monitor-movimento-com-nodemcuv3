#ifndef ALARM_H
#define ALARM_H

#include "config.h"
#include "sensors.h"
#include "buzzer.h"

bool alarmActivated = true;
unsigned long lastAlarm = 0;

void verifyAlarm() {
	if (alarmActivated == false) return;

	bool motionDetected = readMotionSensor();
	float distance = readDistanceSensor();

	if (motionDetected || (distance > 0 && distance < ALARM_DIST)) {
		if (millis() - lastAlarm > BUZZER_TIME) {
			activateBuzzer();
			lastAlarm = millis();
			Serial.println("Alarme acionado!");
		}
	} else {
		deactivateBuzzer();
	}
}

void setAlarmStatus(bool status) {
	alarmActivated = status;
	if (status == false) deactivateBuzzer();
}

bool getAlarmStatus() {
	return alarmActivated;
}

#endif
