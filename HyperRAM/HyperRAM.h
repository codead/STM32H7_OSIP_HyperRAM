/*
 * HyperRAM.h
 *
 *  Created on: Nov 19, 2023
 *      Author: DucHuyLe
 */

#ifndef EXTERNAL_RAM_HYPERRAM_HYPERRAM_H_
#define EXTERNAL_RAM_HYPERRAM_HYPERRAM_H_

#include "stm32h7xx_hal.h"
#include <stdio.h>
#include "IS66WVHxxM8.h"
/* Select OSPI is OSPI1 or OSPI2 */
#define USE_OSPI 																							USE_OSPI1
#define USE_HYPERRAM_DEVICE																		USE_IS66WVHxxM8
/* Select OSPI is OSPI1 or OSPI2 */
#if (USE_OSPI == USE_OSPI1)
#define OCTOSPI_BASE                                          OCTOSPI1_BASE
#define hospi 																								hospi1
extern OSPI_HandleTypeDef hospi1;
#elif (USE_OSPI == USE_OSPI2)
#define OCTOSPI_BASE 																					OCTOSPI2_BASE
#define hospi 																								hospi2
extern OSPI_HandleTypeDef hospi2;
#else
#endif
/* Select HyperRAM device */
#if (USE_HYPERRAM_DEVICE == USE_IS66WVHxxM8)
#define HYPERRAM_SIZE 																				(uint32_t)(IS66WVHxxM8_RAM_SIZE)
#define HYPERRAM_BLOCK_SIZE 																	(uint32_t)(IS66WVHxxM8_BLOCK_SIZE)
#endif

/* define HyperRAM status */
typedef enum
{
	HyperRAM_ERROR = -1,
	HyperRAM_OK = 0,
}HyperRAM_StatusTypeDef;


HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_Test(void);
HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_Test_2(void);
HyperRAM_StatusTypeDef HyperRAM_WriteRead1Block_Test(void);
HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_TestPerformance(void);
HyperRAM_StatusTypeDef HyperRAM_WriteReadRegion_TestPerformance(uint32_t add, uint32_t length);

void HyperRAM_DelayBlock_Calibration(void);


#endif /* EXTERNAL_RAM_HYPERRAM_HYPERRAM_H_ */
