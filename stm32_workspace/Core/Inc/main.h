/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f4xx_hal.h"
#include <stdint.h>
/* Procedure
	1. Set UE bit in USART_CR1
	2. define M bit in USART_CR1
	3. STOP Bits in USART_CR2
	4. Baud rate in USART_BRR Value = 0x683
	5. Set TE bit of USART_CR1 to send idle frame as first transmission
	6. wait till TXE.
	7. write data in USART_DR
	8. if you want to end transmission don't write to DR just wait for TC.

*/
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define USART1_BASEADDR   0x40011000
#define RCC_BASEADDR      0x40023800
#define GPIOA_BASEADDR    0x40020000

#define PTR (*(volatile uint32_t*) 0x50020000)

///////////////////////////////////////////////////////////////////////////////////
#define RCC_AHB1ENR (*(volatile uint32_t*) (RCC_BASEADDR + 0x30))
#define GPIOA_EN 0

#define RCC_APB2ENR (*(volatile uint32_t*) (RCC_BASEADDR + 0x44))
#define USART1_EN 4
/////////////////////////////////////////////////////////////////////////////////

#define USART_SR (*(volatile uint32_t*) (USART1_BASEADDR + 0x00))
#define TC   6
#define TXE  7
#define RXNE 5

#define USART_DR (*(volatile uint32_t*) (USART1_BASEADDR + 0x04))

#define USART_BRR (*(volatile uint32_t*) (USART1_BASEADDR + 0x08))

#define USART_CR1 (*(volatile uint32_t*) (USART1_BASEADDR + 0x0C))
#define UE 13
#define M  12
#define TE  3
#define RE  2

#define USART_CR2 (*(volatile uint32_t*) (USART1_BASEADDR + 0x10))
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define GPIOA_MODER (*(volatile uint32_t*) (GPIOA_BASEADDR + 0x00))
/* 01: gpo
   10: AF */
#define GPIOA_AFRH (*(volatile uint32_t*) (GPIOA_BASEADDR + 0x24))
/*
 * 9 = 4
 * 10 = 8
 * AF7 = 0111
 * */
#define GPIOA_ODR (*(volatile uint32_t*) (GPIOA_BASEADDR + 0x14))
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void init(void);
void clk(void);
void gpio(void);
void toggle(void);
void UART_TX_REG(uint32_t data);

///////////////////////////// ASCI TABLE ///////////////////////////////////////
void print(char text[]);


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

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
