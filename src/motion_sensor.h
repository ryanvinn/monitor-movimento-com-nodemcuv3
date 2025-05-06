#ifndef SENSORS_H
#define SENSORS_H

#include "configs.h" // Para definição de PIN_MOTION_SENSOR

/**
 * @file sensors.h
 * @brief Biblioteca para leitura de sensores
 *
 * Contém as funções para configuração e leitura
 * de sensores utilizados no sistema
 */

/**
 * @brief Configura o pino do sensor de movimento
 *
 * Inicializa o pino definido em configs.h como INPUT
 * e imprime mensagem de confirmação no Serial Monitor
 *
 * @note Deve ser chamada na inicialização do sistema
 */
void setupMotionSensor() {
  pinMode(PIN_MOTION_SENSOR, INPUT);
  Serial.println("Sensor de movimento configurado.");
}

/**
 * @brief Lê o estado atual do sensor de movimento
 *
 * Realiza a leitura digital do pino do sensor
 *
 * @return true se movimento foi detectado (HIGH)
 * @return false se nenhum movimento detectado (LOW)
 *
 * @note O sensor deve retornar HIGH quando detecta movimento
 * e LOW quando não há movimento
 */
bool readMotionSensor() {
  return digitalRead(PIN_MOTION_SENSOR) == HIGH;
}

#endif
