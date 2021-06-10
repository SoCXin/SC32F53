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
  * <h2><center>&copy; COPYRIGHT 2015 Silan Microelectronics </center></h2>
  ********************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC32F53xx_CMP_H
#define __SC32F53xx_CMP_H

#include "sc32f53xx_conf.h"


/** 
  * @brief  CMP_CP0P0_EXTERCHx_Select  
  */
typedef enum
{
		CMP_CP0P0_ExterCH0  = 0x00,   	/*!< CMP Positive channel 0 selection is external channel 0. */        
		CMP_CP0P0_ExterCH1  = 0x01,   	/*!< CMP Positive channel 0 selection is external channel 1. */          
		CMP_CP0P0_ExterCH2	= 0x02,   	/*!< CMP Positive channel 0 selection is external channel 2. */         			
		CMP_CP0P0_ExterCH3	= 0x03,   	/*!< CMP Positive channel 0 selection is external channel 3. */          
}CMPCP0P0ExterCHx_TypeDef;

#define IS_CMP_CP0P0(CP0P0)  (((CP0P0) == CMP_CP0P0_ExterCH0) || ((CP0P0) == CMP_CP0P0_ExterCH1)||\
														 ((CP0P0) == CMP_CP0P0_ExterCH2) || ((CP0P0) == CMP_CP0P0_ExterCH3))


/** 
  * @brief  CMP_CP0N0_EXTERCHx_Select  
  */
typedef enum
{
		CMP_CP0N0_ExterCH0  = 0x00,   	/*!< CMP negative channel 0 selection is external channel 0. */         
		CMP_CP0N0_ExterCH1  = 0x01,   	/*!< CMP negative channel 0 selection is external channel 1. */          
		CMP_CP0N0_ExterCH2	= 0x02,   	/*!< CMP negative channel 0 selection is external channel 2. */         			
		CMP_CP0N0_ExterCH3	= 0x03,   	/*!< CMP negative channel 0 selection is external channel 3. */          
}CMPCP0N0ExterCHx_TypeDef;

#define IS_CMP_CP0N0(CP0N0)  (((CP0N0) == CMP_CP0N0_ExterCH0) || ((CP0N0) == CMP_CP0N0_ExterCH1)||\
														 ((CP0N0) == CMP_CP0N0_ExterCH2) || ((CP0N0) == CMP_CP0N0_ExterCH3))


/** 
  * @brief  CMP_CP0N_Select  
  */
typedef enum
{
		CMP_CP0N_CVREF0  = 0x00,   	 /*!< CMP negative channel selection is CVREF0. */       
		CMP_CP0N_EXTER = 0x01,   		/*!< CMP negative channel selection is external channels. */  
		CMP_CP0N_VANA	  = 0x02,   	/*!< CMP negative channel selection is VANA. */        			
		CMP_CP0N_VSS		= 0x03,   	/*!< CMP negative channel selection is VSS. */     
}CMPCP0N_TypeDef;

#define IS_CMP_CP0N(CP0N)  (((CP0N) == CMP_CP0N_EXTER) || ((CP0N) == CMP_CP0N_CVREF0)||\
														((CP0N) == CMP_CP0N_VANA) || ((CP0N) == CMP_CP0N_VSS))


/** 
  * @brief  CMP_CP0P_Select  
  */
typedef enum
{
		CMP_CP0P_OP0O  = 0x00,   	  /*!< CMP Positive channel selection is OPA out. */     
		CMP_CP0P_EXTER   = 0x01,   	/*!< CMP Positive channel selection is external channels. */    
		CMP_CP0P_VTS	  = 0x02,   	/*!< CMP Positive channel selection is VTS. */         			
		CMP_CP0P_VDD15	= 0x03,   	/*!< CMP Positive channel selection is VDD15. */      
}CMPCP0P_TypeDef;

#define IS_CMP_CP0P(CP0P)  (((CP0P) == CMP_CP0P_EXTER) || ((CP0P) == CMP_CP0P_OP0O)||\
														((CP0P) == CMP_CP0P_VTS) || ((CP0P) == CMP_CP0P_VDD15))

/** 
  * @brief  CMP_VS_Select  
  */
typedef enum
{
		CMP_VS_VDD   = 0x00,   	/*!<Internal resistance partial voltage step power selection is VDD. */           
		CMP_VS_Reserve   = 0x01,   	/*!<Internal resistance partial voltage step power selection is Reserve. */   
}CMPVS_TypeDef;

