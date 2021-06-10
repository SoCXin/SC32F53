/**
  ******************************************************************************
  * @file    sc32f53xx_eru.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the eru system firmware functions.
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
#include "sc32f53xx_eru.h"


#define EXISEL_CLEAR_Mask_0          			((uint32_t)0xffffff88)            /*!< ERU EXISEL Mask 0*/ 
#define EXISEL_CLEAR_Mask_1          			((uint32_t)0xffff88ff)            /*!< ERU EXISEL Mask 1*/ 
#define EXISEL_CLEAR_Mask_2         			((uint32_t)0xff88ffff)            /*!< ERU EXISEL Mask 2*/ 
#define EXISEL_CLEAR_Mask_3         			((uint32_t)0x88ffffff)            /*!< ERU EXISEL Mask 3*/ 
#define EXICON_BaseInit_CLEAR_Mask        ((uint32_t)0xfff0fff1)            /*!< ERU BaseInit EXICON Mask */ 
#define EXICON_OutConfig_CLEAR_Mask       ((uint32_t)0xffffff8E)            /*!< ERU OutConfig EXICON Mask */ 
#define EXOCON_OutConfig_CLEAR_Mask       ((uint32_t)0xfff0ffc8)            /*!< ERU OutConfig EXOCON Mask */ 

/**
  * @brief  Initializes the ERU according to the specified
  *         parameters in the ERU_BaseInitTypeDef.
  * @param  ERU_BaseInitStruct: pointer to a ERU_BaseInitTypeDef
  *         structure that contains the configuration information for the 
  *         specified ERU peripheral.
  * @retval None
  */
void ERU_BaseInit(ERU_BaseInitTypeDef* ERU_BaseInitStruct)
{
		uint32_t tmpreg;
		
		/* Check the parameters */
		assert_param(IS_ERU_Channel(ERU_BaseInitStruct->ERU_Channel));
		assert_param(IS_ERU_EventA(ERU_BaseInitStruct->ERU_EventA));
		assert_param(IS_ERU_EventB(ERU_BaseInitStruct->ERU_EventB));
		assert_param(IS_ERU_InvA(ERU_BaseInitStruct->ERU_InvA));
		assert_param(IS_ERU_InvB(ERU_BaseInitStruct->ERU_InvB));
		assert_param(IS_ERU_Source(ERU_BaseInitStruct->ERU_Source));
		assert_param(IS_ERU_Polarity(ERU_BaseInitStruct->ERU_Polarity));
		assert_param(IS_ERU_Polarity(ERU_BaseInitStruct->ERU_FLDispose));
	
		tmpreg = ERU->EXISEL;
		switch(ERU_BaseInitStruct->ERU_Channel)
		{
			case ERU_Channel_0:
			{
					tmpreg &= EXISEL_CLEAR_Mask_0;
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventA);
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventB);
					break;
			}
			case ERU_Channel_1:
			{
					tmpreg &= EXISEL_CLEAR_Mask_1;
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventA);
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventB);
					break;
			}
			case ERU_Channel_2:
			{
					tmpreg &= EXISEL_CLEAR_Mask_2;
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventA);
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventB);
					break;
			}
			case ERU_Channel_3:
			{
					tmpreg &= EXISEL_CLEAR_Mask_3;
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventA);
					tmpreg |=  (uint32_t)(ERU_BaseInitStruct->ERU_EventB);
					break;
			}
		}	
		ACCESSEN_WRITE_KEY;
		ERU->EXISEL = tmpreg;
		
		tmpreg = ERU->EXICON[ERU_BaseInitStruct->ERU_Channel];
		tmpreg &= EXICON_BaseInit_CLEAR_Mask;
		tmpreg |= (uint32_t)(ERU_BaseInitStruct->ERU_InvB << 19);
		tmpreg |= (uint32_t)(ERU_BaseInitStruct->ERU_InvA << 18);
		tmpreg |= (uint32_t)(ERU_BaseInitStruct->ERU_Source << 16);
		tmpreg |= (uint32_t)(ERU_BaseInitStruct->ERU_Polarity << 2);
		tmpreg |= (uint32_t)(ERU_BaseInitStruct->ERU_FLDispose << 1);
		ACCESSEN_WRITE_KEY;
		ERU->EXICON[ERU_BaseInitStruct->ERU_Channel] = tmpreg;	
}

