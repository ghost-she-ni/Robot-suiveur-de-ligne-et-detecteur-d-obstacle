#include "line_sensor.h"

void LineSensor_Init(void) {
    // Activer l'horloge GPIOA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // Configurer PA5 et PA6 en mode analogique (capteurs de ligne)
    GPIOA->MODER |= GPIO_MODER_MODE5 | GPIO_MODER_MODE6;

    // Activer l'horloge ADC
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Configurer et calibrer l'ADC
    ADC1->CR |= ADC_CR_ADCAL;  // Démarrer la calibration
    while (ADC1->CR & ADC_CR_ADCAL);  // Attendre la fin de la calibration

    // Configurer l'ADC
    ADC1->CFGR1 |= ADC_CFGR1_RES_1;  // Résolution 8 bits
    ADC1->CR |= ADC_CR_ADEN;  // Activer l'ADC
    while (!(ADC1->ISR & ADC_ISR_ADRDY));  // Attendre que l'ADC soit prêt
}

uint32_t LineSensor_ReadLeft(void) {
     //Sélectionner le canal 5 (PA5)
    ADC1->CHSELR = ADC_CHSELR_CHSEL5;
     //Démarrer la conversion
    ADC1->CR |= ADC_CR_ADSTART;
     //Attendre la fin de la conversion
    while (!(ADC1->ISR & ADC_ISR_EOC));
     //Lire la valeur convertie
    return ADC1->DR;
}

uint32_t LineSensor_ReadRight(void) {
    // Sélectionner le canal 6 (PA6)
    ADC1->CHSELR = ADC_CHSELR_CHSEL6;
    // Démarrer la conversion
    ADC1->CR |= ADC_CR_ADSTART;
    // Attendre la fin de la conversion
    while (!(ADC1->ISR & ADC_ISR_EOC));
    // Lire la valeur convertie
    return ADC1->DR;
}
