/**
  ******************************************************************************
  * @file    sc32f53xx_dma.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the dma system firmware functions.
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
#ifndef __SC32F53xx_DMA_H
#define __SC32F53xx_DMA_H

#include "sc32f53xx_conf.h"

#pragma anon_unions

typedef struct {                               /*!< (@ 0x20000100) DMA_DATA_Type Structure                                  	*/
  __IO uint32_t   *SOURCE;                     /*!< (@ 0x00000000) Primary source_end_ptr                                     */
  __IO uint32_t   *DESTION;                    /*!< (@ 0x00000004) Primary destion_end_ptr                                    */
	union{
		__IO uint32_t CTL;                          /*!< (@ 0x00000000) DMA countrl Register                                     */   
    struct {
      __IO uint32_t CYCLE_CTRL   	   : 3;          
      __IO uint32_t NEXT_USEBURST    : 1;     
			__IO uint32_t N_MINUS_1			   : 10; 	
			__IO uint32_t R_POWER				   : 4; 
			__I  uint32_t									 : 7;
			__IO uint32_t	CIRC						 : 1;
			__IO uint32_t	DATA_SIZE				 : 2;
			__IO uint32_t	SRC_INC					 : 2;
			__IO uint32_t	DST_INC					 : 2;                                        
    } CTL_b;
  };                                    
	__I  uint32_t   RESERVED0;
		
//	__IO uint32_t   *ALT_SOURCE;                 /*!< (@ 0x00000010) Alternate source_end_ptr                                   */
//  __IO uint32_t   *ALT_DESTION;                /*!< (@ 0x00000014) Alternate destion_end_ptr                                  */
////	union {
////		__IO uint32_t ALT_CTL;                          /*!< (@ 0x00000000) DMA countrl Register                                     */   
//    struct {
//      __IO uint32_t CYCLE_CTRL   	   : 3;          
//      __IO uint32_t NEXT_USEBURST    : 1;     
//			__IO uint32_t N_MINUS_1			   : 10; 	
//			__IO uint32_t R_POWER				   : 4; 
//			__I  uint32_t									 : 7;
//			__IO uint32_t	CIRC						 : 1;
//			__IO uint32_t	DATA_SIZE				 : 2;
//			__IO uint32_t	SRC_INC					 : 2;
//			__IO uint32_t	DST_INC					 : 2;                                        
//    } ALT_CTL_b;
////  } ;                                      
//	__I  uint32_t   RESERVED1;	
} DMA_DATA_Type;

#define DMA_DATA_BASE0                (DMA_DATA_BASE0_Address)
#define DMA_DATA_BASE1                (DMA_DATA_BASE0+0x20)
#define DMA_DATA_BASE2                (DMA_DATA_BASE0+0x40)
#define DMA_DATA_BASE3               	(DMA_DATA_BASE0+0x60)
#define DMA_DATA_BASE4                (DMA_DATA_BASE0+0x80)
#define DMA_DATA_BASE5                (DMA_DATA_BASE0+0xA0)
#define DMA_DATA0                     ((DMA_DATA_Type*)                DMA_DATA_BASE0)
#define DMA_DATA1                     ((DMA_DATA_Type*)                DMA_DATA_BASE1)
#define DMA_DATA2                     ((DMA_DATA_Type*)                DMA_DATA_BASE2)
#define DMA_DATA3                     ((DMA_DATA_Type*)                DMA_DATA_BASE3)
#define DMA_DATA4                     ((DMA_DATA_Type*)                DMA_DATA_BASE4)
#define DMA_DATA5                     ((DMA_DATA_Type*)                DMA_DATA_BASE5)

#define DMA_ALT_DATA_BASE0                (DMA_DATA_BASE0+0x10)
#define DMA_ALT_DATA_BASE1                (DMA_DATA_BASE0+0x30)
#define DMA_ALT_DATA_BASE2                (DMA_DATA_BASE0+0x50)
#define DMA_ALT_DATA_BASE3                (DMA_DATA_BASE0+0x70)
#define DMA_ALT_DATA_BASE4                (DMA_DATA_BASE0+0x90)
#define DMA_ALT_DATA_BASE5                (DMA_DATA_BASE0+0xB0)
#define DMA_ALT_DATA0                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE0)
#define DMA_ALT_DATA1                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE1)
#define DMA_ALT_DATA2                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE2)
#define DMA_ALT_DATA3                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE3)
#define DMA_ALT_DATA4                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE4)
#define DMA_ALT_DATA5                     ((DMA_DATA_Type*)                DMA_ALT_DATA_BASE5)


