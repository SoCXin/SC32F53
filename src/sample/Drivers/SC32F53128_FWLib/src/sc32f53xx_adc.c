/**
  ******************************************************************************
  * @file    sc32f53xx_adc.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    24-05-2019
  * @brief   This file provides all the ADC firmware functions.
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
#include "sc32f53xx_adc.h"


#define ADC_CTRL_REG_CLEAR_Mask           ((uint32_t)0xFFFF7E00)        /*!< ADC ADC_CTRL_REG Mask  */ 
#define SEQx_CTRL_REG_CLEAR_Mask          ((uint32_t)0xF9FFFFFF)        /*!< ADC SEQx_CTRL_REG Mask  */ 
#define ADC_TRIM_REG_CLEAR_MASK           ((uint32_t)0x7FFBFFFC)				/*!< ADC ADC_TRIM_REG Mask  */ 

/**
  * @brief  Initializes the ADC peripheral according to the specified parameters
  *         in the ADC_InitStruct.
  * @param  ADC_InitStruct: pointer to an ADC_InitTypeDef structure that contains
  *         the configuration information for the specified ADC peripheral.
  * @retval None
  */
void ADC_Init(ADC_InitTypeDef* ADC_InitStruct)
{
  uint32_t tmpreg;
	uint32_t temp;
	
  /* Check the parameters */
  assert_param(IS_ADC_CLKDIV(ADC_InitStruct->ADC_CLKDIV));
	assert_param(IS_ADC_R1xBSel(ADC_InitStruct->ADC_R1xBSel));
	assert_param(IS_ADC_REF(ADC_InitStruct->ADC_RefVolSet));
	assert_param(IS_ADC_EXRFSel(ADC_InitStruct->ADC_EXRFSel));
	assert_param(IS_ADC_VREFVDDSet(ADC_InitStruct->ADC_VREFVDDSel));
	
	tmpreg = ADC->ADCCTRL;
  /* Clear SEQA_LOWPRIO, EXRF_SEL, ADC_CLKON, CLKDIV[7:0] bits */
  tmpreg &= ADC_CTRL_REG_CLEAR_Mask;	
	
	/* Set the ADC configuration bits */
	tmpreg |= (ADC_InitStruct->ADC_EXRFSel <<15);
	tmpreg |= (ADC_InitStruct->ADC_CLKON << 8);
	tmpreg |= (ADC_InitStruct->ADC_CLKDIV);	
	
	/* Write to ADC_CTRL_REG */
	ADC->ADCCTRL = tmpreg;
	
	temp = ADC->ADC_TRIM;
	/* Clear VFS_S, R10B, ADC_VREFLI_TIE_GND*/
	temp &= ADC_TRIM_REG_CLEAR_MASK;	
	temp |=  (ADC_InitStruct->ADC_RefVolSet<<0);
	temp |=  (ADC_InitStruct->ADC_R1xBSel<<31);
	temp |=  (ADC_InitStruct->ADC_VREFVDDSel<<18);
	ADC->ADC_TRIM = temp;
}

/**
  * @brief  Fills ADC_InitStruct member with its default value.
  * @param  ADC_InitStruct : pointer to an ADC_InitTypeDef structure which will be initialized.
  * @retval None
  */
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct)
{
  /* Reset ADC init structure parameters values */
  /* initialize the ADC_EXRFSel member */
  ADC_InitStruct->ADC_EXRFSel = ADC_INTER_REF;
	/* initialize the ADC_RefVolSet member */
	ADC_InitStruct->ADC_RefVolSet = ADC_VREF_4V;
  /* Initialize the ADC_CLKON member */
  ADC_InitStruct->ADC_CLKON = DISABLE;
  /* Initialize the ADC_CLKDIV member */
  ADC_InitStruct->ADC_CLKDIV = 0x00;
	/* Initialize the ADC_R1xBSel member */
	ADC_InitStruct->ADC_R1xBSel = ADC_R12B_ENABLE;
	/* Initialize the ADC_VREFVDDSel member */
	ADC_InitStruct->ADC_VREFVDDSel = ADC_VREFVDD_DISABLE;
}

