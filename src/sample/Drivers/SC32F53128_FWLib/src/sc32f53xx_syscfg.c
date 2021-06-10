/**
  ******************************************************************************
  * @file    sc32f53xx_syscfg.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the syscfg functions.
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
#include "sc32f53xx_syscfg.h"

/**
  * @brief  Enables or disables the System RAM 0 Parity.
  * @param  NewState: new state of the System RAM 0 Parity. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SYSCFG_SysRam0ParityCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
			/* Enable the System RAM 0 Parity */
			ACCESSEN_WRITE_KEY;
			SYSCFG->SYSRAM_CTRL |= SYSCFG_SYSRAM_CTRL_SYSRAM0_PARITY_INTREN_Msk;
  }
  else
  {
			/* Disable the System RAM 0 Parity */
		  ACCESSEN_WRITE_KEY; 
      SYSCFG->SYSRAM_CTRL &= ~SYSCFG_SYSRAM_CTRL_SYSRAM0_PARITY_INTREN_Msk;
  }
}

/**
  * @brief  Enables or disables the System RAM 1 Parity.
  * @param  NewState: new state of the System RAM 1 Parity. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SYSCFG_SysRam1ParityCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
			/* Enable the System RAM 0 Parity */
			ACCESSEN_WRITE_KEY;
			SYSCFG->SYSRAM_CTRL |= SYSCFG_SYSRAM_CTRL_SYSRAM1_PARITY_INTREN_Msk;
  }
  else
  {
			/* Disable the System RAM 0 Parity */
			ACCESSEN_WRITE_KEY;
			SYSCFG->SYSRAM_CTRL &= ~SYSCFG_SYSRAM_CTRL_SYSRAM1_PARITY_INTREN_Msk;
  }
}

/**
  * @brief  Clear the System RAMx Parity error.
  * @param  RAMx: Specified the System RAM 1 Parity. 
  * This parameter can be: 
	*	@arg SysRAMx_Parity_RAM0,SysRAMx_Parity_RAM1.
  * @retval None
  */
void SYSCFG_ClearParityErr(uint32_t RAMx)
{
		/* Check the parameters */
		assert_param(IS_SysParity_RAMx(RAMx));

		ACCESSEN_WRITE_KEY;
		SYSCFG->SYSRAM_CTRL |= RAMx;
		SYSCFG->SYSRAM_CTRL &= ~RAMx;
}

/**
  * @brief  Enables or disables the UART3 Output in half duplex mode.
  * @param  NewState: new state of the System RAM 1 Parity. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SYSCFG_UART3_HalfDuplexModeCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
			/* Enable the UART3 Output in half duplex mode */		
			ACCESSEN_WRITE_KEY;
			SYSCFG->MISC_CTRL |= (uint32_t)(1<<2);
  }
  else
  {
			/* Disable the UART3 Output in half duplex mode */
			ACCESSEN_WRITE_KEY;
			SYSCFG->MISC_CTRL  &= ~(uint32_t)(1<<2);
  }
}

/**
  * @brief  Enables or disables the SYSCFG Stop TIMx Bkin3.
	* @param  StopTIMx: Specified Timer channel.
	*   This parameter can be:
	*	@arg SYSCFG_Bkin3_StopTIM1,SYSCFG_Bkin3_StopTIM3£¬
		SYSCFG_Bkin3_StopTIM15£¬SYSCFG_Bkin3_StopTIM16£¬SYSCFG_Bkin3_StopTIM17.
  * @param  NewState: new state of the System RAM 1 Parity. 
  *   This parameter can be: SET or RESET.
  * @retval None
  */
void SYSCFG_StopTIMxBkin3Config(uint32_t StopTIMx,FlagStatus NewState)
{
		/* Check the parameters */
		assert_param(IS_SYSCFG_Bkin3_StopTIMx(StopTIMx));
		assert_param(IS_FLAG_STATUS(NewState));
	
		if (NewState != RESET)
		{
				ACCESSEN_WRITE_KEY;
				SYSCFG->ETIMER_CFG |= StopTIMx;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				SYSCFG->ETIMER_CFG &= ~StopTIMx;
		}
}

/**
  * @brief  Select the SYSCFG  TIMx Bkin Fsel Value.
	 * @param  TIMx: Specified Timer channel,can be TIM1,3,15,16,17. 
  * @param  BkinFsel: Specified TIMx Bkin choose. 
  *   This parameter can be:any combination of the following values:
  *     @arg SYSCFG_TIMx_BkinFsel_StopTIMx:  choose TIMx Software to stop
  *     @arg SYSCFG_TIMx_BkinFsel_StopTIMxAndBkin:  choose TIMx Software to stop and TIMx_bkin[2:0]
  * @retval None
  */
void SYSCFG_TIMxBkinSelect(uint16_t TIMx,uint32_t BkinFsel)
{
		/* Check the parameters */
		assert_param(IS_SYSCFG_TIMx_BkinFsel(BkinFsel));
		assert_param(IS_SYSCFG_BkinFsel_TIMx(TIMx));
		
		if(BkinFsel == SYSCFG_TIMx_BkinFsel_StopTIMx)
		{
				ACCESSEN_WRITE_KEY;
				SYSCFG->ETIMER_CFG |= (uint32_t)(SYSCFG_TIMx_BkinFsel_StopTIMx << TIMx);
		}
		else
		{	
				ACCESSEN_WRITE_KEY;
				SYSCFG->ETIMER_CFG &= ~(uint32_t)(SYSCFG_TIMx_BkinFsel_StopTIMx << TIMx);
		}
}

