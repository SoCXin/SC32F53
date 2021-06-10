/**
  ******************************************************************************
  * @file    sc32f53xx_uart.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    22-05-2019
  * @brief   This file provides all the UART firmware functions.
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
#include "sc32f53xx_uart.h"
#include "sc32f53xx_clock.h"

#define UARTLCR_H_CLEAR_Mask           ((uint16_t)0xFF11)        /*!< UART UARTLCR_H Mask  */ 
#define UARTCR_CLEAR_Mask              ((uint16_t)0x3CFF)        /*!< UART UARTCR Mask  */ 
							

/**
  * @brief  Initializes the UARTx peripheral according to the specified
  *         parameters in the UART_InitStruct .
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure
  *         that contains the configuration information for the specified UART 
  *         peripheral.
  * @retval None
  */
void UART_Init(UART1_Type* UARTx, UART_InitTypeDef* UART_InitStruct)
{
  uint32_t tmpreg = 0x00, pclk01_value = 0x00;  
  uint32_t integerdivider = 0x00;
  uint16_t fractionaldivider = 0x00;
	
	/* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_BAUDRATE(UART_InitStruct->UART_BaudRate));  
  assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
  assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
  assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
  assert_param(IS_UART_MODE(UART_InitStruct->UART_Mode));
  assert_param(IS_UART_HARDWARE_FLOW_CONTROL(UART_InitStruct->UART_HardwareFlowControl));

/*---------------------------- UART BRR Configuration -----------------------*/
  /* Configure the UART Baud Rate -------------------------------------------*/
	pclk01_value = CLK_GetPclk01Freq();  //Get the UART Clock
	
	/* Determine the integer part */
	integerdivider =(uint32_t)(pclk01_value / (16 * UART_InitStruct->UART_BaudRate));
	UARTx->UARTIBRD =(uint16_t) integerdivider;
	/* Determine the fractional part */
//	fractionaldivider = (pclk01_value % (16 * UART_InitStruct->UART_BaudRate)) * 64;
	fractionaldivider = (uint16_t)((((pclk01_value%(16*UART_InitStruct->UART_BaudRate))<<7)+(16*UART_InitStruct->UART_BaudRate))/(UART_InitStruct->UART_BaudRate<<5));
	UARTx->UARTFBRD = (uint8_t)fractionaldivider;		
/*---------------------------- UART UARTLCR_H Configuration -----------------------*/
  tmpreg = UARTx->UARTLCR_H;
  /* Clear PE, EPS, STP2, WLEN, SPS bits */
  tmpreg &= UARTLCR_H_CLEAR_Mask;
  /* Configure the UART StopBits, WordLength, Parity ------------*/
  tmpreg = (uint32_t)(UART_InitStruct->UART_StopBits | UART_InitStruct->UART_WordLength |
						UART_InitStruct->UART_Parity);

/* Write to UART UARTLCR_H */
  UARTx->UARTLCR_H = (uint16_t)tmpreg;	
	
/*---------------------------- UART UARTCR Configuration -----------------------*/
  tmpreg = UARTx->UARTCR;
  /* Clear CTSE, RTSE, TXE and RXE bits */
  tmpreg &= UARTCR_CLEAR_Mask;
  /* Set CTSE and RTSE bits according to USART_HardwareFlowControl value */
  /* Set TE and RE bits according to USART_Mode value */
	tmpreg |= (uint32_t)(UART_InitStruct->UART_Mode | UART_InitStruct->UART_HardwareFlowControl);
	
  /* Write to UART UARTCR */
  UARTx->UARTCR = (uint16_t)tmpreg;

}	


/**
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure
  *         which will be initialized.
  * @retval None
  */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
  /* UART_InitStruct members default value */
  UART_InitStruct->UART_BaudRate = 0;
  UART_InitStruct->UART_WordLength = UART_WordLength_8b;
  UART_InitStruct->UART_StopBits = UART_StopBits_1;
  UART_InitStruct->UART_Parity = UART_Parity_No ;
  UART_InitStruct->UART_Mode = UART_Mode_RX | UART_Mode_TX;
  UART_InitStruct->UART_HardwareFlowControl = UART_HardwareFlowControl_None;  
}

