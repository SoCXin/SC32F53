/**
  ******************************************************************************
  * @file    sc32f53xx_ssp.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the ssp firmware functions.
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
#include "sc32f53xx_ssp.h"


#define SSPCR0_CLEAR_Mask            ((uint16_t)0x0000)        /*!< SSP SSPCR0 Mask  */ 
#define SSPCR1_CLEAR_Mask            ((uint16_t)0xFFFA)        /*!< SSP SSPCR1 Mask  */ 

/**
  * @brief  Initializes the SSP according to 
  *         the specified parameters in the SSP_InitTypeDef.
  * @param  SSP_InitStruct: pointer to a SSP_InitTypeDef
  *         structure that contains the configuration information for the 
  *         specified SSP peripheral.
  * @retval None
  */
void SSP_Init(SSP_InitTypeDef* SSP_InitStruct)
{
		uint16_t tmpreg;
		
		/* Check the parameters */
		assert_param(IS_SSP_DataSize(SSP_InitStruct->SSP_SPH));
		assert_param(IS_SSP_DataSize(SSP_InitStruct->SSP_SPO));
		assert_param(IS_SSP_DataSize(SSP_InitStruct->SSP_DataSize));
		assert_param(IS_SSP_Format(SSP_InitStruct->SSP_Format));
		assert_param(IS_SSP_MS(SSP_InitStruct->SSP_MS));
		assert_param(IS_SSP_Mode(SSP_InitStruct->SSP_Mode));
		assert_param(IS_SSP_SRC_Div(SSP_InitStruct->SSP_SRC_Div));
		assert_param(IS_SSP_CPSDVSR_Div(SSP_InitStruct->SSP_CPSDVSR_Div));
	
		tmpreg = SSP->SSPCR0;
		tmpreg &= SSPCR0_CLEAR_Mask;
		tmpreg |= SSP_InitStruct->SSP_SPH;
		tmpreg |= SSP_InitStruct->SSP_SPO;
		tmpreg |= SSP_InitStruct->SSP_DataSize;
		tmpreg |= SSP_InitStruct->SSP_Format;
		tmpreg |= (SSP_InitStruct->SSP_SRC_Div<<8);
		SSP->SSPCR0 = (uint16_t)(tmpreg);
	
		tmpreg = SSP->SSPCR1;
		tmpreg &= SSPCR1_CLEAR_Mask;
		tmpreg |= SSP_InitStruct->SSP_MS;
		tmpreg |= SSP_InitStruct->SSP_Mode;
		SSP->SSPCR1 = (uint16_t)(tmpreg);
		
		SSP->SSPCPSR = (uint16_t)(SSP_InitStruct->SSP_CPSDVSR_Div);
}

/**
  * @brief  Fills each SSP_InitStruct member with its default value.
  * @param  SSP_InitStruct : pointer to a SSP_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void SSP_InitStructInit(SSP_InitTypeDef* SSP_InitStruct)
{
  /* Set the default configuration */
  SSP_InitStruct->SSP_SPH = SSP_SPH_Edge1;
  SSP_InitStruct->SSP_SPO = SSP_SPO_Low;
  SSP_InitStruct->SSP_DataSize = SSP_DataSize_Reserve;
  SSP_InitStruct->SSP_Format = SSP_Format_SPI;
  SSP_InitStruct->SSP_SRC_Div = 0;
  SSP_InitStruct->SSP_MS = SSP_MS_Master;
  SSP_InitStruct->SSP_Mode = SSP_Mode_Regular;
  SSP_InitStruct->SSP_CPSDVSR_Div = 0;
}


/**
  * @brief  Enables or disables the specified SSP peripheral.
  * @param  NewState: new state of the SSP peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SSP_Cmd(FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		if (NewState != DISABLE)
		{
				/* Enable the selected SPI peripheral */
				SSP->SSPCR1 |= SSP_SSPCR1_SSE_Msk;
		}
		else
		{
				/* Disable the selected SPI peripheral */
				SSP->SSPCR1 &= ~SSP_SSPCR1_SSE_Msk;
		}
}

/**
  * @brief  Enables or disables the specified SSP SlaveOut peripheral.
  * @param  NewState: new state of the SSP peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SSP_SlaveOut_Cmd(FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		if (NewState != DISABLE)
		{
				/* Enable SSP SlaveOut peripheral */
				SSP->SSPCR1 &= ~SSP_SSPCR1_SOD_Msk;
		}
		else
		{
				/* Disable  SSP SlaveOut peripheral */
				SSP->SSPCR1 |= SSP_SSPCR1_SOD_Msk;
		}
}

/**
  * @brief  Transmits a Data through the SSP peripheral.
  * @param  Data : Data to be transmitted.
  * @retval None
  */
void SSP_SendData(uint16_t Data)
{
  /* Write in the SSPDR register the data to be sent */
  SSP->SSPDR = Data;
}

/**
  * @brief  Returns the most recent received data by the SSP peripheral. 
  * @retval The value of the received data.
  */
uint16_t SSP_ReceiveData(void)
{ 
  /* Return the data in the SSPDR register */
  return SSP->SSPDR;
}


