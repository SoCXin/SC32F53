/**
  ******************************************************************************
  * @file    sc32f53xx_wt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    25-05-2019
  * @brief   This file provides all the WT firmware functions.
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
#include "sc32f53xx_wt.h"



/**
  * @brief Enables or disables the WT.
  * @param[in] NewState new state of WT_EN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void WT_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set RCHEN bit */
    CHIPCTL->WT_CTRL_b.WT_EN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset RCHEN bit */
    CHIPCTL->WT_CTRL_b.WT_EN = 0;
  }
}

/**
  * @brief  WT interrupt enable set.
  * @param[in] NewState new state of WT_EN.
               This parameter can be: ENABLE or DISABLE.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void WT_IRQCmd(FunctionalState NewState, uint16_t priority)
{
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
	  NVIC_ClearPendingIRQ(WT_IRQn);
	  NVIC_SetPriority(WT_IRQn,priority);
	  NVIC_EnableIRQ(WT_IRQn);
    CHIPCTL_WRITE_KEY;
		/* Set INTEN bit */
    CHIPCTL->WT_CTRL_b.INTEN = 1;
  }
  else
  {	
		NVIC_DisableIRQ(WT_IRQn);
		CHIPCTL_WRITE_KEY;
		/* Reset INTEN bit */
    CHIPCTL->WT_CTRL_b.INTEN = 0;
  }  
}

/**
  * @brief  Selects the Buzzer frequency.
  * @param[in] BUZ_Frequency : Specifies the Buzzer frequency.
	*   This parameter can be one of the following values:
  *     @arg BUZ_8192HZ;	
  *     @arg BUZ_4096HZ;
	*     @arg BUZ_2048HZ;
	*     @arg BUZ_1024HZ;
  * @retval None
  */
void WT_BUZSEL(BUZSEL_Typedef BUZ_Frequency)
{
	/* Check the parameters */
	assert_param(IS_WT_BUZSEL(BUZ_Frequency));
	
  CHIPCTL_WRITE_KEY;
	CHIPCTL->WT_CTRL_b.BUZ_SEL = BUZ_Frequency;	
}

/**
  * @brief  Selects scintillation frequency.
  * @param[in] BUZ_Frequency : Specifies the scintillation frequency.
	*   This parameter can be one of the following values:
  *     @arg BK_2HZ;	
  *     @arg BK_1HZ;
	*     @arg BK_0_5HZ;
	*     @arg BK_0_25HZ;
  * @retval None
  */
void WT_BKSEL(BKSEL_Typedef BK_Frequency)
{
	/* Check the parameters */
	assert_param(IS_WT_BKSEL(BK_Frequency));

  CHIPCTL_WRITE_KEY;
	CHIPCTL->WT_CTRL_b.BK_SEL = BK_Frequency;
}

/**
  * @brief  Sets WT Alerm value (Set wake-up time).
  * @param  Alerm_value: specifies the WT Alerm value.
  *   This parameter must be a number between 0 and 0xFF.
  * @retval None
  */
void WT_SetAlerm(uint8_t Alerm_value)
{
  /* Check the parameters */
  assert_param(IS_WT_ALERM(Alerm_value));
  
	CHIPCTL_WRITE_KEY;
	CHIPCTL->WT_ALERM_b.ALERM = Alerm_value;
}

/**
  * @brief  Checks whether the WT interrupt flag is set or not.
  * @param  None
  * @retval The new state of the WT interrupt flag (SET or RESET)
  */
FlagStatus WT_GetFlagStatus(void)
{
  return (FlagStatus)(CHIPCTL->WT_CTRL_b.INT);
}

/**
  * @brief  Clears WT interrupt flag.
  * @param  None
  * @retval None
  */
void WT_ClearFlag(void)
{
	CHIPCTL_WRITE_KEY;
  CHIPCTL->WT_CTRL_b.INT = 1;
}

/**
  * @brief  Read WT count cnt.
  * @param  None
  * @retval return WT count cnt
  */
uint32_t  WT_ReadCnt(void)
{
	uint32_t WTCnt;
	WTCnt = CHIPCTL->WT_CNT_b.WT_CNT;
	return WTCnt;
}


