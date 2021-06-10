/**
  ******************************************************************************
  * @file    sc32f53xx_ssp.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the ssp system firmware functions.
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
#ifndef __SC32F53xx_SSP_H
#define __SC32F53xx_SSP_H

#include "sc32f53xx_conf.h"

/** @defgroup SSP_Transfer_DataSize_Select
  * @{
  */
#define  SSP_DataSize_Reserve (uint16_t)0x0000     /*!< transmitted data size is Reserve. */
#define  SSP_DataSize_4b      (uint16_t)0x0003     /*!< transmitted data size is 4 bits. */
#define  SSP_DataSize_5b      (uint16_t)0x0004     /*!< transmitted data size is 5 bits. */
#define  SSP_DataSize_6b      (uint16_t)0x0005     /*!< transmitted data size is 6 bits. */
#define  SSP_DataSize_7b      (uint16_t)0x0006     /*!< transmitted data size is 7 bits. */
#define  SSP_DataSize_8b      (uint16_t)0x0007     /*!< transmitted data size is 8 bits. */
#define  SSP_DataSize_9b      (uint16_t)0x0008     /*!< transmitted data size is 9 bits. */
#define  SSP_DataSize_10b     (uint16_t)0x0009     /*!< transmitted data size is 10 bits. */
#define  SSP_DataSize_11b     (uint16_t)0x000a     /*!< transmitted data size is 11 bits. */
#define  SSP_DataSize_12b     (uint16_t)0x000b     /*!< transmitted data size is 12 bits. */
#define  SSP_DataSize_13b     (uint16_t)0x000c     /*!< transmitted data size is 13 bits. */
#define  SSP_DataSize_14b     (uint16_t)0x000d     /*!< transmitted data size is 14 bits. */
#define  SSP_DataSize_15b     (uint16_t)0x000e     /*!< transmitted data size is 15 bits. */
#define  SSP_DataSize_16b     (uint16_t)0x000f     /*!< transmitted data size is 16 bits. */

#define IS_SSP_DataSize(DataSize)    (((DataSize) == SSP_DataSize_4b) || ((DataSize) == SSP_DataSize_5b) ||\
																			((DataSize) == SSP_DataSize_6b) || ((DataSize) == SSP_DataSize_7b) ||\
																			((DataSize) == SSP_DataSize_8b) || ((DataSize) == SSP_DataSize_9b) ||\
																			((DataSize) == SSP_DataSize_10b) || ((DataSize) == SSP_DataSize_11b) ||\
																			((DataSize) == SSP_DataSize_12b) || ((DataSize) == SSP_DataSize_13b) ||\
																			((DataSize) == SSP_DataSize_14b) || ((DataSize) == SSP_DataSize_15b) ||\
																			((DataSize) == SSP_DataSize_16b) || ((DataSize) == SSP_DataSize_Reserve))

/** @defgroup SSP_SPH_Config
  * @{
  */
#define  SSP_SPH_Edge1    			 	 (uint16_t)0x0000     /*!<Capture or change data output state on the first clock Edge . */   
#define  SSP_SPH_Edge2     			 	 (uint16_t)0x0080     /*!<Capture or change data output state on the second clocks Edges. */   

#define IS_SSP_SPH(SPH)    (((SPH) == SSP_SPH_Edge1) || ((SPH) == SSP_SPH_Edge2))


/** @defgroup SSP_SPO_Config
  * @{
  */
#define  SSP_SPO_Low    			 	 (uint16_t)0x0000     /*!<Maintain a low level between transmissions. */   
#define  SSP_SPO_High     			 (uint16_t)0x0040     /*!<Maintain a high level between transmissions. */   

#define IS_SSP_SPO(SPO)    (((SPO) == SSP_SPO_Low) || ((SPO) == SSP_SPO_High))


/** @defgroup SSP_Transfer_Format_Select
  * @{
  */
#define  SSP_Format_SPI     			 (uint16_t)0x0000     /*!< Transmission frame format is SPI. */
#define  SSP_Format_TI     				 (uint16_t)0x0010     /*!< Transmission frame format is TI. */
#define  SSP_Format_Microwire      (uint16_t)0x0020     /*!< Transmission frame format is Microwire. */

#define IS_SSP_Format(Format)    (((Format) == SSP_Format_SPI) || ((Format) == SSP_Format_TI) || ((Format) == SSP_Format_Microwire))

/** @defgroup SSP_MS_Config
  * @{
  */
#define  SSP_MS_Master    			 	 (uint16_t)0x0000     /*!< Master mode. */   
#define  SSP_MS_Slave     				 (uint16_t)0x0004     /*!< Slave mode. */   

#define IS_SSP_MS(MS)    (((MS) == SSP_MS_Master) || ((MS) == SSP_MS_Slave))

/** @defgroup SSP_Mode_Regular
  * @{
  */
#define  SSP_Mode_Regular    			 	 (uint16_t)0x0000     /*!< Loopback mode is regular. */  
#define  SSP_Mode_SingleWire     		 (uint16_t)0x0001     /*!< Loopback mode is single wire. */  

#define IS_SSP_Mode(Mode)    (((Mode) == SSP_Mode_Regular) || ((Mode) == SSP_Mode_SingleWire))
	
