#include "gpio.h"

void GPIO_Init(void) {
    // Activer l'horloge GPIOA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // Configurer les pins PA1, PA2, PA5, PA6, PA7, PA8, PA9, PA10, PA11 en mode sortie et entrée
    GPIOA->MODER &= ~(GPIO_MODER_MODE1 | GPIO_MODER_MODE2 | GPIO_MODER_MODE5 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7 | GPIO_MODER_MODE8 | GPIO_MODER_MODE9 | GPIO_MODER_MODE10 | GPIO_MODER_MODE11);
    GPIOA->MODER |= (GPIO_MODER_MODE1_0 | GPIO_MODER_MODE2_0 | GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE9_0 | GPIO_MODER_MODE10_0 | GPIO_MODER_MODE11_0);
    GPIOA->MODER &= ~GPIO_MODER_MODE8;  // PA8 en entrée pour Echo

    // Configurer les pins en mode push-pull
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_1 | GPIO_OTYPER_OT_2 | GPIO_OTYPER_OT_5 | GPIO_OTYPER_OT_6 | GPIO_OTYPER_OT_7 | GPIO_OTYPER_OT_9 | GPIO_OTYPER_OT_10 | GPIO_OTYPER_OT_11);

    // Configurer les pins en mode haute vitesse
    GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEED1 | GPIO_OSPEEDER_OSPEED2 | GPIO_OSPEEDER_OSPEED5 | GPIO_OSPEEDER_OSPEED6 | GPIO_OSPEEDER_OSPEED7 | GPIO_OSPEEDER_OSPEED9 | GPIO_OSPEEDER_OSPEED10 | GPIO_OSPEEDER_OSPEED11);

    // Désactiver les résistances de pull-up/pull-down
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD1 | GPIO_PUPDR_PUPD2 | GPIO_PUPDR_PUPD5 | GPIO_PUPDR_PUPD6 | GPIO_PUPDR_PUPD7 | GPIO_PUPDR_PUPD8 | GPIO_PUPDR_PUPD9 | GPIO_PUPDR_PUPD10 | GPIO_PUPDR_PUPD11);

    // Configurer PA0 et PA4 comme entrées pour les suiveurs de ligne
    GPIOA->MODER &= ~(GPIO_MODER_MODE0 | GPIO_MODER_MODE4);
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD0 | GPIO_PUPDR_PUPD4);  // Pas de pull-up ni pull-down
}

void GPIO_SetPinHigh(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
    GPIOx->BSRR = (1 << PinNumber);
}

void GPIO_SetPinLow(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
    GPIOx->BRR = (1 << PinNumber);
}

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
    return (GPIOx->IDR & (1 << PinNumber)) ? 1 : 0;
}
