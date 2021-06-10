/**
  ******************************************************************************
  * @file    sc32f53xx_gpio.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    9-12-2019
  * @brief   This file provides all the GPIO firmware functions.
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
#ifndef __SC32F53xx_GPIO_H
#define __SC32F53xx_GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"



#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == PA) || \
                                    ((PERIPH) == PB) || \
                                    ((PERIPH) == PC) || \
                                    ((PERIPH) == PF)) 



/** @defgroup GPIO_pins_define 
  * @{
  */
#define GPIO_Pin_0                 ((uint16_t)0x0000)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0001)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0002)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0003)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0004)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0005)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0006)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0007)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0008)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0009)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x000A)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x000B)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x000C)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x000D)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x000E)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x000F)  /*!< Pin 15 selected */


#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || \
                              ((PIN) == GPIO_Pin_3) || \
                              ((PIN) == GPIO_Pin_4) || \
                              ((PIN) == GPIO_Pin_5) || \
                              ((PIN) == GPIO_Pin_6) || \
                              ((PIN) == GPIO_Pin_7) || \
                              ((PIN) == GPIO_Pin_8) || \
                              ((PIN) == GPIO_Pin_9) || \
                              ((PIN) == GPIO_Pin_10) || \
                              ((PIN) == GPIO_Pin_11) || \
                              ((PIN) == GPIO_Pin_12) || \
                              ((PIN) == GPIO_Pin_13) || \
                              ((PIN) == GPIO_Pin_14) || \
                              ((PIN) == GPIO_Pin_15))


/** 
  * @brief  Gpio Reverse input selection  
**/	
typedef enum
{
		GPIO_UnreverseIn = 0x00,		/*!< GPIO Unreverse input.  */  
		GPIO_ReverseIn = 0x01,			/*!< GPIO Reverse input.  */  
}GPIOInv_TypeDef;

#define IS_GPIO_Inv(Inv)  (((Inv) == GPIO_UnreverseIn) || ((Inv) == GPIO_ReverseIn))

/** 
  * @brief  Gpio direct selection  
  */	
typedef enum
{
	GPIO_DirIn  = 0x00,           /*!< GPIO input.  */  
  GPIO_DirOut = 0x01,           /*!< GPIO output. */                 
}GPIODir_TypeDef;

#define IS_GPIO_Dir(Dir)  (((Dir) == GPIO_DirIn) || ((Dir) == GPIO_DirOut))

/** 
  * @brief  Gpio Drive current mode selection  
  */
typedef enum
{
	GPIO_DriveLow  = 0x00,         /*!< Low drive current.  */  
  GPIO_DriveHigh = 0x01,         /*!< High drive current. */                 
}GPIODrive_TypeDef;

#define IS_GPIO_Drive(Drive)  (((Drive) == GPIO_DriveLow) || ((Drive) == GPIO_DriveHigh))

/** 
  * @brief  Gpio Open drain mode selection  
  */
typedef enum 
{
  GPIO_ODDisable = 0x00,         /*!< Open drain disable.  */         
  GPIO_ODEnable  = 0x01,         /*!< Open drain enable. */     
}GPIOOD_TypeDef;

#define IS_GPIO_OD(OD)  (((OD) == GPIO_ODDisable) || ((OD) == GPIO_ODEnable))

/** 
  * @brief  Gpio pull-up mode selection  
  */
typedef enum 
{
  GPIO_NoPUPD   = 0x00,           /*!< No pull-up and pull-down.  */  
  GPIO_PD       = 0x01,           /*!< input pull-down.  */    
  GPIO_PU       = 0x02,           /*!< input pull-up.  */ 
	GPIO_Repeater = 0x03,						/*!< input pull-up or pull-down base on the value of PAD.  */ 
}GPIOPuPd_TypeDef;

#define IS_GPIO_PuPd(PuPd)  (((PuPd) == GPIO_NoPUPD) || ((PuPd) == GPIO_PD) ||\
														((PuPd) == GPIO_PU) || ((PuPd) == GPIO_Repeater))

/** 
  * @brief  Gpio slew rate mode selection  
  */
typedef enum
{
	GPIO_Fast  = 0x00,             /*!< fast.  */ 
  GPIO_Slow  = 0x01,             /*!< slow.  */ 
}GPIOSlewRate_TypeDef;

