/**
  ******************************************************************************
  * @file    sc32f53xx_clock.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the clock system firmware functions.
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
#ifndef __SC32F53xx_CLOCK_H
#define __SC32F53xx_CLOCK_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"


#define RCH_VALUE    ((uint32_t)16000000)   /*!< Value of the Internal high speed oscillator in Hz*/
#define RCL_VALUE    ((uint32_t)32000)      /*!< Value of the Internal low speed oscillator in Hz*/
#define OSCH_VALUE   ((uint32_t)8000000)   /*!< Value of the External high speed oscillator in Hz */
#define OSCL_VALUE   ((uint32_t)32768)      /*!< Value of the External low speed oscillator in Hz */


/** @defgroup AHB01_peripheral 
  * @{
  */
#define CLK_AHB01Periph_GPIOA             ((uint32_t)0x00000001)		/*!< AHB01 GPIOA clock control bit */ 
#define CLK_AHB01Periph_GPIOB             ((uint32_t)0x00000002)		/*!< AHB01 GPIOB clock control bit */ 
#define CLK_AHB01Periph_GPIOC             ((uint32_t)0x00000004)		/*!< AHB01 GPIOC clock control bit */ 
#define CLK_AHB01Periph_GPIOF             ((uint32_t)0x00000020)		/*!< AHB01 GPIOF clock control bit */ 
#define CLK_AHB01Periph_ALL            		((uint32_t)0x00000027)		/*!< AHB01 All clock control bit */ 

#define IS_CLK_AHB01_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFFFD8) == 0x00) && ((PERIPH) != 0x00))


/** @defgroup AHB23_peripheral 
  * @{
  */
#define CLK_AHB23Periph_COPROC             ((uint32_t)0x00000001)		/*!< AHB23 COPROC clock control bit */  
#define CLK_AHB23Periph_All             	 ((uint32_t)0x00000001)		/*!< AHB23 All clock control bit */  

#define IS_CLK_AHB23_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFFFFE) == 0x00) && ((PERIPH) != 0x00))


/** @defgroup APB01_peripheral 
  * @{
  */
#define CLK_APB01Periph_PPU               ((uint32_t)0x00000004)		/*!< APB01 PPU clock control bit */   
#define CLK_APB01Periph_ERU               ((uint32_t)0x00000008)		/*!< APB01 ERU clock control bit */  
#define CLK_APB01Periph_DMA               ((uint32_t)0x00000040)		/*!< APB01 DMA clock control bit */  
#define CLK_APB01Periph_UART1             ((uint32_t)0x00010000)		/*!< APB01 UART1 clock control bit */  
#define CLK_APB01Periph_UART2             ((uint32_t)0x00020000)		/*!< APB01 UART2 clock control bit */  
#define CLK_APB01Periph_UART3             ((uint32_t)0x00040000)		/*!< APB01 UART3 clock control bit */  
#define CLK_APB01Periph_UART4             ((uint32_t)0x00080000)		/*!< APB01 UART4 clock control bit */  
#define CLK_APB01Periph_UART5             ((uint32_t)0x00100000)		/*!< APB01 UART5 clock control bit */  
#define CLK_APB01Periph_UART6             ((uint32_t)0x00200000)		/*!< APB01 UART6 clock control bit */  
#define CLK_APB01Periph_I2C               ((uint32_t)0x00800000)		/*!< APB01 I2C clock control bit */  
#define CLK_APB01Periph_SSP               ((uint32_t)0x01000000)		/*!< APB01 SSP clock control bit */  
#define CLK_APB01Periph_ALL               ((uint32_t)0x01BF004C)		/*!< APB01 All clock control bit */  

#define IS_CLK_APB01_PERIPH(PERIPH) ((((PERIPH) & 0xFE40FFB3) == 0x00) && ((PERIPH) != 0x00))


/** @defgroup APB23_peripheral 
  * @{
  */
