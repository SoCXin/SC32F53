/**
  ******************************************************************************
  * @file    sc32f53xx_i2c.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the i2c functions.
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
#include "sc32f53xx_i2c.h"


#define  I2C_CLVER_CLKDIV    (uint32_t)0x00000283   /*!< I2C CLK Div Mask  */ 


/**
  * @brief  Set the I2C crossover value.
  * @param  CLKDiv: Frequency value.
	*   This parameter can be any combination of the following values:
  *     @arg I2C_PCLK_Div256:  1/256 PCLK
  *     @arg I2C_PCLK_Div224:  1/224 PCLK
	*     @arg I2C_PCLK_Div192:  1/192 PCLK
  *     @arg I2C_PCLK_Div160:  1/160 PCLK
	*     @arg I2C_PCLK_Div960:  1/960 PCLK
  *     @arg I2C_PCLK_Div120:  1/120 PCLK
	*     @arg I2C_PCLK_Div60:   1/60 PCLK
  *     @arg I2C_PCLK_Div32:   1/32 PCLK
	*     @arg I2C_PCLK_Div512:  1/512 PCLK
  *     @arg I2C_PCLK_Div2048: 1/2048 PCLK
	*     @arg I2C_PCLK_Div4096: 1/4096 PCLK
  * @retval None
  */
void I2C_SysclkConfig(uint32_t CLKDiv)
{
		assert_param(IS_I2C_PCLK(CLKDiv));
		
		I2C->CCLR |= I2C_CLVER_CLKDIV;
		I2C->CSET |= CLKDiv;
}

/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  NewState: new state of the I2C peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I2C_Cmd(FlagStatus NewState)
{
		assert_param(IS_FLAG_STATUS(NewState));
		if (NewState != RESET)
		{
				/* Enable I2C */
				I2C->CSET_b.EN = SET; //Ð´1ÖÃÎ»
		}
		else
		{
				/* Disable I2C */
				I2C->CCLR_b.EN = SET; //Ð´1ÇåÁã
		}
}

/**
  * @brief  Enables or disables the specified I2C STO bit.
  * @param  NewState: new state of the I2C STO bit. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I2C_STO_Cmd(FlagStatus NewState)
{
		assert_param(IS_FLAG_STATUS(NewState));
		if (NewState != RESET)
		{
				/* Enable I2C */
				I2C->CSET_b.STO = SET; //Ð´1ÖÃÎ»
		}
		else
		{
				/* Disable I2C */
				I2C->CCLR_b.STO = SET; //Ð´1ÇåÁã
		}
}

/**
  * @brief  Enables or disables the specified I2C STA bit.
  * @param  NewState: new state of the I2C STA bit. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I2C_STA_Cmd(FlagStatus NewState)
{
		assert_param(IS_FLAG_STATUS(NewState));
		if (NewState != RESET)
		{
				/* Enable I2C */
				I2C->CSET_b.STA = SET; //Ð´1ÖÃÎ»
		}
		else
		{
				/* Disable I2C */
				I2C->CCLR_b.STA = SET; //Ð´1ÇåÁã
		}
}

/**
  * @brief  Enables or disables the specified I2C AA bit.
  * @param  NewState: new state of the I2C AA bit. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I2C_AA_Cmd(FlagStatus NewState)
{
		assert_param(IS_FLAG_STATUS(NewState));
		if (NewState != RESET)
		{
				/* Enable I2C */
				I2C->CSET_b.AA = SET; //Ð´1ÖÃÎ»
		}
		else
		{
				/* Disable I2C */
				I2C->CCLR_b.AA = SET; //Ð´1ÇåÁã
		}
}

/**
  * @brief  Clear I2C SI bit.
  * @param  None
  * @retval None
  */
void I2C_Clear_SI(void)
{
		I2C->CCLR_b.SI = 1;
}

/**
  * @brief  Read the current working status of I2C.
  * @param  None
  * @retval None
  */
uint8_t I2C_Read_SRState(void)
{
		uint8_t SRState_Value;
		SRState_Value = (uint8_t)I2C->SR;
		return SRState_Value;
}

/**
  * @brief  Read I2C SI bit status.
  * @param  None
  * @retval None
  */
uint8_t I2C_Read_SIState(void)
{
		uint8_t SIState_Value;
		SIState_Value = (uint8_t)I2C->CSR_b.SI;
		return SIState_Value;
}

/**
  * @brief  Read I2C STO bit status.
  * @param  None
  * @retval None
  */
uint8_t I2C_Read_STOState(void)
{
		uint8_t STOState_Value;
		STOState_Value = (uint8_t)I2C->CSR_b.STO;
		return STOState_Value;
}

/**
  * @brief  Read I2C Receive Value.
  * @param  None
  * @retval None
  */
uint8_t I2C_Read_DATA(void)
{
		uint8_t Data_Value;
		Data_Value = (uint8_t)I2C->DATA;
		return Data_Value;
}

/**
  * @brief  Write I2C Send Value.
  * @param  None
  * @retval None
  */
void I2C_Write_DATA(uint8_t WriteData)
{
		I2C->DATA = WriteData;
}
