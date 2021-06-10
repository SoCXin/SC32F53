/**
  ******************************************************************************
  * @file    sc32f53xx_gpio.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    20-05-2019
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
  * <h2><center>&copy; COPYRIGHT 2019 Silan Microelectronics </center></h2>
  ********************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_gpio.h"



#define CFG_CLEAR_Mask            ((uint32_t)0xF8FC5A2F)        /*!< GPIO CFG Mask  */ 
#define CFG_FUNC_CLEAR_Mask       ((uint32_t)0xFFFFFFF8)        /*!< GPIO CFG FUNC Bits Mask  */ 
//#define OUTEN_CLEAR_Mask          ((uint32_t)0x0000)            /*!< GPIO OUTEN Mask */ 


/**
  * @brief  Initializes the GPIOx peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_Init(PA_Type* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	uint32_t tmpreg = 0x00;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
	assert_param(IS_GPIO_Dir(GPIO_InitStruct->GPIO_Dir));
	assert_param(IS_GPIO_Drive(GPIO_InitStruct->GPIO_Drive));
	assert_param(IS_GPIO_OD(GPIO_InitStruct->GPIO_OD));
	assert_param(IS_GPIO_PuPd(GPIO_InitStruct->GPIO_PUPD));
	assert_param(IS_GPIO_SlewRate(GPIO_InitStruct->GPIO_SlewRate));
	assert_param(IS_GPIO_Inv(GPIO_InitStruct->GPIO_RevIn));
	assert_param(IS_GPIO_Filt(GPIO_InitStruct->GPIO_Filt));
	assert_param(IS_GPIO_FiltClkDiv(GPIO_InitStruct->GPIO_FiltClk));
	
/*---------------------------- GPIO OUTEN Configuration -----------------------*/
	tmpreg = GPIOx->OUTEN;
  /* Clear OUTEN */	
	tmpreg &= ~(1<<GPIO_InitStruct->GPIO_Pin);
	/* Set GPIO output or input */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_Dir << GPIO_InitStruct->GPIO_Pin);	
	/* Write to OUTEN */
	GPIOx->OUTEN = tmpreg;
	
/*---------------------------- GPIO CFG Configuration -----------------------*/		
  tmpreg = GPIOx->CFG[GPIO_InitStruct->GPIO_Pin];
	/* Clear clkdiv, filt, inv, od, sr, pupd, drv bits */
	tmpreg &= CFG_CLEAR_Mask;
	/* Set drv bits according to GPIO_Drive value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_Drive << 10);
	/* Set filt bits according to GPIO_Filt value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_Filt << 16);	
	/* Set clkdiv bits according to GPIO_FiltClk value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_FiltClk << 24);		
	/* Set od bits according to GPIO_OD value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_OD << 13);		
	/* Set pupd bits according to GPIO_PUPD value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_PUPD << 6);	
	/* Set inv bits according to GPIO_RevIn value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_RevIn << 15);	
	/* Set sr bits according to GPIO_SlewRate value */
	tmpreg |= (uint32_t)(GPIO_InitStruct->GPIO_SlewRate << 8);	
	/* Write to CFG */
	ACCESSEN_WRITE_KEY;
	GPIOx->CFG[GPIO_InitStruct->GPIO_Pin] = tmpreg;
}

/**
  * @brief  Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct : pointer to a GPIO_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void GPIO_InitStructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
  /* Set the default configuration */
  GPIO_InitStruct->GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct->GPIO_Dir = GPIO_DirIn;
  GPIO_InitStruct->GPIO_Drive = GPIO_DriveLow;
  GPIO_InitStruct->GPIO_Filt = GPIO_Filt_No;
  GPIO_InitStruct->GPIO_FiltClk = GPIO_FiltClk_Div1;
  GPIO_InitStruct->GPIO_OD = GPIO_ODDisable;
  GPIO_InitStruct->GPIO_PUPD = GPIO_NoPUPD;
  GPIO_InitStruct->GPIO_RevIn = GPIO_UnreverseIn;
  GPIO_InitStruct->GPIO_SlewRate = GPIO_Fast;
}


/**
  * @brief  Reads the specified GPIO input data port.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @param  PuPd:  Set IO port state.
  *   This parameter can be one of the BitAction enum values:
  *     @arg GPIO_NoPUPD: the port pin is Dangling
  *     @arg GPIO_PD: the port pin is pull-down
  *     @arg GPIO_PU: the port pin is	pull-up
  *     @arg GPIO_Repeater:  input pull-up or pull-down base on the value of PAD
  * @retval No.
  */
