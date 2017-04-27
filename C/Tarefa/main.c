/**
 * Processo Seletivo 2017 - main.c
 *
 * Equipe ThundeRatz de Robótica
 * 03/2017
 */

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "sensors.h"
#include "motors.h"

int main() {
	sensors_init();
	motors_init();
	sei();
	wdt_reset();
	wdt_disable();

	for (;;) {

		if (get_sensor(SENSOR_FE) <= DIST && get_sensor(SENSOR_FD) <= DIST) { //se o robô adversário estiver centralizado à frente
			while (get_sensor(SENSOR_FE) <= DIST || get_sensor(SENSOR_FD) <= DIST) { //até o robô estar totalmente desalinhado (não empurrando nada)
				motors(255, 255);
			}
		}

		if (get_sensor(SENSOR_LE) < 5 || get_sensor(SENSOR_LD < 5)) { //se estiver sendo empurrado pelos lados
			motors(255, 255); //mover para frente para não travar quando for girar
		_	delay_ms(500); //tempo movendo para frente
		}

		motors(255, -255); //robô gira e repete o ciclo até encontrar adversário novamente
		_delay_ms(10);
	}

	return 0;
}