/**
  * @brief  Select the Systick clock Source.
	* @param  CLKSource: Specified Systick clock Source. 
  *   This parameter can be:any combination of the following values:
  *     @arg SYSCFG_Systick_CLKSource_HCLK:  choose HCLK as the Systick clock Source
  *     @arg SYSCFG_Systick_CLKSource_RCL_HCLKRCHDiv:  choose HCLK/RCH Div Or External RCL as the Systick clock Source
  * @retval None
  */
void SYSCFG_SystickCLKSelect(uint32_t CLKSource)
{
		/* Check the parameters */
		assert_param(IS_SYSCFG_CLKSource(CLKSource));
		
		ACCESSEN_WRITE_KEY;
		SYSCFG->SYSTICK_CFG &= ~SYSCFG_SYSTICK_CFG_NOREF_Msk;
		SYSCFG->SYSTICK_CFG |= CLKSource;
}

/**
  * @brief   whether Systick clock is normal or skew.
  * @param  CLKStatus: Specified Systick clock status.
	*   This parameter can be:any combination of the following values:
  *     @arg SYSCFG_Systick_CLKStatus_Normal:  Systick clock status is Normal.
  *     @arg SYSCFG_Systick_CLKStatus_Skew:  Systick clock status is Skew.
  * @retval The new state of Systick clock status (SET(means Skew) or RESET(means Normal)).
  */
ITStatus SYSCFG_GetSystickCLKStatus(uint32_t CLKStatus)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_SYSCFG_CLKStatus(CLKStatus));
	
	if((SYSCFG->SYSTICK_CFG & CLKStatus) != (uint32_t)RESET)
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
  * @brief   config  Systick clock to be normal or skew.
  * @param  CLKStatus: Specified Systick clock status.
	*   This parameter can be:any combination of the following values:
  *     @arg SYSCFG_Systick_CLKStatus_Normal:  Systick clock status is Normal.
  *     @arg SYSCFG_Systick_CLKStatus_Skew:  Systick clock status is Skew.
  * @retval None.
  */
void SYSCFG_SystickCLKStatusConfig(uint32_t CLKStatus)
{
		/* Check the parameters */	
		assert_param(IS_SYSCFG_CLKStatus(CLKStatus));
	
		ACCESSEN_WRITE_KEY;
		SYSCFG->SYSTICK_CFG &= ~SYSCFG_SYSTICK_CFG_SKEW_Msk;
		SYSCFG->SYSTICK_CFG |= CLKStatus;
}

/**
  * @brief   Select  Systick clock calibration value.
  * @param  CLKCalibVal: Specified Systick clock calibration value.
  * @retval None.
  */
void SYSCFG_SystickCLKCalibValSelect(uint32_t CLKCalibVal)
{
		/* Check the parameters */	
		assert_param(IS_SYSCFG_CLKCalibVal(CLKCalibVal));
	
		ACCESSEN_WRITE_KEY;
		SYSCFG->SYSTICK_CFG &= ~SYSCFG_SYSTICK_CFG_STCALIB_Msk;
		SYSCFG->SYSTICK_CFG |= CLKCalibVal;
}

/**
  * @brief  SYSCFG interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void SYSCFG_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(SYS_IRQn);
    NVIC_SetPriority(SYS_IRQn,priority);   
    NVIC_EnableIRQ(SYS_IRQn);               
}

/**
  * @brief  SYSCFG interrupt disenable set.
  * @retval None
  */
void SYSCFG_DisableIRQ(void)
{  
    NVIC_DisableIRQ(SYS_IRQn);               
}

/**
  * @brief   whether System int Status is set or reset.
  * @param  Status: Specified System int Status.
	*   This parameter can be:any combination of the following values:
  *     @arg SYSCFG_SYSSAM1_ParityERR:  System RAM 1 Parity error.
	*     @arg SYSCFG_SYSSAM1_ParityERRIT:  System RAM 1 Parity error interrupt.
	*     @arg SYSCFG_SYSSAM0_ParityERR:  System RAM 1 Parity error.
	*     @arg SYSCFG_SYSSAM0_ParityERRIT:  System RAM 1 Parity error interrupt.
	*     @arg SYSCFG_FLASH_IT:  Flash interrupt.
  *     @arg SYSCFG_PPU_IT:   PPU interrupt.
  * @retval The new state of System int status (SET or RESET).
  */
ITStatus SYSCFG_GetSYSINTStatus(uint32_t Status)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_SYSCFG_SYSINT_Status(Status));
	
	if((SYSCFG->SYSINT_STATUS & Status) != (uint32_t)RESET)
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
  * @brief  where is the address of System RAM0 Parity Error.
  * @param  None
  * @retval The Address of System RAM0 Parity Error.
  */
uint16_t SYSCFG_GetSysRAM0ParityErrAddr(void)
{
  uint16_t itmask;
	
	itmask = (uint16_t)(SYSCFG->SYSRAM_STATUS_b.SYSRAM0_PARITY_ERR_ADDR);
  return itmask;  
}

/**
  * @brief  where is the address of System RAM1 Parity Error.
  * @param  None
  * @retval The Address of System RAM1 Parity Error.
  */
uint16_t SYSCFG_GetSysRAM1ParityErrAddr(void)
{
  uint16_t itmask;
	
	itmask = (uint16_t)(SYSCFG->SYSRAM_STATUS_b.SYSRAM1_PARITY_ERR_ADDR);
  return itmask;  
}