#define CLK_APB23Periph_TIM14             ((uint32_t)0x00000001)		/*!< APB23 TIM14 clock control bit */ 
#define CLK_APB23Periph_TIM15             ((uint32_t)0x00000002)		/*!< APB23 TIM15 clock control bit */ 
#define CLK_APB23Periph_TIM16             ((uint32_t)0x00000004)		/*!< APB23 TIM16 clock control bit */ 
#define CLK_APB23Periph_TIM17             ((uint32_t)0x00000008)		/*!< APB23 TIM17 clock control bit */ 
#define CLK_APB23Periph_ADC               ((uint32_t)0x00000100)		/*!< APB23 ADC clock control bit */ 
#define CLK_APB23Periph_ACMP_OPA          ((uint32_t)0x00000400)		/*!< APB23 ACMP_OPA clock control bit */ 
#define CLK_APB23Periph_TIM1              ((uint32_t)0x00001000)		/*!< APB23 TIM1 clock control bit */ 
#define CLK_APB23Periph_TIM3              ((uint32_t)0x00002000)		/*!< APB23 TIM3 clock control bit */ 
#define CLK_APB23Periph_ALL               ((uint32_t)0x0000350F)		/*!< APB23 All clock control bit */ 

#define IS_CLK_APB23_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFCAF0) == 0x00) && ((PERIPH) != 0x00))


/** @defgroup System_clock_source 
  * @{
  */
#define CLK_SYSCLKSource_RCH              ((uint32_t)0x00000000)		/*!< System clock selection is RCH */ 
#define CLK_SYSCLKSource_OSCH             ((uint32_t)0x00000001)		/*!< System clock selection is OSCH */ 
#define CLK_SYSCLKSource_PLLCLK           ((uint32_t)0x00000002)		/*!< System clock selection is PLL */ 
#define CLK_SYSCLKSource_RCL              ((uint32_t)0x00000003)		/*!< System clock selection is RCL */ 
#define CLK_SYSCLKSource_OSCL             ((uint32_t)0x00000007)		/*!< System clock selection is OSCL */ 

#define IS_CLK_SYSCLK_SOURCE(SOURCE) (((SOURCE) == CLK_SYSCLKSource_RCH) || \
                                      ((SOURCE) == CLK_SYSCLKSource_OSCH) || \
																			((SOURCE) == CLK_SYSCLKSource_PLLCLK) || \
																			((SOURCE) == CLK_SYSCLKSource_RCL) || \
                                      ((SOURCE) == CLK_SYSCLKSource_OSCL))																	


/** @defgroup PCLK01_PCLK23_clock_source 
  * @{
  */
#define CLK_HCLK_Div1                    ((uint32_t)0x00000000)		/*!< HCLK Frequency division 1*/
#define CLK_HCLK_Div2                    ((uint32_t)0x00000001)		/*!< HCLK Frequency division 2*/
#define CLK_HCLK_Div3                    ((uint32_t)0x00000002)		/*!< HCLK Frequency division 3*/
#define CLK_HCLK_Div4                    ((uint32_t)0x00000003)		/*!< HCLK Frequency division 4*/
#define CLK_HCLK_Div5                    ((uint32_t)0x00000004)		/*!< HCLK Frequency division 5*/
#define CLK_HCLK_Div6                    ((uint32_t)0x00000005)		/*!< HCLK Frequency division 6*/
#define CLK_HCLK_Div7                    ((uint32_t)0x00000006)		/*!< HCLK Frequency division 7*/
#define CLK_HCLK_Div8                    ((uint32_t)0x00000007)		/*!< HCLK Frequency division 8*/
#define CLK_HCLK_Div9                    ((uint32_t)0x00000008)		/*!< HCLK Frequency division 9*/
#define CLK_HCLK_Div10                   ((uint32_t)0x00000009)		/*!< HCLK Frequency division 10*/
#define CLK_HCLK_Div11                   ((uint32_t)0x0000000A)		/*!< HCLK Frequency division 11*/
#define CLK_HCLK_Div12                   ((uint32_t)0x0000000B)		/*!< HCLK Frequency division 12*/
#define CLK_HCLK_Div13                   ((uint32_t)0x0000000C)		/*!< HCLK Frequency division 13*/
#define CLK_HCLK_Div14                   ((uint32_t)0x0000000D)		/*!< HCLK Frequency division 14*/
#define CLK_HCLK_Div15                   ((uint32_t)0x0000000E)		/*!< HCLK Frequency division 15*/
#define CLK_HCLK_Div16                   ((uint32_t)0x0000000F)		/*!< HCLK Frequency division 16*/

