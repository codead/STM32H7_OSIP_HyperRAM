/*
 * APSxx08L.h
 *
 *  Created on: Dec 9, 2023
 *      Author: DucHuyLe
 */

#ifndef EXTERNAL_RAM_IOTRAM_APSXX08L_APSXX08L_H_
#define EXTERNAL_RAM_IOTRAM_APSXX08L_APSXX08L_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32h7xx_hal.h"
/*Select PSRAM APmemory*/
#define APSxx08L_USE_DEVICE											APSxx08L_3V

//#define APSxx08L_USE_DEVICE											APS6408L_1V8
/*APS12808L-3OB PSRAM APmemory*/
#if(APSxx08L_USE_DEVICE == APSxx08L_3V)
#define LINEAR_BURST_READ 0x20
#define LINEAR_BURST_WRITE 0xA0
#elif (APSxx08L_USE_DEVICE == APS6408L_1V8)
#define LINEAR_BURST_READ 0xA0
#define LINEAR_BURST_WRITE 0x20
#endif

#define DUMMY_CLOCK_CYCLES_SRAM_READ 5
#define DUMMY_CLOCK_CYCLES_SRAM_WRITE 4
/* Read Operations */
#if(APSxx08L_USE_DEVICE == APSxx08L_3V)
#define READ_CMD                                0x00
#define READ_LINEAR_BURST_CMD                   0x20
#define READ_HYBRID_BURST_CMD                   0x3F

/* Write Operations */
#define WRITE_CMD                               0x80
#define WRITE_LINEAR_BURST_CMD                  0xA0
#define WRITE_HYBRID_BURST_CMD                  0xBF
#elif (APSxx08L_USE_DEVICE == APS6408L_1V8)
/* Read Operations */
#define READ_CMD                                0x80
#define READ_LINEAR_BURST_CMD                   0xA0
#define READ_HYBRID_BURST_CMD                   0xBF

/* Write Operations */
#define WRITE_CMD                               0x00
#define WRITE_LINEAR_BURST_CMD                  0x20
#define WRITE_HYBRID_BURST_CMD                  0x3F
#endif
/* Reset Operations */
#define RESET_CMD                               0xFF
	 /* Register Operations */
#if(APSxx08L_USE_DEVICE == APSxx08L_3V)
#define READ_REG_CMD                            0x40
#define WRITE_REG_CMD                           0xC0
#elif (APSxx08L_USE_DEVICE == APS6408L_1V8)
#define READ_REG_CMD                            0xC0
#define WRITE_REG_CMD                           0x40
#endif
/* Default dummy clocks cycles */
#define DUMMY_CLOCK_CYCLES_READ                 5
#define DUMMY_CLOCK_CYCLES_WRITE                4
#define DUMMY_CLOCK_CYCLES_REGWRITE             0

HAL_StatusTypeDef APSxx08L_Init(OSPI_HandleTypeDef hospi);
HAL_StatusTypeDef APSxx08L_MemoryMapped(OSPI_HandleTypeDef hospi);
OSPI_RegularCmdTypeDef APSxx08L_ReadReg(OSPI_RegularCmdTypeDef sCommand);
OSPI_RegularCmdTypeDef APSxx08L_WriteReg(OSPI_RegularCmdTypeDef sCommand);
#ifdef __cplusplus
}
#endif
#endif /* EXTERNAL_RAM_IOTRAM_APSXX08L_APSXX08L_H_ */