/** @defgroup UART_Exported_Constants
  * @{
  */ 
  
#define IS_DMA_ALL_DATAx(DMA_DATAx) 	 (((DMA_DATAx) == DMA_DATA0) || ((DMA_DATAx) == DMA_DATA1)  || \
																			 ((DMA_DATAx) == DMA_DATA2) || ((DMA_DATAx) == DMA_DATA3)  || \
																			 ((DMA_DATAx) == DMA_DATA4) || ((DMA_DATAx) == DMA_DATA5)  || \
																			 ((DMA_DATAx) == DMA_ALT_DATA0) || ((DMA_DATAx) == DMA_ALT_DATA1)  || \
																			 ((DMA_DATAx) == DMA_ALT_DATA2) || ((DMA_DATAx) == DMA_ALT_DATA3)  || \
																			 ((DMA_DATAx) == DMA_ALT_DATA4) || ((DMA_DATAx) == DMA_ALT_DATA5))

#define IS_DMA_Main_DATAx(DMA_DATAx) 	 		(((DMA_DATAx) == DMA_DATA0) || ((DMA_DATAx) == DMA_DATA1)  || \
																			 ((DMA_DATAx) == DMA_DATA2) || ((DMA_DATAx) == DMA_DATA3)  || \
																			 ((DMA_DATAx) == DMA_DATA4) || ((DMA_DATAx) == DMA_DATA5))
																	 
/** @defgroup DMA_Mode_Select
  * @{
  */
#define  DMA_Mode_Stop      					(uint32_t)0x00000000     /*!<DMA work mode is stop. */     
#define  DMA_Mode_Basic     					(uint32_t)0x00000001     /*!<DMA work mode is basic. */ 
#define  DMA_Mode_AutoReq      				(uint32_t)0x00000002     /*!<DMA work mode is automatic request. */ 
#define  DMA_Mode_Pingpong      			(uint32_t)0x00000003     /*!<DMA work mode is pingpong. */ 
#define  DMA_Mode_MemoryMain      		(uint32_t)0x00000004     /*!<DMA work mode is memory dispersion and aggregation In the main data structure. */ 
#define  DMA_Mode_MemoryAlt      			(uint32_t)0x00000005     /*!<DMA work mode is memory dispersion and aggregation In the standby data structure. */ 
#define  DMA_Mode_PeripheralMain      (uint32_t)0x00000006     /*!<DMA work mode is Peripherals dispersion and aggregation In the main data structure. */
#define  DMA_Mode_peripheralAlt      	(uint32_t)0x00000007     /*!<DMA work mode is Peripherals dispersion and aggregation In the standby data structure. */ 

#define IS_DMA_Mode(Mode)    		(((Mode) == DMA_Mode_Stop) || ((Mode) == DMA_Mode_Basic) || \
																((Mode) == DMA_Mode_AutoReq) || ((Mode) == DMA_Mode_Pingpong) || \
																((Mode) == DMA_Mode_MemoryMain) || ((Mode) == DMA_Mode_MemoryAlt) || \
																((Mode) == DMA_Mode_PeripheralMain) || ((Mode) == DMA_Mode_peripheralAlt))																
		
		
/** @defgroup DMA_TransferNum_Select
  * @{
  */
#define  DMA_TransferNum_1      		(uint32_t)0x00000000     /*!<DMA transmit times is 1 before the arbitration. */
#define  DMA_TransferNum_2     			(uint32_t)0x00004000     /*!<DMA transmit times is 2 before the arbitration. */
#define  DMA_TransferNum_4      		(uint32_t)0x00008000     /*!<DMA transmit times is 4 before the arbitration. */
#define  DMA_TransferNum_8      		(uint32_t)0x0000C000     /*!<DMA transmit times is 8 before the arbitration. */
#define  DMA_TransferNum_16      		(uint32_t)0x00010000     /*!<DMA transmit times is 16 before the arbitration. */
#define  DMA_TransferNum_32      		(uint32_t)0x00014000     /*!<DMA transmit times is 32 before the arbitration. */
#define  DMA_TransferNum_64      		(uint32_t)0x00018000     /*!<DMA transmit times is 64 before the arbitration. */
#define  DMA_TransferNum_128      	(uint32_t)0x0001C000     /*!<DMA transmit times is 128 before the arbitration. */
#define  DMA_TransferNum_256      	(uint32_t)0x00020000     /*!<DMA transmit times is 256 before the arbitration. */
#define  DMA_TransferNum_512      	(uint32_t)0x00024000     /*!<DMA transmit times is 512 before the arbitration. */
#define  DMA_TransferNum_1024      	(uint32_t)0x00028000     /*!<DMA transmit times is 1024 before the arbitration. */

