#include "led.h"

void Led_init(LED_TypeDef *led, GPIO_TypeDef * port, uint8_t pn){

	led->gpioPort=port;
	led->pin=pn;

	//Activation de l'horloge sur le port en question

	//d terminer le num ro du port 0--> GPIOA, 1-->GPIOB, etc.
	uint8_t nb_port;
	nb_port=(uint32_t)((uint32_t *)port - IOPPERIPH_BASE)/ (uint32_t)0x400;
	//activation de l'hologe
	//2-activation de l'hologe
	RCC->IOPENR|=1<<nb_port;

	//configuration de la pin en sortie
	led->gpioPort->MODER&=~(0b11<<2*pn);
	led->gpioPort->MODER|=(0b01<<2*pn);
}


void Led_turnOn(LED_TypeDef *led){
	led->gpioPort->BSRR = (1 << led->pin); // Met le bit correspondant à la LED à 1 pour l'allumer

}


void Led_turnOff(LED_TypeDef *led){
	led->gpioPort->BSRR = (1 << (led->pin + 16)); // Met le bit correspondant à la LED à 0 pour l'éteindre

}

void Led_toggle(LED_TypeDef *led){
	led->gpioPort->ODR ^= (1 << led->pin); // Inverse l'état de la LED en utilisant l'opérateur XOR

}

uint8_t Led_isOn(LED_TypeDef *led){
	return (led->gpioPort->ODR >> led->pin) & 0x1; // Vérifie si le bit correspondant à la LED est à 1 (allumée)
}

uint8_t Led_isOff(LED_TypeDef *led){
	return !Led_isOn(led); // Utilise la fonction Led_isOn pour déterminer si la LED est éteinte
}
