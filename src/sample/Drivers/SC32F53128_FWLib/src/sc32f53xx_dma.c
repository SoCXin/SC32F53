/**
  ******************************************************************************
  * @file    sc32f53xx_dma.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the dma system firmware functions.
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
#include "sc32f53xx_dma.h"


#define CTRLx_Config_CLEAR_Mask          ((uint32_t)0xFF6060CB)        /*!< DMA CTRLx Config Mask  */ 
#define CHx_CTL_CLEAR_Mask            	 ((uint32_t)0x03FC0008)        /*!< DMA CHx CTL Mask  */ 


/**
  * @brief  Initializes the DMA_DATAx CTL register according to 
  *         the specified parameters in the DMA_CTLInitTypeDef.
	* @param  DMA_DATAx: specified the DMA DATA channel.
	* This parameter can be any combination of the following values:
	*	@arg DMA_DATA0,DMA_DATA1,DMA_DATA2,DMA_DATA3,DMA_DATA4,DMA_DATA5,DMA_ALT_DATA0,DMA_ALT_DATA1,
	* DMA_ALT_DATA2,DMA_ALT_DATA3,DMA_ALT_DATA4,DMA_ALT_DATA5.  
  * @param  DMA_CTLInitStruct: pointer to a DMA_CTLInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified DMA_DATAx CTL register.
  * @retval None
  */
void DMA_CTLInit(DMA_DATA_Type* DMA_DATAx,DMA_CTLInitTypeDef* DMA_CTLInitStruct)
{
		uint32_t tmpreg;
		
		/* Check the parameters */
		assert_param(IS_DMA_ALL_DATAx(DMA_DATAx));
		assert_param(IS_DMA_Mode(DMA_CTLInitStruct->DMA_Mode));
		assert_param(IS_DMA_TransferNum(DMA_CTLInitStruct->DMA_TransferNum));
		assert_param(IS_DMA_DataSize(DMA_CTLInitStruct->DMA_DataSize));
		assert_param(IS_DMA_SourceAddInc(DMA_CTLInitStruct->DMA_SourceAddInc));
		assert_param(IS_DMA_TargetAddInc(DMA_CTLInitStruct->DMA_TargetAddInc));
		assert_param(IS_DMA_TotalNum(DMA_CTLInitStruct->DMA_TotalNum));
	
		tmpreg = (uint32_t)0x00;
		tmpreg |= DMA_CTLInitStruct->DMA_Mode;
		tmpreg |= DMA_CTLInitStruct->DMA_DataSize;
		tmpreg |= DMA_CTLInitStruct->DMA_SourceAddInc;
		tmpreg |= DMA_CTLInitStruct->DMA_TargetAddInc;
		tmpreg |= DMA_CTLInitStruct->DMA_TotalNum<<4;
		tmpreg |= DMA_CTLInitStruct->DMA_TransferNum;
		
		DMA_DATAx->CTL = (uint32_t)tmpreg;
}

/**
  * @brief  Fills each DMA_CTLInitStruct member with its default value.
  * @param  DMA_CTLInitStruct : pointer to a DMA_CTLInitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void DMA_CTLStructInit(DMA_CTLInitTypeDef* DMA_CTLInitStruct)
{
  /* Set the default configuration */
  DMA_CTLInitStruct->DMA_Mode = DMA_Mode_Stop;
  DMA_CTLInitStruct->DMA_DataSize = DMA_DataSize_Byte;
  DMA_CTLInitStruct->DMA_SourceAddInc = DMA_SourceAddInc_Byte;
  DMA_CTLInitStruct->DMA_TargetAddInc = DMA_TargetAddInc_Byte;
  DMA_CTLInitStruct->DMA_TotalNum = 0;
  DMA_CTLInitStruct->DMA_TransferNum = DMA_TransferNum_1;
}


/**
  * @brief  Initializes the DMA according to 
  *         the specified parameters in the DMA_InitTypeDef.
  * @param  DMA_InitStruct: pointer to a DMA_InitTypeDef
  *         structure that contains the configuration information for the 
  *         specified DMA peripheral.
  * @retval None
  */
