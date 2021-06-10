/**
  ******************************************************************************
  * @file    sc32f53xx_flash.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the flash functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
  * AS A RESULT, SLMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
  * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
  * CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
  * INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
  * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
  * IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
  * <h2><center>&copy; COPYRIGHT 2019 Silan Microelectronics </center></h2>
  ********************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_flash.h"

/**
  * @brief  Enable or Disable the specified Flash Mode.
  * @param  Mode: specifies the Flash  Mode Enable Status to check.
  *   This parameter can be one of the following values:
	*     @arg FLASH_Mode_OPSTART: Flash Programming and Block erase start
  *     @arg FLASH_Mode_PROG: Flash Programming mode
  *     @arg FLASH_Mode_PAGE: Flash Block erase mode
  *     @arg FLASH_Mode_MASS: Flash Program area full erase mode
  *     @arg FLASH_Mode_RD: Flash Read mode
	*     @arg FLASH_Mode_NVR: Flash Information area operation mode
  *     @arg FLASH_Mode_BOOTKEY: Flash BOOT partition KEY matches mode
  *     @arg FLASH_Mode_USR1KEY: Flash USER1 partition KEY matches mode
	*     @arg FLASH_Mode_USR2KEY: Flash USER2 partition KEY matches mode
	* @param  NewState: new state of the Flash Mode. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void FLASH_Mode_Cmd(uint32_t Mode,FunctionalState NewState)
{
		uint32_t Temp;
		assert_param(IS_FLASH_Mode(Mode));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		switch(Mode)
		{
				case FLASH_Mode_OPSTART:
							if(NewState != DISABLE)
							{				  
									Temp = NVIC->ISER[0];
									NVIC->ICER[0] = 0xffffffff;
									EFLASH->FEED = 0x12345678;
									EFLASH->FEED = 0x87654321;								
								  EFLASH->CSET_b.OPSTART = 1;
									NVIC->ISER[0] = Temp;
							}
							break;
				case FLASH_Mode_PROG:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.PROGEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.PROGEN = 1;
							}
							break;
				case FLASH_Mode_PAGE:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.PAGEEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.PAGEEN = 1;
							}
							break;
				case FLASH_Mode_MASS:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.MASSEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.MASSEN = 1;
							}
							break;
				case FLASH_Mode_RD:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.RDEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.RDEN = 1;
							}
							break;
				case FLASH_Mode_NVR:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.NVREN = 1;
							}
							else
							{
									EFLASH->CCLR_b.NVREN = 1;
							}
							break;
				case FLASH_Mode_BOOTKEY:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.BOOTKEYEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.BOOTKEYEN = 1;
							}
							break;
				case FLASH_Mode_USR1KEY:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.USR1KEYEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.USR1KEYEN = 1;
							}
							break;
				case FLASH_Mode_USR2KEY:
							if(NewState != DISABLE)
							{
									EFLASH->CSET_b.USR2KEYEN = 1;
							}
							else
							{
									EFLASH->CCLR_b.USR2KEYEN = 1;
							}
							break;	
				default:
							break;
		}
}

/**
  * @brief  Get the specified Flash Mode Enable Status.
  * @param  Status: specifies the Flash  Mode Enable Status to check.
  *   This parameter can be one of the following values:
  *     @arg FLASH_Mode_PROG: Flash Programming mode
  *     @arg FLASH_Mode_PAGE: Flash Block erase mode
  *     @arg FLASH_Mode_MASS: Flash Program area full erase mode
  *     @arg FLASH_Mode_RD: Flash Read mode
	*     @arg FLASH_Mode_NVR: Flash Information area operation mode
  *     @arg FLASH_Mode_BOOTKEY: Flash BOOT partition KEY matches mode
  *     @arg FLASH_Mode_USR1KEY: Flash USER1 partition KEY matches mode
	*     @arg FLASH_Mode_USR2KEY: Flash USER2 partition KEY matches mode
  * @retval The new state of Flash Mode Enable Status (ENABLE or DISABLE).
  */
FunctionalState Flash_GetEnableStatus(uint32_t Status)
{
  uint32_t itmask;
  FunctionalState bitstatus = DISABLE;
  /* Check the parameters */
  assert_param(IS_FLASH_Enable_Status(Status));
	
	itmask = EFLASH->CTRL;
	itmask &= Status;
  if((itmask != (uint16_t)DISABLE))
  {
    bitstatus = ENABLE;
  }
  else
  {
    bitstatus = DISABLE;
  }
  
  return bitstatus;  
}

/**
  * @brief  Flash  Read-wait configuration.
  * @param  Delay: value of the  Flash  read-wait configuration. 
  *   This parameter can be any combination of the following values:
	*     @arg FLASH_Delay_No:  	no read-wait
  *     @arg FLASH_Delay_CLK1:  one clock read-wait
	*     @arg FLASH_Delay_CLK2:  two clock read-waits
  *     @arg FLASH_Delay_CLK3:  three clock read-waits
  * @retval None
  */