/**
  * @brief  Configures the ADC Power management module.
  * @param  PD_ConfigStruct: pointer to a PD_ConfigStruct structure that
  *         contains the configuration information for the ADC PWR.
  * @retval None
  */
void ADC_PDConfig(PD_ConfigTypeDef* PD_ConfigStruct)
{	
	/* Set the ADC power down bits */
  ADC->ADCCTRL_b.PD_ADC = (PD_ConfigStruct->ADC_PowerDown);
  ADC->ADCCTRL_b.PD_ADC_CORE = (PD_ConfigStruct->ADC_CORE_PowerDown);
  ADC->ADCCTRL_b.PD_ADC_REF = (PD_ConfigStruct->ADC_REF_PowerDown);
}

/**
  * @brief  Fills PD_ConfigStruct member with its default value.
  * @param  PD_ConfigStruct : pointer to an PD_ConfigTypeDef structure which will be initialized.
  * @retval None
  */
void ADC_PDConfigStructInit(PD_ConfigTypeDef* PD_ConfigStruct)
{
  /* Set the default configuration */
  PD_ConfigStruct->ADC_PowerDown = ENABLE;
	PD_ConfigStruct->ADC_CORE_PowerDown = ENABLE;
  PD_ConfigStruct->ADC_REF_PowerDown = ENABLE;
}

/**
  * @brief  Enables or disables the ADC SEQA software start conversion .
  * @param  Conversion_Mode: specifies the conversion mode of the ADC SEQA.
  *   This parameter can be one of the following values:
  *     @arg ADC_Conversion_Single: Single conversion
  *     @arg ADC_Conversion_Repeat: Repeat conversion
  * @param  NewState: new state of the selected ADC SEQA software start conversion.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_SEQA_SoftwareTrigSet(uint32_t Conversion_Mode, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_ADC_CONVERSION(Conversion_Mode));
	
  if (NewState != DISABLE)
  {
    /* Enable the ADC SEQA conversion on external event and start the  ADC SEQA conversion */  
		ADC->SEQA_CTRL &= SEQx_CTRL_REG_CLEAR_Mask;	
    ADC->SEQA_CTRL |= Conversion_Mode;
  }
  else
  {
    /* Disable the ADC SEQA conversion on external event and start the  ADC SEQA conversion */
    ADC->SEQA_CTRL &= ~Conversion_Mode;
  }		
}


/**
  * @brief Enables or disables the SEQA.
  * @param[in]  NewState new state of SEQA_EN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void ADC_SEQAENCmd(FunctionalState NewState)
{
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set SEQA_EN bit */
    ADC->SEQA_CTRL_b.SEQA_EN = 1;
  }
  else
  {
		/* Reset SEQA_EN bit */
    ADC->SEQA_CTRL_b.SEQA_EN = 0;
  }
}


/**
  * @brief Enables or disables the SEQA Start .
  * @param[in]  NewState new state of SEQA_StartEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void ADC_SEQA_StartENCmd(FunctionalState NewState)
{
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set SEQA_StartEN bit */
    ADC->SEQA_CTRL_b.SEQA_START = 1;
  }
  else
  {
		/* Reset SEQA_StartEN bit */
    ADC->SEQA_CTRL_b.SEQA_START = 0;
  }
}


/**
  * @brief  Enables or disables the ADC SEQB software start conversion .
  * @param  Conversion_Mode: specifies the conversion mode of the ADC SEQB.
  *   This parameter can be one of the following values:
  *     @arg ADC_Conversion_Single: Single conversion
  *     @arg ADC_Conversion_Repeat: Repeat conversion
  * @param  NewState: new state of the ADC SEQB software start conversion.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_SEQB_SoftwareTrigSet(uint32_t Conversion_Mode, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_ADC_CONVERSION(Conversion_Mode));
	
  if (NewState != DISABLE)
  {
    /* Enable the ADC SEQB conversion on external event and start the ADC SEQB conversion */ 
    ADC->SEQB_CTRL &= SEQx_CTRL_REG_CLEAR_Mask;	
    ADC->SEQB_CTRL |= Conversion_Mode;
  }
  else
  {
    /* Disable the ADC SEQB conversion on external event and start the  ADC SEQB conversion */
    ADC->SEQB_CTRL &= ~Conversion_Mode;
  }		
}


