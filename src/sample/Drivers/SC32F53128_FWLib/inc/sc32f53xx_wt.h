/**
  ******************************************************************************
  * @file    sc32f53xx_wt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    23-05-2019
  * @brief   This file provides all the WT firmware functions.
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
#ifndef __SC32F53xx_WT_H
#define __SC32F53xx_WT_H

#include "sc32f53xx_conf.h"


/**
  * @brief  Buzzer frequency selection
  */
typedef enum
{
  BUZ_8192HZ = 0x00,                 /*!< Buzzer frequency select 8192HZ */
	BUZ_4096HZ = 0x01,                 /*!< Buzzer frequency select 4096HZ */
  BUZ_2048HZ = 0x02,                 /*!< Buzzer frequency select 2048HZ */
  BUZ_1024HZ = 0x03,                 /*!< Buzzer frequency select 1024HZ */
}BUZSEL_Typedef;

#define IS_WT_BUZSEL(FREQUENCY) (((FREQUENCY) == BUZ_8192HZ) || \
                                      ((FREQUENCY) == BUZ_4096HZ) || \
																			((FREQUENCY) == BUZ_2048HZ) || \
                                      ((FREQUENCY) == BUZ_1024HZ))		


/**
  * @brief  Scintillation frequency selection
  */
typedef enum
{
  BK_2HZ   = 0x00,                   /*!< Scintillation frequency select 2HZ */
	BK_1HZ   = 0x01,                   /*!< Scintillation frequency select 1HZ */
  BK_0_5HZ = 0x02,                   /*!< Scintillation frequency select 1/2HZ */
  BK_0_25HZ = 0x03,                   /*!< Scintillation frequency select 1/4HZ */
}BKSEL_Typedef;

#define IS_WT_BKSEL(FREQUENCY)  (((FREQUENCY) == BK_2HZ) || \
                                      ((FREQUENCY) == BK_1HZ) || \
																			((FREQUENCY) == BK_0_5HZ) || \
                                      ((FREQUENCY) == BK_0_25HZ))	


#define IS_WT_ALERM(ALERM) ((ALERM) <= 0xFF)


void WT_Cmd(FunctionalState NewState);
void WT_IRQCmd(FunctionalState NewState, uint16_t priority);
void WT_BUZSEL(BUZSEL_Typedef BUZ_Frequency);
void WT_BKSEL(BKSEL_Typedef BK_Frequency);
void WT_SetAlerm(uint8_t Alerm_value);
FlagStatus WT_GetFlagStatus(void);
void WT_ClearFlag(void);
uint32_t  WT_ReadCnt(void);

#endif