#define IS_DMA_TransferNum(TransferNum)    	(((TransferNum) == DMA_TransferNum_1) || ((TransferNum) == DMA_TransferNum_2) || \
																						((TransferNum) == DMA_TransferNum_4) || ((TransferNum) == DMA_TransferNum_8) || \
																						((TransferNum) == DMA_TransferNum_16) || ((TransferNum) == DMA_TransferNum_32) || \
																						((TransferNum) == DMA_TransferNum_64) || ((TransferNum) == DMA_TransferNum_128) || \
																						((TransferNum) == DMA_TransferNum_256) || ((TransferNum) == DMA_TransferNum_512) || \
																						((TransferNum) == DMA_TransferNum_1024))
																
/** @defgroup DMA_Mode_Select
 * @{
 */
#define  DMA_DataSize_Byte     				  (uint32_t)0x00000000     /*!<The width of the transmitted source data is byte. */
#define  DMA_DataSize_HalfWord     			(uint32_t)0x04000000     /*!<The width of the transmitted source data is half-word. */
#define  DMA_DataSize_Word      				(uint32_t)0x08000000     /*!<The width of the transmitted source data is word. */

#define IS_DMA_DataSize(DataSize)    		(((DataSize) == DMA_DataSize_Byte) || ((DataSize) == DMA_DataSize_HalfWord) || \
																				((DataSize) == DMA_DataSize_Word))													
																
/** @defgroup DMA_SourceAddInc_Select
 * @{
 */
#define  DMA_SourceAddInc_Byte     				  (uint32_t)0x00000000     /*!<Source address increment is byte. */
#define  DMA_SourceAddInc_HalfWord      		(uint32_t)0x10000000     /*!<Source address increment is half-word. */
#define  DMA_SourceAddInc_Word     				  (uint32_t)0x20000000     /*!<Source address increment is word. */
#define  DMA_SourceAddInc_Fixed     				(uint32_t)0x30000000     /*!<Source address increment is fixed. */

#define IS_DMA_SourceAddInc(SourceAddInc)    		(((SourceAddInc) == DMA_SourceAddInc_Byte) || ((SourceAddInc) == DMA_SourceAddInc_HalfWord) || \
																									((SourceAddInc) == DMA_SourceAddInc_Word) || ((SourceAddInc) == DMA_SourceAddInc_Fixed))	
																				
/** @defgroup DMA_TargetAddInc_Select
 * @{
 */
#define  DMA_TargetAddInc_Byte     				  (uint32_t)0x00000000     /*!<Target address increment is byte. */
#define  DMA_TargetAddInc_HalfWord      		(uint32_t)0x40000000     /*!<Target address increment is half-word. */
#define  DMA_TargetAddInc_Word     				  (uint32_t)0x80000000     /*!<Target address increment is word. */
#define  DMA_TargetAddInc_Fixed     				(uint32_t)0xC0000000     /*!<Target address increment is fixed. */

#define IS_DMA_TargetAddInc(TargetAddInc)    		(((TargetAddInc) == DMA_TargetAddInc_Byte) || ((TargetAddInc) == DMA_TargetAddInc_HalfWord) || \
																								((TargetAddInc) == DMA_TargetAddInc_Word) || ((TargetAddInc) == DMA_TargetAddInc_Fixed))
																								
/** @defgroup DMA_TotalNum_Select
 * @{
 */
#define IS_DMA_TotalNum(TotalNum)     		((TotalNum) <= 0x3ff)     /*!<DMA total transmitted value. */   


/** 
  * @brief  DMA CTL Init Structure definition  
  */ 
