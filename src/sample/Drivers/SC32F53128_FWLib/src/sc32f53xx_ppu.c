/**
  ******************************************************************************
  * @file    sc32f53xx_ppu.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the ppu functions.
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
#include "sc32f53xx_ppu.h"



/**
  * @brief Enables or disables the  Write SRAM  Section by DMA or CPU.
	* @param  SRAMWrite: specifies the Write SRAM  Section by DMA or CPU
  *   This parameter can be any combination of the following values:
	*     @arg PPU_SRAM_CPUWrite_0_1K
  *     @arg PPU_SRAM_CPUWrite_1_2K
  *     @arg PPU_SRAM_CPUWrite_2_3K
	*			...
	*     @arg PPU_SRAM_DMAWrite_0_1K	
	*     @arg PPU_SRAM_DMAWrite_1_2K	
	*     @arg PPU_SRAM_DMAWrite_2_3K	
	*     ....
  * @param[in]  NewState new state of Write SRAM  Section by DMA or CPU , value accepted ENABLE, DISABLE.
  * @retval None
  */
void PPU_SRAM_WriteSectionCmd(uint32_t SRAMWrite, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_PPU_SRAMWrite(SRAMWrite));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
			ACCESSEN_WRITE_KEY;
			PPU->RAM_PROT |= 	SRAMWrite;
  }
  else
  {
			ACCESSEN_WRITE_KEY;
			PPU->RAM_PROT &= 	~SRAMWrite;
  }
}



/**
  * @brief  Enables or disables the specified PPU interrupts.
  * @param  PPU_IT: specifies the PPU interrupts sources to be enabled
  *   or disabled. 
  *   This parameter can be any combination of the following values:
  *     @arg PPU_IT_RAM: RAM Write failure interrupt 
  *     @arg PPU_IT_HPS01: HPS01 Write failure interrupt
  *     @arg PPU_IT_HPS01: HPS01 Write failure interrupt
	*     @arg PPU_IT_PPS01: PPS01 Write failure interrupt
  *     @arg PPU_IT_PPS23: PPS23 Write failure interrupt
  * @param  NewState: new state of the specified PPU interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void PPU_ITConfig(uint32_t PPU_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_PPU_IT(PPU_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
			ACCESSEN_WRITE_KEY;
			PPU->CTRL |= 	PPU_IT;
  }
  else
  {
			ACCESSEN_WRITE_KEY;
			PPU->CTRL &= 	~PPU_IT;
  }
}


/**
  * @brief  PPU interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void PPU_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(SYS_IRQn);
    NVIC_SetPriority(SYS_IRQn,priority);   
    NVIC_EnableIRQ(SYS_IRQn);               
}

/**
  * @brief  PPU interrupt disenable set.
  * @retval None
  */
void PPU_DisableIRQ(void)
{  
    NVIC_DisableIRQ(SYS_IRQn);               
}

/**
  * @brief Enables or disables the register HPS01.
	* @param  Px: specifies the Register HPS01 bit
  *   This parameter can be any combination of the following values:
	*     @arg PPU_HPS01_PA: PA write enable bit
  *     @arg PPU_HPS01_PB: PB write enable bit
  *     @arg PPU_HPS01_PC: PC write enable bit
	*     @arg PPU_HPS01_PF: PF write enable bit
  * @param[in]  NewState new state of the register HPS01 , value accepted ENABLE, DISABLE.
  * @retval None
  */
void PPU_HPS01Cmd(uint32_t Px,FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_PPU_HPS01_Px(Px));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				PPU->HPS01_PROT |= 	Px;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				PPU->HPS01_PROT &= 	~Px;
		}
}

/**
  * @brief Enables or disables the register HPS01.
  * @param[in]  NewState new state of the register HPS23 , value accepted ENABLE, DISABLE.
  * @retval None
  */
void PPU_HPS23Cmd(FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				PPU->HPS23_PROT_b.CRCWEN = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				PPU->HPS23_PROT_b.CRCWEN = 0;
		}
}

