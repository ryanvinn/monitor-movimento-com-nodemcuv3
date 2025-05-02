#ifndef BUZZER_H
#define BUZZER_H

#include "configs.h"

void setupBuzzer() {
	pinMode(PIN_BUZZER, OUTPUT);
	Serial.println("Buzzer configurado.");
}

void toneBuzzer() {
	tone(PIN_BUZZER, 250);
}

void noToneBuzzer() {
	noTone(PIN_BUZZER);
}

void ringBuzzer() {
	toneBuzzer();
	delay(400);
	noToneBuzzer();
	delay(100);
}

#endif
