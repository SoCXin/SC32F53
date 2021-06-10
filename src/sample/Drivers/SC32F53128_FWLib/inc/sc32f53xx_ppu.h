/**
  ******************************************************************************
  * @file    sc32f53xx_ppu.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    28-08-2019
  * @brief   This file provides all the ppu functions.
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
#ifndef __SC32F53xx_PPU_H
#define __SC32F53xx_PPU_H

#include "sc32f53xx_conf.h"

/** @defgroup PPU_SRAM Write section Select
  * @{
  */
#define PPU_SRAM_CPUWrite_0_1K						(uint32_t)0x00000001     /*!< SRAM use CPU write area is 0~1K. */
#define PPU_SRAM_CPUWrite_1_2K						(uint32_t)0x00000002     /*!< SRAM use CPU write area is 1~2K. */
#define PPU_SRAM_CPUWrite_2_3K						(uint32_t)0x00000004     /*!< SRAM use CPU write area is 2~3K. */
#define PPU_SRAM_CPUWrite_3_4K						(uint32_t)0x00000008     /*!< SRAM use CPU write area is 3~4K. */
#define PPU_SRAM_CPUWrite_4_5K						(uint32_t)0x00000010     /*!< SRAM use CPU write area is 4~5K. */
#define PPU_SRAM_CPUWrite_5_6K						(uint32_t)0x00000020     /*!< SRAM use CPU write area is 5~6K. */
#define PPU_SRAM_CPUWrite_6_7K						(uint32_t)0x00000040     /*!< SRAM use CPU write area is 6~7K. */
#define PPU_SRAM_CPUWrite_7_8K						(uint32_t)0x00000080     /*!< SRAM use CPU write area is 7~8K. */
#define PPU_SRAM_DMAWrite_0_1K						(uint32_t)0x00000100     /*!< SRAM use DMA write area is 0~1K. */
#define PPU_SRAM_DMAWrite_1_2K						(uint32_t)0x00000200     /*!< SRAM use DMA write area is 1~2K. */
#define PPU_SRAM_DMAWrite_2_3K						(uint32_t)0x00000400     /*!< SRAM use DMA write area is 2~3K. */
#define PPU_SRAM_DMAWrite_3_4K						(uint32_t)0x00000800     /*!< SRAM use DMA write area is 3~4K. */
#define PPU_SRAM_DMAWrite_4_5K						(uint32_t)0x00001000     /*!< SRAM use DMA write area is 4~5K. */
#define PPU_SRAM_DMAWrite_5_6K						(uint32_t)0x00002000     /*!< SRAM use DMA write area is 5~6K. */
#define PPU_SRAM_DMAWrite_6_7K						(uint32_t)0x00004000     /*!< SRAM use DMA write area is 6~7K. */
#define PPU_SRAM_DMAWrite_7_8K						(uint32_t)0x00008000     /*!< SRAM use DMA write area is 7~8K. */
#define PPU_SRAM_CPUWrite_8_9K						(uint32_t)0x00010000     /*!< SRAM use CPU write area is 8~9K. */
#define PPU_SRAM_CPUWrite_9_10K						(uint32_t)0x00020000     /*!< SRAM use CPU write area is 9~10K. */
#define PPU_SRAM_CPUWrite_10_11K					(uint32_t)0x00040000     /*!< SRAM use CPU write area is 10~11K. */
#define PPU_SRAM_CPUWrite_11_12K					(uint32_t)0x00080000     /*!< SRAM use CPU write area is 11~12K. */
#define PPU_SRAM_CPUWrite_12_13K					(uint32_t)0x00100000     /*!< SRAM use CPU write area is 12~13K. */
#define PPU_SRAM_CPUWrite_13_14K					(uint32_t)0x00200000     /*!< SRAM use CPU write area is 13~14K. */
#define PPU_SRAM_CPUWrite_14_15K					(uint32_t)0x00400000     /*!< SRAM use CPU write area is 14~15K. */
#define PPU_SRAM_CPUWrite_15_16K					(uint32_t)0x00800000     /*!< SRAM use CPU write area is 15~16K. */
#define PPU_SRAM_DMAWrite_8_9K						(uint32_t)0x01000000     /*!< SRAM use DMA write area is 8~9K. */	
#define PPU_SRAM_DMAWrite_9_10K						(uint32_t)0x02000000     /*!< SRAM use DMA write area is 9~10K. */	
#define PPU_SRAM_DMAWrite_10_11K					(uint32_t)0x04000000     /*!< SRAM use DMA write area is 10~11K. */	
#define PPU_SRAM_DMAWrite_11_12K					(uint32_t)0x08000000     /*!< SRAM use DMA write area is 11~12K. */	
#define PPU_SRAM_DMAWrite_12_13K					(uint32_t)0x10000000     /*!< SRAM use DMA write area is 12~13K. */	
#define PPU_SRAM_DMAWrite_13_14K					(uint32_t)0x20000000     /*!< SRAM use DMA write area is 13~14K. */	
#define PPU_SRAM_DMAWrite_14_15K					(uint32_t)0x40000000     /*!< SRAM use DMA write area is 14~15K. */	
#define PPU_SRAM_DMAWrite_15_16K					(uint32_t)0x80000000     /*!< SRAM use DMA write area is 15~16K. */		