/**
  * @brief Enables or disables the register PPS01.
	* @param  PPx: specifies the Register PPS01 bit
  *   This parameter can be any combination of the following values:
	*     @arg PPU_PPS01_SYSCFG: SYSCFG write enable bit
  *     @arg PPU_PPS01_CHIPCTRL: CHIPCTRL write enable bit
  *     @arg PPU_PPS01_ERU: ERU write enable bit
	*     @arg PPU_PPS01_DMA: DMA write enable bit
	*     @arg PPU_PPS01_EFLASH: EFLASH write enable bit
  *     @arg PPU_PPS01_WDT: WDT write enable bit
  *     @arg PPU_PPS01_Uart1: Uart1 write enable bit
	*     @arg PPU_PPS01_Uart2: Uart2 write enable bit
	*     @arg PPU_PPS01_Uart3: Uart3 write enable bit
  *     @arg PPU_PPS01_Uart4: Uart4 write enable bit
  *     @arg PPU_PPS01_Uart5: Uart5 write enable bit
	*     @arg PPU_PPS01_Uart6: Uart6 write enable bit
	*     @arg PPU_PPS01_I2C: I2C write enable bit
  *     @arg PPU_PPS01_SSP: SSP write enable bit
  * @param[in]  NewState new state of the register PPS01 , value accepted ENABLE, DISABLE.
  * @retval None
  */
void PPU_PPS01Cmd(uint32_t PPx,FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_PPU_PPS01_PPx(PPx));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				PPU->PPS01_PROT |= 	PPx;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				PPU->PPS01_PROT &= 	~PPx;
		}
}


/**
  * @brief Enables or disables the register PPS23.
	* @param  PPx: specifies the Register PPS23 bit
  *   This parameter can be any combination of the following values:
	*     @arg PPU_PPS23_TIM14: TIM14 write enable bit
  *     @arg PPU_PPS23_TIM15: TIM15 write enable bit
  *     @arg PPU_PPS23_TIM16: TIM16 write enable bit
	*     @arg PPU_PPS23_TIM17: TIM17 write enable bit
	*     @arg PPU_PPS23_ADC: ADC write enable bit
  *     @arg PPU_PPS23_ACMP_OPA: ACMP_OPA write enable bit
  *     @arg PPU_PPS23_TIM1: TIM1 write enable bit
	*     @arg PPU_PPS23_TIM3: TIM3 write enable bit
	*     @arg PPU_PPS23_LED: LED write enable bit
  * @param[in]  NewState new state of the register PPS23 , value accepted ENABLE, DISABLE.
  * @retval None
  */
void PPU_PPS23Cmd(uint32_t PPx,FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_PPU_PPS23_PPx(PPx));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				PPU->PPS23_PROT |= 	PPx;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				PPU->PPS23_PROT &= 	~PPx;
		}
}


/**
  * @brief  whether SRA Section is write enable or disable.
  * @param  SRAMWrite: SRAMWrite can be SRAM 0~16K DMA¡¢SRAM 0~16K CPU.
  * @retval The new state of  SRA Section write Status(enable or disable).
  */
