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
#ifndef __SC32F53xx_ERU_H
#define __SC32F53xx_ERU_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"

typedef enum
{
  ERU_Channel_0 = 0x00,
	ERU_Channel_1 = 0x01,
	ERU_Channel_2 = 0x02,
	ERU_Channel_3 = 0x03,
}ERUChannel_TypeDef;

#define IS_ERU_Channel(Channel) 	(((Channel) == ERU_Channel_0) || ((Channel) == ERU_Channel_1) || \
																	((Channel) == ERU_Channel_2) || ((Channel) == ERU_Channel_3))


/** 
  * @brief  ERU Event A Select  
**/	
#define		ERU_Event_0A0   (uint32_t)0x00000000   /*!<ERU event A source selection is 0A0. */	 
#define		ERU_Event_0A1   (uint32_t)0x00000001   /*!<ERU event A source selection is 0A1. */		 
#define		ERU_Event_0A2   (uint32_t)0x00000002   /*!<ERU event A source selection is 0A2. */		 
#define		ERU_Event_0A3   (uint32_t)0x00000003   /*!<ERU event A source selection is 0A3. */		 
#define		ERU_Event_0A4   (uint32_t)0x00000004   /*!<ERU event A source selection is 0A4. */		 
#define		ERU_Event_0A5   (uint32_t)0x00000005   /*!<ERU event A source selection is 0A5. */		 
#define		ERU_Event_0A6   (uint32_t)0x00000006   /*!<ERU event A source selection is 0A6. */		 
#define		ERU_Event_0A7   (uint32_t)0x00000007   /*!<ERU event A source selection is 0A7. */	
#define		ERU_Event_1A0   (uint32_t)0x00000000   /*!<ERU event A source selection is 1A0. */		
#define		ERU_Event_1A1   (uint32_t)0x00000100   /*!<ERU event A source selection is 1A1. */	 
#define		ERU_Event_1A2   (uint32_t)0x00000200   /*!<ERU event A source selection is 1A2. */	 
#define		ERU_Event_1A3   (uint32_t)0x00000300   /*!<ERU event A source selection is 1A3. */	 
#define		ERU_Event_1A4   (uint32_t)0x00000400   /*!<ERU event A source selection is 1A4. */	 
#define		ERU_Event_1A5   (uint32_t)0x00000500   /*!<ERU event A source selection is 1A5. */	 
#define		ERU_Event_1A6   (uint32_t)0x00000600   /*!<ERU event A source selection is 1A6. */	 
#define		ERU_Event_1A7   (uint32_t)0x00000700   /*!<ERU event A source selection is 1A7. */	 
#define		ERU_Event_2A0   (uint32_t)0x00000000   /*!<ERU event A source selection is 2A0. */	
#define		ERU_Event_2A1   (uint32_t)0x00010000   /*!<ERU event A source selection is 2A1. */	 
#define		ERU_Event_2A2   (uint32_t)0x00020000   /*!<ERU event A source selection is 2A2. */	 
#define		ERU_Event_2A3   (uint32_t)0x00030000   /*!<ERU event A source selection is 2A3. */	 
#define		ERU_Event_2A4   (uint32_t)0x00040000   /*!<ERU event A source selection is 2A4. */	 
#define		ERU_Event_2A5   (uint32_t)0x00050000   /*!<ERU event A source selection is 2A5. */	 
#define		ERU_Event_2A6   (uint32_t)0x00060000   /*!<ERU event A source selection is 2A6. */	 
#define		ERU_Event_2A7   (uint32_t)0x00070000   /*!<ERU event A source selection is 2A7. */	  
#define		ERU_Event_3A0   (uint32_t)0x00000000   /*!<ERU event A source selection is 3A0. */	
#define		ERU_Event_3A1   (uint32_t)0x01000000   /*!<ERU event A source selection is 3A1. */	 
#define		ERU_Event_3A2   (uint32_t)0x02000000   /*!<ERU event A source selection is 3A2. */	 
#define		ERU_Event_3A3   (uint32_t)0x03000000   /*!<ERU event A source selection is 3A3. */	 
#define		ERU_Event_3A4   (uint32_t)0x04000000   /*!<ERU event A source selection is 3A4. */	 
#define		ERU_Event_3A5   (uint32_t)0x05000000   /*!<ERU event A source selection is 3A5. */	 
#define		ERU_Event_3A6   (uint32_t)0x06000000   /*!<ERU event A source selection is 3A6. */	 
#define		ERU_Event_3A7   (uint32_t)0x07000000   /*!<ERU event A source selection is 3A7. */	 

