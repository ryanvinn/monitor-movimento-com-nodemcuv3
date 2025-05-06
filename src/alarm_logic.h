#ifndef ALARM_H
#define ALARM_H

#include "config.h" // Configurações gerais do sistema
#include "motion_sensor.h" // Interface do sensor de movimento
#include "buzzer.h" // Controle do buzzer

/**
 * @file alarm.h
 * @brief Sistema de Alarme com sensor de movimento e buzzer
 * 
 * Contém a lógica principal do sistema de alarme, incluindo:
 * - Verificação de estado
 * - Controle do buzzer
 * - Detecção de movimento
 */

// Variáveis globais do sistema de alarme
bool alarmSystemStatus = true; // Estado do sistema (true = ligado, false = desligado)
bool ringBuzzerStatus = false; // Estado do buzzer (true = tocando, false = silenciado)


/**
 * @brief Verifica e atualiza o estado do alarme
 *
 * Lógica principal do sistema que:
 * 1. Verifica se o alarme está ativado
 * 2. Controla o buzzer conforme necessidade
 * 3. Monitora o sensor de movimento
 *
 * @note Chamar periodicamente no loop principal
 */
void verifyAlarm() {
	// Estado de sistema desativado
	if (alarmSystemStatus == false) return;

	// Estado de alarme disparado
	if (ringBuzzerStatus == true) ringBuzzer();
	else {
		// Estado de monitoramento
		noToneBuzzer();

		if (motionDetected() == true) ringBuzzerStatus = true;
	} 
}

/**
 * @brief Configura o estado do sistema de alarme
 *
 * @param status Novo estado (true=ativar, false=desativar)
 *
 * @note Ao desativar, também reseta o estado do buzzer
 */
void setAlarmStatus(bool status) {
	alarmSystemStatus = status;
	ringBuzzerStatus = false;
	noToneBuzzer();
}

/**
 * @brief Retorna o estado atual do alarme
 *
 * @return bool true=alarme ativo, false=alarme inativo
 */
bool getAlarmStatus() {
	return alarmSystemStatus;
}

#endif
