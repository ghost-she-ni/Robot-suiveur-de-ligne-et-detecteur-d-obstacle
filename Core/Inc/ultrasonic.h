#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "gpio.h"
#include "timer.h"

// Définir les pins pour le capteur HC-SR04
#define TRIG_PIN 7  // PA7
#define ECHO_PIN 8  // PA8

// Définir les fonctions pour le capteur ultrason
void Ultrasonic_Init(void);
uint32_t Ultrasonic_ReadDistance(void);

#endif // ULTRASONIC_H