void DMA_Init(DMA_InitTypeDef* DMA_InitStruct)
{
		uint32_t tmpreg;
		
		/* Check the parameters */
		assert_param(IS_DMA_CTRLx(DMA_InitStruct->DMA_Channel_CTRLx));
		assert_param(IS_DMA_Request(DMA_InitStruct->DMA_Request0));
		assert_param(IS_DMA_Request(DMA_InitStruct->DMA_Request1));
		assert_param(IS_DMA_REQ0(DMA_InitStruct->DMA_REQ0));
		assert_param(IS_DMA_REQ1(DMA_InitStruct->DMA_REQ1));
		assert_param(IS_DMA_CHxPriority(DMA_InitStruct->DMA_CHxPriority));
		assert_param(IS_DMA_Burst(DMA_InitStruct->DMA_Burst));
		assert_param(IS_DMA_BasePoint(DMA_InitStruct->DMA_BasePoint));
		
		tmpreg = DMA->CTRL[(DMA_InitStruct->DMA_Channel_CTRLx)];
		tmpreg &= CTRLx_Config_CLEAR_Mask;
		tmpreg |= DMA_InitStruct->DMA_BasePoint;
		tmpreg |= DMA_InitStruct->DMA_Burst;
		tmpreg |= DMA_InitStruct->DMA_CHxPriority;	
	
		tmpreg |= (DMA_InitStruct->DMA_REQ0<<15);      //DMA通道请求0默认有效
		tmpreg |= (DMA_InitStruct->DMA_Request0<< 8);

		tmpreg |= (DMA_InitStruct->DMA_REQ1<<23);      //DMA通道请求1默认有效
		tmpreg |= (DMA_InitStruct->DMA_Request1<< 16);
		DMA->CTRL[(DMA_InitStruct->DMA_Channel_CTRLx)] = tmpreg;
						
}

/**
  * @brief  Fills each DMA_InitStruct member with its default value.
  * @param  DMA_InitStruct : pointer to a DMA_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void DMA_InitStructInit(DMA_InitTypeDef* DMA_InitStruct)
{
  /* Set the default configuration */
  DMA_InitStruct->DMA_Channel_CTRLx = DMA_Channel_CTRL0;
  DMA_InitStruct->DMA_BasePoint = DMA_BasePoint_Main;
  DMA_InitStruct->DMA_Burst = DMA_REQ_SREQ_All;
  DMA_InitStruct->DMA_CHxPriority = DMA_CHxPriority_Default;
  DMA_InitStruct->DMA_REQ0 = DMA_REQ0_ENABLE;
  DMA_InitStruct->DMA_Request0 = DMA_UART1_TX;
  DMA_InitStruct->DMA_REQ1 = DMA_REQ1_ENABLE;
  DMA_InitStruct->DMA_Request1 = DMA_UART1_TX;
}

/**
  * @brief  write pointer to the address of the source PTR.
  * @param  DMA_CHx: the value of the DMA channel.
	* This parameter can be any combination of the following values:
	*	@arg DMA_DATA0,DMA_DATA1,DMA_DATA2,DMA_DATA3,DMA_DATA4,DMA_DATA5,DMA_ALT_DATA0,DMA_ALT_DATA1,
	* DMA_ALT_DATA2,DMA_ALT_DATA3,DMA_ALT_DATA4,DMA_ALT_DATA5.  
	* @param  DataPTR: the value of 32 bit array.
  * @retval None
  */
void DMA_32BitsSourcePTR_Write(DMA_DATA_Type* DMA_CHx, uint32_t *DataPTR)
{
		assert_param(IS_DMA_ALL_DATAx(DMA_CHx));
	
		DMA_CHx->SOURCE = DataPTR;
}

/**
  * @brief  write pointer to the target PTR.
  * @param  DMA_CHx: the value of the DMA channel.
	* This parameter can be any combination of the following values:
	*	@arg DMA_DATA0,DMA_DATA1,DMA_DATA2,DMA_DATA3,DMA_DATA4,DMA_DATA5,DMA_ALT_DATA0,DMA_ALT_DATA1,
	* DMA_ALT_DATA2,DMA_ALT_DATA3,DMA_ALT_DATA4,DMA_ALT_DATA5.  
	* @param  DataPTR: the value of 32 bit array.
  * @retval None
  */
void DMA_32BitsTargetPTR_Write(DMA_DATA_Type* DMA_CHx, uint32_t *DataPTR)
{
		assert_param(IS_DMA_ALL_DATAx(DMA_CHx));
	
		DMA_CHx->DESTION = DataPTR;
}


/**
  * @brief  Writes the channel of DMA control base pointer value.
  * @param  None
  * @retval None
  */
void DMA_BasePTR_Write(void)
{
		DMA->BASE_PTR = (uint32_t)(DMA_DATA_BASE0);
}