#define IS_RCC_PCLK(PCLK) (((PCLK) == CLK_HCLK_Div1)  || ((PCLK) == CLK_HCLK_Div2)  || \
                           ((PCLK) == CLK_HCLK_Div3)  || ((PCLK) == CLK_HCLK_Div4)  || \
                           ((PCLK) == CLK_HCLK_Div5)  || ((PCLK) == CLK_HCLK_Div6)  || \
                           ((PCLK) == CLK_HCLK_Div7)  || ((PCLK) == CLK_HCLK_Div8)  || \
                           ((PCLK) == CLK_HCLK_Div9)  || ((PCLK) == CLK_HCLK_Div10) || \
                           ((PCLK) == CLK_HCLK_Div11) || ((PCLK) == CLK_HCLK_Div12) || \
                           ((PCLK) == CLK_HCLK_Div13) || ((PCLK) == CLK_HCLK_Div14) || \
                           ((PCLK) == CLK_HCLK_Div15) || ((PCLK) == CLK_HCLK_Div16)) 											 


/** @defgroup MTCLK_clock_source 
  * @{
  */
#define CLK_SYSCLK_Div1                    ((uint32_t)0x00000000)		/*!< System Frequency division 1*/
#define CLK_SYSCLK_Div2                    ((uint32_t)0x00000100)		/*!< System Frequency division 2*/
#define CLK_SYSCLK_Div3                    ((uint32_t)0x00000200)		/*!< System Frequency division 3*/
#define CLK_SYSCLK_Div4                    ((uint32_t)0x00000300)		/*!< System Frequency division 4*/
#define CLK_SYSCLK_Div5                    ((uint32_t)0x00000400)		/*!< System Frequency division 5*/
#define CLK_SYSCLK_Div6                    ((uint32_t)0x00000500)		/*!< System Frequency division 6*/
#define CLK_SYSCLK_Div7                    ((uint32_t)0x00000600)		/*!< System Frequency division 7*/
#define CLK_SYSCLK_Div8                    ((uint32_t)0x00000700)		/*!< System Frequency division 8*/
#define CLK_SYSCLK_Div9                    ((uint32_t)0x00000800)		/*!< System Frequency division 9*/
#define CLK_SYSCLK_Div10                   ((uint32_t)0x00000900)		/*!< System Frequency division 10*/
#define CLK_SYSCLK_Div11                   ((uint32_t)0x00000A00)		/*!< System Frequency division 11*/
#define CLK_SYSCLK_Div12                   ((uint32_t)0x00000B00)		/*!< System Frequency division 12*/
#define CLK_SYSCLK_Div13                   ((uint32_t)0x00000C00)		/*!< System Frequency division 13*/
#define CLK_SYSCLK_Div14                   ((uint32_t)0x00000D00)		/*!< System Frequency division 14*/
#define CLK_SYSCLK_Div15                   ((uint32_t)0x00000E00)		/*!< System Frequency division 15*/
#define CLK_SYSCLK_Div16                   ((uint32_t)0x00000F00)		/*!< System Frequency division 16*/

#define IS_RCC_MTCLK(MTCLK) (((MTCLK) == CLK_SYSCLK_Div1)  || ((MTCLK) == CLK_SYSCLK_Div2)  || \
                            ((MTCLK) == CLK_SYSCLK_Div3)  || ((MTCLK) == CLK_SYSCLK_Div4)  || \
                            ((MTCLK) == CLK_SYSCLK_Div5)  || ((MTCLK) == CLK_SYSCLK_Div6)  || \
                            ((MTCLK) == CLK_SYSCLK_Div7)  || ((MTCLK) == CLK_SYSCLK_Div8)  || \
                            ((MTCLK) == CLK_SYSCLK_Div9)  || ((MTCLK) == CLK_SYSCLK_Div10) || \
                            ((MTCLK) == CLK_SYSCLK_Div11) || ((MTCLK) == CLK_SYSCLK_Div12) || \
                            ((MTCLK) == CLK_SYSCLK_Div13) || ((MTCLK) == CLK_SYSCLK_Div14) || \
                            ((MTCLK) == CLK_SYSCLK_Div15) || ((MTCLK) == CLK_SYSCLK_Div16)) 		
													 
													 
