#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "configs.h"
#include "alarm_logic.h"
#include "web_content.h"
#include <ESP8266WebServer.h>

ESP8266WebServer server(WEB_SERVER_PORT);

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

void handleRoot() {
    String html = FPSTR(MAIN_PAGE);
    
    html.replace("%ALARM_STATUS%", processor("ALARM_STATUS"));
    html.replace("%BUTTON_TEXT%", processor("BUTTON_TEXT"));
    html.replace("%BUTTON_COLOR%", processor("BUTTON_COLOR"));
    
    server.send(200, "text/html", html);
}

void handleToggle() {
    setAlarmStatus(!getAlarmStatus());
    server.sendHeader("Location", "/");
    server.send(302, "text/plain", "Status alterado");
}

void setupWebServer() {
    server.on("/", HTTP_GET, handleRoot);
    server.on("/toggle", HTTP_POST, handleToggle);

    server.begin();
    Serial.println("Servidor HTTP iniciado");
}

void handleWebRequests() {
    server.handleClient();
}

#endif

