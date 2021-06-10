/**
  ******************************************************************************
  * @file    sc32f53xx_uart.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    20-05-2019
  * @brief   This file provides all the UART firmware functions.
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
#ifndef __SC32F53xx_UART_H
#define __SC32F53xx_UART_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


/** @defgroup UART_Exported_Constants
  * @{
  */ 
  
#define IS_UART_ALL_PERIPH(UARTx) 	 (((UARTx) == UART1) || \
                                     ((UARTx) == UART2) || \
                                     ((UARTx) == UART3) || \
                                     ((UARTx) == UART4) || \
																		 ((UARTx) == UART5) || \
                                     ((UARTx) == UART6))



/** @defgroup UART_Word_Length 
  * @{
  */ 
  
#define UART_WordLength_5b           ((uint16_t)0x0000)    	 /*!<Word length is 5 bits. */
#define UART_WordLength_6b           ((uint16_t)0x0020)   	 /*!<Word length is 6 bits. */
#define UART_WordLength_7b           ((uint16_t)0x0040)      /*!<Word length is 7 bits. */
#define UART_WordLength_8b           ((uint16_t)0x0060)      /*!<Word length is 8 bits. */
                                    
#define IS_UART_WORD_LENGTH(LENGTH)  (((LENGTH) == UART_WordLength_5b) || \
                                      ((LENGTH) == UART_WordLength_6b) || \
                                      ((LENGTH) == UART_WordLength_7b) || \
                                      ((LENGTH) == UART_WordLength_8b)) 

/** @defgroup UART_Error Config 
  * @{
  */ 
  
#define UART_Error_Overrun                   ((uint16_t)0x0800)    /*!<Overrun error. */
#define UART_Error_Break                     ((uint16_t)0x0400)    /*!<Break error. */
#define UART_Error_Parity                    ((uint16_t)0x0200)    /*!<Parity error. */
#define UART_Error_Farming                   ((uint16_t)0x0100)    /*!<Farming  error. */
#define UART_Error_ALL                  		 ((uint16_t)0x0F00)    /*!<ALL  error. */

#define IS_UART_Error(Error)  (((Error) == UART_Error_Overrun) || ((Error) == UART_Error_Break)||\
                              ((Error) == UART_Error_Parity) || ((Error) == UART_Error_Farming)||\
															((Error) == UART_Error_ALL))


/** @defgroup UART_Work_Status Config 
  * @{
  */ 
  
#define UART_WorkStatus_CTS                  	((uint16_t)0x0001)    /*!<Specifies Clear to Send Flag. */
#define UART_WorkStatus_BUSY                  ((uint16_t)0x0008)    /*!<Specifies BUSY Flag. */
#define UART_WorkStatus_RXFE                  ((uint16_t)0x0010)    /*!<Specifies Receive FIFO Empty Flag. */
#define UART_WorkStatus_TXFF                  ((uint16_t)0x0020)    /*!<Specifies Transmit FIFO Full Flag. */
#define UART_WorkStatus_RXFF                  ((uint16_t)0x0040)    /*!<Specifies Receive FIFO Full Flag. */
#define UART_WorkStatus_TXFE                  ((uint16_t)0x0080)    /*!<Specifies Transmit FIFO Empty Flag. */

#define IS_UART_WorkStatus(WorkStatus)  (((WorkStatus) == UART_WorkStatus_CTS)  || ((WorkStatus) == UART_WorkStatus_BUSY)||\
																				((WorkStatus) == UART_WorkStatus_RXFE) || ((WorkStatus) == UART_WorkStatus_TXFE)||\
																				((WorkStatus) == UART_WorkStatus_RXFF) || ((WorkStatus) == UART_WorkStatus_TXFF))
															
/** @defgroup UART_Stop_Bits 
  * @{
  */ 
  
#define UART_StopBits_1                     ((uint16_t)0x0000)
#define UART_StopBits_2                     ((uint16_t)0x0008)

#define IS_UART_STOPBITS(STOPBITS)   (((STOPBITS) == UART_StopBits_1) || \
                                     ((STOPBITS) == UART_StopBits_2)) 
																		 
/** @defgroup UART_Parity 
  * @{
  */ 
  
#define UART_Parity_No                      ((uint16_t)0x0000)    /*!<no odd-even check. */
#define UART_Parity_Even                    ((uint16_t)0x0006)    /*!<Even check. */
#define UART_Parity_Odd                     ((uint16_t)0x0002)    /*!<Odd check. */ 
#define UART_Parity_1                       ((uint16_t)0x0082)    /*!<1 check. */
#define UART_Parity_0                       ((uint16_t)0x0086)    /*!<0 check. */

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_Parity_No) || \
                                 ((PARITY) == UART_Parity_Even) || \
																 ((PARITY) == UART_Parity_Odd) || \
																 ((PARITY) == UART_Parity_1) || \
                                 ((PARITY) == UART_Parity_0))
																 
