#ifndef LED_RGB_H
#define LED_RGB_H

#include "gpio.h"

// Définir les pins pour la LED RGB
#define LED_RED_PIN 9    // PA9
#define LED_GREEN_PIN 10 // PA10
#define LED_BLUE_PIN 11  // PA11

// Définir les fonctions pour contrôler la LED RGB
void LED_RGB_Init(void);
void LED_RGB_SetRed(void);
void LED_RGB_SetGreen(void);
void LED_RGB_SetBlue(void);
void LED_RGB_Off(void);

#endif // LED_RGB_H
