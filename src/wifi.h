#ifndef WIFI_H
#define WIFI_H

#include "config.h"
#include <ESP8266WiFi.h>

void setupWiFi() {
	WiFi.begin(SSID, PASSWORD);
	Serial.print("Conectando ao WiFi: ");

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	Serial.println();
	Serial.print("Conectado! IP: ");
	Serial.println(WiFi.localIP());
}

bool isWiFiConnected() {
	return WiFi.status() == WL_CONNECTED;
}

#endif
