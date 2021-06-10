#include "bsp_uart.h"
#include "bsp_clock.h"
#include "bsp_dma.h"


extern uint8_t D_data1[1024];
extern uint8_t DoneFlag;

int main()
{		
		Set_SYSCLK();   //Ĭ��RCH��Ϊϵͳʱ��  P01b=16M/2	
	
		UART_Config();
		MCLK_Out();
		DMA_UARTx_RX_Channelx_Config();
	
		printf("\r\n************************************************\r\n");
		printf("Start communication \r\n");
		printf("************************************************\r\n");
		while(1)
		{			
				if(DoneFlag)   //�������һ�δ���
				{
						DoneFlag=0;
						printf("\r\n************************************************\r\n");
						printf("It is ok \r\n");
						printf("************************************************\r\n");	
				}		
		}
}

