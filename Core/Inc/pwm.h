#ifndef PWM_H
#define PWM_H

#include "stm32l0xx.h"

void PWM_Init(void);
void PWM_SetDutyCycle(uint32_t channel, uint32_t dutyCycle);

#endif // PWM_H
