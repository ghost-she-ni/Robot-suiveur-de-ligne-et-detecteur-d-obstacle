#ifndef MOTOR_H
#define MOTOR_H

#include "gpio.h"

// Définir les numéros de pins de contrôle des moteurs
#define MOTOR1_IN1_PIN 1  // PA1 - Moteur droit
#define MOTOR1_IN2_PIN 2  // PA2 - Moteur droit
#define MOTOR2_IN1_PIN 5  // PA5 - Moteur gauche
#define MOTOR2_IN2_PIN 6  // PA6 - Moteur gauche

// Définir les fonctions de contrôle des moteurs
void Motor_Init(void);
void Motor_Forward(void);
void Motor_Stop(void);
void Motor_Left(void);
void Motor_Right(void);

#endif // MOTOR_H
