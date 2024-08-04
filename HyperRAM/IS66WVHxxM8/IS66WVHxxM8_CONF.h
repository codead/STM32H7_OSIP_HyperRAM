/*
 * IS66WVHxxM8_CONF.h
 *
 *  Created on: Nov 19, 2023
 *      Author: DucHuyLe
 */

#ifndef EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_CONF_H_
#define EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_CONF_H_
/**
  ******************************************************************************
  * @file    IS66WVHxxM8_conf.h
  * @author  MCD Application Team
  * @brief   IS66WVHxxM8 OctalSPI memory configuration template file.
  *          This file should be copied to the application folder and renamed
  *          to IS66WVHxxM8_conf.h
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
#ifndef IS66WVHxxM8_CONF_H
#define IS66WVHxxM8_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/** @addtogroup BSP
  * @{
  */
#define CONF_OSPI_RAM_ODS                         IS66WVHxxM8_CR0_DS_34   /* IS66WVHxxM8 Output Driver Strength */

#define RW_RECOVERY_TIME                          3U /* 40ns @ 60MHz */
#define DEFAULT_INITIAL_LATENCY                   6U
#define OPTIMAL_FIXED_INITIAL_LATENCY             3U
#define OPTIMAL_FIXED_INITIAL_LATENCY_REG_VAL     IS66WVHxxM8_CR0_IL_3_CLOCK
#define OPTIMAL_VARIABLE_INITIAL_LATENCY          6U
#define OPTIMAL_VARIABLE_INITIAL_LATENCY_REG_VAL  IS66WVHxxM8_CR0_IL_6_CLOCK

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* IS66WVHxxM8_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/





#endif /* EXTERNAL_RAM_HYPERRAM_IS66WVHXXM8_IS66WVHXXM8_CONF_H_ */
