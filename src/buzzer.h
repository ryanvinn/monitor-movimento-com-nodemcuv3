#ifndef BUZZER_H
#define BUZZER_H

#include "configs.h" // Inclui configurações do sistema e definição de PIN_BUZZER

/**
 * @file buzzer.h
 * @brief Biblioteca para controle de um buzzer ativo
 *
 * Disponibiliza funções para configurar e controlar um buzzer sonoro
 */

/**
 * @brief Configura o pino do buzzer como saída
 *
 * Inicializa o pino do buzzer definido em configs.h como OUTPUT
 * e exibe mensagem de confirmação no Serial Monitor
 */
void setupBuzzer() {
	pinMode(PIN_BUZZER, OUTPUT);
	Serial.println("Buzzer configurado.");
}

/**
 * @brief Ativa o buzzer com frequência padrão
 *
 * Gera um tom contínuo de 250Hz no buzzer
 */
void toneBuzzer() {
	tone(PIN_BUZZER, 250);
}

/**
 * @brief Desativa o som do buzzer
 *
 * Interrompe qualquer tom que esteja sendo gerado no buzzer
 */
void noToneBuzzer() {
	noTone(PIN_BUZZER);
}

/**
 * @brief Toca um bipe intermitente no buzzer
 *
 * Efeito sonoro padrão do alarme:
 * 1. Ativa o buzzer por 400ms
 * 2. Pausa por 100ms
 *
 * Ciclo completo dura 500ms
 */
void ringBuzzer() {
	toneBuzzer();
	delay(400);
	noToneBuzzer();
	delay(100);
}

#endif