#define IS_ERU_EventA(EventA)      ((((EventA) & (uint32_t)0xf8f8f8f8) == 0x00) && ((EventA) != (uint32_t)0x00))


/** 
  * @brief  ERU Event B Select  
**/	
#define		ERU_Event_0B0   (uint32_t)0x00000000   /*!<ERU event B source selection is 0B0. */		
#define		ERU_Event_0B1   (uint32_t)0x00000010   /*!<ERU event B source selection is 0B1. */		 
#define		ERU_Event_0B2   (uint32_t)0x00000020   /*!<ERU event B source selection is 0B2. */		 
#define		ERU_Event_0B3   (uint32_t)0x00000030   /*!<ERU event B source selection is 0B3. */		 
#define		ERU_Event_0B4   (uint32_t)0x00000040   /*!<ERU event B source selection is 0B4. */		 
#define		ERU_Event_0B5   (uint32_t)0x00000050   /*!<ERU event B source selection is 0B5. */		 
#define		ERU_Event_0B6   (uint32_t)0x00000060   /*!<ERU event B source selection is 0B6. */		 
#define		ERU_Event_0B7   (uint32_t)0x00000070   /*!<ERU event B source selection is 0B7. */	 
#define		ERU_Event_1B0   (uint32_t)0x00000000   /*!<ERU event B source selection is 1B0. */	
#define		ERU_Event_1B1   (uint32_t)0x00001000   /*!<ERU event B source selection is 1B1. */	 
#define		ERU_Event_1B2   (uint32_t)0x00002000   /*!<ERU event B source selection is 1B2. */	 
#define		ERU_Event_1B3   (uint32_t)0x00003000   /*!<ERU event B source selection is 1B3. */	 
#define		ERU_Event_1B4   (uint32_t)0x00004000   /*!<ERU event B source selection is 1B4. */	 
#define		ERU_Event_1B5   (uint32_t)0x00005000   /*!<ERU event B source selection is 1B5. */	 
#define		ERU_Event_1B6   (uint32_t)0x00006000   /*!<ERU event B source selection is 1B6. */	 
#define		ERU_Event_1B7   (uint32_t)0x00007000   /*!<ERU event B source selection is 1B7. */	  
#define		ERU_Event_2B0   (uint32_t)0x00000000   /*!<ERU event B source selection is 2B0. */	 
#define		ERU_Event_2B1   (uint32_t)0x00100000   /*!<ERU event B source selection is 2B1. */	 
#define		ERU_Event_2B2   (uint32_t)0x00200000   /*!<ERU event B source selection is 2B2. */	 
#define		ERU_Event_2B3   (uint32_t)0x00300000   /*!<ERU event B source selection is 2B3. */	 
#define		ERU_Event_2B4   (uint32_t)0x00400000   /*!<ERU event B source selection is 2B4. */	 
#define		ERU_Event_2B5   (uint32_t)0x00500000   /*!<ERU event B source selection is 2B5. */	 
#define		ERU_Event_2B6   (uint32_t)0x00600000   /*!<ERU event B source selection is 2B6. */	 
#define		ERU_Event_2B7   (uint32_t)0x00700000   /*!<ERU event B source selection is 2B7. */	 
#define		ERU_Event_3B0   (uint32_t)0x00000000   /*!<ERU event B source selection is 3B0. */	
#define		ERU_Event_3B1   (uint32_t)0x10000000   /*!<ERU event B source selection is 3B1. */	 
#define		ERU_Event_3B2   (uint32_t)0x20000000   /*!<ERU event B source selection is 3B2. */	 
#define		ERU_Event_3B3   (uint32_t)0x30000000   /*!<ERU event B source selection is 3B3. */	 
#define		ERU_Event_3B4   (uint32_t)0x40000000   /*!<ERU event B source selection is 3B4. */	 
#define		ERU_Event_3B5   (uint32_t)0x50000000   /*!<ERU event B source selection is 3B5. */	 
#define		ERU_Event_3B6   (uint32_t)0x60000000   /*!<ERU event B source selection is 3B6. */	 
#define		ERU_Event_3B7   (uint32_t)0x70000000   /*!<ERU event B source selection is 3B7. */	 