/**
  * @brief Enables or disables the SEQB.
  * @param[in]  NewState new state of SEQB_EN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void ADC_SEQBENCmd(FunctionalState NewState)
{
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set SEQB_EN bit */
    ADC->SEQB_CTRL_b.SEQB_EN = 1;
  }
  else
  {
		/* Reset SEQB_EN bit */
    ADC->SEQB_CTRL_b.SEQB_EN = 0;
  }
}


/**
  * @brief Enables or disables the SEQB Start.
  * @param[in]  NewState new state of SEQB_StartEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void ADC_SEQB_StartENCmd(FunctionalState NewState)
{
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
		/* Set SEQB_EN bit */
    ADC->SEQB_CTRL_b.SEQB_START = 1;
  }
  else
  {
		/* Reset SEQB_EN bit */
    ADC->SEQB_CTRL_b.SEQB_START = 0;
  }
}


/**
  * @brief  Choose the ADC SEQx channel .
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @param  channel: specifies the channel of the ADC SEQx.
  * @retval None
  */
void ADC_SEQx_ChannelSel(ADCSEQSel_TypeDef SEQSel, uint32_t channel)
{
  /* Check the parameters */
	assert_param(IS_ADC_SEQSel(SEQSel));
	assert_param(IS_ADC_INCHANNEL(channel));	
	
	if(SEQSel == ADC_SEQ_SEQA)
	{
			ADC->SEQA_CTRL &= ~ADC_SEQA_CTRL_SEQA_CH_SEL_Msk;
			ADC->SEQA_CTRL |= channel;
	}
	else if(SEQSel == ADC_SEQ_SEQB)
	{
			ADC->SEQB_CTRL &= ~ADC_SEQB_CTRL_SEQB_CH_SEL_Msk;
			ADC->SEQB_CTRL |= channel;
	}	
}


/**
  * @brief  Configures the SEQx Hardware trigger source and polarity selection.
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @param[in] Trig_Source : Specifies the ADC SEQB Hardware trigger source.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_TRIGSRC_TIM1.
  *     @arg ADC_TRIGSRC_TIM3.
	*     @arg ADC_TRIGSRC_TIM14.
	*     @arg ADC_TRIGSRC_TIM15.
	*     @arg ADC_TRIGSRC_TIM16.
	*     @arg ADC_TRIGSRC_TIM17.
	*     @arg ADC_TRIGSRC_ERU0.
	*     @arg ADC_TRIGSRC_ERU1.
	*     @arg ADC_TRIGSRC_ERU2.
	*     @arg ADC_TRIGSRC_ERU3.
  * @param[in] Trig_Edge : Specifies the ADC SEQB Hardware trigger source polarity.
  *   This parameter can be any combination of the following values:
  *     @arg ADC_TRIG_RISE.
  *     @arg ADC_TRIG_FALL.
  * @retval None
  */