void GPIO_PUPDConfig(PA_Type* GPIOx, uint16_t GPIO_Pin,GPIOPuPd_TypeDef PuPd)
{
		/* Check the parameters */
		assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
		assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
		ACCESSEN_WRITE_KEY;
		GPIOx->CFG_b[GPIO_Pin].PUPD = PuPd;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
uint8_t GPIO_ReadInputDataBit(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitvalue = 0x00;
  
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin)); 
  
  if ((GPIOx->PIN & (1 << GPIO_Pin)) != (uint32_t)Bit_RESET)
  {
    bitvalue = (uint8_t)Bit_SET;
  }
  else
  {
    bitvalue = (uint8_t)Bit_RESET;
  }
  return bitvalue;
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
uint16_t GPIO_ReadInputData(PA_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  
  return ((uint16_t)GPIOx->PIN);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t GPIO_ReadOutputDataBit(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitvalue = 0x00;
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin)); 
  
  if ((GPIOx->OUTSET & (1 << GPIO_Pin)) != (uint32_t)Bit_RESET)
  {
    bitvalue = (uint8_t)Bit_SET;
  }
  else
  {
    bitvalue = (uint8_t)Bit_RESET;
  }
  return bitvalue;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @retval GPIO output data port value.
  */
uint16_t GPIO_ReadOutputData(PA_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    
  return ((uint16_t)GPIOx->OUTSET);
}

/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetBits(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  
  GPIOx->OUTSET = (1 << GPIO_Pin);
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_ResetBits(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  
  GPIOx->OUTCLR = (1 << GPIO_Pin);
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(PA_Type* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_BIT_ACTION(BitVal)); 
  
  if (BitVal != Bit_RESET)
  {
		GPIOx->OUT |= (1 << GPIO_Pin);
  }
  else
  {
    GPIOx->OUT &= ~(1 << GPIO_Pin);
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(PA_Type* GPIOx, uint16_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  
  GPIOx->OUT = PortVal;
}

/**
  * @brief  Configure as output port.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetOutEn(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */	
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

	GPIOx->OUTEN |= (1 << GPIO_Pin);
}

/**
  * @brief  Sets GPIO Alternate functions.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  AF_Mode: specifies the value to be written to the selected bit.
  *   This parameter can be one of the GPIOAFMode_TypeDef enum values:
  *     @arg GPIO_AF0: GPIO Alternate functions 0
  *     ...
  *     @arg GPIO_AF7: GPIO Alternate functions 7
  * @retval None
  */
void GPIO_SetAFMode(PA_Type* GPIOx, uint16_t GPIO_Pin, GPIOAFMode_TypeDef AF_Mode)
{
  uint32_t tmpreg = 0x00;
	
  /* Check the parameters */	
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	assert_param(IS_GPIO_AFMode(AF_Mode));
	
	tmpreg = GPIOx->CFG[GPIO_Pin];
	/* Clear func bits */
	tmpreg &= CFG_FUNC_CLEAR_Mask;
	/* set func bits */
	tmpreg |= AF_Mode;
	
	ACCESSEN_WRITE_KEY;
	GPIOx->CFG[GPIO_Pin] = tmpreg;
}

/**
  * @brief  Set the selected Analog port bits.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetAnalogMode(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */	
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

	ACCESSEN_WRITE_KEY;
	GPIOx->CFG[GPIO_Pin] |= (1 << 4);
	GPIOx->OUTEN &= ~(1 << GPIO_Pin);
}

/**
  * @brief  Flip the selected data port bits.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetOUTTGL(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */	
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

	GPIOx->OUTTGL = (1 << GPIO_Pin);
}

/**
  * @brief  Sets Gpio type of interrupt trigger mode.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  Trig_Mode: specifies the value to be written to the selected bit.
  *   This parameter can be one of the GPIOIRQ_Typedef enum values:
  *     @arg GPIO_IRQHigh: the high level to trigger the interrupt
  *     @arg GPIO_IRQRising: the rising edge to trigger an interrupt
  * @retval None
  */
