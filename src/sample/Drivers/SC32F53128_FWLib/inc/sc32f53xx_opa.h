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
#ifndef __SC32F53xx_OPA_H
#define __SC32F53xx_OPA_H

#include "sc32f53xx_conf.h"


/** 
  * @brief  OPA_Gain_x Select  
**/	
#define		OPA_Gain_1     (uint32_t)0x00000000     /*!< Internal gain selection is 1. */	 
#define		OPA_Gain_2     (uint32_t)0x00010000     /*!< Internal gain selection is 2. */		 
#define		OPA_Gain_3     (uint32_t)0x00020000     /*!< Internal gain selection is 3. */		 
#define		OPA_Gain_4     (uint32_t)0x00030000     /*!< Internal gain selection is 4. */		 
#define		OPA_Gain_5     (uint32_t)0x00040000     /*!< Internal gain selection is 5. */		 
#define		OPA_Gain_6     (uint32_t)0x00050000     /*!< Internal gain selection is 6. */		 
#define		OPA_Gain_7   	 (uint32_t)0x00060000     /*!< Internal gain selection is 7. */		 
#define		OPA_Gain_8     (uint32_t)0x00070000     /*!< Internal gain selection is 8. */		
#define		OPA_Gain_9     (uint32_t)0x00080000     /*!< Internal gain selection is 9. */		 
#define		OPA_Gain_10    (uint32_t)0x00090000	    /*!< Internal gain selection is 10. */	 
#define		OPA_Gain_12    (uint32_t)0x000a0000     /*!< Internal gain selection is 12. */		 
#define		OPA_Gain_14    (uint32_t)0x000b0000     /*!< Internal gain selection is 14. */		 
#define		OPA_Gain_16    (uint32_t)0x000c0000     /*!< Internal gain selection is 16. */		 
#define		OPA_Gain_20    (uint32_t)0x000d0000     /*!< Internal gain selection is 20. */		 
#define		OPA_Gain_24    (uint32_t)0x000e0000     /*!< Internal gain selection is 24. */		 
#define		OPA_Gain_32    (uint32_t)0x000f0000     /*!< Internal gain selection is 32. */		 

#define IS_OPA_Gain(Gain)  (((Gain) == OPA_Gain_1) || ((Gain) == OPA_Gain_2)||\
													 ((Gain) == OPA_Gain_3) || ((Gain) == OPA_Gain_4)||\
													 ((Gain) == OPA_Gain_5) || ((Gain) == OPA_Gain_6)||\
													 ((Gain) == OPA_Gain_7) || ((Gain) == OPA_Gain_8)||\
													 ((Gain) == OPA_Gain_9) || ((Gain) == OPA_Gain_10)||\
													 ((Gain) == OPA_Gain_12) || ((Gain) == OPA_Gain_14)||\
													 ((Gain) == OPA_Gain_16) || ((Gain) == OPA_Gain_20)||\
													 ((Gain) == OPA_Gain_24) || ((Gain) == OPA_Gain_32))

/** 
  * @brief  OPA Bias Voltage Select  
**/	
#define		OPA_BiasVolt_HalfVDD50    (uint32_t)0x00000000     /*!< Amplifier output bias voltage selection is half of VDD50. */	 	 
#define		OPA_BiasVolt_VANA    		  (uint32_t)0x02000000    /*!< Amplifier output bias voltage selection is VANA. */	 

#define IS_OPA_BiasVot(BiasVolt)  (((BiasVolt) == OPA_BiasVolt_HalfVDD50) || ((BiasVolt) == OPA_BiasVolt_VANA))


/** 
  * @brief  OPA Bias  Connect Config
**/	
#define		OPA_BiasConnect_Break    	(uint32_t)0x00000000    /*!<Offset connected to IO is break. */		 
#define		OPA_BiasConnect_Output    (uint32_t)0x01000000    /*!<Offset connected to IO is OPBEX out. */	 

#define IS_OPA_BiasConnect(BiasConnect)  (((BiasConnect) == OPA_BiasConnect_Break) || ((BiasConnect) == OPA_BiasConnect_Output))

															 
/** 
  * @brief  OPA_Invert_InRES  Config  
**/	
#define		OPA_Invert_InRES_No    			 (uint32_t)0x00000000    /*!<Invert input path resistance is disconnect. */	 
#define		OPA_Invert_InRES_Connect     (uint32_t)0x00000200    /*!<Invert input path resistance is connect. */	

#define IS_OPA_InvertInRES(InvertInRES)  (((InvertInRES) == OPA_Invert_InRES_No) || ((InvertInRES) == OPA_Invert_InRES_Connect))

/** 
  * @brief  OPA_Normal_InRES Config  
**/	
#define		OPA_Normal_InRES_No    			 (uint32_t)0x00000000    /*!<Positive phase input path resistance is disconnect. */		 
#define		OPA_Normal_InRES_Connect     (uint32_t)0x00000100    /*!<Positive phase input path resistance is connect. */		

#define IS_OPA_NormalInRES(NormalInRES)  (((NormalInRES) == OPA_Normal_InRES_No) || ((NormalInRES) == OPA_Normal_InRES_Connect))


/** 
  * @brief  OPA Init Structure definition  
  */ 
typedef struct {
	 uint32_t OPA_Gain;   								/*!< OPA   internal gain selection
	                                              This parameter can be a value of @ref OPA_Gain */
	
   uint32_t OPA_BiasVolt;         			/*!< OPA Output offset voltage selection
	                                              This parameter can be a value of @ref OPA_BiasVolt */
	
  uint32_t OPA_BiasConnect;         		/*!< OPA Offset connection to IO enabled
	                                              This parameter can be a value of @ref OPA_BiasConnect */
	
	
	uint32_t OPA_InvertInRES;    					/*!< OPA Inverting input path resistance stub selection
	                                              This parameter can be a value of @ref OPA_InvertInRES */
	
	uint32_t OPA_NormalInRES;    					/*!< OPA Positive input path resistance stub selection
	                                              This parameter can be a value of @ref OPA_NormalInRES */
}OPA_InitTypeDef;


void OPA_Init(OPA_InitTypeDef* OPA_InitStruct);
void OPA_InitStructInit(OPA_InitTypeDef* OPA_InitStruct);
void OPA_Cmd(FunctionalState NewState);
void OPA_OutCmd(FunctionalState NewState);
void OPA_Invert_InBackCmd(FunctionalState NewState);
void OPA_Normal_InBackCmd(FunctionalState NewState);

#endif

