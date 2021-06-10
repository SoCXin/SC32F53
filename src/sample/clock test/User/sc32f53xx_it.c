/**
  ******************************************************************************
  * @file    GPIO/IOToggle/sc32f53128_it.h 
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
#include "sc32f53xx_gpio.h"

uint8_t Cnt=0;
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

void PA_IRQHandler(void)
{
		if(GPIO_GetIRQStatus(PA,GPIO_Pin_0) !=0x00)     //PA0´¥·¢
		{		
				GPIO_ClearIRQStatus(PA,GPIO_Pin_0);      //Ð´1ÇåÁã
				Flag=1;
				Cnt++;
				if(Cnt>5)
						Cnt=1;
		}	
}

/******************************************************************************/
/*                 SC32F53128 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