/**
  * @brief  Enables or disables the specified UART peripheral.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  NewState: new state of the UARTx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_Cmd(UART1_Type* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
			/* Enable the selected UART by setting the UARTEN bit in the UARTCR register */
			UARTx->UARTCR_b.UARTEN = 1;
  }
  else
  {
			/* Disable the selected UART by clearing the UARTEN bit in the UARTCR register */
			UARTx->UARTCR_b.UARTEN = 0;
  }
}

/**
  * @brief  Enables or disables the loopback mode.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  NewState: new state of the loopback mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_LBCmd(UART1_Type* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the loopback mode by setting the LBE bit in the UARTCR register */
    UARTx->UARTCR_b.LBE = 1;
  }
  else
  {
    /* Disable the loopback mode by clearing the LBE bit in the UARTCR register */
    UARTx->UARTCR_b.LBE = 0;
  }
}

/**
  * @brief  Enables or disables the specified UART FIFO.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  NewState: new state of the UARTx FIFO.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_FIFO_Cmd(UART1_Type* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
			UARTx->UARTLCR_H_b.FEN = 1;
  }
  else
  {
			UARTx->UARTLCR_H_b.FEN = 0;
  }
}

/**
  * @brief  Config the specified UART RX and TX FIFO Trigger interrupt selection.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  RXFIFO_Sel: new state of the UARTx RX FIFO Trigger interrupt selection.
  *         This parameter can be one of the following values:
	* 	UART_RXFIFO_Eighth: Greater than or equal to eighth Trigger
	* 	UART_RXFIFO_Quarter: Greater than or equal to Quarter Trigger
	* 	UART_RXFIFO_Half: Greater than or equal to Half Trigger
	* 	UART_RXFIFO_ThreeQuarters: Greater than or equal to ThreeQuarters Trigger
	* 	UART_RXFIFO_SevenEighths: Greater than or equal to SevenEighths Trigger
	* @param  TXFIFO_Sel: new state of the UARTx TX FIFO Trigger interrupt selection.
  *         This parameter can be one of the following values:
	* 	UART_TXFIFO_Eighth: Greater than or equal to eighth Trigger
	* 	UART_TXFIFO_Quarter: Greater than or equal to Quarter Trigger
	* 	UART_TXFIFO_Half: Greater than or equal to Half Trigger
	* 	UART_TXFIFO_ThreeQuarters: Greater than or equal to ThreeQuarters Trigger
	* 	UART_TXFIFO_SevenEighths: Greater than or equal to SevenEighths Trigger 
  * @retval None
  */
void UART_FIFO_Config(UART1_Type* UARTx, uint16_t RXFIFO_Sel, uint16_t TXFIFO_Sel)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_RX_IT_FIFO_Select(RXFIFO_Sel));
  assert_param(IS_UART_TX_IT_FIFO_Select(TXFIFO_Sel));
	
  UARTx->UARTIFLS_b.RXIFLSEL = RXFIFO_Sel;
	UARTx->UARTIFLS_b.TXIFLSEL = TXFIFO_Sel;
}


/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  Data: the data to transmit.
  * @retval None
  */
void UART_SendData(UART1_Type* UARTx, uint8_t Data)
{
		/* Check the parameters */
		assert_param(IS_UART_ALL_PERIPH(UARTx));
		assert_param(IS_UART_DATA(Data)); 
    
		/* Transmit Data */
		UARTx->UARTDR = (uint8_t)Data;
}

/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @retval The received data.
  */
uint8_t UART_ReceiveData(UART1_Type* UARTx)
{
	uint8_t receive_data;
	
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  /* Receive Data */
	receive_data = UARTx->UARTDR;
	return receive_data;  
}

