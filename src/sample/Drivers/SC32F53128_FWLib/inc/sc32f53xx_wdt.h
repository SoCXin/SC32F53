/**
  ******************************************************************************
  * @file    sc32f53xx_wdt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    25-05-2019
  * @brief   This file provides all the WDT firmware functions.
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
#ifndef __SC32F53xx_WDT_H
#define __SC32F53xx_WDT_H


/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


#define IS_WDT_RELOAD(RELOAD) (1 <= (RELOAD) <= 0xFFFFFFFF)


void WDT_SetReload(uint32_t Reload_Value);
uint32_t WDT_ReadCountVal(void);
void WDT_RESENCmd(FunctionalState NewState);
void WDT_EnableIRQ(uint16_t priority);
void WDT_DisableIRQ(void);
void WDT_INTENCmd(FunctionalState NewState);
FlagStatus WDT_GetOriginalFlag(void);
FlagStatus WDT_GetITFlag(void);
void WDT_ClearITFlag(void);


#endif

