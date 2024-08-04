/*
 * IS66WVHxxM8.h
 *
 *  Created on: Nov 19, 2023
 *      Author: DucHuyLe
 */

//#ifndef EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_H_
//#define EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_H_
/**
  ******************************************************************************
  * @file    IS66WVHxxM8.h
  * @author  MCD Application Team
  * @brief   This file contains all the description of the IS66WVHxxM8 Octal memory.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IS66WVHxxM8_H
#define __IS66WVHxxM8_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "IS66WVHxxM8_CONF.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup Components
  * @{
  */

/** @addtogroup IS66WVHxxM8
  * @{
  */

/** @defgroup IS66WVHxxM8_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup IS66WVHxxM8_Exported_Constants
  * @{
  */

/**
  * @brief  IS66WVHxxM8 Configuration
  */
#define USE_IS66WVHxxM8 																								USE_IS66WVH16M8

#define IS66WVH16M8_SIZE		 																						(uint32_t)(16 * 1024 * 1024)
#define IS66WVH8M8_SIZE			 																						(uint32_t)(8 * 1024 * 1024)
#define IS66WVHxxM8_BLOCK_SIZE																					(uint32_t)(256)


#if (USE_IS66WVHxxM8 == USE_IS66WVH16M8)
#define IS66WVHxxM8_RAM_SIZE           																	IS66WVH16M8_SIZE               /* 128 MBits => 16 MBytes */
#elif (USE_IS66WVHxxM8 == USE_IS66WVH8M8)
#define IS66WVHxxM8_RAM_SIZE           																	IS66WVH8M8_SIZE               /* 128 MBits => 16 MBytes */
#else
#endif
/**
  * @brief  MX25LM51245G Error codes
  */
#define IS66WVHxxM8_OK                           (0)
#define IS66WVHxxM8_ERROR                        (-1)

/******************************************************************************
  * @brief  IS66WVHxxM8 Registers
  ****************************************************************************/
/* Device Identification Register 0 */
#define IS66WVHxxM8_DIR0_ADDRESS        0x00000000U

#define IS66WVHxxM8_DIR0_MANUFACTURER   0x000FU     /*!< Manufacturer */
#define IS66WVHxxM8_DIR0_CADC           0x00F0U     /*!< Column Address Bit Count */
#define IS66WVHxxM8_DIR0_RABC           0x1F00U     /*!< Row Address Bit Count */
#define IS66WVHxxM8_DIR0_DADDR          0xC000U     /*!< Die Address */
#define IS66WVHxxM8_DIR0_DADDR_DIE_0    0x0000U     /*!< Die 0 Address */
#define IS66WVHxxM8_DIR0_DADDR_DIE_1    0x4000U     /*!< Die 1 Address */
#define IS66WVHxxM8_DIR0_DADDR_DIE_2    0x8000U     /*!< Die 2 Address */
#define IS66WVHxxM8_DIR0_DADDR_DIE_3    0xC000U     /*!< Die 3 Address */

/* Device Identification Register 1 */
#define IS66WVHxxM8_DIR1_ADDRESS        0x00000002U

#define IS66WVHxxM8_DIR1_DTYPE          0x000FU     /*!< Device Type */
#define IS66WVHxxM8_DIR1_DTYPE_HYPERRAM 0x0000U     /*!< HyperRAM Device Type */

/* Configuration Register 0 */
#define IS66WVHxxM8_CR0_ADDRESS         0x00001000U

