/**
  ******************************************************************************
  * @file    sc32f53xx_iwdt.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    27-05-2019
  * @brief   This file provides all the IWDT firmware functions.
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
#ifndef __SC32F53xx_IWDT_H
#define __SC32F53xx_IWDT_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


/** @defgroup IWDT_prescaler 
  * @{
  */

#define IWDT_Prescaler_1            ((uint8_t)0x00)    /*!< Clock predivider value is 1 */
#define IWDT_Prescaler_2            ((uint8_t)0x01)    /*!< Clock predivider value is 2 */
#define IWDT_Prescaler_4            ((uint8_t)0x02)    /*!< Clock predivider value is 4 */
#define IWDT_Prescaler_8            ((uint8_t)0x03)    /*!< Clock predivider value is 8 */
#define IWDT_Prescaler_16           ((uint8_t)0x04)    /*!< Clock predivider value is 16 */
#define IWDT_Prescaler_32           ((uint8_t)0x05)    /*!< Clock predivider value is 32 */
#define IWDT_Prescaler_64           ((uint8_t)0x06)    /*!< Clock predivider value is 64 */
#define IWDT_Prescaler_128          ((uint8_t)0x07)    /*!< Clock predivider value is 128 */
#define IWDT_Prescaler_256          ((uint8_t)0x08)    /*!< Clock predivider value is 256 */
#define IS_IWDT_PRESCALER(PRESCALER) (((PRESCALER) == IWDT_Prescaler_1)  || \
                                      ((PRESCALER) == IWDT_Prescaler_2)  || \
                                      ((PRESCALER) == IWDT_Prescaler_4) || \
                                      ((PRESCALER) == IWDT_Prescaler_8) || \
                                      ((PRESCALER) == IWDT_Prescaler_16) || \
                                      ((PRESCALER) == IWDT_Prescaler_32)|| \
																			((PRESCALER) == IWDT_Prescaler_64)|| \
																			((PRESCALER) == IWDT_Prescaler_128)|| \
                                      ((PRESCALER) == IWDT_Prescaler_256))
																			

typedef enum
{
  Win_RLD   = 0x00,    /*!< Window value selection is Win_RLD */
  Win_RLD_2 = 0x01,    /*!< Window value selection is Win_RLD_2 */  
}WinSel_Typedef;

#define IS_IWDT_RELOAD(RELOAD) ((RELOAD) <= 0xFFFF)


void IWDT_Enable(void);
void IWDT_SetPrescaler(uint8_t IWDT_Prescaler);
void IWDT_SetReload(uint16_t Reload);
void IWDT_SetWin(WinSel_Typedef Win_Value);
void IWDT_WINENCmd(FunctionalState NewState);
FlagStatus IWDT_GetFlagStatus(uint16_t IWDT_FLAG);
void IWDT_ClearFlag(void);
uint16_t IWDT_ReadCnt(void);
void IWDT_EnableIRQ(uint16_t priority);
void IWDT_DisableIRQ(void);

#endif

