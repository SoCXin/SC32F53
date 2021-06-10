/**
  ******************************************************************************
  * @file    sc32f53xx_adc.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    24-05-2019
  * @brief   This file provides all the ADC firmware functions.
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
#ifndef __SC32F53xx_ADC_H
#define __SC32F53xx_ADC_H

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_conf.h"



/** @defgroup ADC_channel_AINx 
  * @{
  */

#define ADC_Channel_AIN0                               ((uint16_t)0x0001)
#define ADC_Channel_AIN1                               ((uint16_t)0x0002)
#define ADC_Channel_AIN2                               ((uint16_t)0x0004)
#define ADC_Channel_AIN3                               ((uint16_t)0x0008)
#define ADC_Channel_AIN4                               ((uint16_t)0x0010)
#define ADC_Channel_AIN5                               ((uint16_t)0x0020)
#define ADC_Channel_AIN6                               ((uint16_t)0x0040)
#define ADC_Channel_AIN7                               ((uint16_t)0x0080)
#define ADC_Channel_AIN8                               ((uint16_t)0x0100)
#define ADC_Channel_AIN9                               ((uint16_t)0x0200)
#define ADC_Channel_AIN10                              ((uint16_t)0x0400)
#define ADC_Channel_AIN11                              ((uint16_t)0x0800)
#define ADC_Channel_AIN12                              ((uint16_t)0x1000)
#define ADC_Channel_AIN13                              ((uint16_t)0x2000)
#define ADC_Channel_AIN14                              ((uint16_t)0x4000)
#define ADC_Channel_AIN15                              ((uint16_t)0x8000)
#define ADC_Channel_AllINA	                           ((uint16_t)0x00FF)
#define ADC_Channel_AllINB                             ((uint16_t)0xFF00)
#define ADC_Channel_All                                ((uint16_t)0xFFFF)

#define IS_ADC_INCHANNEL(INCHANNEL)  ((((INCHANNEL) & 0xFFFF0000) == 0x00) && ((INCHANNEL) != 0x00))
			
			
typedef enum
{
  ADC_Channel_0 = 0x00,
	ADC_Channel_1 = 0x01,
	ADC_Channel_2 = 0x02,
	ADC_Channel_3 = 0x03,
	ADC_Channel_4 = 0x04,
	ADC_Channel_5 = 0x05,
	ADC_Channel_6 = 0x06,
	ADC_Channel_7 = 0x07,
	ADC_Channel_8 = 0x08,
	ADC_Channel_9 = 0x09,
	ADC_Channel_10 = 0x0A,
	ADC_Channel_11 = 0x0B,
	ADC_Channel_12 = 0x0C,
	ADC_Channel_13 = 0x0D,
	ADC_Channel_14 = 0x0E,
	ADC_Channel_15 = 0x0F,
}ADCChannel_TypeDef;

#define IS_ADC_CHANNEL(CHANNEL) 	(((CHANNEL) == ADC_Channel_0) || ((CHANNEL) == ADC_Channel_1) || \
																	((CHANNEL) == ADC_Channel_2) || ((CHANNEL) == ADC_Channel_3) || \
																	((CHANNEL) == ADC_Channel_4) || ((CHANNEL) == ADC_Channel_5) || \
																	((CHANNEL) == ADC_Channel_6) || ((CHANNEL) == ADC_Channel_7) || \
																	((CHANNEL) == ADC_Channel_8) || ((CHANNEL) == ADC_Channel_9) || \
																	((CHANNEL) == ADC_Channel_10) || ((CHANNEL) == ADC_Channel_11) || \
																	((CHANNEL) == ADC_Channel_12) || ((CHANNEL) == ADC_Channel_13) || \
																	((CHANNEL) == ADC_Channel_14) || ((CHANNEL) == ADC_Channel_15))


/** @defgroup ADC_mode 
  * @{
  */
#define ADC_Conversion_Single         ((uint32_t)0x04000000)			/*!<single conversion*/  
#define ADC_Conversion_Repeat         ((uint32_t)0x02000000)			/*!<repeat conversion*/  

#define IS_ADC_CONVERSION(CONVERSION) 	(((CONVERSION) == ADC_Conversion_Single) || ((CONVERSION) == ADC_Conversion_Repeat))


