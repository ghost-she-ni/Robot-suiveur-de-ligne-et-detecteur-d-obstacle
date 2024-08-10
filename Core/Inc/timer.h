#ifndef TIMER_H
#define TIMER_H

#include "stm32l0xx.h"

void Timer_Init(void);
void Timer_Start(void);
void Timer_Stop(void);
uint32_t Timer_GetValue(void);

#endif // TIMER_H