#define IS_CMP_VS(VS)  (((VS) == CMP_VS_VDD) || ((VS) == CMP_VS_Reserve))


/** 
  * @brief  CMP_PartVolt_Planx_Select  
  */
typedef enum
{
		CMP_PartVolt_Plan1  = 0x00,   	/*!<Partial pressure option is plan 1. */           
		CMP_PartVolt_Plan2  = 0x02,   	/*!<Partial pressure option is plan 2. */ 
		CMP_PartVolt_Plan3  = 0x01,   	/*!<Partial pressure option is plan 3. */         			
		CMP_PartVolt_Plan4	= 0x03,   	/*!<Partial pressure option is plan 4. */      
}CMPPartVolt_TypeDef;

#define IS_CMP_PartVolt(PartVolt)  (((PartVolt) == CMP_PartVolt_Plan1) || ((PartVolt) == CMP_PartVolt_Plan2)||\
																	 ((PartVolt) == CMP_PartVolt_Plan3) || ((PartVolt) == CMP_PartVolt_Plan4))


/** 
  * @brief  CMP_Delay_Config  
  */
typedef enum
{
		CMP_Delay_Enable  = 0x01,    	/*!<CMP delay enable. */        
		CMP_Delay_Disable = 0x00,     /*!<CMP delay disable. */  
}CMPDelay_TypeDef;

#define IS_CMP_Delay(Delay)  (((Delay) == CMP_Delay_Enable) || ((Delay) == CMP_Delay_Disable))


/** 
  * @brief  CMP_IRQ_Config 
  */
typedef enum
{
		CMP_IRQNo  		 = 0x00,    	/*!<The interrupt trigger source is none. */          
		CMP_IRQRising  = 0x01,    	/*!<The interrupt trigger source is the rising edge. */ 
		CMP_IRQFalling = 0x02,    	/*!<The interrupt trigger source is the falling edge. */  
		CMP_IRQEdge    = 0x03,    	/*!<The interrupt trigger source is the rising and falling edge. */  
}CMPIRQ_TypeDef;

#define IS_CMP_IRQ(IRQ)  (((IRQ) == CMP_IRQNo) || ((IRQ) == CMP_IRQRising) ||\
												 ((IRQ) == CMP_IRQFalling) || ((IRQ) == CMP_IRQEdge))


/** 
  * @brief  CMP_OutGate_Config  
  */
typedef enum
{
		CMP_OutGate_No  	= 0x00,    	 /*!<Disable out gate. */          
		CMP_OutGate_HighLevel = 0x01,  /*!<Enable out gate. */  
}CMPOutGate_TypeDef;

#define IS_CMP_OutGate(OutGate)  (((OutGate) == CMP_OutGate_No) || ((OutGate) == CMP_OutGate_HighLevel))


/** 
  * @brief  CMP_OutSynch_Select 
  */
typedef enum
{
		CMP_OutSynch_No 	 = 0x00,
		CMP_OutSynch_T1CH1 = 0x08,   /*!<Output synchronization selection is T1 channel 1. */ 
		CMP_OutSynch_T1CH2 = 0x09,   /*!<Output synchronization selection is T1 channel 2. */  
		CMP_OutSynch_T1CH3 = 0x0A,   /*!<Output synchronization selection is T1 channel 3. */ 
		CMP_OutSynch_T1CH4 = 0x0B,   /*!<Output synchronization selection is T1 channel 4. */  
}CMPOutSynch_TypeDef;

#define IS_CMP_OutSynch(OutSynch)  (((OutSynch) == CMP_OutSynch_T1CH1) || ((OutSynch) == CMP_OutSynch_T1CH2)||\
																	 ((OutSynch) == CMP_OutSynch_T1CH3) || ((OutSynch) == CMP_OutSynch_T1CH4) ||\
																	 ((OutSynch) == CMP_OutSynch_No))


/** 
  * @brief  CMP Reverse Output Select  
**/	
typedef enum
{
		CMP_UnreverseOut = 0x00,   /*!<Output inversely selection is disable. */  	  	 
		CMP_ReverseOut = 0x01,     /*!<Output inversely selection is enable. */    		
}CMPInv_TypeDef;

#define IS_CMP_Inv(Inv)  (((Inv) == CMP_UnreverseOut) || ((Inv) == CMP_ReverseOut))