typedef struct {
	
		uint32_t DMA_Mode;              				  /*!< DMA cycle work mode.
	                                              This parameter can be a value of @ref DMA_Mode */
	
		uint32_t DMA_TransferNum;                /*!<Sets the number of DMA transfers that can occur before the controller rearbitrates.
	                                              This parameter can be a value of @ref DMA_TransferNum */
	
		uint32_t	DMA_TotalNum;									/*!< Total number of DMA transfers set.
	                                              This parameter can be a value of @ref DMA_TotalNum */
	
		uint32_t DMA_DataSize;                   /*!< The width of the transmitted source data.
	                                              This parameter can be a value of @ref DMA_DataSize */
	
		uint32_t	DMA_SourceAddInc;							/*!< Source address increment.
	                                              This parameter can be a value of @ref DMA_SourceAddInc */
				
		uint32_t 	DMA_TargetAddInc;            /*!< Target address incrementn.
	                                              This parameter can be a value of @ref DMA_TargetAddInc */
																																																		
}DMA_CTLInitTypeDef;

/** @defgroup DMA_Channel_Select
  * @{
  */
#define  DMA_Channel_0      ((uint32_t)0x00000001)    /*!<DMA channel 0. */ 
#define  DMA_Channel_1      ((uint32_t)0x00000002)     /*!<DMA channel 1. */  
#define  DMA_Channel_2      ((uint32_t)0x00000004)     /*!<DMA channel 2. */ 
#define  DMA_Channel_3      ((uint32_t)0x00000008)     /*!<DMA channel 3. */ 
#define  DMA_Channel_4      ((uint32_t)0x00000010)     /*!<DMA channel 4. */ 
#define  DMA_Channel_5      ((uint32_t)0x00000020)     /*!<DMA channel 5. */ 

#define IS_DMA_Channel(Channel)    ((((Channel) & (uint32_t)0xFFFFFFC0) == 0x00) && ((Channel) != (uint32_t)0x00))
											

/** @defgroup DMA_Channel_CTRLx_Select
  * @{
  */
#define  DMA_Channel_CTRL0      0x00     /*!<DMA channel CTRL0 which is corresponded to DMA channel 0. */ 
#define  DMA_Channel_CTRL1      0x01     /*!<DMA channel CTRL1 which is corresponded to DMA channel 1. */  
#define  DMA_Channel_CTRL2      0x02     /*!<DMA channel CTRL2 which is corresponded to DMA channel 2. */ 
#define  DMA_Channel_CTRL3      0x03     /*!<DMA channel CTRL3 which is corresponded to DMA channel 3. */ 
#define  DMA_Channel_CTRL4      0x04     /*!<DMA channel CTRL4 which is corresponded to DMA channel 4. */ 
#define  DMA_Channel_CTRL5      0x05     /*!<DMA channel CTRL5 which is corresponded to DMA channel 5. */ 

#define IS_DMA_CTRLx(CTRLx)   	(((CTRLx) == DMA_Channel_CTRL0) || ((CTRLx) == DMA_Channel_CTRL1) ||\
                                ((CTRLx) == DMA_Channel_CTRL2) || ((CTRLx) == DMA_Channel_CTRL3) ||\
																((CTRLx) == DMA_Channel_CTRL4) || ((CTRLx) == DMA_Channel_CTRL5))


/** @defgroup DMA_Request_Select
  * @{
  */
#define  DMA_UART1_TX      0x00     /*!<Hardware trigger source selection is UART1 TX. */
#define  DMA_UART1_RX      0x01     /*!<Hardware trigger source selection is UART1 RX. */
#define  DMA_UART2_TX      0x02     /*!<Hardware trigger source selection is UART2 TX. */
#define  DMA_UART2_RX      0x03     /*!<Hardware trigger source selection is UART2 RX. */
#define  DMA_UART3_TX      0x04     /*!<Hardware trigger source selection is UART3 TX. */
#define  DMA_UART3_RX      0x05     /*!<Hardware trigger source selection is UART3 RX. */
#define  DMA_SSP_TX        0x08     /*!<Hardware trigger source selection is SSP TX. */
#define  DMA_SSP_RX        0x09     /*!<Hardware trigger source selection is SSP RX. */
#define  DMA_ADC_SEQA      0x0a     /*!<Hardware trigger source selection is ADC SEQA. */
#define  DMA_ADC_SEQB      0x0b     /*!<Hardware trigger source selection is ADC SEQB. */
#define  DMA_ERU0      		 0x0c     /*!<Hardware trigger source selection is ERU0. */
#define  DMA_ERU1      		 0x0d     /*!<Hardware trigger source selection is ERU1. */
#define  DMA_ERU2      		 0x0e     /*!<Hardware trigger source selection is ERU2. */
#define  DMA_ERU3      		 0x0f     /*!<Hardware trigger source selection is ERU3. */
#define  DMA_UART4_TX      0x10     /*!<Hardware trigger source selection is UART4 TX. */
#define  DMA_UART4_RX      0x11     /*!<Hardware trigger source selection is UART4 RX. */
#define  DMA_UART5_TX      0x12     /*!<Hardware trigger source selection is UART5 TX. */
#define  DMA_UART5_RX      0x13     /*!<Hardware trigger source selection is UART5 RX. */
#define  DMA_UART6_TX      0x14     /*!<Hardware trigger source selection is UART6 TX. */
#define  DMA_UART6_RX      0x15     /*!<Hardware trigger source selection is UART6 RX. */