/****** 参考电压***************/
typedef enum
{
	ADC_VREF_4V = 0x00,			/*!<reference voltage ie 4V*/             
	ADC_VREF_3V = 0x01,			/*!<reference voltage ie 3V*/  
	ADC_VREF_2V = 0x02,			/*!<reference voltage ie 2V*/  
	ADC_VREF_EXT = 0x03,		/*!<reference voltage ie external*/  
}ADCREF_TypeDef;

#define IS_ADC_REF(REF)   (((REF) == (ADC_VREF_4V)) || ((REF) == (ADC_VREF_3V)) || \
													((REF) == (ADC_VREF_2V)) || ((REF) == (ADC_VREF_EXT)))

/******选择内外部参考*******/
typedef enum
{
		ADC_INTER_REF = 0x00,			/*!<Select internal reference*/
		ADC_EXTER_REF = 0x01,			/*!<Select external reference*/
}ADCEXRFSel_TypeDef;

#define IS_ADC_EXRFSel(EXRFSel)    (((EXRFSel) == (ADC_INTER_REF)) || ((EXRFSel) == (ADC_EXTER_REF)))


/****** 硬件触发源***************/
typedef enum
{
	ADC_TRIGSRC_TIM1  =  0x00,				/*!<Hardware trigger source selection is TIM1*/
	ADC_TRIGSRC_TIM3  =  0x01,				/*!<Hardware trigger source selection is TIM3*/
	ADC_TRIGSRC_TIM14 =  0x02,				/*!<Hardware trigger source selection is TIM14*/
	ADC_TRIGSRC_TIM15 =  0x03,				/*!<Hardware trigger source selection is TIM15*/
	ADC_TRIGSRC_TIM16 =  0x04,				/*!<Hardware trigger source selection is TIM16*/
	ADC_TRIGSRC_TIM17 =  0x05,				/*!<Hardware trigger source selection is TIM17*/
	ADC_TRIGSRC_ERU0  =  0x0C,				/*!<Hardware trigger source selection is ERU0*/  
	ADC_TRIGSRC_ERU1  =  0x0D,				/*!<Hardware trigger source selection is ERU1*/
	ADC_TRIGSRC_ERU2  =  0x0E,				/*!<Hardware trigger source selection is ERU2*/
	ADC_TRIGSRC_ERU3  =  0x0F,				/*!<Hardware trigger source selection is ERU3*/
}ADCTRIGSRC_TypeDef;

#define IS_ADC_TRIGSRC(TRIGSRC)   (((TRIGSRC) == (ADC_TRIGSRC_TIM1)) || ((TRIGSRC) == (ADC_TRIGSRC_TIM3)) || \
										              ((TRIGSRC) == (ADC_TRIGSRC_TIM14)) || ((TRIGSRC) == (ADC_TRIGSRC_TIM15)) || \
																	((TRIGSRC) == (ADC_TRIGSRC_TIM16)) || ((TRIGSRC) == (ADC_TRIGSRC_TIM17)) || \
																	((TRIGSRC) == (ADC_TRIGSRC_ERU0)) || ((TRIGSRC) == (ADC_TRIGSRC_ERU1)) || \
																	((TRIGSRC) == (ADC_TRIGSRC_ERU2)) || ((TRIGSRC) == (ADC_TRIGSRC_ERU3)))


/******硬件触发极性选择**************/
typedef enum
{
	ADC_TRIG_RISE = 0x00,				/*!<Hardware triggers polarity selection is rise. */		
	ADC_TRIG_FALL = 0x01,			  /*!<Hardware triggers polarity selection is fall. */		
}ADCTRIGEdge_TypeDef;

#define IS_ADC_TRIGEdge(TRIGEdge)     (((TRIGEdge) == (ADC_TRIG_RISE)) || ((TRIGEdge) == (ADC_TRIG_FALL)))


/******Mode选择**************/
typedef enum
{
  Mode_DATx = 0x00,			/*!<Mode selection is Data channel. */	
	Mode_SEQx = 0x01,			/*!<Mode selection is SEQx. */	
}ModeSel_TypeDef;

#define IS_ADC_ModeSel(ModeSel)     (((ModeSel) == (Mode_DATx)) || ((ModeSel) == (Mode_SEQx)))


/******阈值信道选择**************/
typedef enum
{
  Channel_SelCMP0 = 0x00,			/*!<Threshold channel selection is 0. */	
	Channel_SelCMP1 = 0x01,			/*!<Threshold channel selection is 1. */	
}ChannelCmpSel_TypeDef;