/** @defgroup UART_Mode 
  * @{
  */ 
  
#define UART_Mode_RX                        ((uint16_t)0x0200)    /*!<UART Receive Enable. */     
#define UART_Mode_TX                        ((uint16_t)0x0100)    /*!<UART Transmit Enable. */   

#define IS_UART_MODE(MODE) ((((MODE) & (uint16_t)0xFCFF) == 0x00) && ((MODE) != (uint16_t)0x00))


/** @defgroup UART_Hardware_Flow_Control 
  * @{
  */ 
#define UART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define UART_HardwareFlowControl_RTS        ((uint16_t)0x4000)
#define UART_HardwareFlowControl_CTS        ((uint16_t)0x8000)
#define UART_HardwareFlowControl_RTS_CTS    ((uint16_t)0xC000)

#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HardwareFlowControl_None) || \
                               ((CONTROL) == UART_HardwareFlowControl_RTS) || \
                               ((CONTROL) == UART_HardwareFlowControl_CTS) || \
                               ((CONTROL) == UART_HardwareFlowControl_RTS_CTS))


/** @defgroup UART_RX_IT_FIFO_Select 
  * @{
  */
#define   UART_RXFIFO_Eighth 							((uint16_t)0x0000)   /*!<Amount of data in the receive FIFO that triggers the interrupt is Eighth. */	    			
#define   UART_RXFIFO_Quarter    					((uint16_t)0x0001)   /*!<Amount of data in the receive FIFO that triggers the interrupt is Quarter. */		  
#define   UART_RXFIFO_Half   							((uint16_t)0x0002)   /*!<Amount of data in the receive FIFO that triggers the interrupt is Half. */		   
#define   UART_RXFIFO_ThreeQuarters   		((uint16_t)0x0003)   /*!<Amount of data in the receive FIFO that triggers the interrupt is ThreeQuarters. */		
#define   UART_RXFIFO_SevenEighths   			((uint16_t)0x0004)   /*!<Amount of data in the receive FIFO that triggers the interrupt is SevenEighths. */		

#define IS_UART_RX_IT_FIFO_Select(Select)\
                               (((Select) == UART_RXFIFO_Eighth) || \
                               ((Select) == UART_RXFIFO_Quarter) || \
                               ((Select) == UART_RXFIFO_Half) || \
															 ((Select) == UART_RXFIFO_ThreeQuarters) || \
                               ((Select) == UART_RXFIFO_SevenEighths))


/** @defgroup UART_TX_IT_FIFO_Select 
  * @{
  */
#define   UART_TXFIFO_Eighth 							((uint16_t)0x0000)   /*!<Amount of data in the sending FIFO that triggers the interrupt is Eighth. */	   			
#define   UART_TXFIFO_Quarter    					((uint16_t)0x0001)   /*!<Amount of data in the sending FIFO that triggers the interrupt is Quarter. */	 	  
#define   UART_TXFIFO_Half   							((uint16_t)0x0002)   /*!<Amount of data in the sending FIFO that triggers the interrupt is Half. */	 	   
#define   UART_TXFIFO_ThreeQuarters   		((uint16_t)0x0003)   /*!<Amount of data in the sending FIFO that triggers the interrupt is ThreeQuarters. */	 	
#define   UART_TXFIFO_SevenEighths   			((uint16_t)0x0004)   /*!<Amount of data in the sending FIFO that triggers the interrupt is SevenEighths. */	 

#define IS_UART_TX_IT_FIFO_Select(Select)\
                               (((Select) == UART_TXFIFO_Eighth) || \
                               ((Select) == UART_TXFIFO_Quarter) || \
                               ((Select) == UART_TXFIFO_Half) || \
															 ((Select) == UART_TXFIFO_ThreeQuarters) || \
                               ((Select) == UART_TXFIFO_SevenEighths))
															 
															 
/** @defgroup UART_IT_Trigger_Source 
  * @{
  */
