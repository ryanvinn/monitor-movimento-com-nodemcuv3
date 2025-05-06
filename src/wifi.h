#ifndef WIFI_H
#define WIFI_H

#include "config.h" // Para SSID e PASSWORD
#include <ESP8266WiFi.h> // Biblioteca WiFi do ESP8266

/**
 * @file wifi.h
 * @brief Configuração e gerenciamento de conexão WiFi
 * 
 * Contém funções para estabelecer e verificar a conexão WiFi
 * usando as credenciais definidas em config.h
 */

/**
 * @brief Inicializa a conexão WiFi
 *
 * Realiza a conexão com a rede WiFi usando as credenciais
 * definidas em config.h. Bloqueia até que a conexão seja estabelecida.
 *
 * @note Exibe no Serial Monitor:
 * - Tentativa de conexão
 * - Progresso (pontos)
 * - IP atribuído quando conectado
 *
 * @warning Esta função é bloqueante até que a conexão seja estabelecida
 */
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

/**
 * @brief Verifica o estado da conexão WiFi
 *
 * @return true se conectado à rede WiFi
 * @return false se desconectado
 *
 * @note Útil para verificar periodicamente se a conexão
 * permanece ativa durante a operação do sistema
 */
bool isWiFiConnected() {
	return WiFi.status() == WL_CONNECTED;
}

#endif