void ADC_SEQx_HardWareTrigSet(ADCSEQSel_TypeDef SEQSel, ADCTRIGSRC_TypeDef Trig_Source, ADCTRIGEdge_TypeDef Trig_Edge)
{
	assert_param(IS_ADC_SEQSel(SEQSel));
	assert_param(IS_ADC_TRIGEdge(Trig_Edge));
	assert_param(IS_ADC_TRIGSRC(Trig_Source));
	
	if(SEQSel == ADC_SEQ_SEQA)
	{
			/* Config the ADC SEQx_TRIGSEL bits */
			ADC->SEQA_CTRL_b.SEQA_TRIGSEL = Trig_Source;
			/* Config the ADC SEQx_TRIGPOL bits */
			ADC->SEQA_CTRL_b.SEQA_TRIGPOL = Trig_Edge;
			/* Synchronous clock on */
			ADC->SEQA_CTRL_b.SEQA_SYNCBYP = 0;
	}
	else if(SEQSel == ADC_SEQ_SEQB)
	{
			/* Config the ADC SEQx_TRIGSEL bits */
			ADC->SEQB_CTRL_b.SEQB_TRIGSEL = Trig_Source;
			/* Config the ADC SEQx_TRIGPOL bits */
			ADC->SEQB_CTRL_b.SEQB_TRIGPOL = Trig_Edge;
			/* Synchronous clock on */
			ADC->SEQB_CTRL_b.SEQB_SYNCBYP = 0;
	}
}


/**
  * @brief Config the SEQx mode selection.
	* @param[in]  ModeSel: can be Mode_DATx,Mode_SEQx.
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @retval None
  */
void ADC_SEQx_ModeConfig(ADCSEQSel_TypeDef SEQSel,uint32_t ModeSel)
{
	assert_param(IS_ADC_SEQSel(SEQSel));
	assert_param(IS_ADC_ModeSel(ModeSel));
	if(SEQSel == ADC_SEQ_SEQA)
	{
			ADC->SEQA_CTRL_b.SEQA_MODE = ModeSel;
	}
	else if(SEQSel == ADC_SEQ_SEQB)
	{
			ADC->SEQB_CTRL_b.SEQB_MODE = ModeSel;
	}
}


/**
  * @brief  Choose the ADC SEQx Conversion Width .
  * @param  Conversion_Width: specifies the Conversion Width  of the ADC SEQx.
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @retval None
  */
void ADC_SEQx_ConvWidthSet(ADCSEQSel_TypeDef SEQSel,uint32_t Conversion_Width)
{
		assert_param(IS_ADC_SEQSel(SEQSel));
  
		if(SEQSel == ADC_SEQ_SEQA)
		{
				ADC->SEQA_PERD = Conversion_Width;
		}
		else if(SEQSel == ADC_SEQ_SEQB)
		{
				ADC->SEQB_PERD = Conversion_Width;
		}
		
}


/**
  * @brief  Threshold channel selection
  * @param  channel:  Specifies the channel of the ADC.
	* @param  Cmp_Sel:  Specifies the Threshold channel.
	*   This parameter can be any combination of the following values:
  *     @arg Channel_SelCMP0:  the Threshold channel 0.
  *     @arg Channel_SelCMP1:  the Threshold channel 1.
  * @retval None
  */
void ADC_ChannelCmpSel(uint32_t channel, ChannelCmpSel_TypeDef Cmp_Sel)
{
  /* Check the parameters */
	assert_param(IS_ADC_INCHANNEL(channel));
	assert_param(IS_ADC_CmpSel(Cmp_Sel));
	
	if (Cmp_Sel)
	{
			ADC->CHL_THRSEL |= channel;
	}	
	else
	{
			ADC->CHL_THRSEL &= ~channel;
	}
}


/**
  * @brief  Threshold channel selection
  * @param  channel:  Specifies the channel of the ADC.
	* @param  Cmp_Sel:  Specifies the Threshold channel.
	*   This parameter can be any combination of the following values:
  *     @arg Channel_SelCMP0:  the Threshold channel 0.
  *     @arg Channel_SelCMP1:  the Threshold channel 1.
  * @retval None
  */
void ADC_WriteChannelCmpThrVal(ChannelCmpSel_TypeDef Cmp_Sel, uint16_t ThrHighVal, uint16_t ThrLowVal)
{
  /* Check the parameters */
	assert_param(IS_ADC_CmpSel(Cmp_Sel));
	
	if (Cmp_Sel)
	{
			ADC->ADC_THR1 |= (uint32_t)(ThrHighVal<<16);
			ADC->ADC_THR1 |= (uint32_t)(ThrLowVal);
	}	
	else
	{
			ADC->ADC_THR0 |= (uint32_t)(ThrHighVal<<16);
			ADC->ADC_THR0 |= (uint32_t)(ThrLowVal);
	}
}