void FLASH_DelayCLK(uint32_t Delay)
{
		assert_param(IS_FLASH_Delay(Delay));
	
		EFLASH->CFG_b.READCFG = Delay;
}

/**
  * @brief  Flash  prefetch enable or disable.
  * @param  NewState: new state of the prefetch. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void FLASH_Prefetch_Cmd(FunctionalState NewState)
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				EFLASH->CFG_b.PREFETCHEN = 1;
		}
		else
		{
				EFLASH->CFG_b.PREFETCHEN = 0;
		}
}

/**
  * @brief  Flash Data prefetch enable or disable.
  * @param  NewState: new state of the Data prefetch. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void FLASH_DataPrefetch_Cmd(FunctionalState NewState)
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				EFLASH->CFG_b.NODATAPRF = 1;
		}
		else
		{
				EFLASH->CFG_b.NODATAPRF = 0;
		}
}

/**
  * @brief  The goal is config the address to write.
  * @param  Address:specifies the address to write.
  * @retval None
  */
void FLASH_WriteADDR(uint32_t Address)
{	
		EFLASH->ADDR = Address;
}

/**
  * @brief  The goal is config the data to write.
  * @param  Data:specifies the data to write.
  * @retval None
  */
void FLASH_WriteDATA(uint32_t Data)
{
		EFLASH->DATA = Data;
}


/**
  * @brief  The goal is to start FLASH programmer or block erase.
  * @param  None.
  * @retval None
  */
void FLASH_WriteFEED(void)
{
		EFLASH->FEED = 0x12345678;
		EFLASH->FEED = 0x87654321;
}

/**
  * @brief  Flash interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void Flash_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(SYS_IRQn);
    NVIC_SetPriority(SYS_IRQn,priority);   
    NVIC_EnableIRQ(SYS_IRQn);               
}

/**
  * @brief  Flash interrupt disable set.
  * @retval None
  */
void Flash_DisableIRQ(void)
{  
    NVIC_DisableIRQ(SYS_IRQn);               
}

/**
  * @brief  Clear the specified Flash interrupt Flag.
  * @param  ITSource: specifies the Flash interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg FLASH_IT_Complete:  OverRun Error interrupt
  *     @arg FLASH_IT_Protect:  Break Error Interrupt
  *     @arg FLASH_IT_Error:  Parity Error interrupt
  *     @arg FLASH_IT_RCHOff:  Framing Error Interrupt
  *     @arg FLASH_IT_DRDErr:  Receive Ttimeout Interrupt
	* @param  NewState: new state of the DMAy Channelx. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void Flash_ITCmd(uint32_t ITSource, FunctionalState NewState)
{
		assert_param(IS_FLASH_IT(ITSource));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{			
				EFLASH->IEN |= ITSource;
		}
		else
		{
				EFLASH->IEN &= ~ITSource;
		}
}

/**
  * @brief  Get the specified Flash interrupt Flag.
  * @param  ITSource: specifies the Flash interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg FLASH_IT_Complete:  OverRun Error interrupt
  *     @arg FLASH_IT_Protect:  Break Error Interrupt
  *     @arg FLASH_IT_Error:  Parity Error interrupt
  *     @arg FLASH_IT_RCHOff:  Framing Error Interrupt
  *     @arg FLASH_IT_DRDErr:  Receive Ttimeout Interrupt
  * @retval The new state of Flash interrupt (SET or RESET).
  */
