#ifndef BUZZER_H
#define BUZZER_H

#include "configs.h"

void setupBuzzer() {
	pinMode(PIN_BUZZER, OUTPUT);
}

void activateBuzzer() {
	digitalWrite(PIN_BUZZER, HIGH);
}

void deactivateBuzzer() {
	digitalWrite(PIN_BUZZER, LOW);
}

void ringBuzzer(int duration) {
	activateBuzzer();
	delay(duration);
	deactivateBuzzer();
}

#endif