#define IS_ADC_CmpSel(CmpSel)     (((CmpSel) == (Channel_SelCMP0)) || ((CmpSel) == (Channel_SelCMP1)))


/******阈值比较结果**************/
typedef enum
{
  ADC_Range_Greater = 0x02,			/*!<Threshold comparison result is greater. */	
	ADC_Range_Less = 0x01,				/*!<Threshold comparison result is Less. */
	ADC_Range_Between = 0x00,			/*!<Threshold comparison result is Between. */
}ADCRange_TypeDef;

#define IS_ADC_Range(Range)     (((Range) == (ADC_Range_Greater)) || ((Range) == (ADC_Range_Less))\
																((Range) == (ADC_Range_Between)))


typedef enum
{
	ADC_CMP_DISABLE = 0x00,		/*!<Threshold comparison disable . */	
	ADC_CMP_OUT = 0x01,				/*!<Threshold comparison out the gate. */	
}ADCCMPINTSet_TypeDef;

#define IS_ADC_CMPINTSet(CMPINTSet)     (((CMPINTSet) == (ADC_CMP_DISABLE)) || ((CMPINTSet) == (ADC_CMP_OUT)))


#define ADC_IT_SEQA             ((uint16_t)0x0001)		/*!<SEQA interrupt source. */		
#define ADC_IT_SEQB             ((uint16_t)0x0002)		/*!<SEQB interrupt source. */	
#define ADC_IT_OVR              ((uint16_t)0x0004)		/*!<Ovrerun interrupt source. */	
#define ADC_IT_THRCMP           ((uint16_t)0x0008)		/*!<Threshold comparison interrupt source. */	
#define ADC_IT_SEQAOVR          ((uint16_t)0x0010)		/*!<SEQA Overrun interrupt source. */	
#define ADC_IT_SEQBOVR          ((uint16_t)0x0020)		/*!<SEQB Overrun interrupt source. */	

#define IS_ADC_IT(IT)     		((((IT) & 0xFFFFFFC0) == 0x00) && ((IT) != 0x00))


typedef enum
{
	 ADC_R12B_ENABLE = 0x00,				  /*!<Conversion results is 12 bits. */		 
	 ADC_R10B_ENABLE = 0x01,				  /*!<Conversion results is 12 bits. */		 	 
}ADCR1xBSel_TypeDef;

#define IS_ADC_R1xBSel(R1xBSel)     (((R1xBSel) == (ADC_R12B_ENABLE)) || ((R1xBSel) == (ADC_R10B_ENABLE)))


typedef enum
{
	 ADC_VREFVDD_DISABLE = 0x00,				/*!<VDD as reference voltage disable . */	
	 ADC_VREFVDD_ENABLE = 0x01,				  /*!<VDD as reference voltage enable . */		 
}ADCVREFVDDSel_TypeDef;

#define IS_ADC_VREFVDDSet(VREFVDDSel)     ((VREFVDDSel) == (ADC_VREFVDD_DISABLE)) || ((VREFVDDSel) == (ADC_VREFVDD_ENABLE))


typedef enum
{
	 ADC_SEQ_SEQA = 0x00,				/*!<Sequence of choice is SEQA. */	
	 ADC_SEQ_SEQB = 0x01,				/*!<Sequence of choice is SEQB. */	 
}ADCSEQSel_TypeDef;

#define IS_ADC_SEQSel(SEQSel)      ((SEQSel) == (ADC_SEQ_SEQA)) || ((SEQSel) == (ADC_SEQ_SEQB))


typedef enum
{
	 ADC_SEQA_IRQ = 0x00,			/*!<Interrupt entry address selection is ADC_SEQA. */
	 ADC_SEQB_IRQ = 0x01,			/*!<Interrupt entry address selection is ADC_SEQB. */	 
	 ADC_IRQ 			= 0x02,			/*!<Interrupt entry address selection is ADC. */
}ADCIRQSel_TypeDef;

#define IS_ADC_IRQSel(IRQSel)      (((IRQSel) == (ADC_SEQA_IRQ)) || ((IRQSel) == (ADC_SEQB_IRQ)) ||\
																	 ((IRQSel) == (ADC_IRQ)))


#define IS_ADC_CLKDIV(CLKDIV) ((CLKDIV) <= 0xFF)


/** 
  * @brief  ADC Init structure definition  
  */
