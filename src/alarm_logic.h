#ifndef ALARM_H
#define ALARM_H

#include "config.h"
#include "motion_sensor.h"
#include "buzzer.h"

bool alarmSystemStatus = true;
bool ringBuzzerStatus = false;

void verifyAlarm() {
	if (alarmSystemStatus == false) return;

	if (ringBuzzerStatus == true) ringBuzzer();
	else {
		noToneBuzzer();
		bool motionDetected = readMotionSensor();
		if (motionDetected == true) {
			ringBuzzerStatus = true;
		} 
	} 
}

void setAlarmStatus(bool status) {
	alarmSystemStatus = status;
	ringBuzzerStatus = false;
	noToneBuzzer();
}

bool getAlarmStatus() {
	return alarmSystemStatus;
}

#endif
