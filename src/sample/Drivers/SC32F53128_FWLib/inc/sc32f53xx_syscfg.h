/**
  ******************************************************************************
  * @file    sc32f53xx_syscfg.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the syscfg functions.
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
#ifndef __SC32F53xx_SYSCFG_H
#define __SC32F53xx_SYSCFG_H

#include "sc32f53xx_conf.h"

#define ACCESSEN_WRITE_KEY	 (SYSCFG->ACCESS_EN=0x05fa659aul)

/** @defgroup SysRAMx_Parity Config
  * @{
  */
#define SysRAMx_Parity_RAM0				(uint32_t)0x00000200    /*!<system RAM0 parity bit. */ 
#define SysRAMx_Parity_RAM1				(uint32_t)0x00000800    /*!<system RAM1 parity bit. */ 

#define IS_SysParity_RAMx(RAMx)		(((RAMx)==SysRAMx_Parity_RAM0)||((RAMx)==SysRAMx_Parity_RAM1))


/** @defgroup SYSCFG_Bkin3_StopTIMx Config
  * @{
  */
#define SYSCFG_Bkin3_StopTIM1					(uint32_t)0x00000002    /*!<TIM1 software stop bit. */
#define SYSCFG_Bkin3_StopTIM3					(uint32_t)0x00000020    /*!<TIM3 software stop bit. */
#define SYSCFG_Bkin3_StopTIM15				(uint32_t)0x00200000    /*!<TIM15 software stop bit. */
#define SYSCFG_Bkin3_StopTIM16				(uint32_t)0x02000000    /*!<TIM16 software stop bit. */
#define SYSCFG_Bkin3_StopTIM17				(uint32_t)0x20000000    /*!<TIM17 software stop bit. */

#define IS_SYSCFG_Bkin3_StopTIMx(StopTIMx)		(((StopTIMx)==SYSCFG_Bkin3_StopTIM1)||((StopTIMx)==SYSCFG_Bkin3_StopTIM3)||\
																							((StopTIMx)==SYSCFG_Bkin3_StopTIM15)||((StopTIMx)==SYSCFG_Bkin3_StopTIM16)||\
																							((StopTIMx)==SYSCFG_Bkin3_StopTIM17))

/** @defgroup SYSCFG_TIMx Select
  * @{
  */
#define SYSCFG_BkinFsel_TIM1					0x00    /*!<TIM1 offset address. */ 
#define SYSCFG_BkinFsel_TIM3					0x04    /*!<TIM3 offset address. */ 
#define SYSCFG_BkinFsel_TIM15				  0x14    /*!<TIM15 offset address. */ 
#define SYSCFG_BkinFsel_TIM16				  0x18    /*!<TIM16 offset address. */ 
#define SYSCFG_BkinFsel_TIM17				  0x1C    /*!<TIM17 offset address. */ 

#define IS_SYSCFG_BkinFsel_TIMx(TIMx) 		(((TIMx)==SYSCFG_BkinFsel_TIM1)||((TIMx)==SYSCFG_BkinFsel_TIM3)||\
																					((TIMx)==SYSCFG_BkinFsel_TIM15)||((TIMx)==SYSCFG_BkinFsel_TIM16)||\
																					((TIMx)==SYSCFG_BkinFsel_TIM17))

/** @defgroup SYSCFG_TIMx_Bkin_fsel Config
* @{
*/
#define SYSCFG_TIMx_BkinFsel_StopTIMx								0x01    /*!<timx_bkin3 select timx software stop. */ 
#define SYSCFG_TIMx_BkinFsel_StopTIMxAndBkin				0x00   /*!<timx_bkin3 select timx software stop and timx_bkin[2:0]. */ 

#define IS_SYSCFG_TIMx_BkinFsel(BkinFsel)		 (((BkinFsel)==SYSCFG_TIMx_BkinFsel_StopTIMx)||((BkinFsel)==SYSCFG_TIMx_BkinFsel_StopTIMxAndBkin))														


/** @defgroup SYSCFG_Systick_CLKSource Select
* @{
*/
#define SYSCFG_Systick_CLKSource_HCLK										(uint32_t)0x02000000    /*!<Systick reference clock selection is HCLK. */ 
#define SYSCFG_Systick_CLKSource_RCL_HCLKRCHDiv					(uint32_t)0x00000000    /*!<Systick reference clock selection is externally supplied RCL, HCLK or RCH frequency division. */