typedef enum
{
  OSCH_StableTime_4ms =   0x00,  /*!< OSCH stable time selection 4ms. */
  OSCH_StableTime_8ms =   0x01,  /*!< OSCH stable time selection 8ms. */
	OSCH_StableTime_16ms =  0x02,  /*!< OSCH stable time selection 16ms. */
	OSCH_StableTime_32ms =  0x03,  /*!< OSCH stable time selection 32ms. */
}OSCHStable_TypeDef;


typedef enum
{
  OSCH_GAIN_1_4M     =   0x00,      /*!< external high speed oscillation gain selection 1_4M. */
	OSCH_GAIN_4_8M     =   0x01,      /*!< external high speed oscillation gain selection 4_8M. */
	OSCH_GAIN_8_16M    =   0x02,      /*!< external high speed oscillation gain selection 8_16M. */
	OSCH_GAIN_16_32M   =   0x03,      /*!< external high speed oscillation gain selection 16_32M. */
}OSCHGain_TypeDef;


typedef enum
{
  CRY_GAIN_Lowest     =  0x00,      /*!< external low speed oscillation gain selection lowest. */
	CRY_GAIN_MediumLow  =  0x01,      /*!< external low speed oscillation gain selection medium low. */
	CRY_GAIN_MediumHigh =  0x02,      /*!< external low speed oscillation gain selection medium high. */
	CRY_GAIN_Highest    =  0x03,      /*!< external low speed oscillation gain selection highest. */
}OSCLGain_TypeDef;


/**
  * @brief  the PLL reference clock source selection
  */
typedef enum
{
  PLLSource_RCH = 0x00,      /*!< RCH is the reference clock source for PLL. */
	PLLSource_CRY = 0x01,      /*!< CRY is the reference clock source for PLL. */
}PLLSource_Typedef;

/**
  * @brief  PLL Prescaler selection
  */
typedef enum
{
  PLLDIV_1   = 0x00,        /*!< PLL Prescaler selection fpll = fsource/1. */
	PLLDIV_2   = 0x01,        /*!< PLL Prescaler selection fpll = fsource/2. */
	PLLDIV_3   = 0x02,        /*!< PLL Prescaler selection fpll = fsource/3. */
	PLLDIV_4   = 0x03,        /*!< PLL Prescaler selection fpll = fsource/4. */
	PLLDIV_5   = 0x04,        /*!< PLL Prescaler selection fpll = fsource/5. */
	PLLDIV_6   = 0x05,        /*!< PLL Prescaler selection fpll = fsource/6. */
	PLLDIV_7   = 0x06,        /*!< PLL Prescaler selection fpll = fsource/7. */
	PLLDIV_8   = 0x07,        /*!< PLL Prescaler selection fpll = fsource/8. */
	PLLDIV_9   = 0x08,        /*!< PLL Prescaler selection fpll = fsource/9. */
	PLLDIV_10  = 0x09,        /*!< PLL Prescaler selection fpll = fsource/10. */
	PLLDIV_11  = 0x0A,        /*!< PLL Prescaler selection fpll = fsource/11. */
	PLLDIV_12  = 0x0B,        /*!< PLL Prescaler selection fpll = fsource/12. */
	PLLDIV_13  = 0x0C,        /*!< PLL Prescaler selection fpll = fsource/13. */
	PLLDIV_14  = 0x0D,        /*!< PLL Prescaler selection fpll = fsource/14. */
	PLLDIV_15  = 0x0E,        /*!< PLL Prescaler selection fpll = fsource/15. */
	PLLDIV_16  = 0x0F,        /*!< PLL Prescaler selection fpll = fsource/16. */		
}PLLDIV_Typedef;

