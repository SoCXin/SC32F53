#include "bsp_clock.h"


void SysCLK_OSCH_Config(void)
{
		OSCH_ConfigTypeDef OSCH_InitStructure;
		OSCH_ConfigStructInit(&OSCH_InitStructure);
	
		OSCH_InitStructure.OSCH_InResist_ENABLE = ENABLE;
		OSCH_InitStructure.OSCH_Detection_ENABLE = DISABLE;
		OSCH_InitStructure.CRY_StableTime = OSCH_StableTime_4ms;
		OSCH_InitStructure.CRY_GainSelection = OSCH_GAIN_4_8M;
		CLK_OSCHConfig(&OSCH_InitStructure);
}

void SysCLK_OSCL_Config(void)
{
		OSCL_ConfigTypeDef OSCL_InitStructure;	
		OSCL_ConfigStructInit(&OSCL_InitStructure);
	
		OSCL_InitStructure.OSCL_Inverter_ENABLE = DISABLE;
		OSCL_InitStructure.OSCL_InResist_ENABLE = ENABLE;
		OSCL_InitStructure.OSCL_GainSelection = CRY_GAIN_Lowest;
		OSCL_InitStructure.OSCL_Filt_ENABLE = ENABLE;
		OSCL_InitStructure.OSCL_FastMode_ENABLE = DISABLE;
		OSCL_InitStructure.OSCL_Detection_ENABLE = ENABLE;
		CLK_OSCLConfig(&OSCL_InitStructure);
}

void SysCLK_PLL_Config(void)
{
		PLL_ConfigTypeDef PLL_InitStructure;
		PLL_ConfigStructInit(&PLL_InitStructure);
	
		PLL_InitStructure.PLL_Source = PLLSource_RCH;
		PLL_InitStructure.PLL_DIV = PLLDIV_16;
		PLL_InitStructure.PLL_MUL = PLLMUL_24;
		CLK_PLLConfig(&PLL_InitStructure);
}

/*
0h:rcl32k
1h:rch16m
2h:oscin
3h:xclkina
4h:xclkinb
5h:pllout
6h:pllrefclk
8h:sysclk
ah:fclk
*/
void MCLK_Out(void)
{
	GPIO_SetAFMode(PB,GPIO_Pin_3,GPIO_AF3);    		// PB3复用成xclkout
	GPIO_SetBits(PB,GPIO_Pin_3);

//	GPIO_SetAFMode(PA,GPIO_Pin_11,GPIO_AF3);			// PA11复用成xclkout
//	GPIO_SetBits(PA,GPIO_Pin_11);
	
	CLK_MCOConfig(CLK_MCO_SYSCLK,CLK_MCO_DIV1);		//xclkout选择SYSCLK，不分频
}

void Set_SYSCLK(void)   
{	
		SysCLK_OSCL_Config();		//OSCL_Config
		CLK_OSCLCmd(ENABLE);	
		SysCLK_OSCH_Config();		//OSCH_Config
		CLK_OSCHCmd(ENABLE);
		switch(SystemCLK)	
		{
				case CLK_SYSCLKSource_RCH:
							CLK_RCHCmd(ENABLE);     //使能并等待RCH稳定
							CLK_SYSCLKConfig(CLK_SYSCLKSource_RCH);   	//RCH16M as SystemCLK
							break;
				case CLK_SYSCLKSource_RCL:
							CLK_SYSCLKConfig(CLK_SYSCLKSource_RCL);			//RCL as SystemCLK
							break;
				case CLK_SYSCLKSource_OSCH:
							SysCLK_OSCH_Config();		//OSCH_Config
							CLK_OSCHCmd(ENABLE);
							CLK_SYSCLKConfig(CLK_SYSCLKSource_OSCH);    //OSCH as SystemCLK
							break;
				case CLK_SYSCLKSource_PLLCLK:
							CLK_RCHCmd(ENABLE);     //使能并等待RCH稳定
							SysCLK_PLL_Config();		//PLL_Config
							CLK_PLLCmd(ENABLE); 	  //使能并等待PLL稳定
							CLK_SYSCLKConfig(CLK_SYSCLKSource_PLLCLK);  	//PLL as SystemCLK
							break;
		}
		CLK_HCLKConfig(0x01);     					//M0时钟等于sysclk 2分频
		CLK_PCLK01Config(CLK_HCLK_Div1);		//为M0时钟1分频
		CLK_PCLK23Config(CLK_HCLK_Div1);		//为M0时钟1分频
		CLK_MTCLKConfig(CLK_SYSCLK_Div2);		//为sysclk 2分频
}

