/*
 * IoT_RAM.h
 *
 *  Created on: Dec 9, 2023
 *      Author: DucHuyLe
 */

#ifndef EXTERNAL_RAM_IOT_RAM_IOT_RAM_H_
#define EXTERNAL_RAM_IOT_RAM_IOT_RAM_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32h7xx_hal.h"
/*Select IoT_RAM */
#define IoT_RAM_USE_DEVICE											IoT_RAM_USE_APSxx08L
#define IoT_RAM_USE_OSPI												IoT_RAM_USE_OSPI_1

HAL_StatusTypeDef IoT_RAM_Init(void);
HAL_StatusTypeDef IoT_RAM_MemoryMapped(void);
#ifdef __cplusplus
 extern "C" {
#endif

#endif /* EXTERNAL_RAM_IOT_RAM_IOT_RAM_H_ */
