/**
  ******************************************************************************
  * @file    sc32f53xx_led.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    22-05-2019
  * @brief   This file provides all the led firmware functions.
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
#include "sc32f53xx_led.h"


/**
  * @brief  Configures the LED mode .
  * @param  LED_ConfigStruct: pointer to a LED_ConfigStruct structure that
  *         contains the configuration information for the LED.
  * @retval None
  */
void LED_ModeConfig(LED_ConfigTypeDef* LED_ConfigStruct)
{
		assert_param(IS_LED_ScanMode(LED_ConfigStruct->LED_LEDITMD));
		assert_param(IS_LED_ModeSel(LED_ConfigStruct->LED_MODE));
		assert_param(IS_LED_UpdateMode(LED_ConfigStruct->LED_UPDMODE));
	
		/* Set the LED configuration bits */
		LED->LED_CTRL_b.LEDMD = (uint32_t)(LED_ConfigStruct->LED_LEDITMD);
		LED->LED_CTRL_b.MODE = (uint32_t)(LED_ConfigStruct->LED_MODE);
		LED->LED_CTRL_b.UPDMODE = (uint32_t)(LED_ConfigStruct->LED_UPDMODE);
}

/**
  * @brief  Fills each LED_ConfigStruct member with its default value.
  * @param  LED_ConfigStruct : pointer to a LED_ConfigTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void LED_ConfigStructInit(LED_ConfigTypeDef* LED_ConfigStruct)
{
  /* Set the default configuration */
  LED_ConfigStruct->LED_LEDITMD = LED_Scan_Continue;
  LED_ConfigStruct->LED_MODE = LED_ModeSel_1;
  LED_ConfigStruct->LED_UPDMODE = LED_LEDIF_Update;
}

/**
  * @brief Enables or disables the LED .
  * @param[in]  NewState new state of LEDON, value accepted ENABLE, DISABLE.
  * @retval None
  */
void LED_Cmd(FunctionalState NewState)
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
			/* Set LEDON bit */
			LED->LED_CTRL_b.LEDON = 1;
		}
		else
		{
			/* Reset LEDON bit */
			LED->LED_CTRL_b.LEDON = 0;
		}
}


/**
  * @brief  Configures the LED dead width and clock width .
  * @param  Clock_Width: specifies the LED clock width.This parameter can set(0~FF).
  * @param  Dead_Width: specifies the LED dead width.This parameter can set(0~FF),advice Dead_Width > 0x0A.
  * @retval None
  */
void LED_BasicConfig(uint8_t Clock_Width, uint8_t Dead_Width)
{
  /* Set LED clock width bits */	
  LED->DISCOM = Clock_Width;
  /* Set LED dead width bits */	
  LED->LEDDZ = Dead_Width;	
}

/**
  * @brief  Configure the number of COM and SEG.
  * @param  COM_Value: specifies the LED COM number.This parameter can set(0~FF).
  * @param  SEG_Value: specifies the LED SEG number.This parameter can set(0~FFFF).
  * @retval None
  */
void LED_COMSEGConfig(uint8_t COM_Value, uint16_t SEG_Value)
{
	/* Configure the COM  */
  LED->COMSEL = COM_Value;
	/* Configure the SEG  */
	LED->SEGSEL = SEG_Value;	
}


/**
  * @brief Enables or disables the LED interrupt.
	* @param ITSource: specifies the LED interrupt source to check.
	*   This parameter can be one of the following values:
  *     @arg LED_IT_COM: LED COM interrupt
  *     @arg LED_IT_Frame: LED complete a frame Interrupt
  * @param[in]  NewState new state of LED interrupt, value accepted ENABLE, DISABLE.
  * @retval None
  */
void LED_IRQCmd(uint16_t ITSource,FunctionalState NewState)
{
		assert_param(IS_LED_IT(ITSource));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		
		if (NewState != DISABLE)
		{
			/* set interrupt bit */
			LED->LED_CTRL |= ITSource;
		}
		else
		{
			/* Reset interrupt bit */
			LED->LED_CTRL &= ~ITSource;
		}
}


/**
  * @brief Checks whether LED interrupt flag is set or not.
	* @param ITSource: specifies the LED interrupt source to check.
	*   This parameter can be one of the following values:
  *     @arg LED_IT_COM: LED COM interrupt
  *     @arg LED_IT_Frame: LED complete a frame Interrupt
  * @retval The new state of LED interrupt (SET or RESET).
  */
ITStatus LED_GetITStatus(uint16_t ITSource)
{
  ITStatus status = RESET;

	if ((LED->LED_IF & ITSource) != (uint32_t)RESET)
	{
	  status = SET;
	}
	else
	{
	  status = RESET;
	}
	return status;
}

/**
  * @brief Clears the LED pending flags.
	* @param ITSource: specifies the LED interrupt source to check.
	*   This parameter can be one of the following values:
  *     @arg LED_IT_COM: LED COM interrupt
  *     @arg LED_IT_Frame: LED complete a frame Interrupt
  * @retval None
  */
void LED_ClearITStatus(uint16_t ITSource)
{
	LED->LED_IF = ITSource;
}


/**
  * @brief  Checks whether the LED IDLE status flag is set or not.
  * @retval The new state of IDLE flag (SET or RESET).
  */
FlagStatus LED_GetIDLEStatus(void)
{
  FlagStatus ledstatus = RESET;

	if ((LED->LED_IF_b.IDLE_ST & 0x01) != (uint32_t)RESET)
	{
	  ledstatus = SET;
	}
	else
	{
	  ledstatus = RESET;
	}
	return ledstatus;
}

/**
  * @brief  Write the RAM.
  * @param  RAM0_Value: specifies the LED_RAM0 value.
  * @param  RAM1_Value: specifies the LED_RAM1 value.
  * @param  RAM2_Value: specifies the LED_RAM2 value.
  * @param  RAM3_Value: specifies the LED_RAM3 value.
  * @retval None
  */
void LED_WriteRAM(uint32_t RAM0_Value, uint32_t RAM1_Value, uint32_t RAM2_Value, uint32_t RAM3_Value)
{
	/* Write the RAM  */
  LED->LED_RAM0 = RAM0_Value;
	LED->LED_RAM1 = RAM1_Value;
	LED->LED_RAM2 = RAM2_Value;
	LED->LED_RAM3 = RAM3_Value;
}