/**
  * @brief  Read the latest 12-bit conversion results of SEQA or SEQB.
  * @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @retval The latest 12-bit conversion result Value.
  */
uint16_t ADC_Read_Gdat(ADCSEQSel_TypeDef SEQSel)
{
  uint16_t GDat_Value;
	
	assert_param(IS_ADC_SEQSel(SEQSel));
	
	if(SEQSel == ADC_SEQ_SEQA)
	{
			GDat_Value = ADC->SEQA_GDAT_b.RESULT;
	}
	else if(SEQSel == ADC_SEQ_SEQB)
	{
			GDat_Value = ADC->SEQB_GDAT_b.RESULT;
	}
  return GDat_Value;
}

/**
  * @brief  Reads the current channel ADC conversion value
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
uint16_t ADC_ReadData(ADCChannel_TypeDef Channel)
{
		uint16_t Conversion_Value;
	
		assert_param(IS_ADC_CHANNEL(Channel));
		
		Conversion_Value = ADC->DAT_b[Channel].RESULT;
		return Conversion_Value;
}


/**
  * @brief  Reads the OVERRUN status of the current ADC channel
  * @param  channel:  Specifies the channel of the ADC.
	* @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_CHxOverRun_GetStatus(ADCChannel_TypeDef Channel)
{
		assert_param(IS_ADC_CHANNEL(Channel));
	
		return (ADC->CMPFLAG >> (16+Channel)) & 0x01;
}


/**
  * @brief  Reads the current SEQx ADC overrun Status
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_SEQxOverRun_GetStatus(ADCChannel_TypeDef Channel,ADCSEQSel_TypeDef SEQSel)
{
		uint32_t OverRunStatus;
	
		assert_param(IS_ADC_CHANNEL(Channel));
		assert_param(IS_ADC_SEQSel(SEQSel));
		
		if(SEQSel == ADC_SEQ_SEQA)
		{
				OverRunStatus = ADC->SEQA_GDAT_b.OVERRUN;
		}
		else if(SEQSel == ADC_SEQ_SEQB)
		{
				OverRunStatus = ADC->SEQB_GDAT_b.OVERRUN;
		}
		return OverRunStatus;
}


/**
  * @brief  Reads the current channel ADC conversion value
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_CHxOverRun_ClearStatus(ADCChannel_TypeDef Channel)
{
		assert_param(IS_ADC_CHANNEL(Channel));
	
 	  return(ADC_ReadData(Channel));
} 


/**
  * @brief  Reads the current channel ADC Complete Status
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_CHxComplete_GetStatus(ADCChannel_TypeDef Channel)
{
		uint32_t CompleteStatus;
	
		assert_param(IS_ADC_CHANNEL(Channel));
		
		CompleteStatus = ADC->DAT_b[Channel].DATAVALID;
		return CompleteStatus;
}


/**
  * @brief  Reads the current channel ADC Complete Status
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
	* @param  SEQSel: Specifies the current sequence
	*   This parameter can be any combination of the following values:
  *     @arg ADC_SEQ_SEQA:  choose SEQA.
  *     @arg ADC_SEQ_SEQB:  choose SEQB.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_SEQxComplete_GetStatus(ADCChannel_TypeDef Channel,ADCSEQSel_TypeDef SEQSel)
{
		uint32_t CompleteStatus;
	
		assert_param(IS_ADC_CHANNEL(Channel));
		assert_param(IS_ADC_SEQSel(SEQSel));
		
		if(SEQSel == ADC_SEQ_SEQA)
		{
				CompleteStatus = ADC->SEQA_GDAT_b.DATAVALID;
		}
		else if(SEQSel == ADC_SEQ_SEQB)
		{
				CompleteStatus = ADC->SEQB_GDAT_b.DATAVALID;
		}
		return CompleteStatus;
}

/**
  * @brief  ADC interrupt enable config.
	* @param IRQSel:specifies the Interrupt entry address selection.
  * This parameter can be any combination of the following values:
	*    	@arg ADC_SEQA_IRQ: the Interrupt entry address selection is ADC_SEQA_IRQ.
  *    	@arg ADC_SEQB_IRQ: the Interrupt entry address selection is ADC_SEQB_IRQ.
	*    	@arg ADC_IRQ: the Interrupt entry address selection is ADC_IRQ. 
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void ADC_EnableIRQ(ADCIRQSel_TypeDef IRQSel, uint16_t priority)
{
		assert_param(IS_ADC_IRQSel(IRQSel));
	
		if(IRQSel==ADC_SEQA_IRQ)
		{
				NVIC_ClearPendingIRQ(ADC_SEQA_IRQn);
				NVIC_SetPriority(ADC_SEQA_IRQn,priority);   
				NVIC_EnableIRQ(ADC_SEQA_IRQn);
		}
		else if(IRQSel==ADC_SEQB_IRQ)
		{
				NVIC_ClearPendingIRQ(ADC_SEQB_IRQn);
				NVIC_SetPriority(ADC_SEQB_IRQn,priority);   
				NVIC_EnableIRQ(ADC_SEQB_IRQn);
		}
		else if(IRQSel==ADC_IRQ)
		{
				NVIC_ClearPendingIRQ(ADC_IRQn);
				NVIC_SetPriority(ADC_IRQn,priority);   
				NVIC_EnableIRQ(ADC_IRQn);
		}		
}


/**
  * @brief  Disable ADC interrupt.
	* @param IRQSel:specifies the Interrupt entry address selection.
  * This parameter can be any combination of the following values:
	*    	@arg ADC_SEQA_IRQ: the Interrupt entry address selection is ADC_SEQA_IRQ.
  *    	@arg ADC_SEQB_IRQ: the Interrupt entry address selection is ADC_SEQB_IRQ.
	*    	@arg ADC_IRQ: the Interrupt entry address selection is ADC_IRQ. 
  * @retval None
  */
