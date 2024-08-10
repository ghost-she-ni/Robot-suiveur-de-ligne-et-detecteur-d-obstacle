#include "pwm.h"

void PWM_Init(void) {
    // Activer l'horloge pour TIM22
    RCC->APB2ENR |= RCC_APB2ENR_TIM22EN;

    // Configurer les pins PB4 (TIM22_CH1) et PB10 (TIM22_CH2) en mode alternatif
    RCC->IOPENR |= RCC_IOPENR_GPIOBEN;  // Activer l'horloge GPIOB
    GPIOB->MODER &= ~(GPIO_MODER_MODE4 | GPIO_MODER_MODE10);
    GPIOB->MODER |= (GPIO_MODER_MODE4_1 | GPIO_MODER_MODE10_1);

    // Configurer PB4 et PB10 pour l'AF4 (TIM22)
    GPIOB->AFR[0] &= ~(0xF << (4 * 4));  // Clear alternate function for PB4
    GPIOB->AFR[0] |= (4 << (4 * 4));  // Set AF4 for PB4
    GPIOB->AFR[1] &= ~(0xF << ((10 - 8) * 4));  // Clear alternate function for PB10
    GPIOB->AFR[1] |= (4 << ((10 - 8) * 4));  // Set AF4 for PB10

    // Configurer le timer TIM22 pour PWM
    TIM22->PSC = 16 - 1; // Prescaler pour obtenir une fréquence de 1 MHz (16 MHz / 16 = 1 MHz)
    TIM22->ARR = 1000 - 1; // Auto-reload pour obtenir une période de 1 ms (1 kHz)
    TIM22->CCR1 = 0; // Initialiser le rapport cyclique pour CH1
    TIM22->CCR2 = 0; // Initialiser le rapport cyclique pour CH2

    // Configurer TIM22 en mode PWM
    TIM22->CCMR1 = (6 << TIM_CCMR1_OC1M_Pos) | (6 << TIM_CCMR1_OC2M_Pos); // PWM mode 1
    TIM22->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E; // Activer les sorties PWM
    TIM22->CR1 = TIM_CR1_CEN; // Activer TIM22
}

void PWM_SetDutyCycle(uint32_t channel, uint32_t dutyCycle) {
    if (dutyCycle > 1000) dutyCycle = 1000; // Limiter le rapport cyclique à 100%
    if (channel == 1) {
        TIM22->CCR1 = dutyCycle;
    } else if (channel == 2) {
        TIM22->CCR2 = dutyCycle;
    }
}
