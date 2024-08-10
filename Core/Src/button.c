#include "button.h"
#include "stm32l0xx.h"

void Button_Init(void) {
    RCC->IOPENR |= RCC_IOPENR_GPIOCEN;  // Activer l'horloge pour GPIOC
    GPIOC->MODER &= ~(3UL << (13 * 2));  // Mode entrée
    GPIOC->PUPDR |= (1UL << (13 * 2));   // Pull-up activé
}

bool isButtonPressed(void) {
    return (GPIOC->IDR & (1 << 13)) == 0;  // Bouton pressé si bas
}
