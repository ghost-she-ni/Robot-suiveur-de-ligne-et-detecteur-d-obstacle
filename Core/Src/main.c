/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "motor.h"
#include "main.h"
#include "ultrasonic.h"
#include "led_rgb.h"
//#include "line_sensor.h"
#include <stdio.h>

/*#include "gpio.h"

#include "ultrasonic.h"
#include "line_sensor.h"
#include "led_rgb.h"
#include "buzzer.h"*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

// Fonction de délai simple
void delay_ms(int ms) {
    for (int i = 0; i < ms * 1000; i++) {
        __NOP();
    }
}

int main(void) {
    // Initialisation des moteurs, du capteur ultrason et de la LED RGB
    Motor_Init();
    Ultrasonic_Init();
    LED_RGB_Init();

    // Boucle principale
    while (1) {
        uint8_t leftSensor = GPIO_ReadPin(GPIOA, 0);  // Lecture du suiveur de ligne gauche (PA0)
        uint8_t rightSensor = GPIO_ReadPin(GPIOA, 4);  // Lecture du suiveur de ligne droit (PA4)
        uint32_t distance = Ultrasonic_ReadDistance();  // Lire la distance

        if (distance < 10) {  // Si un obstacle est détecté à moins de 10 cm
            Motor_Stop();  // Arrêter les moteurs
            LED_RGB_SetRed();  // Allumer la LED rouge
        } else {
            // Suivre la ligne si aucun obstacle n'est détecté
            if (leftSensor && rightSensor) {  // Les deux détectent la ligne
                Motor_Forward();  // Avancer
                LED_RGB_SetGreen();  // Allumer la LED verte
            } else if (!leftSensor && rightSensor) {  // Seul le suiveur de ligne gauche détecte la ligne
            	Motor_Right();  // Tourner à droite
                LED_RGB_SetGreen();  // Allumer la LED verte
            } else if (leftSensor && !rightSensor) {  // Seul le suiveur de ligne droit détecte la ligne
                Motor_Left();// Tourner à gauche
                LED_RGB_SetGreen();  // Allumer la LED verte
            } else {
                Motor_Stop();  // Arrêter si aucun ne détecte la ligne
                LED_RGB_SetRed();  // Allumer la LED rouge
            }
        }

        delay_ms(100);  // Attendre 100 ms avant la prochaine lecture
    }
}







/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  while (LL_PWR_IsActiveFlag_VOS() != 0)
  {
  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }

  LL_Init1msTick(16000000);

  LL_SetSystemCoreClock(16000000);
  LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
