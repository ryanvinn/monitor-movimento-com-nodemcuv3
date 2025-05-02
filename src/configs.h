#ifndef CONFIG_H
#define CONFIG_H

// Taxa de transmissão de dados
const unsigned long BAUD_RATE = 9600;

// Configurações WiFi
const char* SSID = "computacao";
const char* PASSWORD = "uasc@123";

// Definições dos pinos
const int PIN_MOTION_SENSOR = 13; //D7
const int PIN_BUZZER = 5; //D1

// Parâmetros do alarme
const unsigned long BUZZER_TIME = 3000; // MS

// Configurações do servidor web
const int WEB_SERVER_PORT = 80;

#endif

