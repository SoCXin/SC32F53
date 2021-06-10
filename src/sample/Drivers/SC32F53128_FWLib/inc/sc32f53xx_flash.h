/**
  ******************************************************************************
  * @file    sc32f53xx_flash.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the flash functions.
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
#ifndef __SC32F53xx_FLASH_H
#define __SC32F53xx_FLASH_H

#include "sc32f53xx_conf.h"


/** 
  * @brief  FLASH MODE Select  
**/	
#define		FLASH_Mode_OPSTART     (uint32_t)0x00000001    /*!<Program or block erase  control bits. */   		 
#define		FLASH_Mode_PROG	 		   (uint32_t)0x00000002    /*!<Programmed control bit. */ 	
#define		FLASH_Mode_PAGE  			 (uint32_t)0x00000004    /*!<Block erasure control bit. */			 
#define		FLASH_Mode_MASS				 (uint32_t)0x00000008    /*!<Program area erases all control bit. */	
#define		FLASH_Mode_RD   			 (uint32_t)0x00000010    /*!<Read control bit. */			 
#define		FLASH_Mode_NVR	 			 (uint32_t)0x00000020    /*!<The information area operates the control bit. */	
#define		FLASH_Mode_BOOTKEY   	 (uint32_t)0x00000100    /*!<BOOT partition KEY matches bits. */		 
#define		FLASH_Mode_USR1KEY	   (uint32_t)0x00000200	   /*!<USR1 partition KEY matches bits. */
#define		FLASH_Mode_USR2KEY	   (uint32_t)0x00000400    /*!<USR2 partition KEY matches bits. */	

#define IS_FLASH_Mode(Mode)  		 (((Mode) == FLASH_Mode_OPSTART) || ((Mode) == FLASH_Mode_PROG) ||\
																 ((Mode) == FLASH_Mode_PAGE) || ((Mode) == FLASH_Mode_MASS) ||\
																 ((Mode) == FLASH_Mode_RD) || ((Mode) == FLASH_Mode_NVR) ||\
																 ((Mode) == FLASH_Mode_BOOTKEY) || ((Mode) == FLASH_Mode_USR1KEY) ||\
																 ((Mode) == FLASH_Mode_USR2KEY))
																 
#define IS_FLASH_Enable_Status(Status)   (((Status) == FLASH_Mode_PROG) ||\
																				 ((Status) == FLASH_Mode_PAGE) || ((Status) == FLASH_Mode_MASS) ||\
																				 ((Status) == FLASH_Mode_RD) || ((Status) == FLASH_Mode_NVR) ||\
																				 ((Status) == FLASH_Mode_BOOTKEY) || ((Status) == FLASH_Mode_USR1KEY) ||\
																				 ((Status) == FLASH_Mode_USR2KEY))
																				 
#define IS_FLASH_KeyArea(KeyArea)		 		(((KeyArea) == FLASH_Mode_BOOTKEY) || ((KeyArea) == FLASH_Mode_USR1KEY) ||\
																				((KeyArea) == FLASH_Mode_USR2KEY))


/** 
  * @brief  Flash Delay Config  
**/	
#define		FLASH_Delay_No     	 (uint32_t)0x00000000    /*!<FLASH read-wait configuration is 0 clock. */			 
#define		FLASH_Delay_CLK1     (uint32_t)0x00000001    /*!<FLASH read-wait configuration is 1 clock. */			 
#define		FLASH_Delay_CLK2     (uint32_t)0x00000002    /*!<FLASH read-wait configuration is 2 clock. */			 
#define		FLASH_Delay_CLK3     (uint32_t)0x00000003    /*!<FLASH read-wait configuration is 3 clock. */			 

#define IS_FLASH_Delay(Delay)  	(((Delay) == FLASH_Delay_No) || ((Delay) == FLASH_Delay_CLK1) ||\
															  ((Delay) == FLASH_Delay_CLK2) || ((Delay) == FLASH_Delay_CLK3))
															 
/** 
  * @brief  Flash IT Config  
**/	
#define		FLASH_IT_Complete     	(uint32_t)0x00000001    /*!<End of operation interrupt configuration bit. */			 
#define		FLASH_IT_Protect    		(uint32_t)0x00000002    /*!<Protect interrupt configuration bit. */					 
#define		FLASH_IT_Error     			(uint32_t)0x00000004    /*!<Operation error interrupts configuration bit. */				 
#define		FLASH_IT_RCHOff     		(uint32_t)0x00000008    /*!<RCH Status check interrupt configuration bit. */				 
#define		FLASH_IT_DRDErr     		(uint32_t)0x00000010    /*!<User reading error interrupts configuration bit. */	
#define   FLASH_IT_ALL            (uint32_t)0x0000001F 