/**
  * @brief  Enables or disables the DMA.
  * @param  NewState: new state of the DMAy Channelx. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DMA_Cmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the selected DMAy Channelx */
    DMA->CFG |= DMA_CFG_ENABLE_Msk;
  }
  else
  {
    /* Disable the selected DMAy Channelx */
     DMA->CFG &= ~DMA_CFG_ENABLE_Msk;
  }
}

/**
  * @brief  Enables or disables the DMA channel.
  * @param  DMA_CTRLx: the DMA CTRLx number.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_CTRL0,DMA_Channel_CTRL1,DMA_Channel_CTRL2,
		  DMA_Channel_CTRL3,DMA_Channel_CTRL4,DMA_Channel_CTRL5.
	* @param  NewState: new state of the DMA Channel . 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval none.
  */
void DMA_Channel_Cmd(uint16_t DMA_CTRLx,FunctionalState NewState)
{
  /* Check the parameters */
	assert_param(IS_DMA_CTRLx(DMA_CTRLx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE)
			DMA->CTRL_b[DMA_CTRLx].ENABLE = 1;
	else 
			DMA->CTRL_b[DMA_CTRLx].ENABLE = 0;
}

/**
  * @brief  Enables or disables the DMA channel request 0.
  * @param  DMA_CTRLx: the DMA CTRLx number.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_CTRL0,DMA_Channel_CTRL1,DMA_Channel_CTRL2,
		  DMA_Channel_CTRL3,DMA_Channel_CTRL4,DMA_Channel_CTRL5.
	* @param  NewState: new state of the DMA channel request 0. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval none.
  */
void DMA_REQ0_Cmd(uint16_t DMA_CTRLx,FunctionalState NewState)
{
  /* Check the parameters */
	assert_param(IS_DMA_CTRLx(DMA_CTRLx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE)
			DMA->CTRL_b[DMA_CTRLx].REQ0_MASK = 0;
	else 
			DMA->CTRL_b[DMA_CTRLx].REQ0_MASK = 1;
}

/**
  * @brief  Enables or disables the DMA channel request 1.
  * @param  DMA_CTRLx: the DMA CTRLx number.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_CTRL0,DMA_Channel_CTRL1,DMA_Channel_CTRL2,
		  DMA_Channel_CTRL3,DMA_Channel_CTRL4,DMA_Channel_CTRL5.
	* @param  NewState: new state of the DMA channel request 1. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval none.
  */
void DMA_REQ1_Cmd(uint16_t DMA_CTRLx,FunctionalState NewState)
{
  /* Check the parameters */
	assert_param(IS_DMA_CTRLx(DMA_CTRLx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));

	if(NewState != DISABLE)
			DMA->CTRL_b[DMA_CTRLx].REQ1_MASK = 0;
	else 
			DMA->CTRL_b[DMA_CTRLx].REQ1_MASK = 1;
}

/**
  * @brief  Enables the DMA reset.
  * @param  None
  * @retval None
  */
void DMA_ResetCmd(void)
{
     /* Enable the selected DMA Reset */
     DMA->CFG |= DMA_CFG_RESET_Msk;
}

/**
  * @brief  Enables or Disable the DMA Software request.
  * @param  DMA_CHx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval None
  */
void DMA_SoftWare_REQCmd(uint16_t DMA_Channelx)
{
		/* Check the parameters */
		assert_param(IS_DMA_Channel(DMA_Channelx));
    /* Enable the selected DMA Software request. */
		DMA->SW_REQ = DMA_Channelx;
}


/**
  * @brief  Checks while  DMA request flag is set or not.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval The new state of DMA request flag (SET or RESET).
  */
ITStatus DMA_GetReqStatus(uint16_t DMA_Channelx)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	if((DMA->REQUEST_ON & DMA_Channelx) != (uint32_t)RESET)
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
  * @brief  Checks  whether DMA active flag is set or not.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval The new state of  DMA active flag  (SET or RESET).
  */
ITStatus DMA_GetActiveStatus(uint16_t DMA_Channelx)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	if((DMA->ACTIVE & DMA_Channelx) != (uint32_t)RESET)
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
  * @brief  Checks  whether DMA done flag is set or not.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval The new state of DMA done flag (SET or RESET).
  */
ITStatus DMA_GetDoneStatus(uint16_t DMA_Channelx)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	if((DMA->DONE & DMA_Channelx) != (uint32_t)RESET)
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
  * @brief   Clear DMA done flag.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval none.
  */
void DMA_ClearDoneStatus(uint16_t DMA_Channelx)
{
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	DMA->DONE = DMA_Channelx;

}

/**
  * @brief   whether DMA CFG error flag is set or not.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval The new state of DMA CFG error flag (SET or RESET).
  */
ITStatus DMA_GetCFGErrStatus(uint16_t DMA_Channelx)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	if((DMA->CFG_ERR & DMA_Channelx) != (uint32_t)RESET)
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
  * @brief   Clear DMA CFG error flag.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval none.
  */
void DMA_ClearCFGErrStatus(uint16_t DMA_Channelx)
{
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	DMA->CFG_ERR = DMA_Channelx;

}


/**
  * @brief   whether DMA BUS error flag is set or not.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval The new state of DMA BUS error flag (SET or RESET).
  */
ITStatus DMA_GetBUSErrStatus(uint16_t DMA_Channelx)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	if((DMA->BUS_ERR & DMA_Channelx) != (uint32_t)RESET)
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
  * @brief   Clear DMA BUS error flag.
  * @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
  * @retval none.
  */
void DMA_ClearBUSErrStatus(uint16_t DMA_Channelx)
{
  /* Check the parameters */	
  assert_param(IS_DMA_Channel(DMA_Channelx));
	
	DMA->BUS_ERR = DMA_Channelx;

}

/**
  * @brief  Enables or disables the specified DMA Channelx interrupts.
  * @param  DMA_CTRLx: the DMA CTRLx number.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_CTRL0,DMA_Channel_CTRL1,DMA_Channel_CTRL2,
		  DMA_Channel_CTRL3,DMA_Channel_CTRL4,DMA_Channel_CTRL5.
  * @param  DMA_IT: specifies the DMA interrupts sources to be enabled
  *   or disabled. 
  *   This parameter can be any  combination of the following values:
  *     @arg DMA_IT_DONE:  Transfer complete interrupt 
  *     @arg DMA_IT_CFGERR: Configuration error interrupt
  *     @arg DMA_IT_BUSERR: Bus fault interrupt 
  * @param  NewState: new state of the specified DMA interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DMA_ITConfig(uint16_t DMA_CTRLx, uint32_t DMA_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DMA_CTRLx(DMA_CTRLx));
  assert_param(IS_DMA_IT(DMA_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
			/* Enable the selected DMA interrupts */
			DMA->CTRL[DMA_CTRLx] |= DMA_IT;
  }
  else
  {
      /* Disable the selected DMA interrupts */
			DMA->CTRL[DMA_CTRLx] &= ~DMA_IT;
  }
}