#define IS_DMA_Request(Request)    (((Request) == DMA_UART1_TX) || ((Request) == DMA_UART1_RX) ||\
                                   ((Request) == DMA_UART2_TX) || ((Request) == DMA_UART2_RX) ||\
																	 ((Request) == DMA_UART3_TX) || ((Request) == DMA_UART3_RX) ||\
																	 ((Request) == DMA_SSP_TX) || ((Request) == DMA_SSP_RX) ||\
																	 ((Request) == DMA_ADC_SEQA) || ((Request) == DMA_ADC_SEQB) ||\
																	 ((Request) == DMA_ERU0) || ((Request) == DMA_ERU1) ||\
																	 ((Request) == DMA_ERU2) || ((Request) == DMA_ERU3) ||\
																	 ((Request) == DMA_UART4_TX) || ((Request) == DMA_UART4_RX) ||\
																	 ((Request) == DMA_UART5_TX) || ((Request) == DMA_UART5_RX) ||\
																	 ((Request) == DMA_UART6_TX) || ((Request) == DMA_UART6_RX))
																	 
/** @defgroup DMA_IT_Source_Select
  * @{
  */
#define DMA_IT_DONE                         ((uint32_t)0x10000000)     /*!<DMA transmission completion interrupt. */
#define DMA_IT_CFGERR                       ((uint32_t)0x02000000)     /*!<DMA misconfigured  interrupt. */
#define DMA_IT_BUSERR                       ((uint32_t)0x01000000)     /*!<DMA bus error interrupt. */

#define IS_DMA_IT(IT)    ((((IT) & (uint32_t)0xECFFFFFF) == 0x00) && ((IT) != (uint32_t)0x00))


/** @defgroup DMA_REQ0__Config
  * @{
  */
#define DMA_REQ0_ENABLE               0x00     /*!<DMA Channel request 0 enable. */
#define DMA_REQ0_DISABLE	            0x01     /*!<DMA Channel request 0 disable. */

#define IS_DMA_REQ0(REQ0)    (((REQ0) == DMA_REQ0_ENABLE) || ((REQ0) == DMA_REQ0_DISABLE))


/** @defgroup DMA_REQ1__Config
  * @{
  */
#define DMA_REQ1_ENABLE               0x00     /*!<DMA Channel request 1 enable. */
#define DMA_REQ1_DISABLE	            0x01     /*!<DMA Channel request 1 disable. */

#define IS_DMA_REQ1(REQ1)    (((REQ1) == DMA_REQ0_ENABLE) || ((REQ1) == DMA_REQ1_DISABLE))


/** @defgroup DMA_Channelx_Priority_Config
  * @{
  */
#define DMA_CHxPriority_Default             ((uint32_t)0x00000000)     /*!<DMA Channel priority defaults. */
#define DMA_CHxPriority_High                ((uint32_t)0x00000020)     /*!<DMA Channel priority high. */

#define IS_DMA_CHxPriority(CHxPriority)    (((CHxPriority) == DMA_CHxPriority_Default) || ((CHxPriority) == DMA_CHxPriority_High))


/** @defgroup DMA_Channelx_Burst_Config
  * @{
  */
#define DMA_REQ_SREQ_All            ((uint32_t)0x00000000)     /*!<DMA respond REQ and SREQ. */
#define DMA_REQ_Only                ((uint32_t)0x00000010)     /*!<DMA Only respond REQ. */	

#define IS_DMA_Burst(Burst)    (((Burst) == DMA_REQ_SREQ_All) || ((Burst) == DMA_REQ_Only))

