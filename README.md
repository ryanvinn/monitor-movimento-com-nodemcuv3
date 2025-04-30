# Alarme simples com ESP8266

Projeto de sistema de segurança simples com interface web e disparador de
alarme.

Adicionando a URL de placas do ESP8266
arduino-cli config add board_manager.additional_urls http://arduino.esp8266.com/stable/package_esp8266com_index.json

Instalando a plataforma ESP8266
arduino-cli core install esp8266:esp8266

Listando as placas disponíveis para confirmar
arduino-cli board listall