/** @defgroup SSP_ Status_Select
  * @{
  */
#define  SSP_Status_TFE    				(uint16_t)0x0001     /*!< work status is send FIFO empty. */ 
#define  SSP_Status_TNF    				(uint16_t)0x0002     /*!< work status is send FIFO full. */ 
#define  SSP_Status_RNE   				(uint16_t)0x0004     /*!< work status is receive FIFO empty. */ 
#define  SSP_Status_RFF    				(uint16_t)0x0008     /*!< work status is receive FIFO full. */ 
#define  SSP_Status_Busy    			(uint16_t)0x0010     /*!< work status is busy. */  

#define IS_SSP_Status(Status)    	(((Status) == SSP_Status_Busy) || ((Status) == SSP_Status_RFF)||\
																	((Status) == SSP_Status_RNE) || ((Status) == SSP_Status_TNF)||\
																	((Status) == SSP_Status_TFE))

/** @defgroup SSP_ IT_Select
  * @{
  */
#define  SSP_IT_ROR 			(uint16_t)0x0001     /*!< Interrupt trigger source is receive transfinite. */      
#define  SSP_IT_RT 				(uint16_t)0x0002     /*!< Interrupt trigger source is receive timeout . */     
#define  SSP_IT_RX   			(uint16_t)0x0004     /*!< Interrupt trigger source is receive FIFO. */     
#define  SSP_IT_TX    		(uint16_t)0x0008     /*!< Interrupt trigger source is send FIFO. */     

#define IS_SSP_IT(IT)    		((((IT) & (uint16_t)0xFFF0) == 0x00) && ((IT) != (uint16_t)0x00))
																
#define IS_SSP_Clear_IT(IT)    ((((IT) & (uint16_t)0xFFFC) == 0x00) && ((IT) != (uint16_t)0x00))	

/** @defgroup SSP_ DMA_Req_Select
  * @{
  */
#define  SSP_DMAReq_RX    			(uint16_t)0x0001     /*!< Receive DMA enable. */         
#define  SSP_DMAReq_TX    			(uint16_t)0x0002		 /*!< Send DMA enable. */    

#define IS_SSP_DMAReq(DMAReq)    	((((DMAReq) & (uint16_t)0xFFFC) == 0x00) && ((DMAReq) != (uint16_t)0x00))	

/** @defgroup SSP_SRC_Div_Config
  * @{
  */
#define IS_SSP_SRC_Div(Div)    			((Div) <= 0xFF)    /*!< SRC Serial clock frequency crossover value. */  

/** @defgroup SSP_CPSDVSR_Div_Config
  * @{
  */
#define IS_SSP_CPSDVSR_Div(Div)     (((Div) >= 0x02)&&((Div) <= 0xFF))		 /*!< CPSDVSR Clock predivider value. */  


/** 
  * @brief  SSP Init Structure definition  
  */ 
typedef struct {
	
		uint16_t SSP_SPH;             			 	/*!<  SSP select when Capture or change data output state.
	                                              This parameter can be a value of @ref SSP_SPH */
	
		uint16_t SSP_SPO;             			 	/*!<  SSP Maintain level selection between transmissions.
	                                              This parameter can be a value of @ref SSP_SPO */
	
		uint16_t SSP_DataSize;              	/*!<  SSP Data transmission length selection.
	                                              This parameter can be a value of @ref SSP_DataSize */
	
		uint16_t SSP_Format;                  /*!< SSP frame format selection.
	                                              This parameter can be a value of @ref SSP_Format */
	
		uint16_t SSP_MS;                  		/*!< SSP Master slave selection.
	                                              This parameter can be a value of @ref SSP_MS */
	
		uint16_t	SSP_Mode;										/*!< SSP Loop operation mode selection.
	                                              This parameter can be a value of @ref SSP_Mode */
					
		uint16_t  SSP_SRC_Div;								/*!< SSP SRC Serial clock frequency crossover value selection.
	                                              This parameter can be a value of @ref SSP_Mode */

		uint16_t  SSP_CPSDVSR_Div;						/*!< SSP CPSDVSR Clock predivider value Selection.
	                                              This parameter can be a value of @ref SSP_Mode */
}SSP_InitTypeDef;

void SSP_Init(SSP_InitTypeDef* SSP_InitStruct);
void SSP_InitStructInit(SSP_InitTypeDef* SSP_InitStruct);
void SSP_Cmd(FunctionalState NewState);
void SSP_SlaveOut_Cmd(FunctionalState NewState);
void SSP_SendData(uint16_t Data);
uint16_t SSP_ReceiveData(void);
FlagStatus SSP_GetWorkStatus( uint16_t Status);
void SSP_ITConfig(uint16_t Trig_Source,FunctionalState NewState);
void SSP_EnableIRQ(uint16_t priority);
void SSP_DisableIRQ(void);
ITStatus SSP_GetOriginalStatus(uint16_t Trig_Source);
ITStatus SSP_GetITStatus( uint16_t Trig_Source);
void SSP_ClearITStatus(uint16_t Trig_Source);
void SSP_DMACmd(uint16_t DMAReq, FunctionalState NewState);


#endif

