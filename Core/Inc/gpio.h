#ifndef GPIO_H
#define GPIO_H

#include "stm32l0xx.h"

// Définir les fonctions d'initialisation et de contrôle des GPIO
void GPIO_Init(void);
void GPIO_SetPinHigh(GPIO_TypeDef *GPIOx, uint32_t PinNumber);
void GPIO_SetPinLow(GPIO_TypeDef *GPIOx, uint32_t PinNumber);
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber);

#endif // GPIO_H