#define   UART_IT_OE   						((uint16_t)0x0400)   /*!<Overrun Error Interrupt. */		   			
#define   UART_IT_BE    					((uint16_t)0x0200)   /*!<Break Error Interrupt. */		 	  
#define   UART_IT_PE   						((uint16_t)0x0100)   /*!<Parity Error Interrupt. */		 	   
#define   UART_IT_FE   						((uint16_t)0x0080)   /*!<Framing Error Interrupt. */		 	
#define   UART_IT_RT   						((uint16_t)0x0040)   /*!<Receive Ttimeout Interrupt. */		 	
#define   UART_IT_Transmit   			((uint16_t)0x0020)   /*!<Transmit Interrupt Interrupt. */		 	
#define   UART_IT_Receive   			((uint16_t)0x0010)   /*!<Receive Interrupt Interrupt. */			 	
#define   UART_IT_nUARTCTS    		((uint16_t)0x0002)   /*!<nUARTCTS Modem Interrupt Interrupt. */		 	
#define   UART_IT_ALL							((uint16_t)0x07f2)   /*!<All Interrupt . */		 	

#define IS_UART_IT(IT)    ((((IT) & (uint16_t)0xF80D) == 0x00) && ((IT) != (uint16_t)0x00))

#define IS_UART_Get_IT(UART_IT)\
															 (((UART_IT) == UART_IT_ALL) || \
															 ((UART_IT) == UART_IT_OE) || \
                               ((UART_IT) == UART_IT_BE) || \
															 ((UART_IT) == UART_IT_PE) || \
															 ((UART_IT) == UART_IT_FE) || \
															 ((UART_IT) == UART_IT_RT) || \
															 ((UART_IT) == UART_IT_Transmit) || \
															 ((UART_IT) == UART_IT_Receive) || \
															 ((UART_IT) == UART_IT_nUARTCTS))


/** @defgroup UART_DMA_Requests 
  * @{
  */

#define UART_DMAReq_RX                      ((uint16_t)0x0001)   /*!<DMA request source is RX. */	
#define UART_DMAReq_TX                      ((uint16_t)0x0002)   /*!<DMA request source is TX. */

#define IS_UART_DMAREQ(DMAREQ) ((((DMAREQ) & (uint16_t)0xFFFC) == 0x00) && ((DMAREQ) != (uint16_t)0x00))



#define IS_UART_DATA(DATA) ((DATA) <= 0xFF)
#define IS_UART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x0044AA21))


/** 
  * @brief  UART Init Structure definition  
  */ 
  
typedef struct
{
  uint32_t UART_BaudRate;            /*!< This member configures the UART communication baud rate.
                                         The baud rate is computed using the following formula:
                                            - IntegerDivider = ((PCLK01) / (16 * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 64) + 0.5 */

  uint16_t UART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                         This parameter can be a value of @ref UART_Word_Length */

  uint16_t UART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                         This parameter can be a value of @ref UART_Stop_Bits */

  uint16_t UART_Parity;              /*!< Specifies the parity mode.
                                         This parameter can be a value of @ref UART_Parity */
 
  uint16_t UART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
                                         This parameter can be a value of @ref UART_Mode */

  uint16_t UART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
                                           or disabled.
                                         This parameter can be a value of @ref UART_Hardware_Flow_Control */
} UART_InitTypeDef;



void UART_Init(UART1_Type* UARTx, UART_InitTypeDef* UART_InitStruct); /* Initializes the UARTx peripheral */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);		
void UART_Cmd(UART1_Type* UARTx, FunctionalState NewState);
void UART_FIFO_Cmd(UART1_Type* UARTx, FunctionalState NewState);
void UART_FIFO_Config(UART1_Type* UARTx, uint16_t RXFIFO_Sel, uint16_t TXFIFO_Sel);
void UART_SendData(UART1_Type* UARTx, uint8_t Data);
uint8_t UART_ReceiveData(UART1_Type* UARTx);
void UART_SendBreak_Cmd(UART1_Type* UARTx, FunctionalState NewState);
void UART_LBCmd(UART1_Type* UARTx, FunctionalState NewState);
FlagStatus UART_GetErrFlag(UART1_Type* UARTx, uint16_t Error);
void UART_ClearErrorBit(UART1_Type* UARTx,uint16_t Error);
FlagStatus UART_GetWorkStatus(UART1_Type* UARTx, uint16_t WorkStatus);
FlagStatus UART_GetOriginalStatus(UART1_Type* UARTx, uint16_t ITSource);
void UART_EnableIRQ(UART1_Type* UARTx, uint16_t priority);
void UART_DisableIRQ(UART1_Type* UARTx);
void UART_ITCmd(UART1_Type* UARTx, uint16_t ITSource, FunctionalState NewState);
ITStatus UART_GetITStatus(UART1_Type* UARTx, uint16_t ITSource);
void UART_ClearITFlag(UART1_Type* UARTx, uint16_t ITSource);
void UART_DMACmd(UART1_Type* UARTx, uint16_t UART_DMAReq, FunctionalState NewState);
void UART_DMAOnErr_Cmd(UART1_Type* UARTx, FunctionalState NewState);


#endif