/**
  * @brief  PLL multiply selection
  */
typedef enum
{
  PLLMUL_24  =  0x00,       /*!< PLL multiply selection FPLL = fpll * 1.  */	
	PLLMUL_28  =  0x01,       /*!< PLL multiply selection FPLL = fpll * 2.  */	
	PLLMUL_32  =  0x02,       /*!< PLL multiply selection FPLL = fpll * 3.  */	
	PLLMUL_36  =  0x03,       /*!< PLL multiply selection FPLL = fpll * 4.  */		
}PLLMUL_Typedef;

/**
  * @brief  CLK Clock Output selection
  */
typedef enum
{
  CLK_MCO_RCL            =  0x00,   /*!< Clock Output rcl32k    */
  CLK_MCO_RCH            =  0x01,   /*!< Clock Output rch16m    */
  CLK_MCO_OSCIN          =  0x02,   /*!< Clock Output oscin     */
  CLK_MCO_XCLKINA        =  0x03,   /*!< Clock Output xclkina   */
  CLK_MCO_XCLKINB        =  0x04,   /*!< Clock Output xclkinb   */
  CLK_MCO_PLLOUT         =  0x05,   /*!< Clock Output pllout    */
  CLK_MCO_PLLREFCLK      =  0x06,   /*!< Clock Output pllrefclk */
  CLK_MCO_SYSCLK         =  0x08,   /*!< Clock Output sysclk    */
  CLK_MCO_FCLK           =  0x0A,   /*!< Clock Output fclk      */		
}CLKOutput_TypeDef;

/**
  * @brief  CLK Clock Output division selection
  */
typedef enum 
{
  CLK_MCO_DIV1           =  0x00,   /*!< Clock Output fmco/1   */
  CLK_MCO_DIV2           =  0x01,   /*!< Clock Output fmco/2   */
  CLK_MCO_DIV4           =  0x02,   /*!< Clock Output fmco/4   */
  CLK_MCO_DIV8           =  0x03,   /*!< Clock Output fmco/8   */
  CLK_MCO_DIV16          =  0x04,   /*!< Clock Output fmco/16  */
  CLK_MCO_DIV32          =  0x05,   /*!< Clock Output fmco/32  */
  CLK_MCO_DIV64          =  0x06,   /*!< Clock Output fmco/64  */
  CLK_MCO_DIV128         =  0x07,   /*!< Clock Output fmco/128 */	
}CLKOutDiv_TypeDef;


/**
  * @brief  SYSTICK Clock Output selection
  */
typedef enum
{
  SYSTICK_Source_RCL = 0x00,
	SYSTICK_Source_RCH_DIV16 = 0x02,
	SYSTICK_Source_SCLK_DIV16 = 0x03,
}SystickSel_Typedef;


/** @defgroup CLK_Exported_Types
  * @{
  */

typedef struct
{
  uint32_t SYSCLK_Frequency;    /*!< returns SYSCLK clock frequency expressed in Hz */
  uint32_t HCLK_Frequency;      /*!< returns HCLK clock frequency expressed in Hz */
  uint32_t PCLK01_Frequency;    /*!< returns PCLK01 clock frequency expressed in Hz */
  uint32_t PCLK23_Frequency;    /*!< returns PCLK23 clock frequency expressed in Hz */
  uint32_t MTCLK_Frequency;     /*!< returns MTCLK clock frequency expressed in Hz */
}CLK_ClocksTypeDef;



/** 
  * @brief  OSCH Config Structure definition  
  */ 
typedef struct {
  OSCHStable_TypeDef CRY_StableTime;         /*!< External high speed crystal oscillator stability delay selection. 
	                                              This parameter can be a value of @ref OSCHStable_TypeDef */
	
  FunctionalState OSCH_InResist_ENABLE;      /*!< Specifies wether the feedback resistor is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */
	
	FunctionalState OSCH_Detection_ENABLE;     /*!< External high speed crystal detection is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */
	
	OSCHGain_TypeDef CRY_GainSelection;     /*!< external oscillation gain selection.
	                                              This parameter can be a value of @ref OSCHGain_TypeDef */
}OSCH_ConfigTypeDef;