void ADC_DisableIRQ(ADCIRQSel_TypeDef IRQSel)
{
		assert_param(IS_ADC_IRQSel(IRQSel));
	
		if(IRQSel==ADC_SEQA_IRQ)
		{
				NVIC_DisableIRQ(ADC_SEQA_IRQn); 
		}
		else if(IRQSel==ADC_SEQB_IRQ)
		{
				NVIC_DisableIRQ(ADC_SEQB_IRQn);
		}
		else if(IRQSel==ADC_IRQ)
		{
				NVIC_DisableIRQ(ADC_IRQn);
		}	
}

/**
  * @brief  Config the threshold compares interrupts 
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
	* @param  Cmp_Type:  Specifies the Thresholds compare interrupt types.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_CMP_DISABLE:  DISABLE.
  *     @arg ADC_CMP_OUT:  Interrupt beyond the range threshold.
	*     @arg ADC_CMP_CORSS:  Cross threshold interrupt.
  * @retval None
  */
void ADC_CHxCMP_ITCmd(ADCChannel_TypeDef Channel, ADCCMPINTSet_TypeDef Cmp_Type)
{
		assert_param(IS_ADC_CHANNEL(Channel));
		assert_param(IS_ADC_CMPINTSet(Cmp_Type));
		
		ADC->CMPINTEN &= ~(3 << (Channel * 2));
		ADC->CMPINTEN |= Cmp_Type << (Channel * 2);
}