FunctionalState PPU_GetSRAMWirteSectionStatus(uint32_t SRAMWrite)
{
  FunctionalState bitstatus = DISABLE;
  /* Check the parameters */	
  assert_param(IS_PPU_SRAMWrite(SRAMWrite));
	
	if((PPU->RAM_TRAP & SRAMWrite) != (uint32_t)DISABLE)
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
  * @brief  whether PPU  HPS01 Px is write enable or disable.
  * @param  Px: x can be A,B,C,F.
  * @retval The new state of PPU HPS01 Px write Status(enable or disable).
  */
FunctionalState PPU_GetHPS01Status(uint32_t Px)
{
  FunctionalState bitstatus = DISABLE;
  /* Check the parameters */	
  assert_param(IS_PPU_HPS01_Px(Px));
	
	if((PPU->HPS01_TRAP & Px) != (uint32_t)DISABLE)
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
  * @brief  whether PPU  HPS23 COPROC is write enable or disable.
  * @param  None.
  * @retval The new state of PPU HPS23 COPROC write Status(enable or disable).
  */
FunctionalState PPU_GetHPS23Status(void)
{
  FunctionalState bitstatus = DISABLE;
	
	if((PPU->HPS23_TRAP_b.CRCS) != DISABLE)
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
  * @brief  whether PPU  PPS01 PPx is write enable or disable.
  * @param  PPx: PPx can be SYSCFG,CHIPCRTL,ERU,DMA,FLASH,WDT,UART1~6,I2C,SSP.
  * @retval The new state of PPU  PPS01 PPx write Status(enable or disable).
  */
FunctionalState PPU_GetPPS01Status(uint32_t PPx)
{
  FunctionalState bitstatus = DISABLE;
  /* Check the parameters */	
  assert_param(IS_PPU_PPS01_PPx(PPx));
	
	if((PPU->PPS01_TRAP & PPx) != (uint32_t)DISABLE)
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
  * @brief  whether PPU  PPS23 PPx is write enable or disable.
  * @param  PPx: PPx can be TIM1~17,ADC,LED,ACMP_OPA.
  * @retval The new state of PPU  PPS23 PPx write Status(enable or disable).
  */
FunctionalState PPU_GetPPS23Status(uint32_t PPx)
{
  FunctionalState bitstatus = DISABLE;
  /* Check the parameters */	
  assert_param(IS_PPU_PPS23_PPx(PPx));
	
	if((PPU->PPS23_TRAP & PPx) != (uint32_t)DISABLE)
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
  * @brief  Clears write SRAM Section by DMA or CPU Status.
  * @param  SRAMWrite: SRAMWrite can be SRAM 0~16K DMA¡¢SRAM 0~16K CPU.
  * @retval none.
  */
void PPU_ClearSRAMWirteSectionStatus(uint32_t SRAMWrite)
{
    /* Check the parameters */	
    assert_param(IS_PPU_SRAMWrite(SRAMWrite));
	
	  ACCESSEN_WRITE_KEY;
	  PPU->RAM_TRAP |= SRAMWrite;
}


/**
  * @brief  Clears the PPU  HPS01 Px write Status.
  * @param  Px: x can be A,B,C,F.
  * @retval None
  */
void PPU_ClearHPS01Status(uint32_t Px)
{
		/* Check the parameters */	
		assert_param(IS_PPU_HPS01_Px(Px));

		ACCESSEN_WRITE_KEY;
		PPU->HPS01_TRAP |= Px;
}

/**
  * @brief  Clears the PPU   HPS23 COPROC write Status.
  * @param  None.
  * @retval None.
  */
void PPU_ClearHPS23Status(void)
{
		ACCESSEN_WRITE_KEY;
		PPU->HPS23_TRAP_b.CRCS |= 1;
}

/**
  * @brief   Clears the PPU   PPS01 PPx write Status.
  * @param  PPx: PPx can be SYSCFG,CHIPCRTL,ERU,DMA,FLASH,WDT,UART1~6,I2C,SSP.
  * @retval None.
  */
void PPU_ClearPPS01Status(uint32_t PPx)
{
		/* Check the parameters */	
		assert_param(IS_PPU_PPS01_PPx(PPx));

		ACCESSEN_WRITE_KEY;
		PPU->PPS01_TRAP |= PPx;
}

/**
  * @brief   Clears the PPU   PPS23 PPx write Status.
  * @param  PPx: PPx can be TIM1~17,ADC,LED,ACMP_OPA.
  * @retval None.
  */
void PPU_ClearPPS23Status(uint32_t PPx)
{
		/* Check the parameters */	
		assert_param(IS_PPU_PPS23_PPx(PPx));

		ACCESSEN_WRITE_KEY;
		PPU->PPS23_TRAP |= PPx;
}

