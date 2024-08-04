/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_CS_Pin GPIO_PIN_7
#define LCD_CS_GPIO_Port GPIOA
#define LCD_BL_CTR_Pin GPIO_PIN_0
#define LCD_BL_CTR_GPIO_Port GPIOB
#define LCD_RESET_Pin GPIO_PIN_11
#define LCD_RESET_GPIO_Port GPIOF
#define LCD_CTP_RST_Pin GPIO_PIN_0
#define LCD_CTP_RST_GPIO_Port GPIOG
#define LCD_CTP_INT_Pin GPIO_PIN_1
#define LCD_CTP_INT_GPIO_Port GPIOG
#define LCD_CTP_INT_EXTI_IRQn EXTI1_IRQn
#define GNSS_RESET_Pin GPIO_PIN_13
#define GNSS_RESET_GPIO_Port GPIOB
#define DEBUG_USART2_TX_Pin GPIO_PIN_5
#define DEBUG_USART2_TX_GPIO_Port GPIOD
#define DEBUG_USART2_RX_Pin GPIO_PIN_6
#define DEBUG_USART2_RX_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