/**
  * @brief  DMA interrupt enable set.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void DMA_EnableIRQ(uint16_t priority)
{
    NVIC_ClearPendingIRQ(DMA_IRQn);
    NVIC_SetPriority(DMA_IRQn,priority);   
    NVIC_EnableIRQ(DMA_IRQn);               
}

/**
  * @brief  DMA interrupt disenable set.
  * @retval None
  */
void DMA_DisableIRQ(void)
{  
    NVIC_DisableIRQ(DMA_IRQn);               
}

/**
  * @brief  Clears the DMA IT flag.
	* @param  DMA_Channelx: the channel for DMA.
	*   This parameter can be any combination of the following values:
	*   @arg DMA_Channel_0,DMA_Channel_1,DMA_Channel_2,DMA_Channel_3
			DMA_Channel_4,DMA_Channel_5.
	* @param  DMA_IT:the specified DMA Channelx interrupts.
	*   This parameter can be:
	*   @arg DMA_IT_DONE.
	*   @arg DMA_IT_CFGERR.
	*   @arg DMA_IT_BUSERR.
  * @retval None
  */
void DMA_ClearITStatus(uint16_t DMA_Channelx,uint32_t DMA_IT)
{
		/* Check the parameters */	
		assert_param(IS_DMA_Channel(DMA_Channelx));
		assert_param(IS_DMA_IT(DMA_IT));
	
		switch(DMA_IT)
		{
				case DMA_IT_DONE:
						DMA->DONE = DMA_Channelx;
						break;
				case DMA_IT_CFGERR:
						DMA->CFG_ERR = DMA_Channelx;
						break;
				case DMA_IT_BUSERR:
						DMA->BUS_ERR = DMA_Channelx;
						break;
				default:
						break;
		}		
}