#define IS_CMP_C0RDSVal(C0RDSVal) 		((C0RDSVal) <= 0x1F)     /*!<Internal resistance partial voltage step adjustment value. */     

#define IS_CMP_FiltCLKDIV(FiltCLKDIV) ((FiltCLKDIV) <= 0x1F)   /*!<Digital filtering period selection value. */     

#define IS_CMP_FiltCycle(FiltCycle) 	((FiltCycle) <= 1023)		 /*!<Digital filter clock frequency division value. */


/** 
  * @brief  CMP Init structure definition  
  */
typedef struct
{

	CMPDelay_TypeDef CMP_Delay;                /*!< Specifies the CMP delay enable or disable bit.
                                              This parameter can be a value of @ref CMPDelay_TypeDef */

  CMPPartVolt_TypeDef CMP_PartVolt;          /*!< Specifies the Partial pressure option selection bits.
                                              This parameter can be a value of @ref CMPPartVolt_TypeDef */	
	
  CMPVS_TypeDef CMP_VS;                			 /*!< Specifies the Internal resistance step power supply selection bit.
                                              This parameter can be a value of @ref CMPVS_TypeDef */

  CMPCP0P_TypeDef CMP_CP0P;     						 /*!< Specifies the CP0P channel selection bits.
                                              This parameter can be a value of @ref CMPCP0P_TypeDef */	
	
  CMPCP0N_TypeDef CMP_CP0N;        						/*!< Specifies the CP0N channel selection bits.
                                              This parameter can be a value of @ref CMPCP0N_TypeDef */	
	
  CMPCP0P0ExterCHx_TypeDef CMP_CP0P0ExterCHx;     /*!< Specifies the CP0P0 external channel selection bits.
																									This parameter can be a value of @ref CMPCP0P0ExterCHx_TypeDef */
																							
  CMPCP0N0ExterCHx_TypeDef CMP_CP0N0ExterCHx;    /*!< Specifies the CP0N0 external channel selection bits.
																									This parameter can be a value of @ref CMPCP0N0ExterCHx_TypeDef */
																									
	CMPInv_TypeDef		CMP_Inv;									/*!< Specifies the Output reverse phase selection bit.
																							This parameter can be a value of @ref CMPInv_TypeDef */		

	uint8_t  C0RDSVal;													/*!< Specifies Cooperate with C0VRRH and C0VRRL to realize a variety of voltage values.
																							This parameter can be a value of @ref C0RDSVal_define */		
																								
}CMP_InitTypeDef;

/** 
  * @brief  CMP Filt structure definition  
  */
typedef struct
{

	uint8_t CMP_FiltCLKDIV;                			/*!< Specifies the Digital filtering period value selection bits.
                                              This parameter can be a value of @ref CMP_FiltCLKDIV */

  uint16_t CMP_FiltCycle;           					/*!< Specifies the Digital filter clock frequency division value selection bits.
                                              This parameter can be a value of @ref CMP_FiltCycle */
	
  CMPOutSynch_TypeDef CMP_OutSynch;           /*!< Specifies the Output synchronization selection bits.
                                              This parameter can be a value of @ref CMPOutSynch_TypeDef */	
	
  CMPOutGate_TypeDef CMP_OutGate;             /*!< Specifies the out gate enable or disable bit.
                                              This parameter can be a value of @ref CMPOutGate_TypeDef */
																								
}CMP_FiltTypeDef;

void CMP_BaseInit(CMP_InitTypeDef* CMP_InitStruct);
void CMP_InitStructInit(CMP_InitTypeDef* CMP_InitStruct);
void CMP_FiltInit(CMP_FiltTypeDef* CMP_FiltStruct);
void CMP_FiltStructInit(CMP_FiltTypeDef* CMP_FiltStruct);

void CMP_Cmd(FunctionalState NewState);
void CMP_CVREF0_Cmd(FunctionalState NewState);
void CMP_CVREF0_Output_Cmd(FunctionalState NewState);
void CMP_AnalogFilt_Cmd(FunctionalState NewState);
void CMP_ITConfig(CMPIRQ_TypeDef IRQ,FunctionalState NewState);
void CMP_EnableIRQ(uint16_t priority);
void CMP_DisableIRQ(void);
ITStatus CMP_GetIRQStatus(void);
void CMP_ClearIRQStatus(void);

#endif

