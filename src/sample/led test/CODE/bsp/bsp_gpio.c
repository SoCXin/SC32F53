#include "bsp_gpio.h"


void LED_GPIO_Config(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //初始化结构体变量

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveHigh;
	  GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;
		/*调用库函数，初始化PB1*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM1	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
		/*调用库函数，初始化PB2*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM2	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	
		/*调用库函数，初始化PB10*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM3	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		/*调用库函数，初始化PB11*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM4

		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	
		/*调用库函数，初始化PA13*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG1	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	
		/*调用库函数，初始化PA9*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG2	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	
		/*调用库函数，初始化PA10*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG3	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		/*调用库函数，初始化PA11*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG4	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
		/*调用库函数，初始化PA12*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG5	
		
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	
		/*调用库函数，初始化PF6*/
		GPIO_Init(PF , &GPIO_InitStructure);		  //SEG7
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	
		/*调用库函数，初始化PF7*/
		GPIO_Init(PF , &GPIO_InitStructure);	  //SEG8
		
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(USR1_EXINT_PORT,USR1_EXINT_PIN,USR1_EXINT_IRQ);   //USR1为外部中断 下降沿触发
		GPIO_ClearAllIRQStatus(USR1_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(USR1_EXINT_PORT, USR1_EXINT_PIN);		//Enable the USR1 interrupt	
}


