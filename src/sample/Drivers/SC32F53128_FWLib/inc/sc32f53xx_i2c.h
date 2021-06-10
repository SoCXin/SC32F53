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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC32F53xx_I2C_H
#define __SC32F53xx_I2C_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"



/************ CR3ÊÇ·ñ¿ÉÐ´£¿£¿£¿******/
#define I2C_PCLK_Div256              ((uint32_t)0x00000000)    /*!<I2C clock frequency division value is 256. */	   
#define I2C_PCLK_Div224              ((uint32_t)0x00000001)    /*!<I2C clock frequency division value is 224. */	
#define I2C_PCLK_Div192              ((uint32_t)0x00000002)    /*!<I2C clock frequency division value is 192. */	
#define I2C_PCLK_Div160              ((uint32_t)0x00000003)    /*!<I2C clock frequency division value is 160. */	
#define I2C_PCLK_Div960              ((uint32_t)0x00000080)    /*!<I2C clock frequency division value is 960. */	
#define I2C_PCLK_Div120              ((uint32_t)0x00000081)    /*!<I2C clock frequency division value is 120. */	
#define I2C_PCLK_Div60               ((uint32_t)0x00000082)    /*!<I2C clock frequency division value is 60. */	
#define I2C_PCLK_Div32               ((uint32_t)0x00000083)    /*!<I2C clock frequency division value is 32. */	
#define I2C_PCLK_Div512              ((uint32_t)0x00000200)    /*!<I2C clock frequency division value is 512. */	  
#define I2C_PCLK_Div2048             ((uint32_t)0x00000201)    /*!<I2C clock frequency division value is 2048. */	
#define I2C_PCLK_Div4096             ((uint32_t)0x00000202)    /*!<I2C clock frequency division value is 4096. */	

#define IS_I2C_PCLK(PCLK)    (((PCLK) == (I2C_PCLK_Div256)) || ((PCLK) == (I2C_PCLK_Div224))|| \
														 ((PCLK) == (I2C_PCLK_Div192)) || ((PCLK) == (I2C_PCLK_Div160))|| \
														 ((PCLK) == (I2C_PCLK_Div960)) || ((PCLK) == (I2C_PCLK_Div120))|| \
														 ((PCLK) == (I2C_PCLK_Div60)) || ((PCLK) == (I2C_PCLK_Div32))||	\
														 ((PCLK) == (I2C_PCLK_Div512)) || ((PCLK) == (I2C_PCLK_Div2048))|| \
														 ((PCLK) == (I2C_PCLK_Div4096)))



void I2C_SysclkConfig(uint32_t CLKDiv);
void I2C_Cmd(FlagStatus NewState);
void I2C_STO_Cmd(FlagStatus NewState);
void I2C_STA_Cmd(FlagStatus NewState);
void I2C_AA_Cmd(FlagStatus NewState);
void I2C_Clear_SI(void);
uint8_t I2C_Read_SRState(void);
uint8_t I2C_Read_SIState(void);
uint8_t I2C_Read_STOState(void);
uint8_t I2C_Read_DATA(void);
void I2C_Write_DATA(uint8_t WriteData);


#endif
