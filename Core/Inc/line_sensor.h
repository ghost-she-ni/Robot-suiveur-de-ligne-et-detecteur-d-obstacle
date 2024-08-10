#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include "stm32l0xx.h"

// Définir les fonctions d'initialisation et de lecture des capteurs de ligne
void LineSensor_Init(void);
uint32_t LineSensor_ReadLeft(void);
uint32_t LineSensor_ReadRight(void);

#endif // LINE_SENSOR_H
