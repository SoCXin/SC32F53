/**
  ******************************************************************************
  * @file    sc32f53xx_iwdt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    27-05-2019
  * @brief   This file provides all the IWDT firmware functions.
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
#include "sc32f53xx_iwdt.h"


#define IWDT_CTRL_ENABLE   (CHIPCTL->IWDT_CTRL = 0x05faccccul)

/**
  * @brief  Enables IWDG(If it's the first time the value is written, start iwdt).
  * @note   By updating the iwdt_status register to 1, write the value to generate the feeding operation
  * @param  None
  * @retval None
  */
void IWDT_Enable(void)
{
	CHIPCTL_WRITE_KEY;
	IWDT_CTRL_ENABLE;
}

/**
  * @brief  Sets IWDT Prescaler value.
  * @param  IWDT_Prescaler: specifies the IWDT Prescaler value.
  *   This parameter can be one of the following values:
  *     @arg IWDT_Prescaler_1: IWDT prescaler set to 1
  *     @arg IWDT_Prescaler_2: IWDT prescaler set to 2
  *     @arg IWDT_Prescaler_4: IWDT prescaler set to 4
  *     @arg IWDT_Prescaler_8: IWDT prescaler set to 8
  *     @arg IWDT_Prescaler_16: IWDT prescaler set to 16
  *     @arg IWDT_Prescaler_32: IWDT prescaler set to 32
  *     @arg IWDT_Prescaler_64: IWDT prescaler set to 64
  *     @arg IWDT_Prescaler_128: IWDT prescaler set to 128
  *     @arg IWDT_Prescaler_256: IWDT prescaler set to 256
  * @retval None
  */
void IWDT_SetPrescaler(uint8_t IWDT_Prescaler)
{
  /* Check the parameters */
  assert_param(IS_IWDT_PRESCALER(IWDT_Prescaler));
	
	CHIPCTL_WRITE_KEY;
  CHIPCTL->IWDT_CLKDIV = IWDT_Prescaler;
}

/**
  * @brief  Sets IWDT Reload value.
  * @param  Reload: specifies the IWDT Reload value.
  *   This parameter must be a number between 0 and 0xFFFF.
  * @retval None
  */
void IWDT_SetReload(uint16_t Reload)
{
  /* Check the parameters */
  assert_param(IS_IWDT_RELOAD(Reload));
	
	CHIPCTL_WRITE_KEY;
  CHIPCTL->IWDT_RLD = Reload;
}

/**
  * @brief  Sets IWDT Window value.
  * @param  Reload: specifies the IWDT Window value.
  *   This parameter must be @arg RLD, @arg RLD/2.
  * @retval None
  */
void IWDT_SetWin(WinSel_Typedef Win_Value)
{
	CHIPCTL_WRITE_KEY;
  CHIPCTL->IWDT_CFG_b.WINSEL = Win_Value;
}

/**
  * @brief Enables or disables the window function.
  * @param[in] NewState new state of WINEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void IWDT_WINENCmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set WINEN bit */
    CHIPCTL->IWDT_CFG_b.WINEN = 1;
  }
  else
  {
		/* Reset WINEN bit */
		CHIPCTL_WRITE_KEY;
    CHIPCTL->IWDT_CFG_b.WINEN = 0;
  }
}

/**
  * @brief  Checks whether the specified IWDT Window mode flag is set or not.
  * @param  IWDT_FLAG: specifies the flag to check.
  * @retval The new state of IWDT_FLAG (SET or RESET).
  */
FlagStatus IWDT_GetFlagStatus(uint16_t IWDT_FLAG)
{
  FlagStatus bitstatus = RESET;

  if ((CHIPCTL->IWDT_STATUS & CHIPCTL_IWDT_STATUS_INTR_Msk) != (uint32_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  /* Return the flag status */
  return bitstatus;
}

/**
  * @brief  Clears IWDT Flag.
  * @param  None
  * @retval None
  */
void IWDT_ClearFlag(void)
{
  CHIPCTL_WRITE_KEY;
	CHIPCTL->IWDT_CTRL = 0x05facccc;
}

/**
  * @brief  Read Current count.
  * @param  None
  * @retval return IWDT Current count.
  */
uint16_t IWDT_ReadCnt(void)
{
		uint16_t Cnt;
		Cnt = CHIPCTL->IWDT_STATUS_b.CNT;
		return Cnt;
}

/**
  * @brief  IWDT interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void IWDT_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(IWDT_IRQn);
    NVIC_SetPriority(IWDT_IRQn,priority);   
    NVIC_EnableIRQ(IWDT_IRQn);               
}

/**
  * @brief  IWDT interrupt disenable set.
  * @retval None
  */
void IWDT_DisableIRQ(void)
{  
    NVIC_DisableIRQ(IWDT_IRQn);               
}