#define IS_GPIO_SlewRate(SlewRate)  (((SlewRate) == GPIO_Fast) || ((SlewRate) == GPIO_Slow))


/** 
  * @brief  Gpio Input filter selection 
  */
typedef enum
{
  GPIO_Filt_No =     0x00,          /*!< Input unfiltering.  */ 
  GPIO_Filt_1clock = 0x01,          /*!< Input use 1 clock filter.  */                               
	GPIO_Filt_2clock = 0x02,          /*!< Input use 2 clock filter.  */   
	GPIO_Filt_3clock = 0x03,          /*!< Input use 3 clock filter.  */   
}GPIOFilt_TypeDef;

#define IS_GPIO_Filt(Filt)  (((Filt) == GPIO_Filt_No) || ((Filt) == GPIO_Filt_1clock)|| \
														((Filt) == GPIO_Filt_2clock) || ((Filt) == GPIO_Filt_3clock))

/** 
  * @brief  Gpio Filter clock divider selection
  */
typedef enum
{
  GPIO_FiltClk_Div1 = 0x00,         /*!< filt frequency is 1/1 GPIO clock.  */ 
  GPIO_FiltClk_Div2 = 0x01,         /*!< filt frequency is 1/2 GPIO clock.  */                       
	GPIO_FiltClk_Div3 = 0x02,         /*!< filt frequency is 1/3 GPIO clock.  */ 
	GPIO_FiltClk_Div4 = 0x03,         /*!< filt frequency is 1/4 GPIO clock.  */ 
  GPIO_FiltClk_Div5 = 0x04,         /*!< filt frequency is 1/5 GPIO clock.  */           
	GPIO_FiltClk_Div6 = 0x05,         /*!< filt frequency is 1/6 GPIO clock.  */ 
	GPIO_FiltClk_Div7 = 0x06,         /*!< filt frequency is 1/7 GPIO clock.  */ 
}GPIOFiltClkDiv_TypeDef;

#define IS_GPIO_FiltClkDiv(FiltClkDiv)  (((FiltClkDiv) == GPIO_FiltClk_Div1) || ((FiltClkDiv) == GPIO_FiltClk_Div2)|| \
																				((FiltClkDiv) == GPIO_FiltClk_Div3) || ((FiltClkDiv) == GPIO_FiltClk_Div4) ||\
																				((FiltClkDiv) == GPIO_FiltClk_Div5) || ((FiltClkDiv) == GPIO_FiltClk_Div6) ||\
																				((FiltClkDiv) == GPIO_FiltClk_Div7))
									
/** 
  * @brief  Gpio Alternate functions selection
  */
typedef enum
{
  GPIO_AF0 = 0x00,           /*!< GPIO Alternate functions 0.  */ 
  GPIO_AF1 = 0x01,           /*!< GPIO Alternate functions 1.  */ 
	GPIO_AF2 = 0x02,           /*!< GPIO Alternate functions 2.  */ 
	GPIO_AF3 = 0x03,           /*!< GPIO Alternate functions 3.  */ 
	GPIO_AF4 = 0x04,           /*!< GPIO Alternate functions 4.  */ 
	GPIO_AF5 = 0x05,           /*!< GPIO Alternate functions 5.  */ 
	GPIO_AF6 = 0x06,           /*!< GPIO Alternate functions 6.  */ 
	GPIO_AF7 = 0x07,           /*!< GPIO Alternate functions 7.  */ 
}GPIOAFMode_TypeDef;

#define IS_GPIO_AFMode(AFMode)  		(((AFMode) == GPIO_AF0) || ((AFMode) == GPIO_AF1) || \
																		((AFMode) == GPIO_AF2) || ((AFMode) == GPIO_AF3) || \
																		((AFMode) == GPIO_AF4) || ((AFMode) == GPIO_AF5) || \
																		((AFMode) == GPIO_AF6) || ((AFMode) == GPIO_AF7))

/** 
  * @brief  Gpio type of interrupt trigger mode selection
  */

typedef enum
{
  GPIO_IRQHigh    = 0x00,  	 /*!< High level interrupt  */ 
  GPIO_IRQLow     = 0x01,		 /*!< Low level interrupt  */ 
  GPIO_IRQRising  = 0x02,    /*!< Rising edge interruption  */ 
  GPIO_IRQFalling = 0x03,    /*!< Falling edge interruption  */ 
  GPIO_IRQEdge    = 0x04,    /*!< Rising or Falling edge interruption  */ 
  GPIO_IRQDisable = 0x05,    /*!< Disable interruption */ 
}GPIOIRQ_Typedef;

