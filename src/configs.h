#ifndef CONFIG_H
#define CONFIG_H

// Configurações WiFi
const char* SSID = "computacao";
const char* PASSWORD = "uasc@123";

// Definições dos pinos
const int PIN_MOTION_SENSOR = D7;
const int PIN_DISTANCE_SENSOR_TRIG = D2;
const int PIN_DISTANCE_SENSOR_ECHO = D6;
const int PIN_BUZZER = D5;

// Parâmetros do alarme
const int ALARM_DIST = 50; // CM
const unsigned long BUZZER_TIME = 2000; // MS

// Configurações do servidor web
const int WEB_SERVER_PORT = 80;

#endif