#define IS_ERU_EventB(EventB)      ((((EventB) & (uint32_t)0x8f8f8f8f) == 0x00) && ((EventB) != (uint32_t)0x00))


/** 
  * @brief  ERU ETLx Pattern Detection Cmd
**/	
#define		ERU_PatternDetect_Disable  	(uint32_t)0x00000000     /*!<ERU Pattern Detection Disable for ETLx. */	
#define		ERU_PatternDetect_ETL0  		(uint32_t)0x00010000     /*!<ERU Pattern Detection Enable for ETL0. */		 
#define		ERU_PatternDetect_ETL1 		(uint32_t)0x00020000     /*!<ERU Pattern Detection Enable for ETL1. */
#define		ERU_PatternDetect_ETL2  		(uint32_t)0x00040000   	 /*!<ERU Pattern Detection Enable for ETL2. */		 
#define		ERU_PatternDetect_ETL3 		(uint32_t)0x00080000     /*!<ERU Pattern Detection Enable for ETL3. */		

#define IS_ERU_PatternDetect_ETLx(PatternDetect_ETLx)  	((((PatternDetect_ETLx) & (uint32_t)0xff0fffff) == 0x00))


/** 
  * @brief  ERU Reverse InputA Select  
**/	
typedef enum
{
		ERU_InputA_Unreverse = 0x00,   /*!<ERU input A unreverse. */		 
		ERU_InputA_Reverse = 0x01,     /*!<ERU input A reverse. */		
}ERUInvA_TypeDef;

#define IS_ERU_InvA(InvA)  (((InvA) == ERU_InputA_Unreverse) || ((InvA) == ERU_InputA_Reverse))

/** 
  * @brief  ERU Reverse InputB Selection  
**/	
typedef enum
{
		ERU_InputB_Unreverse = 0x00,   /*!<ERU input B unreverse. */		 
		ERU_InputB_Reverse = 0x01,     /*!<ERU input B reverse. */			
}ERUInvB_TypeDef;

#define IS_ERU_InvB(InvB)  (((InvB) == ERU_InputB_Unreverse) || ((InvB) == ERU_InputB_Reverse))

/** 
  * @brief  ERU  Input Source Selection  
**/	
typedef enum
{
		ERU_Source_A = 0x00,   			/*!<ERU ERSx out is direct output A. */		 
		ERU_Source_B = 0x01,   			/*!<ERU ERSx out is direct output B. */		
		ERU_Source_BOrA = 0x02,		  /*!<ERU ERSx out is  output A or B. */	
		ERU_Source_BAndA = 0x03,	  /*!<ERU ERSx out is  output A and B. */	
}ERUSource_TypeDef;

#define IS_ERU_Source(Source)  (((Source) == ERU_Source_A) || ((Source) == ERU_Source_B)||\
															 ((Source) == ERU_Source_BOrA) || ((Source) == ERU_Source_BAndA))

/** 
  * @brief  ERU  Input Source Polarity 
**/	
typedef enum
{
		ERU_Polarity_No = 0x00,	  			 /*!<Falling edges are not considered edge events. */	 
		ERU_Polarity_Rising  = 0x01,	 	 /*!<rising edges are  considered edge events. */		
		ERU_Polarity_Falling = 0x02,		 /*!<Falling edges are  considered edge events. */	
		ERU_Polarity_Edge = 0x03,		 		 /*!<Falling and rising edges are  considered edge events. */		
}ERUPolarity_TypeDef;

#define IS_ERU_Polarity(Polarity)  (((Polarity) == ERU_Polarity_No) || ((Polarity) == ERU_Polarity_Rising)||\
																	 ((Polarity) == ERU_Polarity_Falling) || ((Polarity) == ERU_Polarity_Edge))



/** 
  * @brief  ERU ETLx OutChannel Selection
**/	
typedef enum
{
		ERU_ETLxOutCHx_OGU0 = 0x00,	 	 /*!<trigger pulses are sent to OGU0. */			 
		ERU_ETLxOutCHx_OGU1 = 0x01,	 	 /*!<trigger pulses are sent to OGU1. */	
		ERU_ETLxOutCHx_OGU2 = 0x02,	 	 /*!<trigger pulses are sent to OGU2. */	
		ERU_ETLxOutCHx_OGU3 = 0x03,	 	 /*!<trigger pulses are sent to OGU3. */	
}ERUETLxOutCHx_TypeDef;