/**
  * @brief  Fills each ERU_BaseInitStruct member with its default value.
  * @param  ERU_BaseInitStruct : pointer to a ERU_BaseInitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void ERU_BaseStructInit(ERU_BaseInitTypeDef* ERU_BaseInitStruct)
{
  /* Set the default configuration */
  ERU_BaseInitStruct->ERU_Channel = ERU_Channel_0;
  ERU_BaseInitStruct->ERU_EventA = ERU_Event_0A0;
  ERU_BaseInitStruct->ERU_EventB = ERU_Event_0B0;
  ERU_BaseInitStruct->ERU_InvB = ERU_InputB_Unreverse;
  ERU_BaseInitStruct->ERU_InvA = ERU_InputA_Unreverse;
  ERU_BaseInitStruct->ERU_Source = ERU_Source_A;
  ERU_BaseInitStruct->ERU_Polarity = ERU_Polarity_No;
  ERU_BaseInitStruct->ERU_FLDispose = ERU_FL_Sticky;
}


/**
  * @brief  Initializes the ERU according to 
  *         the specified parameters in the ERU_OutConfigTypeDef.
  * @param  ERU_OutConfigStruct: pointer to a ERU_OutConfigTypeDef
  *         structure that contains the configuration information for the 
  *         specified ERU peripheral.
  * @retval None
  */
void ERU_OutConfig(ERU_OutConfigTypeDef* ERU_OutConfigStruct)
{
		uint32_t tmpreg;
		
		/* Check the parameters */
		assert_param(IS_ERU_Channel(ERU_OutConfigStruct->ERU_Channel));
		assert_param(IS_ERU_ETLxOutCHx(ERU_OutConfigStruct->ERU_ETLxOutCHx));
		assert_param(IS_ERU_PEConfig(ERU_OutConfigStruct->ERU_PEConfig));
		assert_param(IS_ERU_PatternDetect_ETLx(ERU_OutConfigStruct->ERU_PatternDetect_ETLx));
		assert_param(IS_ERU_GateSel(ERU_OutConfigStruct->ERU_GateSel));
		assert_param(IS_ERU_GEENConfig(ERU_OutConfigStruct->ERU_GEENConfig));
		assert_param(IS_ERU_InterTrigSource(ERU_OutConfigStruct->ERU_InterTrigSource));
		
		tmpreg = ERU->EXICON[ERU_OutConfigStruct->ERU_Channel];
		tmpreg &= EXICON_OutConfig_CLEAR_Mask;
		
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_ETLxOutCHx << 4);
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_PEConfig << 0);
		ACCESSEN_WRITE_KEY;
		ERU->EXICON[ERU_OutConfigStruct->ERU_Channel] = tmpreg;	
	
	
		tmpreg = ERU->EXOCON[ERU_OutConfigStruct->ERU_Channel];
		tmpreg &= EXOCON_OutConfig_CLEAR_Mask;
		
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_PatternDetect_ETLx);
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_GateSel << 4);
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_GEENConfig << 2);
		tmpreg |= (uint32_t)(ERU_OutConfigStruct->ERU_InterTrigSource << 0);	
		
		ACCESSEN_WRITE_KEY;
		ERU->EXOCON[ERU_OutConfigStruct->ERU_Channel] = tmpreg;	
}

/**
  * @brief  Fills each ERU_OutConfigStruct member with its default value.
  * @param  ERU_OutConfigStruct : pointer to a ERU_OutConfigTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void ERU_OutConfigStructInit(ERU_OutConfigTypeDef* ERU_OutConfigStruct)
{
  /* Set the default configuration */
  ERU_OutConfigStruct->ERU_Channel = ERU_Channel_0;
  ERU_OutConfigStruct->ERU_ETLxOutCHx = ERU_ETLxOutCHx_OGU0;
  ERU_OutConfigStruct->ERU_PEConfig = ERU_PE_Disable;
  ERU_OutConfigStruct->ERU_PatternDetect_ETLx = ERU_PatternDetect_Disable;
  ERU_OutConfigStruct->ERU_GateSel = ERU_GateSel_0;
  ERU_OutConfigStruct->ERU_GEENConfig = ERU_GEEN_Disable;
  ERU_OutConfigStruct->ERU_InterTrigSource = ERU_InterTrigSource_OFF;
}

/**
  * @brief  Config the Status flag for ETLx.
	* @param  ERU_Channel: Specifies the channel of the ERU.
	*   This parameter can be any combination of the following values:
	*     @arg ERU_Channel_0,ERU_Channel_1,ERU_Channel_2£¬ERU_Channel_3.
  * @param  NewState: new state of the ERU peripheral. 
  *   This parameter can be: Set or Reset.
  * @retval None
  */
