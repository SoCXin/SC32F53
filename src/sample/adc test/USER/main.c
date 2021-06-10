#include "bsp_adc.h"
#include "bsp_uart.h"
#include "bsp_clock.h"

uint8_t Receive_Data;

void delay(uint32_t time_data);

int main()
{
		uint16_t result;
		
		Set_SYSCLK();
		CLK_APB23PeriphClockCmd(CLK_APB23Periph_ADC,ENABLE);    //使能ADC时钟
		GPIO_SetOutEn(ADC_Assist_PORT, ADC_Assist_PIN);      
		GPIO_ResetBits(ADC_Assist_PORT,ADC_Assist_PIN);   
		UART_Config();
		SEQA_ADCx_Init();
		while(1)
		{
				while(!UART_GetWorkStatus(DEBUG_UARTx,UART_WorkStatus_RXFF));
				Receive_Data = UART_ReceiveData(DEBUG_UARTx); 
				switch(Receive_Data)
				{
						case(0x55): 
								ADC_SEQAENCmd(ENABLE);   			
								while(!ADC_CHxComplete_GetStatus(ADC_CHANNEL));	 //等待通道2 AD转换完成		  		
								result = ADC_ReadData(ADC_CHANNEL);	
								ADC_SEQAENCmd(DISABLE);
								UART_SendData(DEBUG_UARTx,(result>>8));		//发送高8位
								UART_SendData(DEBUG_UARTx,(result&0xff));	//发送低8位
								break;
						default:
								UART_SendData(DEBUG_UARTx,Receive_Data);  
								break;					
				}				
		}
}


void delay(uint32_t time_data)
{
	uint32_t i;
	
	for (i=0;i<time_data;i++);
}

