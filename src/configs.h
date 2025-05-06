#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * @brief Arquivo de configurações globais do sistema
 * 
 * Contém todas as constantes de configuração para:
 * - Comunicação serial
 * - Conexão WiFi
 * - Definição de pinos
 * - Parâmetros do sistema
 */

// Taxa de transmissão de dados
const unsigned long BAUD_RATE = 9600; // Em bits por segundo

// Configurações WiFi
const char* SSID = "computacao";
const char* PASSWORD = "uasc@123";

// Definições dos pinos
const int PIN_MOTION_SENSOR = 13; //D7
const int PIN_BUZZER = 5; //D1

// Configurações do servidor web
const int WEB_SERVER_PORT = 80; // Porta padrão para servidor HTTP

#endif

