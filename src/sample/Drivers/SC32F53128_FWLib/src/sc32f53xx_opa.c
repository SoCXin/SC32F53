/**
  ******************************************************************************
  * @file    sc32f53xx_opa.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the opa system firmware functions.
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
#include "sc32f53xx_opa.h"


#define OPACON_CLEAR_Mask          ((uint32_t)0xFCF0FCFF)            /*!< OPA OPACON Mask */ 


/**
  * @brief  Initializes the OPA Init peripheral according to 
  *         the specified parameters in the OPA_InitTypeDef.
  * @param  OPA_InitStruct: pointer to a OPA_InitTypeDef
  *         structure that contains the configuration information for the 
  *         specified OPA peripheral.
  * @retval None
  */
void OPA_Init(OPA_InitTypeDef* OPA_InitStruct)
{
		uint32_t tmpcr1 = 0;
		/* Check the parameters */
		assert_param(IS_OPA_Gain(OPA_InitStruct->OPA_Gain));
		assert_param(IS_OPA_BiasVot(OPA_InitStruct->OPA_BiasVolt));
		assert_param(IS_OPA_BiasConnect(OPA_InitStruct->OPA_BiasConnect));	
		assert_param(IS_OPA_InvertInRES(OPA_InitStruct->OPA_InvertInRES));
		assert_param(IS_OPA_NormalInRES(OPA_InitStruct->OPA_NormalInRES));
	
		tmpcr1 = ACMPOPA->OPACON;
		tmpcr1 &= OPACON_CLEAR_Mask;
		tmpcr1 |= OPA_InitStruct->OPA_BiasConnect;
		tmpcr1 |= OPA_InitStruct->OPA_BiasVolt;
		tmpcr1 |= OPA_InitStruct->OPA_Gain;
		tmpcr1 |= OPA_InitStruct->OPA_InvertInRES;
		tmpcr1 |= OPA_InitStruct->OPA_NormalInRES;
		ACCESSEN_WRITE_KEY;
		ACMPOPA->OPACON = tmpcr1;
}

/**
  * @brief  Fills each OPA_InitStruct member with its default value.
  * @param  OPA_InitStruct : pointer to a OPA_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void OPA_InitStructInit(OPA_InitTypeDef* OPA_InitStruct)
{
  /* Set the default configuration */
  OPA_InitStruct->OPA_Gain = OPA_Gain_1;
  OPA_InitStruct->OPA_BiasVolt = OPA_BiasVolt_HalfVDD50;
  OPA_InitStruct->OPA_BiasConnect = OPA_BiasConnect_Break;
  OPA_InitStruct->OPA_InvertInRES = OPA_Invert_InRES_No;
  OPA_InitStruct->OPA_NormalInRES = OPA_Normal_InRES_No;
}

/**
  * @brief  Enables or disables the OPA.
  * @param  NewState: new state of the OPA. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void OPA_Cmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPEN = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPEN = 0;
		}
}

/**
  * @brief  Enables or disables the OPA Output to port.
  * @param  NewState: new state of the OPA Output to port..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void OPA_OutCmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPOE = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPOE = 0;
		}
}

/**
  * @brief  Enables or disables the OPA Inverting input feedback path.
  * @param  NewState: new state of the OPA Inverting input feedback path. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void OPA_Invert_InBackCmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPNS = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPNS = 0;
		}
}

/**
  * @brief  Enables or disables the OPA Inverting input feedback path.
  * @param  NewState: new state of the OPA Inverting input feedback path.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void OPA_Normal_InBackCmd(FunctionalState NewState)  
{
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if(NewState != DISABLE)
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPPS = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ACMPOPA->OPACON_b.OPPS = 0;
		}
}


