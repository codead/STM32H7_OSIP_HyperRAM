/*
 * HyperRAM.c
 *
 *  Created on: Nov 19, 2023
 *      Author: DucHuyLe
 */
#include "HyperRAM.h"
#include "stm32h7xx_hal.h"
#include <stdio.h>
#include "IS66WVHxxM8.h"
HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_Test(void)
{
  uint8_t aTxBuffer[] = "**OCTOSPI/Octal-spi PSRAM Memory-mapped\
  communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
  communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
  communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
  communication example**";
  __IO uint8_t *mem_addr;
  uint32_t error_total = 0;
  uint32_t address = 0;
  printf("Size of aTxBuffer = %d\r\n", sizeof(aTxBuffer));
  for(uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
  {
    /* Writing Sequence of 1Mbyte */
    mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);
    /*Writing 1Mbyte (256Byte BUFFERSIZE x 4096 times) */
    for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
    {
      *mem_addr = *(uint8_t *)&aTxBuffer[index];
      mem_addr++;
    }
    address += HYPERRAM_BLOCK_SIZE;
  }
  printf("Writing Sequence of %ld bytes OK...\r\n", HYPERRAM_SIZE);
  /*----------------------------------------------------------------------*/
  address = 0;
  for(uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
  {
    /* Reading Sequence of 1Mbyte */
    mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);

    /*Reading 1Mbyte (256Byte BUFFERSIZE x 4096 times)*/
    for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
    {
      if (*mem_addr != aTxBuffer[index])
      {
        /*if data read is corrupted we can toggle a led here: example blue led*/
//        printf("Wrong access HyperRAM!!! 0x%p = 0x%X # 0x%X\n", mem_addr, *mem_addr, aTxBuffer[index]);
        error_total++;
      }
      else
      {
//        printf("Data of address 0x%p = 0x%X\n", mem_addr, *mem_addr);
      }
      mem_addr++;
    }
    address += HYPERRAM_BLOCK_SIZE;
  }
  printf("Read %ld bytes. Total error = %ld, Error rate %.02f %%\r\n", HYPERRAM_SIZE, error_total, ((double) (error_total)/ HYPERRAM_SIZE) * 100);
  if(error_total > 0)
  {
    return HyperRAM_ERROR;
  }
  else
  {
    return HyperRAM_OK;
  }
}

HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_Test_2(void)
{
	uint8_t aTxBuffer[HYPERRAM_BLOCK_SIZE];
  __IO uint8_t *mem_addr;
  uint32_t error_total = 0;
  uint32_t address = 0;
  printf("Size of aTxBuffer = %d\r\n", sizeof(aTxBuffer));
  for(uint32_t i = 0; i < HYPERRAM_BLOCK_SIZE; i++)
  {
    aTxBuffer[i] = i % HYPERRAM_BLOCK_SIZE;
  }
	for(uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
	{
	  /* Writing Sequence of 1Mbyte */
		mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);
		/*Writing 1Mbyte (256Byte BUFFERSIZE x 4096 times) */
		for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
		{
			*mem_addr = *(uint8_t *)&aTxBuffer[index];
			mem_addr++;
		}
		address += HYPERRAM_BLOCK_SIZE;
	}
	printf("Writing Sequence of %ld bytes OK...\r\n", HYPERRAM_SIZE);
	/*----------------------------------------------------------------------*/
	address = 0;
	for(uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
	{
		/* Reading Sequence of 1Mbyte */
		mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);

		/*Reading 1Mbyte (256Byte BUFFERSIZE x 4096 times)*/
		for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
		{
			if (*mem_addr != aTxBuffer[index])
			{
				/*if data read is corrupted we can toggle a led here: example blue led*/
//				printf("Wrong access HyperRAM!!! 0x%p = 0x%X # 0x%X\n", mem_addr, *mem_addr, aTxBuffer[index]);
				error_total++;
			}
			else
			{
//				printf("Data of address 0x%p = 0x%X\n", mem_addr, *mem_addr);
			}
			mem_addr++;
		}
		address += HYPERRAM_BLOCK_SIZE;
	}
	printf("Read %ld bytes. Total error = %ld, Error rate %.02f %%\r\n", HYPERRAM_SIZE, error_total, ((double) (error_total)/ HYPERRAM_SIZE) * 100);
	if(error_total > 0)
	{
		return HyperRAM_ERROR;
	}
	else
	{
		return HyperRAM_OK;
	}
}
HyperRAM_StatusTypeDef HyperRAM_WriteRead1Block_Test(void)
{
	uint8_t aTxBuffer[] = "**OCTOSPI/Octal-spi PSRAM Memory-mapped\
	communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
	communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
	communication example** **OCTOSPI/Octal-spi PSRAM Memory-mapped\
	communication example**";
  __IO uint8_t *mem_addr;
  static uint32_t error_total = 0;
  uint32_t error_per_frame = 0;
  static uint32_t address = 0;
  uint32_t index;
  printf("Size of aTxBuffer = %d\n", sizeof(aTxBuffer));
  /* Writing Sequence of 1Mbyte */
	mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);
	/*Writing 1Mbyte (256Byte BUFFERSIZE x 4096 times) */
	for (index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
	{
		*mem_addr = *((uint8_t *)&aTxBuffer[index]);
		mem_addr++;
	}

	printf("Writing Sequence of %d bytes OK...\r\n", sizeof(aTxBuffer));
	/*----------------------------------------------------------------------*/
	/* Reading Sequence of 1Mbyte */
	mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);

	/*Reading 1Mbyte (256Byte BUFFERSIZE x 4096 times)*/
	for (index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
	{
		if (*mem_addr != aTxBuffer[index])
		{
			/*if data read is corrupted we can toggle a led here: example blue led*/
			printf("Wrong access HyperRAM!!! 0x%p = 0x%X # 0x%X\r\n", mem_addr, *mem_addr, aTxBuffer[index]);
			error_per_frame++;
			error_total++;
		}
		else
		{
			printf("Data of address 0x%p = 0x%X\r\n", mem_addr, *mem_addr);
		}
		mem_addr++;
	}
	address += 256;
	printf("Read %d bytes. Total error = %ld\r\n",(sizeof(aTxBuffer) / sizeof(*(aTxBuffer))), error_per_frame);
	printf("Total loss rate = %02f %%\r\n", (double)error_total * 100 / address);
	if(error_per_frame > 0)
	{
		return HyperRAM_ERROR;
	}
	else
	{
		return HyperRAM_OK;
	}
}
HyperRAM_StatusTypeDef HyperRAM_WriteReadFullMemory_TestPerformance (void)
{
    uint8_t aTxBuffer[HYPERRAM_BLOCK_SIZE] = {0};
    __IO uint8_t *mem_addr;
    uint32_t error_total = 0;
    uint32_t address = 0;
    uint32_t tick_start = 0;
    uint32_t time_total = 0;
    printf("Size of aTxBuffer = %d\r\n", sizeof(aTxBuffer));
    for(uint32_t i = 0; i < HYPERRAM_BLOCK_SIZE; i++)
    {
        aTxBuffer[i] = i;
    }
    tick_start = HAL_GetTick();
    for (uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
    {
        /* Writing Sequence of 1Mbyte */
        mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);
        /*Writing 1Mbyte (256Byte BUFFERSIZE x 4096 times) */
        for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
        {
            *mem_addr = *(uint8_t *) &aTxBuffer[index];
            mem_addr++;
        }
        address += HYPERRAM_BLOCK_SIZE;
    }
    time_total = HAL_GetTick() - tick_start;
    printf("Writing Sequence of %ld bytes OK with %.04fs\r\n", HYPERRAM_SIZE, (double)time_total / 1000);
    /*----------------------------------------------------------------------*/
    address = 0;
    tick_start = HAL_GetTick();
    for (uint32_t block = 0; block < HYPERRAM_SIZE / HYPERRAM_BLOCK_SIZE; block++)
    {
        /* Reading Sequence of 1Mbyte */
        mem_addr = (__IO uint8_t *)(OCTOSPI_BASE + address);

        /*Reading 1Mbyte (256Byte BUFFERSIZE x 4096 times)*/
        for (uint32_t index = 0; index < sizeof(aTxBuffer) / sizeof(*(aTxBuffer)); index++)
        {
            if (*mem_addr != aTxBuffer[index])
            {
                /*if data read is corrupted we can toggle a led here: example blue led*/
//              printf("Wrong access HyperRAM!!! 0x%p = 0x%X # 0x%X\n", mem_addr, *mem_addr, aTxBuffer[index]);
                error_total++;
            }
            else
            {
//              printf("Read data of address 0x%p = 0x%X\n", mem_addr, *mem_addr);
            }
            mem_addr++;
        }
        address += HYPERRAM_BLOCK_SIZE;
    }
    time_total = HAL_GetTick() - tick_start;
    printf("Read %ld bytes in %.04fs. Total error = %ld, Error rate %.02f %%\r\n", HYPERRAM_SIZE, (double)time_total / 1000, error_total,
            ((double) (error_total) / HYPERRAM_SIZE) * 100);
    if (error_total > 0)
    {
        return HyperRAM_ERROR;
    }
    else
    {
        return HyperRAM_OK;
    }
}
HyperRAM_StatusTypeDef HyperRAM_WriteReadRegion_TestPerformance (uint32_t add, uint32_t length)
{
    __IO uint8_t *mem_addr;
    uint32_t error_total = 0;
    uint32_t address = add;
    uint32_t tick_start = 0;
    uint32_t time_total = 0;
    uint8_t data = 0x00;
    printf("Size of FrameBuffer = %ld\r\n", length);
    /*--------------------------------START WRITE--------------------------------------*/
    tick_start = HAL_GetTick();
    mem_addr = (__IO uint8_t *)address;
    for (uint32_t i = 0; i < length; i++)
    {
        /* Writing Sequence of data lenght */
        *mem_addr++ = data++;
    }
    time_total = HAL_GetTick() - tick_start;
    printf("Writing Sequence of %ld bytes OK with %.04fs\r\n", length, (double)time_total / 1000);
    /*--------------------------------START READ--------------------------------------*/
    tick_start = HAL_GetTick();
    mem_addr = (__IO uint8_t *)address;
    data = 0x00;
    for (uint32_t i = 0; i < length; i++)
    {
        /* Reading Sequence of data length */
        if (*mem_addr != data)
        {
            /*if data read is corrupted we can toggle a led here: example blue led*/
//          printf("Wrong access HyperRAM!!! 0x%p = 0x%X # 0x%X\n", mem_addr, *mem_addr, data);
            error_total++;
        }
        else
        {
//          printf("Read data of address 0x%p OK = 0x%X\n", mem_addr, *mem_addr);
        }
        mem_addr++;
        data++;
    }
    time_total = HAL_GetTick() - tick_start;
    printf("Read %ld bytes in %.04fs. Total error = %ld, Error rate %.02f %%\r\n", length, (double)time_total / 1000, error_total,
            ((double) (error_total) / length) * 100);
    if (error_total > 0)
    {
        return HyperRAM_ERROR;
    }
    else
    {
        return HyperRAM_OK;
    }
}
/* Do not use this function */
void HyperRAM_DelayBlock_Calibration(void)
{
	/*buffer used for calibration*/
	uint8_t Cal_buffer[] = " ****Delay Block Calibration Buffer**** ****Delay\
	Block Calibration Buffer**** ****Delay Block Calibration Buffer****\
	****Delay Block Calibration Buffer**** ****Delay Block Calibration\
	Buffer**** ****Delay Block Calibration Buffer**** ";
	uint16_t index;
	__IO uint8_t *mem_addr;
	uint8_t test_failed;
	uint8_t delay = 0x0;
	uint8_t Min_found = 0;
	uint8_t Max_found = 0;
	uint8_t Min_Window = 0x0;
	uint8_t Max_Window = 0xF;
	uint8_t Mid_window = 0;
	uint8_t calibration_ongoing = 1;
	uint32_t calib_times = 0;
	uint32_t total_error = 0;
	/* Write the Cal_buffer to the memory*/
	printf("Size of Cal_buffer = %d\r\n", sizeof(Cal_buffer));
	mem_addr = (__IO uint8_t *)(OCTOSPI_BASE);
	for (index = 0; index < sizeof(Cal_buffer) / sizeof(*(Cal_buffer)); index++)
	{
		*mem_addr = Cal_buffer[index];
		mem_addr++;
	}
	while (calibration_ongoing)
	{
		total_error = 0;
		/* update the Delayblock calibration */
		//HAL_RCCEx_OCTOSPIDelayConfig(delay, 0);
		MODIFY_REG(hospi.Instance->DCR1, OCTOSPI_DCR1_DLYBYP, (delay << OCTOSPI_DCR1_DLYBYP_Pos)) ;
		test_failed = 0;
		mem_addr = (__IO uint8_t *)(OCTOSPI_BASE);
		for (index = 0; index < sizeof(Cal_buffer) / sizeof(*(Cal_buffer)); index++)
		{
			/* Read the Cal_buffer from the memory*/
			if (*mem_addr != Cal_buffer[index])
			{
				/*incorrect data read*/
				test_failed = 1;
				total_error++;
			}
			mem_addr++;
		}
		/* search for the Min window */
		if (Min_found!=1)
		{
			if (test_failed == 1)
			{
				if (delay < 15)
				{
					delay++;
				}
				else
				{
					/* If delay set to maximum and error still detected: can't use external
					PSRAM */
//					Error_Handler();
					return;
				}
			}
			else
			{
				Min_Window = delay;
				Min_found=1;
				delay = 0xF;
			}
		}
		/* search for the Max window */
		else if (Max_found!=1)
		{
			if (test_failed == 1)
			{
				if (delay > 0)
				{
					delay--;
				}
				else
				{
					/* If delay set to minimum and error still detected: can't use external
					PSRAM */
//					Error_Handler();
					return;
				}
			}
			else
			{
				Max_Window = delay;
				Max_found=1;
			}
		}
		/* min and max delay window found, configure the delay block with the middle
		window value and exit calibration */
		else
		{
			Mid_window = (Max_Window+Min_Window)/2;
			//HAL_RCCEx_OCTOSPIDelayConfig(Mid_window, 0);
			MODIFY_REG(hospi.Instance->DCR1, OCTOSPI_DCR1_DLYBYP, (Mid_window << OCTOSPI_DCR1_DLYBYP_Pos)) ;
			/* exit calibration */
			calibration_ongoing = 0;
		}
		printf("Calib_times = %ld, total_error = %ld\n", ++calib_times, total_error);
	}
}