void GPIO_PinIRQConfig(PA_Type* GPIOx, uint16_t GPIO_Pin, GPIOIRQ_Typedef Trig_Mode)
{
  /* Check the parameters */	
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	assert_param(IS_GPIO_IRQ(Trig_Mode));
	
	switch (Trig_Mode)
	{
		/* Configure the high level to trigger the interrupt */	
	  case GPIO_IRQHigh:
		{
		  GPIOx->INTMASK &= ~(1 << GPIO_Pin);
			GPIOx->INTTYPE &= ~(1 << GPIO_Pin);
			GPIOx->INTBV &= ~(1 << GPIO_Pin);
			GPIOx->INTPOL |= (1 << GPIO_Pin);
			break;
		}
		/* Configure the low level to trigger the interrupt */
		case GPIO_IRQLow:
		{
		  GPIOx->INTMASK &= ~(1 << GPIO_Pin);
			GPIOx->INTTYPE &= ~(1 << GPIO_Pin);
			GPIOx->INTBV &= ~(1 << GPIO_Pin);
			GPIOx->INTPOL &= ~(1 << GPIO_Pin);
			break;
		}
		/* Configure the rising edge to trigger an interrupt */
	  case GPIO_IRQRising:
		{
		  GPIOx->INTMASK &= ~(1 << GPIO_Pin);
			GPIOx->INTTYPE |= (1 << GPIO_Pin);
			GPIOx->INTBV &= ~(1 << GPIO_Pin);
			GPIOx->INTPOL |= (1 << GPIO_Pin);
			break;
		}
		/* Configure the falling edge to trigger an interrupt */
	  case GPIO_IRQFalling:
		{
		  GPIOx->INTMASK &= ~(1 << GPIO_Pin);
			GPIOx->INTTYPE |= (1 << GPIO_Pin);
			GPIOx->INTBV &= ~(1 << GPIO_Pin);
			GPIOx->INTPOL &= ~(1 << GPIO_Pin);
			break;
		}	
		/* Configure the edge to trigger an interrupt */
	  case GPIO_IRQEdge:
		{
		  GPIOx->INTMASK &= ~(1 << GPIO_Pin);
			GPIOx->INTTYPE |= (1 << GPIO_Pin);
			GPIOx->INTBV |= (1 << GPIO_Pin);
			break;
		}	
		/* Interrupt mask*/
		case GPIO_IRQDisable:
		{
		  GPIOx->INTMASK |= (1 << GPIO_Pin);
			break;
		}
		default:
			break;
	}   
}

/**
  * @brief  Checks whether gpio pinx original interrupt flag is set or not.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @retval The new state of pin original interrupt Status(SET or RESET).
  */
FlagStatus GPIO_GetOriginalStatus(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if ((GPIOx->RIS & (1 << GPIO_Pin)) != (uint32_t)RESET)
	{
	  bitstatus = SET;
	}
	else
	{
	  bitstatus = RESET;
	}
	return bitstatus;
}

/**
  * @brief  Clears the pin original interrupt flag.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_ClearOriginalStatus(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	GPIOx->RIS = (1 << GPIO_Pin);
}

/**
  * @brief  GPIO interrupt enable set.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void GPIO_EnableIRQ(PA_Type* GPIOx, uint16_t priority)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
	/* PA Interrupt enable */
	if (GPIOx == PA)
	{
    NVIC_ClearPendingIRQ(PA_IRQn);
    NVIC_SetPriority(PA_IRQn,priority);   
    NVIC_EnableIRQ(PA_IRQn);               
	}
	/* PB Interrupt enable */
	else if (GPIOx == PB)
	{
    NVIC_ClearPendingIRQ(PB_IRQn);
    NVIC_SetPriority(PB_IRQn,priority);   
    NVIC_EnableIRQ(PB_IRQn);               	  
	}
	/* PC Interrupt enable */
	else if (GPIOx == PC)
	{
    NVIC_ClearPendingIRQ(PC_IRQn);
    NVIC_SetPriority(PC_IRQn,priority);   
    NVIC_EnableIRQ(PC_IRQn);              	  
	}
  /* PF Interrupt enable */	
	else if (GPIOx == PF)
	{
      NVIC_ClearPendingIRQ(PF_IRQn);
      NVIC_SetPriority(PF_IRQn,priority);   
      NVIC_EnableIRQ(PF_IRQn);              
	}
}

/**
  * @brief  GPIO interrupt disenable set.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DisableIRQ(PA_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
	/* PA Interrupt disable */
	if (GPIOx == PA)
	{
    NVIC_DisableIRQ(PA_IRQn);               
	}
	/* PB Interrupt disable */
	else if (GPIOx == PB)
	{   
    NVIC_DisableIRQ(PB_IRQn);               	  
	}
	/* PC Interrupt disable */
	else if (GPIOx == PC)
	{  
    NVIC_DisableIRQ(PC_IRQn);              	  
	}
  /* PF Interrupt disable */	
	else if (GPIOx == PF)
	{
		NVIC_DisableIRQ(PF_IRQn);              
	}			
}

/**
  * @brief  Checks whether gpio pinx  interrupt flag is set or not.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @retval The new state of pin interrupt (SET or RESET).
  */
ITStatus GPIO_GetIRQStatus(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  ITStatus bitstatus = RESET;
  /* Check the parameters */	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if ((GPIOx->MIS & (1 << GPIO_Pin)) != (uint32_t)RESET)
	{
	  bitstatus = SET;
	}
	else
	{
	  bitstatus = RESET;
	}
	return bitstatus;
}

/**
  * @brief  Clears the pin  interrupt flag.
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_ClearIRQStatus(PA_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	GPIOx->MIS = (1 << GPIO_Pin);
}


/**
  * @brief  Clears the all pinx  interrupt flag of GPIOx. 
  * @param  GPIOx: where x can be (A.B.C.F) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClearAllIRQStatus(PA_Type* GPIOx)
{
	/* Check the parameters */	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
	GPIOx->RIS = 0xffff;
	GPIOx->MIS = 0xffff;
}