#define IS_SYSCFG_CLKSource(CLKSource)		(((CLKSource)==SYSCFG_Systick_CLKSource_HCLK)||((CLKSource)==SYSCFG_Systick_CLKSource_RCL_HCLKRCHDiv))		


/** @defgroup SYSCFG_Systick_CLKStatus config
* @{
*/
#define SYSCFG_Systick_CLKStatus_Normal								(uint32_t)0x00000000    /*!<Clock normal. */
#define SYSCFG_Systick_CLKStatus_Skew									(uint32_t)0x01000000    /*!<Clock skew. */

#define IS_SYSCFG_CLKStatus(CLKStatus)		 (((CLKStatus)==SYSCFG_Systick_CLKStatus_Normal)||((CLKStatus)==SYSCFG_Systick_CLKStatus_Skew))		


/** @defgroup SYSCFG_SYSINT Select
  * @{
  */
#define SYSCFG_SYSSAM1_ParityERR				(uint32_t)0x00000020    /*!<Sysram1 parity error bit. */
#define SYSCFG_SYSSAM1_ParityERRIT			(uint32_t)0x00000010    /*!<Sysram1 parity error interrupt bit. */
#define SYSCFG_SYSSAM0_ParityERR				(uint32_t)0x00000008    /*!<Sysram0 parity error bit. */
#define SYSCFG_SYSSAM0_ParityERRIT			(uint32_t)0x00000004    /*!<Sysram0 parity error interrupt bit. */
#define SYSCFG_FLASH_IT									(uint32_t)0x00000002    /*!<FLASH interrupt bit. */
#define SYSCFG_PPU_IT										(uint32_t)0x00000001    /*!<PPU interrupt bit. */

#define IS_SYSCFG_SYSINT_Status(Status) 		(((Status)==SYSCFG_SYSSAM1_ParityERR)||((Status)==SYSCFG_SYSSAM1_ParityERRIT)||\
																						((Status)==SYSCFG_SYSSAM0_ParityERR)||((Status)==SYSCFG_SYSSAM0_ParityERRIT)||\
																						((Status)==SYSCFG_FLASH_IT)||((Status)==SYSCFG_PPU_IT))
																		
																		
/** @defgroup SYSCFG_Systick_CLKCalibVal config
* @{
*/
#define IS_SYSCFG_CLKCalibVal(CLKCalibVal)  ((CLKCalibVal) <= 0xffffff)    /*!<Clock calibration value. */

/** @defgroup SYSCFG_SYSRAM1_PARITY_ERROR_ADDRESS
* @{
*/
#define IS_SYSCFG_SYSRAM1_ParityErrAddr1(ParityErrAddr1)  ((ParityErrAddr1) <= 0x7ff)    /*!<Sysram1 parity error field address. */

/** @defgroup SYSCFG_SYSRAM0_PARITY_ERROR_ADDRESS 
* @{
*/
#define IS_SYSCFG_SYSRAM0_ParityErrAddr0(ParityErrAddr0)  ((ParityErrAddr0) <= 0x7ff)    /*!<Sysram0 parity error field address. */

void SYSCFG_SysRam0ParityCmd(FunctionalState NewState);
void SYSCFG_SysRam1ParityCmd(FunctionalState NewState);
void SYSCFG_ClearParityErr(uint32_t RAMx);
void SYSCFG_UART3_HalfDuplexModeCmd(FunctionalState NewState);
void SYSCFG_StopTIMxBkin3Config(uint32_t StopTIMx,FlagStatus NewState);
void SYSCFG_TIMxBkinSelect(uint16_t TIMx,uint32_t BkinFsel);
void SYSCFG_SystickCLKSelect(uint32_t CLKSource);
ITStatus SYSCFG_GetSystickCLKStatus(uint32_t CLKStatus);
void SYSCFG_SystickCLKStatusConfig(uint32_t CLKStatus);
void SYSCFG_SystickCLKCalibValSelect(uint32_t CLKCalibVal);
void SYSCFG_EnableIRQ(uint16_t priority);
void SYSCFG_DisableIRQ(void);
ITStatus SYSCFG_GetSYSINTStatus(uint32_t Status);
uint16_t SYSCFG_GetSysRAM0ParityErrAddr(void);
uint16_t SYSCFG_GetSysRAM1ParityErrAddr(void);


#endif