ITStatus Flash_GetITStatus(uint32_t ITSource)
{
  uint32_t itmask;
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_FLASH_IT(ITSource));
	
	itmask = EFLASH->ISR;
	itmask &= ITSource;
  if ((itmask != (uint16_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  
  return bitstatus;  
}


/**
  * @brief  Clear the specified Flash interrupt Flag.
  * @param  ITSource: specifies the Flash interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg FLASH_IT_Complete:  OverRun Error interrupt
  *     @arg FLASH_IT_Protect:  Break Error Interrupt
  *     @arg FLASH_IT_Error:  Parity Error interrupt
  *     @arg FLASH_IT_RCHOff:  Framing Error Interrupt
  *     @arg FLASH_IT_DRDErr:  Receive Ttimeout Interrupt
  * @retval None.
  */
void Flash_ClearITFlag(uint32_t ITSource)
{
  /* Check the parameters */
  assert_param(IS_FLASH_IT(ITSource));
	
	EFLASH->ICR |= ITSource;
}

/**
  * @brief  Get the specified Flash Work Status.
  * @param  Status: specifies the Flash  Work Status to check.
  *   This parameter can be one of the following values:
  *     @arg FLASH_Status_BOOTPAREN: BOOT partition status
  *     @arg FLASH_Status_USR1PAREN: USR1 partition status
  *     @arg FLASH_Status_USR2PAREN: USR2 partition status
  *     @arg FLASH_Status_BOOTCRCEN: BOOT CRC Check the enable status
	*     @arg FLASH_Status_USR1CRCEN: USR1 CRC Check the enable status
  *     @arg FLASH_Status_USR2CRCEN: USR2 CRC Check the enable status
  *     @arg FLASH_Status_BOOTKEYOK: BOOT CRC Key matching state 
  *     @arg FLASH_Status_USR1KEYOK: USR1 CRC Key matching state  
	*     @arg FLASH_Status_USR2KEYOK: USR2 CRC Key matching state  
  *     @arg FLASH_Status_BOOTCRCOK: BOOT Partition CRC check status
  *     @arg FLASH_Status_USR1CRCOK: USR1 Partition CRC check status 
  *     @arg FLASH_Status_USR2CRCOK: USR2 Partition CRC check status
  * @retval The new state of Flash Work Status (SET or RESET)..
  */
ITStatus Flash_GetWorkStatus(uint32_t Status)
{
  uint32_t itmask;
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_FLASH_Status(Status));
	
	itmask = EFLASH->STATUS;
	itmask &= Status;
  if((itmask != (uint16_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  
  return bitstatus;  
}

/**
  * @brief  Clear Flash controller reg
  * @retval None.
**/
void Flash_ClearControllerStatus(void)
{
	EFLASH->CCLR = 0xFF;
}

/**
  * @brief specifies flash  area key match
	* @param KeyArea: specifies the Flash key match area.
	* @param FLASH_KEY1: specifies the Flash key 0~31 bits.
	* @param FLASH_KEY2: specifies the Flash key 32~63 bits.
	* @param FLASH_KEY3: specifies the Flash key 64~95 bits.
	* @param FLASH_KEY4: specifies the Flash key 96~127 bits.
  * @retval None.
  */
void Flash_KeyMatch(uint32_t KeyArea,uint32_t FLASH_KEY1,uint32_t FLASH_KEY2,uint32_t FLASH_KEY3,uint32_t FLASH_KEY4)
{	
	assert_param(IS_FLASH_KeyArea(KeyArea));
	
	FLASH_Mode_Cmd(KeyArea,ENABLE);

	EFLASH->KEY1 = FLASH_KEY1;
	EFLASH->KEY2 = FLASH_KEY2;
	EFLASH->KEY3 = FLASH_KEY3;
	EFLASH->KEY4 = FLASH_KEY4;
	
	FLASH_Mode_Cmd(KeyArea,DISABLE);
}

/**
  * @brief program flash page,flash should be erased before program.
	* @param page_num: 512 bytes per page,64kb flash have 80 pages and 128kb have 160 pages
  * @param dataLen:1~512bytes
  * @param *data:program data pointer
  * @retval None.
  */
void Flash_ProgramPage(uint32_t page_num,uint16_t dataLen,uint32_t *data)
{
	uint32_t pageAddr = page_num*512;
	
	assert_param(dataLen%4 == 0);
	
	Flash_ClearControllerStatus();
	Flash_ITCmd(FLASH_IT_ALL,ENABLE);
	Flash_ClearITFlag(FLASH_IT_ALL);
	
	while(dataLen)
	{
		FLASH_Mode_Cmd(FLASH_Mode_PROG,ENABLE);
		FLASH_WriteADDR(pageAddr);
		
		FLASH_WriteDATA(*data);
		
	  FLASH_Mode_Cmd(FLASH_Mode_OPSTART,ENABLE);

		while((Flash_GetITStatus(FLASH_IT_Complete) & 0x01) == 0x00);
		Flash_ClearITFlag(FLASH_IT_Complete);
		
		data += 1;
		pageAddr += 4;
		dataLen -=4;
	}
	Flash_ITCmd(FLASH_IT_ALL,DISABLE);
}

/**
  * @brief erase flash page
	* @param page_num: 512 bytes per page,64kb flash have 80 pages and 128kb have 160 pages
  * @retval None.
  */
void Flash_ErasePage(uint8_t page_num)
{	
	Flash_ClearControllerStatus();
	Flash_ITCmd(FLASH_IT_ALL,ENABLE);
	Flash_ClearITFlag(FLASH_IT_ALL);
	
	FLASH_Mode_Cmd(FLASH_Mode_PAGE,ENABLE);
	FLASH_WriteADDR(page_num*512);
	
	FLASH_Mode_Cmd(FLASH_Mode_OPSTART,ENABLE);
	while((Flash_GetITStatus(FLASH_IT_Complete) & 0x01) == 0x00);
	
	Flash_ClearITFlag(FLASH_IT_Complete);
	Flash_ITCmd(FLASH_IT_ALL,DISABLE);
}

