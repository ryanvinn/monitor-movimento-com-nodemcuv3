#ifndef ALARM_H
#define ALARM_H

#include "config.h"
#include "motion_sensor.h"
#include "buzzer.h"

bool alarmActivated = true;
unsigned long lastAlarm = 0;

void verifyAlarm() {
	if (alarmActivated == false) {
		noToneBuzzer();
		return;
	}

	bool motionDetected = readMotionSensor();

	if ((motionDetected == true) && (millis() - lastAlarm > BUZZER_TIME)) {
		lastAlarm = millis();
		ringBuzzer();
		Serial.println("!");
	} else {
		noToneBuzzer();
		Serial.println(".");
	}
}

void setAlarmStatus(bool status) {
	alarmActivated = status;
}

bool getAlarmStatus() {
	return alarmActivated;
}

#endif
