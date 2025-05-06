#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "configs.h"
#include "alarm_logic.h"
#include "web_content.h"
#include <ESP8266WebServer.h>

ESP8266WebServer server(WEB_SERVER_PORT); // Instância do servidor web na porta definida em configs.h

/**
 * @brief Processa variáveis de template para a página web
 *
 * Substitui placeholders no HTML por valores dinâmicos
 *
 * @param var Nome do placeholder a ser processado
 * @return String Valor a ser inserido no template
 *
 * @note Placeholders suportados:
 * - ALARM_STATUS: Retorna "LIGADO" ou "DESLIGADO"
 * - BUTTON_TEXT: Retorna "Ligar Alarme" ou "Desligar Alarme"
 * - BUTTON_COLOR: Retorna cor verde (#44ff44) ou vermelha (#ff4444)
 */
String processor(const String& var) {
    if(var == "ALARM_STATUS") {
        return getAlarmStatus() ? "LIGADO" : "DESLIGADO";
    }
    else if(var == "BUTTON_TEXT") {
        return getAlarmStatus() ? "Desligar Alarme" : "Ligar Alarme";
    }
    else if(var == "BUTTON_COLOR") {
        return getAlarmStatus() ? "#ff4444" : "#44ff44";
    }
    return String();
}

/**
 * @brief Manipula requisições para a página raiz (/)
 *
 * Processa o template HTML e envia a página completa ao cliente
 */
void handleRoot() {
    String html = FPSTR(MAIN_PAGE); // Carrega template da memória flash
    
    // Substitui placeholders por valores dinâmicos
    html.replace("%ALARM_STATUS%", processor("ALARM_STATUS"));
    html.replace("%BUTTON_TEXT%", processor("BUTTON_TEXT"));
    html.replace("%BUTTON_COLOR%", processor("BUTTON_COLOR"));
    
    server.send(200, "text/html", html);
}

/**
 * @brief Manipula requisições para alternar o estado do alarme (/toggle)
 *
 * Inverte o estado atual do alarme e redireciona para a página principal
 */
void handleToggle() {
    setAlarmStatus(!getAlarmStatus()); // Inverte estado do alarme
    server.sendHeader("Location", "/"); // Redireciona para a raiz
    server.send(302, "text/plain", "Status alterado");
}

/**
 * @brief Configura o servidor web
 *
 * Define os handlers para as rotas:
 * - GET / → Página principal
 * - POST /toggle → Alternar estado do alarme
 *
 * @note Deve ser chamado uma vez durante a inicialização
 */
void setupWebServer() {
    server.on("/", HTTP_GET, handleRoot);
    server.on("/toggle", HTTP_POST, handleToggle);

    server.begin();
    Serial.println("Servidor HTTP iniciado");
}

/**
 * @brief Processa requisições do cliente web
 *
 * @note Deve ser chamado repetidamente no loop principal
 */
void handleWebRequests() {
    server.handleClient();
}

#endif