#define IS_ERU_ETLxOutCHx(ETLxOutCHx)  (((ETLxOutCHx) == ERU_ETLxOutCHx_OGU0) || ((ETLxOutCHx) == ERU_ETLxOutCHx_OGU1) ||\
																				((ETLxOutCHx) == ERU_ETLxOutCHx_OGU2) || ((ETLxOutCHx) == ERU_ETLxOutCHx_OGU3))


/** 
  * @brief  ERU FL Flag Dispose
**/	
typedef enum
{
		ERU_FL_Sticky = 0x00,	 	  /*!<The status flag FL is not cleared by hardware and is used as sticky  bit. */			 
		ERU_FL_Rebuild = 0x01,	 	 /*!<The status flag FL rebuilds a level detection of the desired event. */	
}ERUFLDispose_TypeDef;

#define IS_ERU_FLDispose(FLDispose)  (((FLDispose) == ERU_FL_Sticky) || ((FLDispose) == ERU_FL_Rebuild))


/** 
  * @brief  ETLx Output Trigger Pulse Configuration
**/	
typedef enum
{
		ERU_PE_Disable = 0x00,  	/*!<Output Trigger Pulse Disable for ETLx. */	
		ERU_PE_Enable = 0x01,	 	  /*!<Output Trigger Pulse Enable for ETLx. */			 			 	
}ERUPEConfig_TypeDef;

#define IS_ERU_PEConfig(PEConfig)  (((PEConfig) == ERU_PE_Disable) || ((PEConfig) == ERU_PE_Enable))


/** 
  * @brief  ETLx Gate Event dection Configuration
**/	
typedef enum
{
		ERU_GEEN_Disable = 0x00,  	/*!<The event detection is disabled. */	
		ERU_GEEN_Enable = 0x01,	 	  /*!<The event detection is enabled. */			 			 	
}ERUGEENConfig_TypeDef;

#define IS_ERU_GEENConfig(GEENConfig)  (((GEENConfig) == ERU_GEEN_Disable) || ((GEENConfig) == ERU_GEEN_Enable))


/** 
  * @brief  ERU GateSel Choose (GP Bit)
**/	
typedef enum
{
		ERU_GateSel_0 = 0x00,	 	 /*!<Gate selection 0(ERU_GOUTy forbidden,ERU_IOUTy can't activate). */			 
		ERU_GateSel_1 = 0x01,	 	 /*!<Gate selection 1(ERU_GOUTy always enable,when ERU_TOUTy activate ERU_IOUTy also activate). */		
		ERU_GateSel_2 = 0x02,	 	 /*!<Gate selection 2(ERU_GOUTy¡¢ERU_PDOUTy is same,when PDR=1,ERU_TOUTy activate,ERU_IOUTy also activate). */	
		ERU_GateSel_3 = 0x03,	 	 /*!<Gate selection 3(ERU_GOUTy¡¢ERU_PDOUTy is opposite,when PDR=0,ERU_TOUTy activate,ERU_IOUTy also activate). */	
}ERUGateSel_TypeDef;

#define IS_ERU_GateSel(GateSel)  (((GateSel) == ERU_GateSel_0) || ((GateSel) == ERU_GateSel_1) ||\
																 ((GateSel) == ERU_GateSel_2) || ((GateSel) == ERU_GateSel_3))


/** 
  * @brief  ERU Internal trigger source selection
**/	
typedef enum
{
		ERU_InterTrigSource_OFF   = 0x00,	 	 /*!< Peripherals trigger input OFF. */		 
		ERU_InterTrigSource_OGUy1 = 0x01,	 	 /*!< Peripherals trigger input is OGUy1. */	
		ERU_InterTrigSource_OGUy2 = 0x02,	 	 /*!< Peripherals trigger input is OGUy2. */
		ERU_InterTrigSource_OGUy3 = 0x03,	 	 /*!< Peripherals trigger input is OGUy3. */
}ERUInterTrigSource_TypeDef;

#define IS_ERU_InterTrigSource(InterTrigSource)     (((InterTrigSource) == ERU_InterTrigSource_OFF) ||\
																									  ((InterTrigSource) == ERU_InterTrigSource_OGUy1) ||\
																										((InterTrigSource) == ERU_InterTrigSource_OGUy2) ||\
																										((InterTrigSource) == ERU_InterTrigSource_OGUy3))