/**
  * @brief  Enables or disables the specified UART send break.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  NewState: new state of the send break sign.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_SendBreak_Cmd(UART1_Type* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
			/* Send break characters */
			UARTx->UARTLCR_H |= UART1_UARTLCR_H_BRK_Msk;
  }
  else
  {
			/* Send break characters */
			UARTx->UARTLCR_H &= ~UART1_UARTLCR_H_BRK_Msk;
  }
}


/**
  * @brief  get the specified UART  Error flag.
  * @param  UARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *    UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  Error: specifies the UART Error source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_Error_Overrun
  *     @arg UART_Error_Break
  *     @arg UART_Error_Parity
  *     @arg UART_Error_Farming
	*     @arg UART_Error_All
  * @retval the specified UART  Error flag(set or reset).
  */
FlagStatus UART_GetErrFlag(UART1_Type* UARTx, uint16_t Error)
{
  uint32_t itmask;
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_Error(Error));
	
	itmask = UARTx->UARTDR;
	itmask &= Error;
  if ((itmask != (uint16_t)RESET))
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
  * @brief  Clear the specified UART all Error flag.
  * @param  UARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *    UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  Error: specifies the UART Error source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_Error_Overrun
  *     @arg UART_Error_Break
  *     @arg UART_Error_Parity
  *     @arg UART_Error_Farming
	*     @arg UART_Error_ALL
  * @retval None.
  */
void UART_ClearErrorBit(UART1_Type* UARTx,uint16_t Error)
{
		 /* Check the parameters */
		assert_param(IS_UART_ALL_PERIPH(UARTx));
		assert_param(IS_UART_Error(Error));
	
		UARTx->UARTRSR |= (Error>>8);
}

/**
  * @brief  Checks whether the specified UART work status is set or reset.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  WorkStatus: specifies the UART work status to check.
  *   This parameter can be one of the following values:
  *     @arg UART_WorkStatus_CTS:  Reset to send 
  *     @arg UART_WorkStatus_BUSY:  UART busy Flag
  *     @arg UART_WorkStatus_RXFE:  Receive FIFO null flag
  *     @arg UART_WorkStatus_TXFE: Send FIFO null flag
  *     @arg UART_WorkStatus_RXFF:  Receive FIFO full Flag
  *     @arg UART_WorkStatus_TXFF:  Send FIFO full Flag
  * @retval The new state of UART work status(SET or RESET).
  */
FlagStatus UART_GetWorkStatus(UART1_Type* UARTx, uint16_t WorkStatus)
{
  uint32_t itmask;
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_WorkStatus(WorkStatus));
	
	itmask = UARTx->UARTFR;
	itmask &= WorkStatus;
  if ((itmask != (uint16_t)RESET))
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
  * @brief  Checks whether the specified UART Original status has occurred or not.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  ITSource: specifies the UART interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_IT_OE:  OverRun Error interrupt
  *     @arg UART_IT_BE:  Break Error Interrupt
  *     @arg UART_IT_PE:  Parity Error interrupt
  *     @arg UART_IT_FE:  Framing Error Interrupt
  *     @arg UART_IT_RT:  Receive Ttimeout Interrupt
  *     @arg UART_IT_Transmit: Transmit Interrupt
  *     @arg UART_IT_Receive:  Transmit Interrupt
  *     @arg UART_IT_nUARTCTS:  nUARTCTS Modem Interrupt
  * @retval The new state of UART Original status(SET or RESET).
  */
FlagStatus UART_GetOriginalStatus(UART1_Type* UARTx, uint16_t ITSource)
{
  uint32_t itmask;
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_Get_IT(ITSource));
	
	itmask = UARTx->UARTRIS;
	itmask &= ITSource;
  if ((itmask != (uint16_t)RESET))
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
  * @brief  UART interrupt enable set.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  priority: specifies the priority of an interrupt.
  * @retval None
  */
