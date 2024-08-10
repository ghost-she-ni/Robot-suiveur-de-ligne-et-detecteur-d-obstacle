#include "led_rgb.h"

void LED_RGB_Init(void) {
    // Initialiser les GPIO pour la LED RGB
    GPIO_Init();
}

void LED_RGB_SetRed(void) {
    GPIO_SetPinHigh(GPIOA, LED_RED_PIN);
    GPIO_SetPinLow(GPIOA, LED_GREEN_PIN);
    GPIO_SetPinLow(GPIOA, LED_BLUE_PIN);
}

void LED_RGB_SetGreen(void) {
    GPIO_SetPinLow(GPIOA, LED_RED_PIN);
    GPIO_SetPinHigh(GPIOA, LED_GREEN_PIN);
    GPIO_SetPinLow(GPIOA, LED_BLUE_PIN);
}

void LED_RGB_SetBlue(void) {
    GPIO_SetPinLow(GPIOA, LED_RED_PIN);
    GPIO_SetPinLow(GPIOA, LED_GREEN_PIN);
    GPIO_SetPinHigh(GPIOA, LED_BLUE_PIN);
}

void LED_RGB_Off(void) {
    GPIO_SetPinLow(GPIOA, LED_RED_PIN);
    GPIO_SetPinLow(GPIOA, LED_GREEN_PIN);
    GPIO_SetPinLow(GPIOA, LED_BLUE_PIN);
}