typedef struct
{
  
  FunctionalState ADC_CLKON;               /*!< Specifies ADC clock gating selection                                              
                                               This parameter can be set to ENABLE or DISABLE */

	uint8_t ADC_CLKDIV;        						   /*!< Specifies ADC clock division */

	ADCEXRFSel_TypeDef  ADC_EXRFSel;				 /*!< Specifies ADC Internal and external reference selection. */ 
	
  ADCREF_TypeDef ADC_RefVolSet;            /*!< Specifies the reference voltage selection. */
	
	ADCR1xBSel_TypeDef ADC_R1xBSel;          /* Specifies the number of data bits after conversion. */
	
	ADCVREFVDDSel_TypeDef  ADC_VREFVDDSel;   /* whether Choose VDD as the reference. */
	
}ADC_InitTypeDef;


/** 
  * @brief  ADC PWR Config Structure definition  
  */ 
typedef struct {
	
  FunctionalState ADC_PowerDown;              /*!<Specifies the Power off control  selection. */
	
  FunctionalState ADC_CORE_PowerDown;         /*!< Specifies the digital core power off control  selection. */
	
	FunctionalState ADC_REF_PowerDown;          /*!< Specifies the refer to module power failure controlselection. */

}PD_ConfigTypeDef;



void ADC_Init(ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_PDConfig(PD_ConfigTypeDef* PD_ConfigStruct);
void ADC_PDConfigStructInit(PD_ConfigTypeDef* PD_ConfigStruct);

void ADC_SEQA_SoftwareTrigSet(uint32_t Conversion_Mode, FunctionalState NewState);
void ADC_SEQAENCmd(FunctionalState NewState);
void ADC_SEQA_StartENCmd(FunctionalState NewState);

void ADC_SEQB_SoftwareTrigSet(uint32_t Conversion_Mode, FunctionalState NewState);
void ADC_SEQBENCmd(FunctionalState NewState);
void ADC_SEQB_StartENCmd(FunctionalState NewState);

void ADC_SEQx_ChannelSel(ADCSEQSel_TypeDef SEQSel, uint32_t channel);
void ADC_SEQx_HardWareTrigSet(ADCSEQSel_TypeDef SEQSel, ADCTRIGSRC_TypeDef Trig_Source, ADCTRIGEdge_TypeDef Trig_Edge);
void ADC_SEQx_ModeConfig(ADCSEQSel_TypeDef SEQSel,uint32_t ModeSel);
void ADC_SEQx_ConvWidthSet(ADCSEQSel_TypeDef SEQSel,uint32_t Conversion_Width);
void ADC_ChannelCmpSel(uint32_t channel, ChannelCmpSel_TypeDef Cmp_Sel);
void ADC_WriteChannelCmpThrVal(ChannelCmpSel_TypeDef Cmp_Sel, uint16_t ThrHighVal, uint16_t ThrLowVal);
uint16_t ADC_Read_Gdat(ADCSEQSel_TypeDef SEQSel);
uint16_t ADC_ReadData(ADCChannel_TypeDef Channel);
uint32_t ADC_CHxOverRun_GetStatus(ADCChannel_TypeDef Channel);
uint32_t ADC_SEQxOverRun_GetStatus(ADCChannel_TypeDef Channel,ADCSEQSel_TypeDef SEQSel);
uint32_t ADC_CHxOverRun_ClearStatus(ADCChannel_TypeDef Channel);
uint32_t ADC_CHxComplete_GetStatus(ADCChannel_TypeDef Channel);
uint32_t ADC_SEQxComplete_GetStatus(ADCChannel_TypeDef Channel,ADCSEQSel_TypeDef SEQSel);
void ADC_EnableIRQ(ADCIRQSel_TypeDef IRQSel, uint16_t priority);
void ADC_DisableIRQ(ADCIRQSel_TypeDef IRQSel);
void ADC_CHxCMP_ITCmd(ADCChannel_TypeDef Channel, ADCCMPINTSet_TypeDef Cmp_Type);
uint32_t ADC_CHxCmp_GetITStatus(ADCChannel_TypeDef Channel);
void ADC_CHxCmp_ClearITStatus(ADCChannel_TypeDef Channel);
void ADC_SEQITCmd(uint16_t ADC_IT, FunctionalState NewState);
ITStatus ADC_GetSEQITStatus(uint16_t ADC_IT);
void ADC_ClearSEQITStatus(uint16_t ADC_IT);


#endif

