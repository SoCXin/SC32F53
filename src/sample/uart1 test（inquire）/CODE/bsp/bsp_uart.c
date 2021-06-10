#include "bsp_uart.h"


//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    

void _sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((DEBUG_UARTx->UARTFR_b.BUSY & 0X1) == 1);//ѭ������,ֱ���������   
	DEBUG_UARTx->UARTDR_b.DATA = (uint8_t) ch;      
	return ch;
}

void _ttywrch(int ch)
{
ch = ch;
}
#endif


/**
  * @brief  USART GPIO ����,������������
  * @param  ��
  * @retval ��
  */
void UART_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		UART_InitTypeDef UART_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //��ʼ���ṹ�����
		UART_StructInit(&UART_InitStructure);
	
		// �򿪴��������ʱ��
		DEBUG_UART_APBxClkCmd(DEBUG_UART_CLK,ENABLE);
		
		GPIO_SetAFMode(DEBUG_UART_TX_GPIO_PORT,DEBUG_UART_TX_GPIO_PIN,GPIO_AF0);
		GPIO_SetAFMode(DEBUG_UART_RX_GPIO_PORT,DEBUG_UART_RX_GPIO_PIN,GPIO_AF0);
		// ��USART Tx��GPIO����Ϊ���츴��ģʽ		
		GPIO_InitStructure.GPIO_FiltClk = GPIO_FiltClk_Div1;  	//GPIOʱ�Ӳ���Ƶ
		GPIO_InitStructure.GPIO_Pin = DEBUG_UART_TX_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;   						//���ó����
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;						//GPIO����
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;					//����������
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;						//��©ģʽ��Ч
		GPIO_Init(DEBUG_UART_TX_GPIO_PORT, &GPIO_InitStructure);

		// ��USART Rx��GPIO����Ϊ��������ģʽ
		GPIO_InitStructure.GPIO_FiltClk = GPIO_FiltClk_Div1;  	//GPIOʱ�Ӳ���Ƶ
		GPIO_InitStructure.GPIO_Filt = GPIO_Filt_No;            //���벻�˲�
		GPIO_InitStructure.GPIO_Pin = DEBUG_UART_RX_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirIn;   						//���ó�����	
		GPIO_InitStructure.GPIO_PUPD = GPIO_NoPUPD;             //��������
		GPIO_InitStructure.GPIO_RevIn = GPIO_UnreverseIn;						//��������
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
			
//		UART_EnableIRQ(DEBUG_UARTx,1);    //UART�ж����á�ʹ��
//		UART_ITCmd(DEBUG_UARTx,UART_IT_Receive,ENABLE);   // ����Receive�ж�
		
		UART_Cmd(DEBUG_UARTx,ENABLE);  		//ʹ��UART
}


/****************** ����8λ������ ************************/
void UART_SendArray( UART1_Type* UARTx, uint8_t *array, uint16_t num)
{
  uint8_t i;
	
	for(i=0; i<num; i++)
  {
	    /* ����һ���ֽ����ݵ�USART */
	    UART_SendData(UARTx,array[i]);	  
  }
}

/*****************  �����ַ��� **********************/
void UART_SendString(UART1_Type* UARTx, char *str)
{
	unsigned int k=0;
  do 
  {
      UART_SendData(UARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
}

/*****************  ����һ��16λ�� **********************/
void UART_SendHalfWord( UART1_Type* UARTx, uint16_t ch)
{
	uint8_t Temp_H, Temp_L;
	
	/* ȡ���߰�λ */
	Temp_H = (ch&0XFF00)>>8;
	/* ȡ���Ͱ�λ */
	Temp_L = ch&0XFF;
	
	/* ���͸߰�λ */
	UART_SendData(UARTx,Temp_H);	
	
	/* ���͵Ͱ�λ */
	UART_SendData(UARTx,Temp_L);	
}
