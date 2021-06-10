/**
  ******************************************************************************
  * @file    sc32f53xx_led.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    22-05-2019
  * @brief   This file provides all the LED firmware functions.
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
#ifndef __SC32F53xx_LED_H
#define __SC32F53xx_LED_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


/**
  * @brief  LED interrupt operation mode control selection
  */
typedef enum
{
  LED_Scan_Continue = 0x00,    /*!< LEDIF = 1, LED scan continues  */
  LED_Scan_Stop = 0x01,    		 /*!< LEDIF = 1, LED scan Stop  */
}LEDScanMode_Typedef;

#define IS_LED_ScanMode(ScanMode) 	(((ScanMode) == LED_Scan_Continue) || ((ScanMode) == LED_Scan_Stop))	

/**
  * @brief  LED work mode selection
  */
typedef enum
{
  LED_ModeSel_1 = 0x00,    /*!< LED mode 1 (Non-dimmable LED display) */
  LED_ModeSel_2 = 0x01,    /*!< LED mode 2 (LED display with adjustable light) */
}LEDModeSel_Typedef;

#define IS_LED_ModeSel(ModeSel) 	(((ModeSel) == LED_ModeSel_1) || ((ModeSel) == LED_ModeSel_2))	


/**
  * @brief  LED RAM register update mode selection
  */
typedef enum
{
  LED_LEDIF_Update = 0x00,    /*!< LEDIF when the LED RAM is updated into the shadow register */
  LED_COMIF_Update = 0x01,    /*!< COMIF when the LED RAM is updated into the shadow register */
}LEDUpdateMode_Typedef;

#define IS_LED_UpdateMode(UpdateMode) 	(((UpdateMode) == LED_LEDIF_Update) || ((UpdateMode) == LED_COMIF_Update))	


/** @defgroup LED_IT_Source 
  * @{
  */
#define   LED_IT_COM   						((uint16_t)0x0008)   /*!<COM Interrupt. */		   			
#define   LED_IT_Frame    				((uint16_t)0x0010)   /*!<LED Frame Interrupt. */		 	  	 	

#define IS_LED_IT(ITSource)    ((((ITSource) & (uint16_t)0xFFE7) == 0x00) && ((ITSource) != (uint16_t)0x00))


/** 
  * @brief  LED Config Structure definition  
  */ 
typedef struct {
	
  LEDScanMode_Typedef LED_LEDITMD;              /*!< Specifies the LED interrupt operation mode control selection.
	                                              This parameter can be a value of @ref LEDScanMode_Typedef */
	
  LEDModeSel_Typedef LED_MODE;                  /*!< Specifies the LED work mode selection.
	                                              This parameter can be a value of @ref LEDModeSel_Typedef */
	
	LEDUpdateMode_Typedef LED_UPDMODE;               /*!< Specifies the LED RAM register update mode selection.
	                                              This parameter can be a value of @ref LEDUpdateMode_Typedef */
}LED_ConfigTypeDef;



void LED_ModeConfig(LED_ConfigTypeDef* LED_ConfigStruct);
void LED_ConfigStructInit(LED_ConfigTypeDef* LED_ConfigStruct);
void LED_Cmd(FunctionalState NewState);
void LED_BasicConfig(uint8_t Clock_Width, uint8_t Dead_Width);
void LED_COMSEGConfig(uint8_t COM_Value, uint16_t SEG_Value);
void LED_IRQCmd(uint16_t ITSource,FunctionalState NewState);
ITStatus LED_GetITStatus(uint16_t ITSource);
void LED_ClearITStatus(uint16_t ITSource);
FlagStatus LED_GetIDLEStatus(void);
void LED_WriteRAM(uint32_t RAM0_Value, uint32_t RAM1_Value, uint32_t RAM2_Value, uint32_t RAM3_Value);



#endif