#define IS_GPIO_IRQ(IRQ)  		(((IRQ) == GPIO_IRQHigh) || ((IRQ) == GPIO_IRQLow)|| \
															((IRQ) == GPIO_IRQRising) || ((IRQ) == GPIO_IRQFalling) ||\
															((IRQ) == GPIO_IRQEdge) || ((IRQ) == GPIO_IRQDisable))

/** 
  * @brief  Bit_SET and Bit_RESET enumeration  
  */
typedef enum
{ 
	Bit_RESET = 0x00,   /*!< Reset bit */ 
  Bit_SET   = 0x01,		/*!< Set bit */ 
}BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))


/** 
  * @brief  GPIO Init structure definition  
  */

typedef struct
{
  uint16_t GPIO_Pin;                       /*!< Specifies the GPIO pins to be configured.
                                              This parameter can be any value of @ref GPIO_pins_define */

  GPIODir_TypeDef GPIO_Dir;                /*!< Specifies the direct for the selected pins.
                                              This parameter can be a value of @ref GPIODir_TypeDef */

  GPIODrive_TypeDef GPIO_Drive;            /*!< Specifies the drive mode for the selected pins.
                                              This parameter can be a value of @ref GPIODrive_TypeDef */
	
  GPIOOD_TypeDef GPIO_OD;                  /*!< Specifies the open drain mode for the selected pins.
                                              This parameter can be a value of @ref GPIOOD_TypeDef */	
	
  GPIOPuPd_TypeDef GPIO_PUPD;              /*!< Specifies the input mode for the selected pins.
                                              This parameter can be a value of @ref GPIOPuPd_TypeDef */

  GPIOSlewRate_TypeDef GPIO_SlewRate;      /*!< Specifies the slew rate mode for the selected pins.
                                              This parameter can be a value of @ref GPIOSlewRate_TypeDef */	
	
  GPIOInv_TypeDef GPIO_RevIn;        /*!< Specifies the Reverse input mode for the selected pins.
                                              This parameter can be a value of @ref GPIOInv_TypeDef */	
	
  GPIOFilt_TypeDef GPIO_Filt;              /*!< Specifies the Reverse input mode for the selected pins.
                                              This parameter can be a value of @ref GPIOFilt_TypeDef */
																							
  GPIOFiltClkDiv_TypeDef GPIO_FiltClk;     /*!< Specifies the Reverse input mode for the selected pins.
                                              This parameter can be a value of @ref GPIOFiltClkDiv_TypeDef */
																								
}GPIO_InitTypeDef;


void GPIO_Init(PA_Type* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_InitStructInit(GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_PUPDConfig(PA_Type* GPIOx, uint16_t GPIO_Pin,GPIOPuPd_TypeDef PuPd);
uint8_t GPIO_ReadInputDataBit(PA_Type* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(PA_Type* GPIOx);
uint8_t GPIO_ReadOutputDataBit(PA_Type* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(PA_Type* GPIOx);
void GPIO_SetBits(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(PA_Type* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(PA_Type* GPIOx, uint16_t PortVal);
void GPIO_SetAFMode(PA_Type* GPIOx, uint16_t GPIO_Pin, GPIOAFMode_TypeDef AF_Mode);
void GPIO_SetAnalogMode(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_SetOUTTGL(PA_Type* GPIOx, uint16_t GPIO_Pin);
FlagStatus GPIO_GetOriginalStatus(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ClearOriginalStatus(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_PinIRQConfig(PA_Type* GPIOx, uint16_t GPIO_Pin, GPIOIRQ_Typedef Trig_Mode);
void GPIO_EnableIRQ(PA_Type* GPIOx, uint16_t priority);
void GPIO_DisableIRQ(PA_Type* GPIOx);
ITStatus GPIO_GetIRQStatus(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ClearIRQStatus(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_SetFuncMode(PA_Type* GPIOx, uint16_t GPIO_Pin,uint16_t AFMode);
void GPIO_SetOutEn(PA_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ClearAllIRQStatus(PA_Type* GPIOx);

#endif

