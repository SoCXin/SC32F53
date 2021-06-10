/**
  ******************************************************************************
  * @file    sc32f53xx_wdt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    23-05-2019
  * @brief   This file provides all the WDT firmware functions.
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
#include "sc32f53xx_wdt.h"


#define WDT_WRITE_KEY   (CHIPCTL->CHIP_KEY =0x1ACCE551ul)

/**
  * @brief  Sets WDT Reload value.
  * @param  Reload: specifies the WDT Reload value.
  *   This parameter must be a number between 1 and 0xFFFFFFFF.
  * @retval None
  */
void WDT_SetReload(uint32_t Reload_Value)
{
  /* Check the parameters */
  assert_param(IS_WDT_RELOAD(Reload_Value));
  WDT->WDOGLOAD = Reload_Value;
}

/**
  * @brief  Read WDT count value.
  * @param  none.
  * @retval return the WDT count value.
  */
uint32_t WDT_ReadCountVal(void)
{
	uint32_t CountVal;
  CountVal = WDT->WDOGVALUE;
	return CountVal;
}

/**
  * @brief Enables or disables the WDT Reset.
  * @param[in] NewState new state of RESEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void WDT_RESENCmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set RESEN bit */
    WDT->WDOGCONTROL_b.RSTEN = 1;
  }
  else
  {		
		/* Reset RESEN bit */
    WDT->WDOGCONTROL_b.RSTEN = 0;
  }
}

/**
  * @brief  WDT interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void WDT_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(WWDT_IRQn);
    NVIC_SetPriority(WWDT_IRQn,priority);   
    NVIC_EnableIRQ(WWDT_IRQn);               
}

/**
  * @brief  WDT interrupt disenable set.
  * @retval None
  */
void WDT_DisableIRQ(void)
{  
    NVIC_DisableIRQ(WWDT_IRQn);               
}


/**
  * @brief Enables or disables the WDT Interrupt.
  * @param[in] NewState new state of INTEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void WDT_INTENCmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set INTEN bit */
    WDT->WDOGCONTROL_b.INTEN = 1;
  }
  else
  {		
		/* Reset INTEN bit */
    WDT->WDOGCONTROL_b.INTEN = 0;
  }
}


/**
  * @brief  Checks whether the WDT Original interrupt flag is set or not.
  * @param  None
  * @retval The new state of the WDT Original interrupt flag (SET or RESET)
  */
FlagStatus WDT_GetOriginalFlag(void)
{
  return (FlagStatus)(WDT->WDOGRIS_b.WDOGINT);
}


/**
  * @brief  Checks whether the WDT interrupt flag is set or not.
  * @param  None
  * @retval The new state of the WDT interrupt flag (SET or RESET)
  */
FlagStatus WDT_GetITFlag(void)
{
  return (FlagStatus)(WDT->WDOGMIS_b.WDOGMINT);
}


/**
  * @brief  Clears WDT Interrupt flag.
  * @param  None
  * @retval None
  */
void WDT_ClearITFlag(void)
{
  WDT->WDOGINTCLR = 0xAA;
}
