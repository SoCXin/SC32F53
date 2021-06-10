#include "bsp_uart.h"


//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;
//定义_sys_exit()以避免使用半主机模式    

void _sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
	while((DEBUG_UARTx->UARTFR_b.BUSY & 0X1) == 1);//循环发送,直到发送完毕   
	DEBUG_UARTx->UARTDR_b.DATA = (uint8_t) ch;      
	return ch;
}

void _ttywrch(int ch)
{
ch = ch;
}
#endif


/**
  * @brief  USART GPIO 配置,工作参数配置
  * @param  无
  * @retval 无
  */
void UART_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		UART_InitTypeDef UART_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //初始化结构体变量
		UART_StructInit(&UART_InitStructure);
	
		// 打开串口外设的时钟
		DEBUG_UART_APBxClkCmd(DEBUG_UART_CLK,ENABLE);
		
		GPIO_SetAFMode(DEBUG_UART_TX_GPIO_PORT,DEBUG_UART_TX_GPIO_PIN,GPIO_AF0);
		GPIO_SetAFMode(DEBUG_UART_RX_GPIO_PORT,DEBUG_UART_RX_GPIO_PIN,GPIO_AF0);
		// 将USART Tx的GPIO配置为推挽复用模式		
		GPIO_InitStructure.GPIO_FiltClk = GPIO_FiltClk_Div1;  	//GPIO时钟不分频
		GPIO_InitStructure.GPIO_Pin = DEBUG_UART_TX_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;   						//配置成输出
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;						//GPIO快速
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;					//低驱动电流
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;						//开漏模式无效
		GPIO_Init(DEBUG_UART_TX_GPIO_PORT, &GPIO_InitStructure);

		// 将USART Rx的GPIO配置为浮空输入模式
		GPIO_InitStructure.GPIO_FiltClk = GPIO_FiltClk_Div1;  	//GPIO时钟不分频
		GPIO_InitStructure.GPIO_Filt = GPIO_Filt_No;            //输入不滤波
		GPIO_InitStructure.GPIO_Pin = DEBUG_UART_RX_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirIn;   						//配置成输入	
		GPIO_InitStructure.GPIO_PUPD = GPIO_NoPUPD;             //输入悬空
		GPIO_InitStructure.GPIO_RevIn = GPIO_UnreverseIn;						//正向输入
		GPIO_Init(DEBUG_UART_RX_GPIO_PORT, &GPIO_InitStructure);

		UART_ClearErrorBit(DEBUG_UARTx,UART_Error_ALL);      // clear all error	
		UART_ClearITFlag(DEBUG_UARTx,UART_IT_ALL);		// clear all IT flag
	
		UART_InitStructure.UART_BaudRate = DEBUG_UART_BAUDRATE;
		UART_InitStructure.UART_WordLength = UART_WordLength_8b;
		UART_InitStructure.UART_StopBits = UART_StopBits_1;
		UART_InitStructure.UART_Mode = UART_Mode_RX | UART_Mode_TX;
		UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;
		UART_InitStructure.UART_Parity = UART_Parity_No;
		UART_Init(DEBUG_UARTx, &UART_InitStructure);
			
//		UART_EnableIRQ(DEBUG_UARTx,1);    //UART中断配置、使能
//		UART_ITCmd(DEBUG_UARTx,UART_IT_Receive,ENABLE);   // 开启Receive中断
		
		UART_Cmd(DEBUG_UARTx,ENABLE);  		//使能UART
}


/****************** 发送8位的数组 ************************/
void UART_SendArray( UART1_Type* UARTx, uint8_t *array, uint16_t num)
{
  uint8_t i;
	
	for(i=0; i<num; i++)
  {
	    /* 发送一个字节数据到USART */
	    UART_SendData(UARTx,array[i]);	  
  }
}

/*****************  发送字符串 **********************/
void UART_SendString(UART1_Type* UARTx, char *str)
{
	unsigned int k=0;
  do 
  {
      UART_SendData(UARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
}

/*****************  发送一个16位数 **********************/
void UART_SendHalfWord( UART1_Type* UARTx, uint16_t ch)
{
	uint8_t Temp_H, Temp_L;
	
	/* 取出高八位 */
	Temp_H = (ch&0XFF00)>>8;
	/* 取出低八位 */
	Temp_L = ch&0XFF;
	
	/* 发送高八位 */
	UART_SendData(UARTx,Temp_H);	
	
	/* 发送低八位 */
	UART_SendData(UARTx,Temp_L);	
}
