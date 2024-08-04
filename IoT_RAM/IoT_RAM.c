/*
 * IoT_RAM.c
 *
 *  Created on: Dec 9, 2023
 *      Author: DucHuyLe
 */


#ifdef __cplusplus
 extern "C" {
#endif
#include "IoT_RAM.h"
#include "APSxx08L.h"
#include "octospi.h"
#include <stdio.h>
#if(APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_1)
extern OSPI_HandleTypeDef hospi1;
#elif(APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_2)
extern OSPI_HandleTypeDef hospi2;
#else
#endif

HAL_StatusTypeDef IoT_RAM_Init(void)
{
#if((IoT_RAM_USE_DEVICE == IoT_RAM_USE_APSxx08L) || (APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_1))
	APSxx08L_Init(hospi1);
#elif((IoT_RAM_USE_DEVICE == IoT_RAM_USE_APSxx08L) || (APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_2))
	APSxx08L_Init(hospi2);
#endif
	printf("Config IoT_RAM_Init OK\r\n");
	return HAL_OK;
}

HAL_StatusTypeDef IoT_RAM_MemoryMapped(void)
{
#if((IoT_RAM_USE_DEVICE == IoT_RAM_USE_APSxx08L) || (APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_1))
	APSxx08L_MemoryMapped(hospi1);
#elif((IoT_RAM_USE_DEVICE == IoT_RAM_USE_APSxx08L) || (APSxx08L_USE_OSPI == IoT_RAM_USE_OSPI_2))
	APSxx08L_MemoryMapped(hospi2);
#endif
	return HAL_OK;
}

#ifdef __cplusplus
 extern "C" {
#endif
