/**
  ******************************************************************************
  * @file    sc32f53xx_crc.c
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

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_crc.h"


/**
  * @brief  Configs the CRC peripheral according to the specified parameters
  *         in the CRC_ConfigStruct.
  * @param  CRC_ConfigStruct: pointer to an CRC_ConfigTypeDef structure that contains
  *         the configuration information for the specified CRC peripheral.
  * @retval None
  */
void CRC_Config(CRC_ConfigTypeDef* CRC_ConfigStruct)
{	
	/* Check the parameters */
  assert_param(IS_GPS_CRCx(CRC_ConfigStruct->CRC_GPSCRCx));
  assert_param(IS_CRC_LM(CRC_ConfigStruct->CRC_LM));
	assert_param(IS_CRC_BytesNum(CRC_ConfigStruct->CRC_BytesNum));
	
	/* Set the CRC configuration */
	CRC->CRC_CTRL_b.CRC_GPS = CRC_ConfigStruct->CRC_GPSCRCx;
	CRC->CRC_CTRL_b.CRC_LM = CRC_ConfigStruct->CRC_LM;
	CRC->CRC_CTRL_b.CRC_BYTE = CRC_ConfigStruct->CRC_BytesNum;
}

/**
  * @brief  Fills CRC_ConfigStruct member with its default value.
  * @param  CRC_ConfigStruct : pointer to an CRC_ConfigTypeDef structure which will be initialized.
  * @retval None
  */
void CRC_ConfigStructInit(CRC_ConfigTypeDef* CRC_ConfigStruct)
{
  /* Reset CRC Config structure parameters values */
  /* initialize the CRC_BytesNum member */
  CRC_ConfigStruct->CRC_BytesNum = CRC_BytesNum_1;
	/* initialize the CRC_GPSCRCx member */
	CRC_ConfigStruct->CRC_GPSCRCx = GPS_CRC8_0x07;
  /* Initialize the CRC_LM member */
  CRC_ConfigStruct->CRC_LM = CRC_LM_Lsb;

}

/**
  * @brief Congfig the CRC reset Sign.
  * @param  CRC_ResetSign: specifies the sign of the CRC.
  *   This parameter can be one of the following values:
  *     @arg CRC_ResetSign_Logic: Reset logic sign
  *     @arg CRC_ResetSign_Result: Reset reslut sign
  * @param  CRC_ResetStatus: new state of the CRC reset sign.
  *   This parameter can be one of the following values:
  *     @arg CRC_ResetStatus_No: Reset sign not set 
  *     @arg CRC_ResetStatus_Yes: Reset sign set 
  * @retval None
  */
void CRC_ResetCmd(uint32_t CRC_ResetSign, CRCResetStatus_TypeDef CRC_ResetStatus)
{
  /* Check the parameters */
  assert_param(IS_CRC_ResetSign(CRC_ResetSign));
	assert_param(IS_CRC_ResetStatus(CRC_ResetStatus));
  
	if(CRC_ResetStatus==CRC_ResetStatus_Yes)
	{
			CRC->CRC_CTRL |= CRC_ResetSign;
	}
	else if(CRC_ResetStatus==CRC_ResetStatus_No)
	{
			CRC->CRC_CTRL &= ~CRC_ResetSign;
	}
}


/**
  * @brief Write the CRC data.
  * @param  CRC_Data: specifies the data to CRC check.
  * @retval None
  */
void CRC_WirteData(uint32_t CRC_Data)
{
		CRC->CRC_DATA = CRC_Data;
}


/**
  * @brief  Read the CRC check result which initial value is CRC_DATA register data.
  * @param  none
  * @retval The CRC check result.
  */
uint32_t CRC_ReadResult(void)
{
		uint32_t tmpreg;
		uint32_t temp;
	
		temp = (uint32_t)(CRC->CRC_CTRL_b.CRC_GPS);
		switch(temp)
		{
				case 0:
						tmpreg = (uint32_t)(CRC->CRC_RESULT & 0xFF);
						break;
				case 1:
						tmpreg = (uint32_t)(CRC->CRC_RESULT & 0xFFFF);
						break;
				case 2:
						tmpreg = (uint32_t)(CRC->CRC_RESULT & 0xFFFFFF);
						break;
				case 3:
						tmpreg = (uint32_t)(CRC->CRC_RESULT & 0xFFFFFFFF);
						break;					
		}
		return(tmpreg);
}

