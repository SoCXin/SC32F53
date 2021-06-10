/**
  ******************************************************************************
  * @file    GPIO/IOToggle/sc32f53xx_it.h 
  * @author  MCD Application Team
  * @version V0.0.0
  * @date    10-10-2019
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_it.h" 
#include "bsp_uart.h"

uint8_t Receive_Data;
uint8_t Flag;
 
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
}

void UART1_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}

void UART2_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}

void UART3_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}

void UART4_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}

void UART5_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}

void UART6_IRQHandler(void)
{
		if(UART_GetITStatus(DEBUG_UARTx,UART_IT_Receive))
		{
				Flag=1;
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);
				UART_ClearITFlag(DEBUG_UARTx,UART_IT_Receive);
		}
}
/******************************************************************************/
/*                 SC32F53128 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