#define IS_FLASH_IT(IT)           (((IT) == FLASH_IT_Complete) || ((IT) == FLASH_IT_Protect) ||\
                                    ((IT) == FLASH_IT_Error) || ((IT) == FLASH_IT_RCHOff) || \
																		((IT) == FLASH_IT_DRDErr) || ((IT) == FLASH_IT_ALL) )
/** 
  * @brief  Flash Status Config  
**/	
#define		FLASH_Status_BOOTPAREN     		(uint32_t)0x00000001    /*!<BOOT zone state bit. */			 
#define		FLASH_Status_USR1PAREN    		(uint32_t)0x00000002    /*!<USR1 zone state bit. */		 
#define		FLASH_Status_USR2PAREN    		(uint32_t)0x00000004    /*!<USR2 zone state bit. */		 
#define		FLASH_Status_BOOTCRCEN     		(uint32_t)0x00000100    /*!<BOOT CRC check state bit. */			 
#define		FLASH_Status_USR1CRCEN     		(uint32_t)0x00000200    /*!<USR1 CRC check state bit. */		 
#define		FLASH_Status_USR2CRCEN     		(uint32_t)0x00000400    /*!<USR2 CRC check state bit. */		 
#define		FLASH_Status_BOOTKEYOK    		(uint32_t)0x00010000    /*!<BOOT key matches state bit. */		 
#define		FLASH_Status_USR1KEYOK     		(uint32_t)0x00020000    /*!<USR1 key matches state bit. */		 
#define		FLASH_Status_USR2KEYOK     		(uint32_t)0x00040000    /*!<USR2 key matches state bit. */		 
#define		FLASH_Status_BOOTCRCOK    		(uint32_t)0x01000000    /*!<BOOT partition CRC check status bits. */		 
#define		FLASH_Status_USR1CRCOK     		(uint32_t)0x02000000    /*!<USR1 partition CRC check status bits. */		 
#define		FLASH_Status_USR2CRCOK     		(uint32_t)0x04000000    /*!<USR2 partition CRC check status bits. */		 

#define IS_FLASH_Status(Status)  			(((Status) == FLASH_Status_BOOTPAREN) || ((Status) == FLASH_Status_USR1PAREN) ||\
																			((Status) == FLASH_Status_USR2PAREN) || ((Status) == FLASH_Status_BOOTCRCEN)||\
																			((Status) == FLASH_Status_USR1CRCEN) || ((Status) == FLASH_Status_USR2CRCEN)||\
																			((Status) == FLASH_Status_BOOTKEYOK) || ((Status) == FLASH_Status_USR1KEYOK)||\
																			((Status) == FLASH_Status_USR2KEYOK) || ((Status) == FLASH_Status_BOOTCRCOK)||\
																			((Status) == FLASH_Status_USR1CRCOK) || ((Status) == FLASH_Status_USR2CRCOK))															
																



void FLASH_Mode_Cmd(uint32_t Mode,FunctionalState NewState);
FunctionalState Flash_GetEnableStatus(uint32_t Status);
void FLASH_DelayCLK(uint32_t Delay);
void FLASH_Prefetch_Cmd(FunctionalState NewState);
void FLASH_DataPrefetch_Cmd(FunctionalState NewState);
void FLASH_WriteADDR(uint32_t Address);
void FLASH_WriteDATA(uint32_t Data);
void FLASH_WriteFEED(void);
void Flash_EnableIRQ(uint16_t priority);
void Flash_DisableIRQ(void);
void Flash_ITCmd(uint32_t ITSource, FunctionalState NewState);
ITStatus Flash_GetITStatus(uint32_t ITSource);
void Flash_ClearITFlag(uint32_t ITSource);
ITStatus Flash_GetWorkStatus(uint32_t Status);

void Flash_ClearControllerStatus(void);
void Flash_KeyMatch(uint32_t KeyArea,uint32_t FLASH_KEY1,uint32_t FLASH_KEY2,uint32_t FLASH_KEY3,uint32_t FLASH_KEY4);
void Flash_ProgramPage(uint32_t page_num,uint16_t dataLen,uint32_t *data);
void Flash_ErasePage(uint8_t page_num);

#endif