#define IS66WVHxxM8_CR0_BLENGTH         0x0003U     /*!< Burst length */
#define IS66WVHxxM8_CR0_BLENGTH_128     0x0000U     /*!< 128 bytes burst length */
#define IS66WVHxxM8_CR0_BLENGTH_64      0x0001U     /*!< 64 bytes burst length */
#define IS66WVHxxM8_CR0_BLENGTH_16      0x0002U     /*!< 16 bytes burst length */
#define IS66WVHxxM8_CR0_BLENGTH_32      0x0003U     /*!< 32 bytes burst length */
#define IS66WVHxxM8_CR0_HBE             0x0004U     /*!< Hybrid burst enable */
#define IS66WVHxxM8_CR0_FLE             0x0008U     /*!< Fixed latency enable */
#define IS66WVHxxM8_CR0_IL              0x00F0U     /*!< Initial latency */
#define IS66WVHxxM8_CR0_IL_5_CLOCK      0x0000U     /*!< 5 clock latency */
#define IS66WVHxxM8_CR0_IL_6_CLOCK      0x0010U     /*!< 6 clock latency */
#define IS66WVHxxM8_CR0_IL_3_CLOCK      0x00E0U     /*!< 3 clock latency */
#define IS66WVHxxM8_CR0_IL_4_CLOCK      0x00F0U     /*!< 4 clock latency */
#define IS66WVHxxM8_CR0_DS              0x7000U     /*!< Drive strength */
#define IS66WVHxxM8_CR0_DS_34           0x0000U     /*!< 34 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_115          0x1000U     /*!< 115 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_67           0x2000U     /*!< 67 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_46           0x3000U     /*!< 46 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_34_2         0x4000U     /*!< 34 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_27           0x5000U     /*!< 27 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_22           0x6000U     /*!< 22 ohms drive strength */
#define IS66WVHxxM8_CR0_DS_19           0x7000U     /*!< 19 ohms drive strength */
#define IS66WVHxxM8_CR0_DPDE            0x8000U     /*!< Deep Power down enable */

/* Configuration Register 1 */
#define IS66WVHxxM8_CR1_ADDRESS         0x00001002U

#define IS66WVHxxM8_CR1_DRI             0x0003U     /*!< Distributed refresh interval */
#define IS66WVHxxM8_CR1_DRI_2_TIMES     0x0000U     /*!< 2 times default distributed refresh interval */
#define IS66WVHxxM8_CR1_DRI_4_TIMES     0x0001U     /*!< 4 times default distributed refresh interval */
#define IS66WVHxxM8_CR1_DRI_DEFAULT     0x0002U     /*!< Default distributed refresh interval */
#define IS66WVHxxM8_CR1_DRI_1_5_TIMES   0x0003U     /*!< 1.5 times default distributed refresh interval */

/**
  * @}
  */
/** @defgroup IS66WVHxxM8_Exported_Types IS66WVHxxM8Exported Types
  * @{
  */
typedef enum {
  IS66WVHxxM8_BURST_16_BYTES  = IS66WVHxxM8_CR0_BLENGTH_16,
  IS66WVHxxM8_BURST_32_BYTES  = IS66WVHxxM8_CR0_BLENGTH_32,
  IS66WVHxxM8_BURST_64_BYTES  = IS66WVHxxM8_CR0_BLENGTH_64,
  IS66WVHxxM8_BURST_128_BYTES = IS66WVHxxM8_CR0_BLENGTH_128
} IS66WVHxxM8_BurstLength_t;
/**
  * @}
  */

/** @defgroup IS66WVHxxM8_Exported_Functions
  * @{
  */
/* Read/Write Array Commands **************************************************/
int32_t IS66WVHxxM8_Read(OSPI_HandleTypeDef *Ctx, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t IS66WVHxxM8_Read_DMA(OSPI_HandleTypeDef *Ctx, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t IS66WVHxxM8_Write(OSPI_HandleTypeDef *Ctx, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t IS66WVHxxM8_Write_DMA(OSPI_HandleTypeDef *Ctx, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t IS66WVHxxM8_EnableMemoryMappedMode(OSPI_HandleTypeDef *Ctx);

/* Register/Setting Commands **************************************************/
int32_t IS66WVHxxM8_ReadCfgReg0(OSPI_HandleTypeDef *Ctx, uint16_t *Value);
int32_t IS66WVHxxM8_WriteCfgReg0(OSPI_HandleTypeDef *Ctx, uint16_t Value, uint32_t LatencyMode, uint32_t InitialLatency);
int32_t IS66WVHxxM8_ReadCfgReg1(OSPI_HandleTypeDef *Ctx, uint16_t *Value);
int32_t IS66WVHxxM8_WriteCfgReg1(OSPI_HandleTypeDef *Ctx, uint16_t Value, uint32_t LatencyMode, uint32_t InitialLatency);

/* ID Commands ****************************************************************/
int32_t IS66WVHxxM8_ReadID(OSPI_HandleTypeDef *Ctx, uint16_t *ID);

/* Power down Commands ********************************************************/
int32_t IS66WVHxxM8_EnterPowerDown(OSPI_HandleTypeDef *Ctx, uint32_t LatencyMode, uint32_t InitialLatency);
int32_t IS66WVHxxM8_LeavePowerDown(OSPI_HandleTypeDef *Ctx);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __IS66WVHxxM8_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



//#endif /* EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_H_ */
