/**
  ******************************************************************************
  * @file    sc32f53xx_cmp.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the cmp system firmware functions.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#include "sc32f53xx_cmp.h"


#define CP0CON_CLEAR_Mask          ((uint32_t)0xE0f006CC)            /*!< CMP CP0CON Mask */ 
#define CP0CFG_CLEAR_Mask          ((uint32_t)0xC00e0f07)            /*!< CMP CP0CFG Mask */ 


/**
  * @brief  Initializes the CMP according to 
  *         the specified parameters in the CMP_InitTypeDef.
  * @param  CMP_InitStruct: pointer to a CMP_InitTypeDef
  *         structure that contains the configuration information for the 
  *         specified CMP peripheral.
  * @retval None
  */
void CMP_BaseInit(CMP_InitTypeDef* CMP_InitStruct)
{
  uint32_t tmpreg;
	
  /* Check the parameters */
  assert_param(IS_CMP_Delay(CMP_InitStruct->CMP_Delay));
	assert_param(IS_CMP_PartVolt(CMP_InitStruct->CMP_PartVolt));
	assert_param(IS_CMP_VS(CMP_InitStruct->CMP_VS));
	assert_param(IS_CMP_CP0P(CMP_InitStruct->CMP_CP0P));
	assert_param(IS_CMP_CP0N(CMP_InitStruct->CMP_CP0N));
	assert_param(IS_CMP_CP0P0(CMP_InitStruct->CMP_CP0P0ExterCHx));
	assert_param(IS_CMP_CP0N0(CMP_InitStruct->CMP_CP0N0ExterCHx));
	assert_param(IS_CMP_Inv(CMP_InitStruct->CMP_Inv));
	assert_param(IS_CMP_C0RDSVal(CMP_InitStruct->C0RDSVal));
	
	
	tmpreg = ACMPOPA->CP0CON;
	tmpreg &= CP0CON_CLEAR_Mask;
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_Delay << 8);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_CP0N0ExterCHx << 26);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_CP0P0ExterCHx << 24);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_CP0N << 4);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_CP0P << 0);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_VS << 12);
	tmpreg |=  (uint32_t)(CMP_InitStruct->CMP_PartVolt << 13);
	tmpreg |=  (uint32_t)(CMP_InitStruct->C0RDSVal << 15);
	ACCESSEN_WRITE_KEY;
	ACMPOPA->CP0CON = tmpreg;
	
	tmpreg = ACMPOPA->CP0CFG;
	tmpreg &= ~ACMPOPA_CP0CFG_C0OINV_Msk;
	tmpreg |= CMP_InitStruct->CMP_Inv;
	ACCESSEN_WRITE_KEY;
	ACMPOPA->CP0CFG = tmpreg;
}

/**
  * @brief  Fills each CMP_InitStruct member with its default value.
  * @param  CMP_InitStruct : pointer to a CMP_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void CMP_InitStructInit(CMP_InitTypeDef* CMP_InitStruct)
{
  /* Set the default configuration */
  CMP_InitStruct->CMP_Delay = CMP_Delay_Disable;
  CMP_InitStruct->CMP_CP0N0ExterCHx = CMP_CP0N0_ExterCH0;
  CMP_InitStruct->CMP_CP0P0ExterCHx = CMP_CP0P0_ExterCH0;
  CMP_InitStruct->CMP_CP0N = CMP_CP0N_CVREF0;
  CMP_InitStruct->CMP_CP0P = CMP_CP0P_OP0O;
  CMP_InitStruct->CMP_VS = CMP_VS_VDD;
  CMP_InitStruct->CMP_PartVolt = CMP_PartVolt_Plan1;
  CMP_InitStruct->C0RDSVal = 0x00;
  CMP_InitStruct->CMP_Inv = CMP_UnreverseOut;
}


/**
  * @brief  Initializes the CMP Filt according to 
  *         the specified parameters in the CMP_FiltTypeDef.
  * @param  CMP_FiltStruct: pointer to a CMP_FiltTypeDef
  *         structure that contains the configuration information for the 
  *         specified CMP Filt peripheral.
  * @retval None
  */