void ERU_FL_Config(ERUChannel_TypeDef ERU_Channel,FlagStatus NewState)
{
		assert_param(IS_ERU_Channel(ERU_Channel));
		assert_param(IS_FLAG_STATUS(NewState));
		
		if (NewState != RESET)
		{
				ACCESSEN_WRITE_KEY;
				ERU->EXICON_b[ERU_Channel].FL = 1;
		}
		else
		{
				ACCESSEN_WRITE_KEY;
				ERU->EXICON_b[ERU_Channel].FL = 0;
		}
}


/**
  * @brief  Read the Status flag for ETLx.
	* @param  ERU_Channel: Specifies the channel of the ERU.
	*   This parameter can be any combination of the following values:
	*     @arg ERU_Channel_0,ERU_Channel_1,ERU_Channel_2£¬ERU_Channel_3.
  * @retval the Status flag for ETLx .
  */
uint8_t ERU_FL_Status(ERUChannel_TypeDef ERU_Channel)
{
  uint8_t bitstatus;
  /* Check the parameters */
  assert_param(IS_ERU_Channel(ERU_Channel));
	
	ACCESSEN_WRITE_KEY;
  bitstatus = ERU->EXICON_b[ERU_Channel].FL;
 
  return bitstatus;  
}


/**
  * @brief  Read the Status flag for pattern matching .
	* @param  ERU_Channel: Specifies the channel of the ERU.
	*   This parameter can be any combination of the following values:
	*     @arg ERU_Channel_0,ERU_Channel_1,ERU_Channel_2£¬ERU_Channel_3.
  * @retval the Status flag for pattern matching.
  */
uint8_t ERU_PDR_Status(ERUChannel_TypeDef ERU_Channel)
{
  uint8_t bitstatus;
  /* Check the parameters */
  assert_param(IS_ERU_Channel(ERU_Channel));
	
	ACCESSEN_WRITE_KEY;
  bitstatus = ERU->EXOCON_b[ERU_Channel].PDR;
 
  return bitstatus;  
}

/**
  * @brief  ERU interrupt enable set.
	* @param  ERU_Channel: Specifies the channel of the ERU.
	*   This parameter can be any combination of the following values:
	*     @arg ERU_Channel_0,ERU_Channel_1,ERU_Channel_2£¬ERU_Channel_3.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void ERU_EnableIRQ(ERUChannel_TypeDef ERU_Channel,uint16_t priority)
{
		assert_param(IS_ERU_Channel(ERU_Channel));
	
		switch(ERU_Channel)
		{
					case ERU_Channel_0:
					{
							NVIC_ClearPendingIRQ(ERU0_IRQn);
							NVIC_SetPriority(ERU0_IRQn,priority);   
							NVIC_EnableIRQ(ERU0_IRQn);  
							break;
					}
					case ERU_Channel_1:
					{
							NVIC_ClearPendingIRQ(ERU1_IRQn);
							NVIC_SetPriority(ERU1_IRQn,priority);   
							NVIC_EnableIRQ(ERU1_IRQn);  
							break;
					}
					case ERU_Channel_2:
					{
							NVIC_ClearPendingIRQ(ERU2_IRQn);
							NVIC_SetPriority(ERU2_IRQn,priority);   
							NVIC_EnableIRQ(ERU2_IRQn);  
							break;
					}
					case ERU_Channel_3:
					{
							NVIC_ClearPendingIRQ(ERU3_IRQn);
							NVIC_SetPriority(ERU3_IRQn,priority);   
							NVIC_EnableIRQ(ERU3_IRQn);  
							break;
					}
		}									             
}

/**
  * @brief  ERU interrupt disenable set.
	* @param  ERU_Channel: Specifies the channel of the ERU.
	*   This parameter can be any combination of the following values:
	*     @arg ERU_Channel_0,ERU_Channel_1,ERU_Channel_2£¬ERU_Channel_3.
  * @retval None
  */
void ERU_DisableIRQ(ERUChannel_TypeDef ERU_Channel)
{  
		assert_param(IS_ERU_Channel(ERU_Channel));
	
		switch(ERU_Channel)
		{
					case ERU_Channel_0:
					{
							NVIC_DisableIRQ(ERU0_IRQn);    
							break;
					}
					case ERU_Channel_1:
					{
							NVIC_DisableIRQ(ERU1_IRQn);   
							break;
					}
					case ERU_Channel_2:
					{
							NVIC_DisableIRQ(ERU2_IRQn);    
							break;
					}
					case ERU_Channel_3:
					{
							NVIC_DisableIRQ(ERU3_IRQn);    
							break;
					}
		}	                
}

