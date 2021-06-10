#include "bsp_uart.h"
#include "bsp_clock.h"

uint8_t	Data[8] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
uint8_t Receive_Data;
char  String[] = "Silan--53128QSB_UARTDemoProject";
uint8_t DataNum = 8;
uint16_t HalfWordData = 0x1234;

void Delay(uint32_t a)
{
		while(a--);		
}

int main()
{		
	
		Set_SYSCLK();   //默认RCH作为系统时钟  APB01=16M/2	
	
		UART_Config();
		MCLK_Out();
	
		printf("\r\n************************************************\r\n");
		printf("Start communication \r\n");
		printf("************************************************\r\n");
		while(1)
		{
				while(!UART_GetWorkStatus(DEBUG_UARTx,UART_WorkStatus_RXFF));
				Receive_Data = UART_ReceiveData(DEBUG_UARTx);   
				switch(Receive_Data)
				{
						case 0x66:
						{
								printf("DATA_0 is OK\r\n");
								break;
						}					   
						case 0x88:
						{
								UART_SendArray(DEBUG_UARTx,Data,DataNum);    //发送一个8位数组
								printf("\r\n");
								break;
						}
						case 0x99:
						{
								UART_SendString(DEBUG_UARTx,String);  //发送一个字符串
								printf("\r\n");
								break;
						}	
						case 0xAA:
						{
								UART_SendHalfWord(DEBUG_UARTx,HalfWordData);  //发送一个16位数据
								printf("\r\n");
								break;
						}			
						default:
						{
								UART_SendData(DEBUG_UARTx,Receive_Data);
								printf("\r\n");
								break;
						}							
				}
		}
}