void CMP_FiltInit(CMP_FiltTypeDef* CMP_FiltStruct)
{
  uint32_t tmpreg;
	
  /* Check the parameters */
  assert_param(IS_CMP_OutSynch(CMP_FiltStruct->CMP_OutSynch));
	assert_param(IS_CMP_OutGate(CMP_FiltStruct->CMP_OutGate));
	assert_param(IS_CMP_FiltCycle(CMP_FiltStruct->CMP_FiltCycle));
	assert_param(IS_CMP_FiltCLKDIV(CMP_FiltStruct->CMP_FiltCLKDIV));

	tmpreg = ACMPOPA->CP0CFG;
	tmpreg &= CP0CFG_CLEAR_Mask;
	tmpreg |=  (uint32_t)(CMP_FiltStruct->CMP_FiltCycle << 20);
	tmpreg |=  (uint32_t)(CMP_FiltStruct->CMP_FiltCLKDIV << 12);
	tmpreg |=  (uint32_t)(CMP_FiltStruct->CMP_OutGate << 3);
	tmpreg |=  (uint32_t)(CMP_FiltStruct->CMP_OutSynch << 4);
	ACCESSEN_WRITE_KEY;
	ACMPOPA->CP0CON = tmpreg;

}

/**
  * @brief  Fills each CMP_FiltStruct member with its default value.
  * @param  CMP_FiltStruct : pointer to a CMP_FiltTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void CMP_FiltStructInit(CMP_FiltTypeDef* CMP_FiltStruct)
{
  /* Set the default configuration */
  CMP_FiltStruct->CMP_FiltCycle = 0;
	CMP_FiltStruct->CMP_FiltCLKDIV = 0;
  CMP_FiltStruct->CMP_OutGate = CMP_OutGate_No;
  CMP_FiltStruct->CMP_OutSynch = CMP_OutSynch_No;
}


/**
  * @brief  Enables or disables the specified CMP peripheral.
  * @param  NewState: new state of the CMP peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CMP_Cmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0EN = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0EN = 0;
		}
}

/**
  * @brief  Enables or disables the  CMP CVREF0 peripheral.
  * @param  NewState: new state of the CMP CVREF0 peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CMP_CVREF0_Cmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0REFEN = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0REFEN = 1;
		}
}

/**
  * @brief  Enables or disables the  CMP CVREF0 output .
  * @param  NewState: new state of the CMP CVREF0 peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CMP_CVREF0_Output_Cmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0REFOES = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0REFOES = 0;
		}
}

/**
  * @brief  Enables or disables the specified CMP out analog Filter bit.
  * @param  NewState: new state of the CMP out analog Filter bit. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CMP_AnalogFilt_Cmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0AFILT = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CON_b.C0AFILT = 0;
		}
}


/**
  * @brief  Config CMP IT Trig_Source Enable or Disable
	* @param  NewState: new state of the CMP IT. 
  *   This parameter can be: ENABLE or DISABLE.
  * @param  IRQ : what is Interrupt trigger condition.
	*   This parameter can be any combination of the following values:
  *     @arg CMP_IRQNo:  No  Interrupt
  *     @arg CMP_IRQRising:  Rising edge interruption
	*     @arg CMP_IRQFalling: Falling edge interruption
  *     @arg CMP_IRQEdge:  Rising /Falling edge interruption
  * @retval None
  */
void CMP_ITConfig(CMPIRQ_TypeDef IRQ,FunctionalState NewState)
{
	
		assert_param(IS_CMP_IRQ(IRQ));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		
		ACCESSEN_WRITE_KEY;
		ACMPOPA->CP0CFG_b.C0INTS &= ~ACMPOPA_CP0CFG_C0INTS_Msk;
		ACCESSEN_WRITE_KEY;
		ACMPOPA->CP0CFG_b.C0INTS |= IRQ;
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CFG_b.C0INTM = 0;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->CP0CFG_b.C0INTM = 1;
		}
}  

/**
  * @brief  CMP interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void CMP_EnableIRQ(uint16_t priority)
{
		NVIC_ClearPendingIRQ(ACMPOPA_IRQn);
    NVIC_SetPriority(ACMPOPA_IRQn,priority);   
    NVIC_EnableIRQ(ACMPOPA_IRQn);
}

/**
  * @brief  CMP interrupt disenable set.
  * @retval None
  */
void CMP_DisableIRQ(void) 
{
		NVIC_DisableIRQ(ACMPOPA_IRQn);
}

/**
  * @brief  Checks whether SSP interrupt flag is set or not.
  * @param  None
  * @retval The new state of CMP interrupt (SET or RESET).
  */
ITStatus CMP_GetIRQStatus(void)
{
  ITStatus bitstatus = RESET;
	
	if((ACMPOPA->CP0CFG_b.C0FLG) != (uint32_t)RESET)
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
  * @brief  Clear CMP interrupt flag.
  * @param  None
  * @retval None
  */
void CMP_ClearIRQStatus(void)
{
		ACCESSEN_WRITE_KEY;
		ACMPOPA->CP0CFG_b.C0FLG = 1;
}



