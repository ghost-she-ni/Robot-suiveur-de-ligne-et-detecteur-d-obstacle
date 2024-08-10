#include "timer.h"

void Timer_Init(void) {
    // Activer l'horloge pour TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Configurer le timer
    TIM2->PSC = 16 - 1;  // Prescaler pour obtenir une résolution de 1 microseconde (16 MHz / 16 = 1 MHz)
    TIM2->ARR = 0xFFFFFFFF;  // Auto-reload à la valeur maximale
    TIM2->CNT = 0;  // Initialiser le compteur à 0
    TIM2->CR1 = TIM_CR1_CEN;  // Activer le timer
}

void Timer_Start(void) {
    TIM2->CNT = 0;  // Réinitialiser le compteur
    TIM2->CR1 |= TIM_CR1_CEN;  // Démarrer le timer
}

void Timer_Stop(void) {
    TIM2->CR1 &= ~TIM_CR1_CEN;  // Arrêter le timer
}

uint32_t Timer_GetValue(void) {
    return TIM2->CNT;  // Lire la valeur du compteur
}