#define IS_PPU_SRAMWrite(SRAMWrite) 		(((SRAMWrite)==PPU_SRAM_CPUWrite_0_1K)||((SRAMWrite)==PPU_SRAM_CPUWrite_1_2K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_2_3K)||((SRAMWrite)==PPU_SRAM_CPUWrite_3_4K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_4_5K)||((SRAMWrite)==PPU_SRAM_CPUWrite_5_6K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_6_7K)||((SRAMWrite)==PPU_SRAM_CPUWrite_7_8K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_0_1K)||((SRAMWrite)==PPU_SRAM_DMAWrite_1_2K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_2_3K)||((SRAMWrite)==PPU_SRAM_DMAWrite_3_4K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_4_5K)||((SRAMWrite)==PPU_SRAM_DMAWrite_5_6K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_6_7K)||((SRAMWrite)==PPU_SRAM_DMAWrite_7_8K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_8_9K)||((SRAMWrite)==PPU_SRAM_CPUWrite_9_10K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_10_11K)||((SRAMWrite)==PPU_SRAM_CPUWrite_11_12K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_12_13K)||((SRAMWrite)==PPU_SRAM_CPUWrite_13_14K)||\
																				((SRAMWrite)==PPU_SRAM_CPUWrite_14_15K)||((SRAMWrite)==PPU_SRAM_CPUWrite_15_16K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_8_9K)||((SRAMWrite)==PPU_SRAM_DMAWrite_9_10K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_10_11K)||((SRAMWrite)==PPU_SRAM_DMAWrite_11_12K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_12_13K)||((SRAMWrite)==PPU_SRAM_DMAWrite_13_14K)||\
																				((SRAMWrite)==PPU_SRAM_DMAWrite_14_15K)||((SRAMWrite)==PPU_SRAM_DMAWrite_15_16K))
															

/** @defgroup PPU_CTRL_IT Select
  * @{
  */
#define PPU_IT_RAM							(uint32_t)0x00000010     /*!< RAM Write failure interrupt bit. */
#define PPU_IT_HPS01						(uint32_t)0x00000100     /*!< HPS01 Write failure interrupt bit. */
#define PPU_IT_HPS23						(uint32_t)0x00000200     /*!< HPS23 Write failure interrupt bit. */
#define PPU_IT_PPS01						(uint32_t)0x00001000     /*!< PPS01 Write failure interrupt bit. */
#define PPU_IT_PPS23						(uint32_t)0x00002000     /*!< PPS23 Write failure interrupt bit. */

#define IS_PPU_IT(IT) 		(((IT)==PPU_IT_RAM)||((IT)==PPU_IT_HPS01)||\
													((IT)==PPU_IT_HPS23)||((IT)==PPU_IT_PPS01)||\
													((IT)==PPU_IT_PPS23))
																
																
/** @defgroup PPU_HPS01_Px Select
  * @{
  */
#define PPU_HPS01_PA						(uint32_t)0x00000001     /*!< PA module write enable bit. */
#define PPU_HPS01_PB						(uint32_t)0x00000002     /*!< PB module write enable bit. */
#define PPU_HPS01_PC						(uint32_t)0x00000004     /*!< PC module write enable bit. */
#define PPU_HPS01_PF						(uint32_t)0x00000020     /*!< PF module write enable bit. */

#define IS_PPU_HPS01_Px(Px) 		(((Px)==PPU_HPS01_PA)||((Px)==PPU_HPS01_PB)||\
																((Px)==PPU_HPS01_PC)||((Px)==PPU_HPS01_PF))

/** @defgroup PPU_PPS01_PPx Select
  * @{
  */
