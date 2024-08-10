#include "motor.h"

void Motor_Init(void) {
    // Initialiser les GPIO pour les moteurs
    GPIO_Init();
}

void Motor_Forward(void) {
    // Faire avancer les moteurs
    GPIO_SetPinHigh(GPIOA, MOTOR1_IN1_PIN);  // PA1 HIGH - Moteur droit en avant
    GPIO_SetPinLow(GPIOA, MOTOR1_IN2_PIN);   // PA2 LOW - Moteur droit en avant
    GPIO_SetPinHigh(GPIOA, MOTOR2_IN1_PIN);  // PA5 HIGH - Moteur gauche en avant
    GPIO_SetPinLow(GPIOA, MOTOR2_IN2_PIN);   // PA6 LOW - Moteur gauche en avant
}

void Motor_Stop(void) {
    // Arrêter les moteurs
    GPIO_SetPinLow(GPIOA, MOTOR1_IN1_PIN);   // PA1 LOW
    GPIO_SetPinLow(GPIOA, MOTOR1_IN2_PIN);   // PA2 LOW
    GPIO_SetPinLow(GPIOA, MOTOR2_IN1_PIN);   // PA5 LOW
    GPIO_SetPinLow(GPIOA, MOTOR2_IN2_PIN);   // PA6 LOW
}

void Motor_Left(void) {
    // Tourner à gauche en arrêtant le moteur gauche et faisant avancer le moteur droit
    GPIO_SetPinHigh(GPIOA, MOTOR1_IN1_PIN);  // PA1 HIGH - Moteur droit en avant
    GPIO_SetPinLow(GPIOA, MOTOR1_IN2_PIN);   // PA2 LOW - Moteur droit en avant
    GPIO_SetPinLow(GPIOA, MOTOR2_IN1_PIN);   // PA5 LOW - Moteur gauche à l'arrêt
    GPIO_SetPinLow(GPIOA, MOTOR2_IN2_PIN);   // PA6 LOW - Moteur gauche à l'arrêt
}

void Motor_Right(void) {
    // Tourner à droite en arrêtant le moteur droit et faisant avancer le moteur gauche
    GPIO_SetPinLow(GPIOA, MOTOR1_IN1_PIN);   // PA1 LOW - Moteur droit à l'arrêt
    GPIO_SetPinLow(GPIOA, MOTOR1_IN2_PIN);   // PA2 LOW - Moteur droit à l'arrêt
    GPIO_SetPinHigh(GPIOA, MOTOR2_IN1_PIN);  // PA5 HIGH - Moteur gauche en avant
    GPIO_SetPinLow(GPIOA, MOTOR2_IN2_PIN);   // PA6 LOW - Moteur gauche en avant
}
