#include "bsp_led.h"

void LED_FUNC(void)
{
		GPIO_SetAFMode(PB,GPIO_Pin_1,GPIO_AF6);       //PB1->LED_COM1
		GPIO_SetAFMode(PB,GPIO_Pin_2,GPIO_AF6);       //PB2->LED_COM2
		GPIO_SetAFMode(PB,GPIO_Pin_10,GPIO_AF6);      //PB10->LED_COM3
		GPIO_SetAFMode(PB,GPIO_Pin_11,GPIO_AF6);      //PB11->LED_COM4
		GPIO_SetAFMode(PA,GPIO_Pin_8,GPIO_AF6);       //PA8->LED_SEG1
		GPIO_SetAFMode(PA,GPIO_Pin_9,GPIO_AF6);       //PA9->LED_SEG2
		GPIO_SetAFMode(PA,GPIO_Pin_10,GPIO_AF6);      //PA10->LED_SEG3
		GPIO_SetAFMode(PA,GPIO_Pin_11,GPIO_AF6);      //PA11->LED_SEG4
		GPIO_SetAFMode(PA,GPIO_Pin_12,GPIO_AF6);      //PA12->LED_SEG5
		GPIO_SetAFMode(PF,GPIO_Pin_6,GPIO_AF6);       //PF6->LED_SEG7
		GPIO_SetAFMode(PF,GPIO_Pin_7,GPIO_AF6);       //PF7->LED_SEG8
}

void LED_UPUDSet()
{
		GPIO_PUPDConfig(PB,GPIO_Pin_1,GPIO_PU);     //COM1
		GPIO_PUPDConfig(PB,GPIO_Pin_2,GPIO_PU);     //COM2
		GPIO_PUPDConfig(PB,GPIO_Pin_10,GPIO_PU);    //COM3
		GPIO_PUPDConfig(PB,GPIO_Pin_11,GPIO_PU);    //COM4
		
		GPIO_PUPDConfig(PA,GPIO_Pin_8,GPIO_PD);     //SEG1
		GPIO_PUPDConfig(PA,GPIO_Pin_9,GPIO_PD);     //SEG2
		GPIO_PUPDConfig(PA,GPIO_Pin_10,GPIO_PD);    //SEG3
		GPIO_PUPDConfig(PA,GPIO_Pin_11,GPIO_PD);    //SEG4
		GPIO_PUPDConfig(PA,GPIO_Pin_12,GPIO_PD);    //SEG5
		GPIO_PUPDConfig(PF,GPIO_Pin_6,GPIO_PD);     //SEG7
		GPIO_PUPDConfig(PF,GPIO_Pin_7,GPIO_PD);     //SEG8
}

void LED_Mode_Config(void)
{
		LED_ConfigTypeDef LED_ConfigStructure;
		LED_ConfigStructInit(&LED_ConfigStructure);
	
		LED_ConfigStructure.LED_MODE = LED_ModeSel_1;
		LED_ConfigStructure.LED_UPDMODE = LED_COMIF_Update;
		LED_ConfigStructure.LED_LEDITMD = LED_Scan_Continue;
		LED_ModeConfig(&LED_ConfigStructure);
}

void LED_Init(void)
{
		LED_FUNC();   				//管脚复用
		LED_UPUDSet();				//选择上下拉
		LED_Mode_Config();		//初始化模式
		LED_BasicConfig(Debug_Clock_Width,Debug_Dead_Width);	
		LED_COMSEGConfig(Debug_LED_COM,Debug_LED_SEG);
}	

