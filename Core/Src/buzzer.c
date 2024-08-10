
#include "buzzer.h"
#include "stm32l0xx.h"

void Buzzer_Init(void) {
    // Activer l'horloge pour le port GPIOA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // Configurer PA8 comme sortie
    GPIOA->MODER &= ~(3UL << (8 * 2));  // Effacer les bits de mode pour PA8
    GPIOA->MODER |= (1UL << (8 * 2));   // Mode sortie

    // Assurer que le buzzer est éteint initialement
    GPIOA->BSRR = (1 << (8 + 16));      // Écrire '1' à la position basse pour éteindre
}

void Buzzer_On(void) {
    GPIOA->BSRR = (1 << 8);  // Écrire '1' à la position haute pour allumer
}

void Buzzer_Off(void) {
    GPIOA->BSRR = (1 << (8 + 16));  // Écrire '1' à la position basse pour éteindre
}