/**
  * @brief  Read the comparison status of the current channel ADC transition value
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
uint32_t ADC_CHxCmp_GetITStatus(ADCChannel_TypeDef Channel)
{
		assert_param(IS_ADC_CHANNEL(Channel));
	
		return (ADC->CMPFLAG >> Channel) & 0x01;
}

/**
  * @brief  Clear the comparison status of the current ADC channel  
  * @param  channel:  Specifies the channel of the ADC.
	*   This parameter can be any combination of the following values:
  *     @arg ADC_Channel_0.
	*     @arg ADC_Channel_1.
	*     @arg ADC_Channel_2.
	*			......
	*     @arg ADC_Channel_14.
	*     @arg ADC_Channel_15.
  * @retval Current channel ADC conversion value
  */
void ADC_CHxCmp_ClearITStatus(ADCChannel_TypeDef Channel)
{
		assert_param(IS_ADC_CHANNEL(Channel));
		ADC->CMPFLAG |= (1<<Channel);
}


/**
  * @brief  Enable or Disable the ADC interrupt source.
  * @param  ADC_IT: specifies the ADC interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg ADC_IT_SEQA:  OverRun Error interrupt
  *     @arg ADC_IT_SEQB:  Break Error Interrupt
  *     @arg ADC_IT_OVR:  Parity Error interrupt
  *     @arg ADC_IT_THRCMP:  Framing Error Interrupt
  *     @arg ADC_IT_SEQAOVR:  Receive Ttimeout Interrupt
  *     @arg ADC_IT_SEQBOVR: Transmit Interrupt
	* @param  NewState: new state of the ADC interrupt source. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void ADC_SEQITCmd(uint16_t ADC_IT, FunctionalState NewState)
{
		assert_param(IS_ADC_IT(ADC_IT));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{			
				ADC->ADC_INTEN |= ADC_IT;
		}
		else
		{
				ADC->ADC_INTEN &= ~ADC_IT;
		}
}

/**
  * @brief  Checks whether the specified ADC interrupt has occurred or not.
  * @param  ADC_IT: specifies the ADC interrupt source to check. 
	*   This parameter can be any combination of the following values:
  *     @arg ADC_IT_SEQA:  Sequence A interrupt /DMA flag bit.
  *     @arg ADC_IT_SEQB:  Sequence B interrupt /DMA flag bit.
	*     @arg ADC_IT_OVR:   Channel overflow interrupt,with 16 Channels.
	*     @arg ADC_IT_THRCMP: The threshold compares interrupts,with 16 Channels.
  *     @arg ADC_IT_SEQAOVR:  Overflow interruption of sequence A.
	*     @arg ADC_IT_SEQBOVR:  Overflow interruption of sequence B.
  * @retval The new state of ADC_IT (SET or RESET).
  */
ITStatus ADC_GetSEQITStatus(uint16_t ADC_IT)
{
		ITStatus bitstatus = RESET;
		/* Check the parameters */
		assert_param(IS_ADC_IT(ADC_IT));

		if (((ADC->ADC_FLAG & ADC_IT) != (uint32_t)RESET))
		{
				/* ADC_IT is set */
				bitstatus = SET;
		}
		else
		{
				/* ADC_IT is reset */
				bitstatus = RESET;
		}
		/* Return the ADC_IT status */
		return  bitstatus;
}

/**
  * @brief  Clear the specified ADC SEQ interrupt flag.
  * @param  ADC_IT: specifies the ADC interrupt source to check. 
	*   This parameter can be any combination of the following values:
  *     @arg ADC_IT_SEQA:  Sequence A interrupt /DMA flag bit.
  *     @arg ADC_IT_SEQB:  Sequence B interrupt /DMA flag bit.
	*     @arg ADC_IT_OVR:   Channel overflow interrupt,with 16 Channels.
	*     @arg ADC_IT_THRCMP: The threshold compares interrupts,with 16 Channels.
  *     @arg ADC_IT_SEQAOVR:  Overflow interruption of sequence A.
	*     @arg ADC_IT_SEQBOVR:  Overflow interruption of sequence B.
  * @retval The new state of ADC_IT (SET or RESET).
  */
void ADC_ClearSEQITStatus(uint16_t ADC_IT)
{
		assert_param(IS_ADC_IT(ADC_IT));
	
		ADC->ADC_FLAG = ADC_IT;
}