/** 
  * @brief  ERU Base Init structure definition  
  */
typedef struct
{

	ERUChannel_TypeDef ERU_Channel;             /*!< Specifies ERU channel selection.
                                              This parameter can be a value of @ref ERUChannel_TypeDef */

  ERUSource_TypeDef ERU_Source;           		/*!< Specifies ERU ERSx out source selection.
                                              This parameter can be a value of @ref ERUSource_TypeDef */
	
  uint32_t 	ERU_EventA;                 				 /*!< Specifies ERU event A selection.
                                              This parameter can be a value of @ref ERU_EventA */	
	
	uint32_t 	ERU_EventB;                 				 /*!< Specifies ERU event B selection.
                                              This parameter can be a value of @ref ERU_EventB */	
	
  ERUPolarity_TypeDef ERU_Polarity;            /*!< Specifies ERU trigger polarity selection.
                                              This parameter can be a value of @ref ERUPolarity_TypeDef */

  ERUInvA_TypeDef ERU_InvA;      							 /*!< Specifies ERU input A unreverse or reverse.
                                              This parameter can be a value of @ref ERUInvA_TypeDef */	
	
  ERUInvB_TypeDef ERU_InvB;        						/*!< Specifies ERU input B unreverse or reverse.
                                              This parameter can be a value of @ref ERUInvB_TypeDef */	
																							
	ERUFLDispose_TypeDef	ERU_FLDispose;				/*!< Specifies the ERU FL Flag Dispose.
                                              This parameter can be a value of @ref ERUFLDispose_TypeDef */																																												
}ERU_BaseInitTypeDef;


/** 
  * @brief  ERU Out Config structure definition  
  */
typedef struct
{

	ERUChannel_TypeDef ERU_Channel;             /*!< Specifies ERU channel selection.
                                              This parameter can be a value of @ref ERUChannel_TypeDef */

  ERUETLxOutCHx_TypeDef ERU_ETLxOutCHx;       /*!< Specifies ERU Output Channel Select for ETLx Output Trigger Pulse.
                                              This parameter can be a value of @ref ERUETLxOutCHx_TypeDef */
	
  ERUPEConfig_TypeDef ERU_PEConfig;         	/*!< Specifies ERU ETLx Output Trigger Pulse configuration.
                                              This parameter can be a value of @ref ERUPEConfig_TypeDef */	
	
	uint32_t 	ERU_PatternDetect_ETLx;           /*!< Specifies ERU  enable Pattern Detection for ETLx.
                                              This parameter can be a value of @ref ERU_PatternDetect_ETLx */	
	
  ERUGateSel_TypeDef ERU_GateSel;             /*!< Specifies ERU GateSel selection(GP bit).
                                              This parameter can be a value of @ref ERUGateSel_TypeDef */

  ERUGEENConfig_TypeDef ERU_GEENConfig;      	/*!< Specifies ERU ETLx Gate Event dection configuration.
                                              This parameter can be a value of @ref ERUGEENConfig_TypeDef */	
	
  ERUInterTrigSource_TypeDef ERU_InterTrigSource;     /*!< Specifies ERU Internal trigger source selection.
																											This parameter can be a value of @ref ERUInterTrigSource_TypeDef */	
																																																																	
}ERU_OutConfigTypeDef;



void ERU_BaseInit(ERU_BaseInitTypeDef* ERU_BaseInitStruct);
void ERU_BaseStructInit(ERU_BaseInitTypeDef* ERU_BaseInitStruct);
void ERU_OutConfig(ERU_OutConfigTypeDef* ERU_OutConfigStruct);
void ERU_OutConfigStructInit(ERU_OutConfigTypeDef* ERU_OutConfigStruct);
void ERU_FL_Config(ERUChannel_TypeDef ERU_Channel,FlagStatus NewState);
uint8_t ERU_FL_Status(ERUChannel_TypeDef ERU_Channel);
uint8_t ERU_PDR_Status(ERUChannel_TypeDef ERU_Channel);
void ERU_EnableIRQ(ERUChannel_TypeDef ERU_Channel,uint16_t priority);
void ERU_DisableIRQ(ERUChannel_TypeDef ERU_Channel);

#endif