void UART_EnableIRQ(UART1_Type* UARTx, uint16_t priority)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	
	/* UART1 Interrupt enable */
	if (UARTx == UART1)
	{
    NVIC_ClearPendingIRQ(UART1_IRQn);
    NVIC_SetPriority(UART1_IRQn,priority);   
    NVIC_EnableIRQ(UART1_IRQn);               
	}
	/* UART2 Interrupt enable */
	else if (UARTx == UART2)
	{
    NVIC_ClearPendingIRQ(UART2_IRQn);
    NVIC_SetPriority(UART2_IRQn,priority);   
    NVIC_EnableIRQ(UART2_IRQn);               	  
	}
	/* UART3 Interrupt enable */
	else if (UARTx == UART3)
	{
    NVIC_ClearPendingIRQ(UART3_IRQn);
    NVIC_SetPriority(UART3_IRQn,priority);   
    NVIC_EnableIRQ(UART3_IRQn);              	  
	}
	/* UART4 Interrupt enable */
	else if (UARTx == UART4)
	{
    NVIC_ClearPendingIRQ(UART4_IRQn);
    NVIC_SetPriority(UART4_IRQn,priority);   
    NVIC_EnableIRQ(UART4_IRQn);               	  
	}
	/* UART5 Interrupt enable */
	else if (UARTx == UART5)
	{
    NVIC_ClearPendingIRQ(UART5_IRQn);
    NVIC_SetPriority(UART5_IRQn,priority);   
    NVIC_EnableIRQ(UART5_IRQn);              	  
	}		
  /* UART6 Interrupt enable */	
	else
	{
		if (UARTx == UART6)
		{
      NVIC_ClearPendingIRQ(UART6_IRQn);
      NVIC_SetPriority(UART6_IRQn,priority);   
      NVIC_EnableIRQ(UART6_IRQn);              
    }			
	}
}

/**
  * @brief  UART interrupt disenable set.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *     This parameter can be one of the following values:
  *     UART1, UART2, UART3, UART4, UART5 or UART6.
  * @retval None
  */
void UART_DisableIRQ(UART1_Type* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
	
	/* UART1 Interrupt disable */
	if (UARTx == UART1)
	{
    NVIC_DisableIRQ(UART1_IRQn);               
	}
	/* UART2 Interrupt disable */
	else if (UARTx == UART2)
	{   
    NVIC_DisableIRQ(UART2_IRQn);               	  
	}
	/* UART3 Interrupt disable */
	else if (UARTx == UART3)
	{  
    NVIC_DisableIRQ(UART3_IRQn);              	  
	}
	/* UART4 Interrupt disable */
	else if (UARTx == UART4)
	{   
    NVIC_DisableIRQ(UART4_IRQn);               	  
	}
	/* UART5 Interrupt disable */
	else if (UARTx == UART5)
	{  
    NVIC_DisableIRQ(UART5_IRQn);              	  
	}
  /* UART6 Interrupt disable */	
	else
	{
		if (UARTx == UART6)
		{
      NVIC_DisableIRQ(UART6_IRQn);              
    }			
	}
}


