/*
 * APSxx08L.c
 *
 *  Created on: Dec 9, 2023
 *      Author: DucHuyLe
 */


#ifdef __cplusplus
 extern "C" {
#endif
#include "APSxx08L.h"
#include <stdio.h>
#include "main.h"
#include "octospi.h"
uint8_t MR_write[1]={0x08};
uint8_t MR_R[8]={0};
uint8_t MR0_read;
#define MR_R_LEN sizeof(MR_R)
#define MR_ADDRESS 0x0

HAL_StatusTypeDef APSxx08L_Init(OSPI_HandleTypeDef hospi)
{
  printf("Start APSxx08L_Init...\r\n");
  OSPI_RegularCmdTypeDef sCommand;
  __HAL_OSPI_DISABLE(&hospi);
  CLEAR_BIT(hospi.Instance->DCR1, OCTOSPI_DCR1_FRCK);
  __HAL_OSPI_ENABLE(&hospi);
  HAL_Delay(100);
		/*-----------Read Register------------*/
	sCommand = APSxx08L_ReadReg(sCommand);
	if (HAL_OSPI_Command(&hospi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
	 Error_Handler();
	}

	if (HAL_OSPI_Receive(&hospi, MR_R, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
	 Error_Handler();
	}
 /*--------------------------------------*/

 /*-----------write Register------------*/

	sCommand = APSxx08L_WriteReg(sCommand);
	if (HAL_OSPI_Command(&hospi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_OSPI_Transmit(&hospi, MR_write, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}
	return HAL_OK;
}
HAL_StatusTypeDef APSxx08L_MemoryMapped(OSPI_HandleTypeDef hospi)
{
  OSPI_RegularCmdTypeDef sCommand;
  OSPI_MemoryMappedTypeDef sMemMappedCfg;
  sCommand.FlashId = HAL_OSPI_FLASH_ID_1;
  sCommand.InstructionMode = HAL_OSPI_INSTRUCTION_8_LINES;
  sCommand.InstructionSize = HAL_OSPI_INSTRUCTION_8_BITS;
  sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  sCommand.AddressMode = HAL_OSPI_ADDRESS_8_LINES;
  sCommand.AddressSize = HAL_OSPI_ADDRESS_32_BITS;
  sCommand.AddressDtrMode = HAL_OSPI_ADDRESS_DTR_ENABLE;
  sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode = HAL_OSPI_DATA_8_LINES;
  sCommand.DataDtrMode = HAL_OSPI_DATA_DTR_ENABLE;
  sCommand.DQSMode = HAL_OSPI_DQS_ENABLE;
  sCommand.SIOOMode = HAL_OSPI_SIOO_INST_EVERY_CMD;
  sCommand.Address = 0;
  sCommand.NbData = 1;
  /* Memory-mapped mode configuration for Linear burst write operations */
  sCommand.OperationType = HAL_OSPI_OPTYPE_WRITE_CFG;
  sCommand.Instruction = LINEAR_BURST_WRITE;
  sCommand.DummyCycles = DUMMY_CLOCK_CYCLES_SRAM_WRITE;
  if (HAL_OSPI_Command(&hospi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
  	Error_Handler();
  }
  /* Memory-mapped mode configuration for Linear burst read operations */
  sCommand.OperationType = HAL_OSPI_OPTYPE_READ_CFG;
  sCommand.Instruction = LINEAR_BURST_READ;
  sCommand.DummyCycles = DUMMY_CLOCK_CYCLES_SRAM_READ;
  if (HAL_OSPI_Command(&hospi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
  	Error_Handler();
  }
//  /*Disable timeout counter for memory mapped mode*/
//  sMemMappedCfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;
  /* OctoSPI activation of memory-mapped mode */
  sMemMappedCfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_ENABLE;
  sMemMappedCfg.TimeOutPeriod     = 0x34;
  /*Enable memory mapped mode*/
  if (HAL_OSPI_MemoryMapped(&hospi, &sMemMappedCfg) != HAL_OK)
  {
  	Error_Handler();
  }
  /*----------------------------------------------------------------------*/
  printf("APS12808 Mapping OK...\r\n");
  return HAL_OK;
}
OSPI_RegularCmdTypeDef APSxx08L_ReadReg(OSPI_RegularCmdTypeDef sCommand)
{
  sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
  sCommand.Instruction        = READ_REG_CMD;
  sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_8_LINES;
  sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  sCommand.Address            = MR_ADDRESS;                            //
  sCommand.AddressMode        = HAL_OSPI_ADDRESS_8_LINES;
  sCommand.AddressSize        = HAL_OSPI_ADDRESS_32_BITS;
  sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_ENABLE;
  sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode           = HAL_OSPI_DATA_8_LINES;
  sCommand.NbData             = MR_R_LEN;               //
  sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_ENABLE;
  sCommand.DummyCycles        = DUMMY_CLOCK_CYCLES_READ;//
  sCommand.DQSMode            = HAL_OSPI_DQS_ENABLE;
  sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;
  return sCommand;
}

OSPI_RegularCmdTypeDef APSxx08L_WriteReg(OSPI_RegularCmdTypeDef sCommand)
{
  sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
  sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
  sCommand.Instruction        = WRITE_REG_CMD;
  sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_8_LINES;
  sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
  sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
  sCommand.Address            = MR_ADDRESS;                            //
  sCommand.AddressMode        = HAL_OSPI_ADDRESS_8_LINES;
  sCommand.AddressSize        = HAL_OSPI_ADDRESS_32_BITS;
  sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_ENABLE;
  sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode           = HAL_OSPI_DATA_8_LINES;
  sCommand.NbData             = 1;               //
  sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_ENABLE;
  sCommand.DummyCycles        = DUMMY_CLOCK_CYCLES_REGWRITE;//
  sCommand.DQSMode            = HAL_OSPI_DQS_ENABLE;
  sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;
  return sCommand;
}
#ifdef __cplusplus
}
#endif
