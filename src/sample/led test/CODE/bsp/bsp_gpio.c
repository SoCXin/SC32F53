#include "bsp_gpio.h"


void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //��ʼ���ṹ�����

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveHigh;
	  GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;
		/*���ÿ⺯������ʼ��PB1*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM1	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
		/*���ÿ⺯������ʼ��PB2*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM2	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	
		/*���ÿ⺯������ʼ��PB10*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM3	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		/*���ÿ⺯������ʼ��PB11*/
		GPIO_Init(PB , &GPIO_InitStructure);	  //COM4

		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	
		/*���ÿ⺯������ʼ��PA13*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG1	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	
		/*���ÿ⺯������ʼ��PA9*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG2	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	
		/*���ÿ⺯������ʼ��PA10*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG3	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		/*���ÿ⺯������ʼ��PA11*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG4	
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
		/*���ÿ⺯������ʼ��PA12*/
		GPIO_Init(PA , &GPIO_InitStructure);	  //SEG5	
		
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	
		/*���ÿ⺯������ʼ��PF6*/
		GPIO_Init(PF , &GPIO_InitStructure);		  //SEG7
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	
		/*���ÿ⺯������ʼ��PF7*/
		GPIO_Init(PF , &GPIO_InitStructure);	  //SEG8
		
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(USR1_EXINT_PORT,USR1_EXINT_PIN,USR1_EXINT_IRQ);   //USR1Ϊ�ⲿ�ж� �½��ش���
		GPIO_ClearAllIRQStatus(USR1_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(USR1_EXINT_PORT, USR1_EXINT_PIN);		//Enable the USR1 interrupt	
}