#define PPU_PPS01_SYSCFG				(uint32_t)0x00000001     /*!< SYSCFG module write enable bit. */
#define PPU_PPS01_CHIPCRTL			(uint32_t)0x00000002     /*!< CHIPCRTL module write enable bit. */
#define PPU_PPS01_ERU						(uint32_t)0x00000008     /*!< ERU module write enable bit. */
#define PPU_PPS01_DMA						(uint32_t)0x00000040     /*!< DMA module write enable bit. */
#define PPU_PPS01_FLASH					(uint32_t)0x00000100     /*!< FLASH module write enable bit. */
#define PPU_PPS01_WDT						(uint32_t)0x00001000     /*!< WDT module write enable bit. */
#define PPU_PPS01_UART1					(uint32_t)0x00010000     /*!< UART1 module write enable bit. */
#define PPU_PPS01_UART2					(uint32_t)0x00020000     /*!< UART2 module write enable bit. */
#define PPU_PPS01_UART3					(uint32_t)0x00040000     /*!< UART3 module write enable bit. */
#define PPU_PPS01_UART4					(uint32_t)0x00080000     /*!< UART4 module write enable bit. */
#define PPU_PPS01_UART5					(uint32_t)0x00100000     /*!< UART5 module write enable bit. */
#define PPU_PPS01_UART6					(uint32_t)0x00200000     /*!< UART6 module write enable bit. */
#define PPU_PPS01_I2C						(uint32_t)0x00800000     /*!< I2C module write enable bit. */
#define PPU_PPS01_SSP						(uint32_t)0x01000000     /*!< SSP module write enable bit. */

#define IS_PPU_PPS01_PPx(PPx) 		(((PPx)==PPU_PPS01_SYSCFG)||((PPx)==PPU_PPS01_CHIPCRTL)||\
																	((PPx)==PPU_PPS01_ERU)||((PPx)==PPU_PPS01_DMA)||\
																	((PPx)==PPU_PPS01_FLASH)||((PPx)==PPU_PPS01_WDT)||\
																	((PPx)==PPU_PPS01_UART1)||((PPx)==PPU_PPS01_UART2)||\
																	((PPx)==PPU_PPS01_UART3)||((PPx)==PPU_PPS01_UART4)||\
																	((PPx)==PPU_PPS01_UART5)||((PPx)==PPU_PPS01_UART6)||\
																	((PPx)==PPU_PPS01_I2C)||((PPx)==PPU_PPS01_SSP))

/** @defgroup PPU_PPS23_PPx Select
  * @{
  */
#define PPU_PPS23_TIM14				(uint32_t)0x00000001     /*!< TIM14 module write enable bit. */
#define PPU_PPS23_TIM15				(uint32_t)0x00000002     /*!< TIM15 module write enable bit. */
#define PPU_PPS23_TIM16				(uint32_t)0x00000004     /*!< TIM16 module write enable bit. */
#define PPU_PPS23_TIM17				(uint32_t)0x00000008     /*!< TIM17 module write enable bit. */
#define PPU_PPS23_ADC					(uint32_t)0x00000100     /*!< ADC module write enable bit. */
#define PPU_PPS23_ACMP_OPA		(uint32_t)0x00000400     /*!< ACMP_OPA module write enable bit. */
#define PPU_PPS23_TIM1				(uint32_t)0x00001000     /*!< TIM1 module write enable bit. */
#define PPU_PPS23_TIM3				(uint32_t)0x00002000     /*!< TIM3 module write enable bit. */
#define PPU_PPS23_LED					(uint32_t)0x00004000     /*!< LED module write enable bit. */

#define IS_PPU_PPS23_PPx(PPx) 		(((PPx)==PPU_PPS23_TIM14)||((PPx)==PPU_PPS23_TIM15)||\
																	((PPx)==PPU_PPS23_TIM16)||((PPx)==PPU_PPS23_TIM17)||\
																	((PPx)==PPU_PPS23_ADC)||((PPx)==PPU_PPS23_ACMP_OPA)||\
																	((PPx)==PPU_PPS23_TIM1)||((PPx)==PPU_PPS23_TIM3)||\
																	((PPx)==PPU_PPS23_LED))

void PPU_ITConfig(uint32_t DMA_IT, FunctionalState NewState);
void PPU_EnableIRQ(uint16_t priority);
void PPU_DisableIRQ(void);
void PPU_HPS01Cmd(uint32_t Px,FunctionalState NewState);
void PPU_HPS23Cmd(FunctionalState NewState);
void PPU_PPS01Cmd(uint32_t PPx,FunctionalState NewState);
void PPU_PPS23Cmd(uint32_t PPx,FunctionalState NewState);
FunctionalState PPU_GetHPS01Status(uint32_t Px);
FunctionalState PPU_GetHPS23Status(void);
FunctionalState PPU_GetPPS01Status(uint32_t PPx);
FunctionalState PPU_GetPPS23Status(uint32_t PPx);
void PPU_ClearHPS01Status(uint32_t Px);
void PPU_ClearHPS23Status(void);
void PPU_ClearPPS01Status(uint32_t PPx);
void PPU_ClearPPS23Status(uint32_t PPx);
void PPU_SRAM_WriteSectionCmd(uint32_t SRAMWrite, FunctionalState NewState);
void PPU_ClearSRAMWirteSectionStatus(uint32_t SRAMWrite);

#endif
