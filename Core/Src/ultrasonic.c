#include "ultrasonic.h"

// Fonction d'initialisation du capteur ultrason
void Ultrasonic_Init(void) {
    GPIO_Init();  // Initialiser les GPIO
    Timer_Init();  // Initialiser le timer

    // Configurer PA7 en sortie pour Trigger
    GPIOA->MODER |= GPIO_MODER_MODE7_0;
    GPIOA->MODER &= ~GPIO_MODER_MODE8;  // PA8 en entrée pour Echo
}

// Fonction pour lire la distance du capteur ultrason
uint32_t Ultrasonic_ReadDistance(void) {
    uint32_t startTime, endTime, duration;

    // Générer une impulsion de 10us sur Trigger
    GPIO_SetPinLow(GPIOA, TRIG_PIN);
    for (volatile int i = 0; i < 1000; i++);  // Délai de quelques cycles
    GPIO_SetPinHigh(GPIOA, TRIG_PIN);
    for (volatile int i = 0; i < 1000; i++);  // Attendre 10us
    GPIO_SetPinLow(GPIOA, TRIG_PIN);

    // Attendre que Echo passe à HIGH
    while (!GPIO_ReadPin(GPIOA, ECHO_PIN));

    // Enregistrer le temps de départ
    Timer_Start();
    startTime = Timer_GetValue();

    // Attendre que Echo repasse à LOW
    while (GPIO_ReadPin(GPIOA, ECHO_PIN));

    // Enregistrer le temps de fin
    endTime = Timer_GetValue();
    Timer_Stop();

    // Calculer la durée de l'impulsion Echo
    duration = endTime - startTime;

    // Convertir la durée en distance (cm)
    uint32_t distance = (duration * 0.0343) / 2;

    return distance;
}