/** 
  * @brief  OSCL Config Structure definition  
  */ 
typedef struct {
  FunctionalState OSCL_InResist_ENABLE;      /*!< Specifies wether the feedback resistor is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */
	
	FunctionalState OSCL_Detection_ENABLE;     /*!< External crystal detection is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */
	
	FunctionalState OSCL_Filt_ENABLE;          /*!< External low speed crystal filt is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */

	FunctionalState OSCL_Inverter_ENABLE;      /*!< External low speed crystal inverter is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */

	FunctionalState OSCL_FastMode_ENABLE;      /*!< External low speed crystal fast mode is enabled or disabled.
	                                              This parameter can be set to ENABLE or DISABLE */	
	
	OSCLGain_TypeDef OSCL_GainSelection;     /*!< external oscillation gain selection.
	                                              This parameter can be a value of @ref OSCLGain_TypeDef */
}OSCL_ConfigTypeDef;

/** 
  * @brief  PLL Config Structure definition  
  */ 
typedef struct {
  PLLSource_Typedef PLL_Source;              /*!< the PLL reference clock source selection.
	                                              This parameter can be a value of @ref CLK_CRYStable_TypeDef */
	
  PLLDIV_Typedef PLL_DIV;                    /*!< PLL Prescaler selection.
	                                              This parameter can be a value of @ref PLLDIV_Typedef */
	
	PLLMUL_Typedef PLL_MUL;                    /*!< PLL multiply selection.
	                                              This parameter can be a value of @ref PLLMUL_Typedef */
}PLL_ConfigTypeDef;


void CLK_AHB01PeriphClockCmd(uint32_t CLK_AHB01Periph, FunctionalState NewState);
void CLK_AHB23PeriphClockCmd(uint32_t CLK_AHB23Periph, FunctionalState NewState);
void CLK_APB01PeriphClockCmd(uint32_t CLK_APB01Periph, FunctionalState NewState);
void CLK_APB23PeriphClockCmd(uint32_t CLK_APB23Periph, FunctionalState NewState);
void CLK_OSCHConfig(OSCH_ConfigTypeDef* OSCH_ConfigStruct);
void OSCH_ConfigStructInit(OSCH_ConfigTypeDef* OSCH_ConfigStruct);
void CLK_OSCLConfig(OSCL_ConfigTypeDef* OSCL_ConfigStruct);
void OSCL_ConfigStructInit(OSCL_ConfigTypeDef* OSCL_ConfigStruct);
void CLK_PLLConfig(PLL_ConfigTypeDef* PLL_ConfigStruct);
void PLL_ConfigStructInit(PLL_ConfigTypeDef* PLL_ConfigStruct);
void CLK_RCHCmd(FunctionalState NewState);
void CLK_OSCHCmd(FunctionalState NewState);
void CLK_OSCLCmd(FunctionalState NewState);
void CLK_PLLCmd(FunctionalState NewState);
void CLK_MCOConfig(CLKOutput_TypeDef CLK_MCO, CLKOutDiv_TypeDef MCO_DIV);
void CLK_SYSCLKConfig(uint32_t CLK_SYSCLKSource);
void CLK_HCLKConfig(uint8_t CLK_SYSCLK);
void CLK_PCLK01Config(uint32_t CLK_HCLK);
void CLK_PCLK23Config(uint32_t CLK_HCLK);
void CLK_MTCLKConfig(uint32_t CLK_SYSCLK);
void CLK_SystickSel(SystickSel_Typedef Systick_Source);
uint32_t CLK_GetSysclkFreq(void);
uint32_t CLK_GetHclkFreq(void);
uint32_t CLK_GetPclk01Freq(void);
uint32_t CLK_GetPclk23Freq(void);
uint32_t CLK_GetMTclkFreq(void);


#endif
















