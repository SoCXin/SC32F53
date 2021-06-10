/**
  ******************************************************************************
  * @file    GPIO/IOToggle/sc32f53xx_conf.h 
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    20-05-2019
  * @brief   Library configuration file.
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
#ifndef __SC32F53xx_CONF_H
#define __SC32F53xx_CONF_H

#define DMA_DATA_BASE0_Address   0x20003E00UL

#define CHIPCTL_WRITE_KEY    (CHIPCTL->CHIP_KEY =0x05fa659aul)
#define ACCESSEN_WRITE_KEY	 (SYSCFG->ACCESS_EN=0x05fa659aul)

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT 
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
#define IS_FLAG_STATUS(STATE) (((STATE) == RESET) || ((STATE) == SET))

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;	

#include "sc32f53128.h"
#include "sc32f53xx_adc.h"
#include "sc32f53xx_clock.h"
#include "sc32f53xx_cmp.h"
#include "sc32f53xx_crc.h"
#include "sc32f53xx_dma.h"
#include "sc32f53xx_eru.h"
#include "sc32f53xx_flash.h"
#include "sc32f53xx_gpio.h"
#include "sc32f53xx_i2c.h"
#include "sc32f53xx_iwdt.h"
#include "sc32f53xx_led.h"
#include "sc32f53xx_opa.h"
#include "sc32f53xx_ppu.h"
#include "sc32f53xx_ssp.h"
#include "sc32f53xx_syscfg.h"
#include "sc32f53xx_system.h"
#include "sc32f53xx_tim.h"
#include "sc32f53xx_uart.h"
#include "sc32f53xx_wdt.h"
#include "sc32f53xx_wt.h"
#include "sc32f53xx_it.h"
#include "misc.h"
#include "stdio.h"
	
#endif /* __sc32f53xx_CONF_H */

/******************* (C) COPYRIGHT 2015 Silan Microelectronics *****END OF FILE****/