/**
  * @brief  Enable or Disable the specified UART interrupt source.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *    UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  ITSource: specifies the UART interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_IT_OE:  OverRun Error interrupt
  *     @arg UART_IT_BE:  Break Error Interrupt
  *     @arg UART_IT_PE:  Parity Error interrupt
  *     @arg UART_IT_FE:  Framing Error Interrupt
  *     @arg UART_IT_RT:  Receive Ttimeout Interrupt
  *     @arg UART_IT_Transmit: Transmit Interrupt
  *     @arg UART_IT_Receive:  Transmit Interrupt
  *     @arg UART_IT_nUARTCTS:  nUARTCTS Modem Interrupt
	* @param  NewState: new state of the specified UART interrupt source. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void UART_ITCmd(UART1_Type* UARTx, uint16_t ITSource, FunctionalState NewState)
{
		assert_param(IS_UART_ALL_PERIPH(UARTx));
		assert_param(IS_UART_IT(ITSource));
		assert_param(IS_FUNCTIONAL_STATE(NewState));
	
		if (NewState != DISABLE)
		{			
				UARTx->UARTIMSC |= ITSource;
		}
		else
		{
				UARTx->UARTIMSC &= ~ITSource;
		}
}



/**
  * @brief  Checks whether the specified UART  interrupt has occurred or not.
  * @param  UARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  ITSource: specifies the UART interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_IT_OE:  OverRun Error interrupt
  *     @arg UART_IT_BE:  Break Error Interrupt
  *     @arg UART_IT_PE:  Parity Error interrupt
  *     @arg UART_IT_FE:  Framing Error Interrupt
  *     @arg UART_IT_RT:  Receive Ttimeout Interrupt
  *     @arg UART_IT_Transmit: Transmit Interrupt
  *     @arg UART_IT_Receive:  Transmit Interrupt
	*     @arg UART_IT_nUARTCTS:  nUARTCTS Modem Interrupt
  * @retval The new state of UART IT status(SET or RESET).
  */
ITStatus UART_GetITStatus(UART1_Type* UARTx, uint16_t ITSource)
{
  uint32_t itmask;
  ITStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_Get_IT(ITSource));
	
	itmask = UARTx->UARTMIS;
	itmask &= ITSource;
  if ((itmask != (uint16_t)RESET))
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
  * @brief  Clear the specified UART interrupt Flag.
  * @param  UARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *    UART1, UART2, UART3, UART4,UART5 or UART6.
  * @param  ITSource: specifies the UART interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg UART_IT_OE:  OverRun Error interrupt
  *     @arg UART_IT_BE:  Break Error Interrupt
  *     @arg UART_IT_PE:  Parity Error interrupt
  *     @arg UART_IT_FE:  Framing Error Interrupt
  *     @arg UART_IT_RT:  Receive Ttimeout Interrupt
  *     @arg UART_IT_Transmit: Transmit Interrupt
  *     @arg UART_IT_Receive:  Transmit Interrupt
  *     @arg UART_IT_nUARTCTS:  nUARTCTS Modem Interrupt
	*     @arg UART_IT_ALL:  all Interrupt
  * @retval None.
  */
void UART_ClearITFlag(UART1_Type* UARTx, uint16_t ITSource)
{
		assert_param(IS_UART_ALL_PERIPH(UARTx));
		assert_param(IS_UART_Get_IT(ITSource));
	
		UARTx->UARTICR = ITSource;
}


/**
  * @brief  Enables or disables the UARTx DMA interface.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  UART_DMAReq: specifies the DMA request.
  *   This parameter can be any combination of the following values:
  *     @arg UART_DMAReq_TX: UART DMA transmit request
  *     @arg UART_DMAReq_RX: UART DMA receive request
  * @param  NewState: new state of the DMA Request sources.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_DMACmd(UART1_Type* UARTx, uint16_t UART_DMAReq, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_DMAREQ(UART_DMAReq));  
  assert_param(IS_FUNCTIONAL_STATE(NewState)); 
  if (NewState != DISABLE)
  {
    /* Enable the DMA transfer for selected requests by setting the DMAT and/or
       DMAR bits in the UART UARTDMACR register */
    UARTx->UARTDMACR |= UART_DMAReq;
  }
  else
  {
    /* Disable the DMA transfer for selected requests by clearing the DMAT and/or
       DMAR bits in the UART UARTDMACR register */
    UARTx->UARTDMACR &= (uint16_t)~UART_DMAReq;
  }
}

/**
  * @brief  Enables or disables the UARTx DMA on error processing.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  NewState: new state of the UARTx DMA on error processing.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_DMAOnErr_Cmd(UART1_Type* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState)); 
  if (NewState != DISABLE)
  {
    UARTx->UARTDMACR_b.DMA_ERROR = 1;
  }
  else
  {
    UARTx->UARTDMACR_b.DMA_ERROR = 0;
  }
}

