/**
  ******************************************************************************
  * @file    sc32f53xx_crc.h
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    15-01-2020
  * @brief   This file provides all the CRC firmware functions.
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
  * <h2><center>&copy; COPYRIGHT 2020 Silan Microelectronics </center></h2>
  ********************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC32F53xx_CRC_H
#define __SC32F53xx_CRC_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


/** 
  * @brief  CRC_GPS selection  
**/	
typedef enum
{
		GPS_CRC8_0x07 = 0x00,					/*!< CRC GPS selection is CRC8_0x07.  */  
		GPS_CRC16_0x8005 = 0x01,			/*!< CRC GPS selection is CRC16_0x8005.  */  
		GPS_CRC16_0x1021 = 0x02,			/*!< CRC GPS selection is CRC16_0x1021.  */  
		GPS_CRC32_0x04C11DB7 = 0x03,	/*!< CRC GPS selection is CRC32_0x04C11DB7.  */   
}GPSCRCx_TypeDef;

#define IS_GPS_CRCx(CRCx)  	(((CRCx) == GPS_CRC8_0x07) || ((CRCx) == GPS_CRC16_0x8005) || \
														((CRCx) == GPS_CRC16_0x1021) || ((CRCx) == GPS_CRC32_0x04C11DB7))

/** 
  * @brief  CRC_LM selection  
  */	
typedef enum
{
	CRC_LM_Lsb  = 0x00,      /*!<CRC_LM selection is Low bit first.  */  
  CRC_LM_Hsb  = 0x01,      /*!<CRC_LM selection is High bit first.  */                
}CRCLM_TypeDef;

#define IS_CRC_LM(LM)  (((LM) == CRC_LM_Lsb) || ((LM) == CRC_LM_Hsb))

/** 
  * @brief  CRC effrctive number of bytes selection  
  */
typedef enum
{
	CRC_BytesNum_1  = 0x00,       /*!<CRC effrctive number of bytes selection is 1. */  
  CRC_BytesNum_2  = 0x01,       /*!<CRC effrctive number of bytes selection is 2. */ 
	CRC_BytesNum_3  = 0x02,       /*!<CRC effrctive number of bytes selection is 3. */ 
	CRC_BytesNum_4  = 0x03,       /*!<CRC effrctive number of bytes selection is 4. */ 
}CRCBytesNum_TypeDef;

#define IS_CRC_BytesNum(BytesNum)   (((BytesNum) == CRC_BytesNum_1) || ((BytesNum) == CRC_BytesNum_2) || \
																		((BytesNum) == CRC_BytesNum_3) || ((BytesNum) == CRC_BytesNum_4))

/** 
  * @brief  CRC Reset Status selection  
  */
typedef enum
{
	CRC_ResetStatus_No  = 0x00,       /*!<CRC Reset Status is not set. */  
  CRC_ResetStatus_Yes  = 0x01,       /*!<CRC Reset Status is set. */ 
}CRCResetStatus_TypeDef;

#define IS_CRC_ResetStatus(ResetStatus)   (((ResetStatus) == CRC_ResetStatus_No) || ((ResetStatus) == CRC_ResetStatus_Yes))


/** 
  * @brief CRC Reset Sign selection  
  */
#define  CRC_ResetSign_Logic    (uint32_t)0x00000001         /*!< CRC Reset logic Sign.  */  
#define  CRC_ResetSign_Result   (uint32_t)0x00000002         /*!< CRC Reset result Sign.  */         

#define IS_CRC_ResetSign(ResetSign)  ((((ResetSign) & (uint32_t)0xFFFFFFFC) == 0x00) && ((ResetSign) != (uint32_t)0x00))


/** 
  * @brief  CRC Config Structure definition  
  */ 
typedef struct {
	
  GPSCRCx_TypeDef CRC_GPSCRCx;          /*!<Specifies the CRC GPS selection. */
	
  CRCLM_TypeDef  CRC_LM;         			  /*!< Specifies the CRC_LM selection. */
	
	CRCBytesNum_TypeDef CRC_BytesNum;     /*!< Specifies the CRC effrctive number of bytes selection. */

}CRC_ConfigTypeDef;


void CRC_Config(CRC_ConfigTypeDef* CRC_ConfigStruct);
void CRC_ConfigStructInit(CRC_ConfigTypeDef* CRC_ConfigStruct);
void CRC_ResetCmd(uint32_t CRC_ResetSign, CRCResetStatus_TypeDef CRC_ResetStatus);
void CRC_WirteData(uint32_t CRC_Data);
uint32_t CRC_ReadResult(void);

#endif