/**
  * @brief  Checks whether SSP Status is set or not.
  * @param  Status: what is the SSP work Status.
	*   This parameter can be any combination of the following values:
  *     @arg SSP_Status_Busy: Busy status  
  *     @arg SSP_Status_RFF:  Receive FIFO full status 
	*     @arg SSP_Status_RNE:  Receive FIFO empty status  
  *     @arg SSP_Status_TNF:  Send FIFO full status 
	*     @arg SSP_Status_TFE:  Send FIFO empty status  
  * @retval The new state of SSP interrupt (SET or RESET).
  */
FlagStatus SSP_GetWorkStatus(uint16_t Status)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_SSP_Status(Status));
	
	if((SSP->SSPSR & Status) != (uint32_t)RESET)
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
  * @brief  Config SSP IT Trig_Source Enable or Disable
	* @param  NewState: new state of the SSP IT. 
  *   This parameter can be: ENABLE or DISABLE.
  * @param  Trig_Source : what is Interrupt trigger condition.
	*   This parameter can be any combination of the following values:
  *     @arg SSP_IT_TX:  Send FIFO status interrupt 
  *     @arg SSP_IT_RX:  Receive FIFO status interrupt
	*     @arg SSP_IT_RT:  Receive timeout interrupt 
  *     @arg SSP_IT_ROR: Receive overrun interrupt 
  * @retval None
  */
void SSP_ITConfig(uint16_t Trig_Source,FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_SSP_IT(Trig_Source));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{
				/* Enable SSP Trig_Source peripheral */
				SSP->SSPIMSC |= Trig_Source;
		}
		else
		{
				/* Disable  SSP Trig_Source peripheral */
				SSP->SSPIMSC &= ~Trig_Source;
		}
}	

/**
  * @brief  SSP interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void SSP_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(SSP_IRQn);
    NVIC_SetPriority(SSP_IRQn,priority);   
    NVIC_EnableIRQ(SSP_IRQn);               
}

/**
  * @brief  SSP interrupt disenable set.
  * @retval None
  */
void SSP_DisableIRQ(void)
{  
    NVIC_DisableIRQ(SSP_IRQn);               
}

/**
  * @brief  Get the state of the SSP original interrupt Status(For query mode).
  * @param  Trig_Source: what is Interrupt trigger condition.
	*   This parameter can be any combination of the following values:
  *     @arg SSP_IT_TX:  Send FIFO status interrupt 
  *     @arg SSP_IT_RX:  Receive FIFO status interrupt
	*     @arg SSP_IT_RT:  Receive timeout interrupt 
  *     @arg SSP_IT_ROR: Receive overrun interrupt 
  * @retval The new state of the original interrupt Status (SET or RESET).
  */
FlagStatus SSP_GetOriginalStatus(uint16_t Trig_Source)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_SSP_IT(Trig_Source));
	
	if((SSP->SSPRIS & Trig_Source) != (uint32_t)RESET)   
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
  * @brief 	Get the state of the SSP  interrupt Status(interrupt needs to be enabled).
  * @param  Trig_Source: what is Interrupt trigger condition.
	*   This parameter can be any combination of the following values:
  *     @arg SSP_IT_TX:  Send FIFO status interrupt 
  *     @arg SSP_IT_RX:  Receive FIFO status interrupt
	*     @arg SSP_IT_RT:  Receive timeout interrupt 
  *     @arg SSP_IT_ROR: Receive overrun interrupt 
  * @retval The new state of the SSP  interrupt Status (SET or RESET).
  */
ITStatus SSP_GetITStatus( uint16_t Trig_Source)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_SSP_IT(Trig_Source));
	
	if((SSP->SSPMIS & Trig_Source) != (uint32_t)RESET)   
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
  * @brief  Clears the SSP IT flags.
  * @param  Trig_Source:what is Interrupt trigger condition.
	*   This parameter can be any combination of the following values:
  *     @arg SSP_IT_RT:  Receive timeout interrupt 
  *     @arg SSP_IT_ROR: Receive overrun interrupt 
  * @retval None
  */
void SSP_ClearITStatus(uint16_t Trig_Source)
{
		/* Check the parameters */	
		assert_param(IS_SSP_Clear_IT(Trig_Source));
	
		SSP->SSPICR |= Trig_Source;
}

/**
  * @brief  Enables or disables the SSP DMA interface.
  * @param  DMAReq: specifies the SSP DMA transfer request to be enabled or disabled. 
  *   This parameter can be any combination of the following values:
  *     @arg SSP_DMAReq_TX: Tx buffer DMA transfer request
  *     @arg SSP_DMAReq_RX: Rx buffer DMA transfer request
  * @param  NewState: new state of the selected SSP DMA transfer request.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SSP_DMACmd(uint16_t DMAReq, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_SSP_DMAReq(DMAReq));
  if (NewState != DISABLE)
  {
			/* Enable the selected SSP DMA requests */
			SSP->SSPDMACR |= (uint16_t)DMAReq;
  }
  else
  {
			/* Disable the selected SSP DMA requests */
			SSP->SSPDMACR &= (uint16_t)~DMAReq;
  }
}