/** @defgroup DMA_Channelx_Priority_Config
  * @{
  */
#define DMA_BasePoint_Main           ((uint32_t)0x00000000)     /*!<Channel control selects the primary base address pointer . */
#define DMA_BasePoint_Standby        ((uint32_t)0x00000004)     /*!<Channel control selects the alternate base address pointer . */	

#define IS_DMA_BasePoint(BasePoint)    (((BasePoint) == DMA_BasePoint_Main) || ((BasePoint) == DMA_BasePoint_Standby))

 
#define IS_DMA_PTR(PTR)     		((PTR) <= 0x00ffffff)     /*!<DMA Channel control base address pointer value . */


/** 
  * @brief  DMA Init Structure definition  
  */ 
typedef struct {
	
		uint8_t DMA_REQ0;              						/*!< Specifies DMA Channel request 0 selection.
	                                              This parameter can be a value of @ref DMA_REQx */
	
		uint8_t DMA_REQ1;              						/*!< Specifies DMA Channel request 1 selection.
	                                              This parameter can be a value of @ref DMA_REQx */
	
		uint8_t DMA_Request1;                    /*!< Specifies DMA request source selection.
	                                              This parameter can be a value of @ref DMA_Request */
	
		uint8_t DMA_Request0;                    /*!< Specifies DMA request source selection.
	                                              This parameter can be a value of @ref DMA_Request */
	
		uint8_t DMA_Channel_CTRLx;                    /*!< Specifies DMA channel CTRLx selection.
	                                              This parameter can be a value of @ref DMA_Channel_CTRLx */
	
		uint32_t	DMA_CHxPriority;							/*!< Specifies DMA channel priority setting.
	                                              This parameter can be a value of @ref DMA_CHxPriority */
				
		uint32_t 	DMA_Burst;                    /*!< Specifies DMA Channels use burst transfer Settings.
	                                              This parameter can be a value of @ref DMA_Burst */
	
		uint32_t	DMA_BasePoint;							/*!< Specifies DMA Base address pointer selection.
	                                              This parameter can be a value of @ref DMA_CHxPriority */
																																																			
}DMA_InitTypeDef;


void DMA_CTLInit(DMA_DATA_Type* DMA_CHx,DMA_CTLInitTypeDef* DMA_CTLInitStruct);
void DMA_CTLStructInit(DMA_CTLInitTypeDef* DMA_CTLInitStruct);
void DMA_Init(DMA_InitTypeDef* DMA_InitStruct);
void DMA_InitStructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_LoopTransfer_Cmd(DMA_DATA_Type* DMA_DATAx,FunctionalState NewState);
void DMA_32BitsSourcePTR_Write(DMA_DATA_Type* DMA_CHx, uint32_t *DataPTR);
void DMA_32BitsTargetPTR_Write(DMA_DATA_Type* DMA_CHx, uint32_t *DataPTR);
void DMA_BasePTR_Write(void);
void DMA_Cmd(FunctionalState NewState);
void DMA_Channel_Cmd(uint16_t DMA_CHx,FunctionalState NewState);
void DMA_REQ0_Cmd(uint16_t DMA_CHx,FunctionalState NewState);
void DMA_REQ1_Cmd(uint16_t DMA_CHx,FunctionalState NewState);
void DMA_ResetCmd(void);
void DMA_SoftWare_REQCmd(uint16_t DMA_Channelx);
ITStatus DMA_GetReqStatus(uint16_t DMA_Channelx);
ITStatus DMA_GetActiveStatus(uint16_t DMA_Channelx);
ITStatus DMA_GetDoneStatus(uint16_t DMA_Channelx);
void DMA_ClearDoneStatus(uint16_t DMA_Channelx);
ITStatus DMA_GetCFGErrStatus(uint16_t DMA_Channelx);
void DMA_ClearCFGErrStatus(uint16_t DMA_Channelx);
ITStatus DMA_GetBUSErrStatus(uint16_t DMA_Channelx);
void DMA_ClearBUSErrStatus(uint16_t DMA_Channelx);
void DMA_ITConfig(uint16_t DMA_Channelx, uint32_t DMA_IT, FunctionalState NewState);
void DMA_EnableIRQ(uint16_t priority);
void DMA_DisableIRQ(void);
void DMA_ClearITStatus(uint16_t DMA_Channelx,uint32_t DMA_IT);

#endif



