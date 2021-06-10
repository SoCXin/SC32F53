#include "bsp_gpio.h"


void GPIO_BaseInit(void) 
{
	
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //初始化结构体变量
	
		GPIO_InitStructure.GPIO_Pin = TIM1_POut_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;       //配置IO口为输出模式
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;		 //关闭开漏模式
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;	 //低驱动电流
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;		 //选择快速输出斜率
		/*调用库函数，初始化TIM1_POut_GPIO*/
		GPIO_Init(TIM1_POut_GPIO_PORT , &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = TIM1_NOut_GPIO_PIN;
		/*调用库函数，初始化TIM1_NOut_GPIO*/
		GPIO_Init(TIM1_NOut_GPIO_PORT, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;	
		/*调用库函数，初始化LED2_GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
}

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void GPIO_Config(void)
{		
		GPIO_SetAFMode(TIM1_POut_GPIO_PORT,TIM1_POut_GPIO_PIN,GPIO_AF2);		//PA8复用为TIM1_CH1  OSC1
		GPIO_SetAFMode(TIM1_NOut_GPIO_PORT,TIM1_NOut_GPIO_PIN,GPIO_AF2);		//PB13复用为TIM1_CH1N  OSC1N	
		
		GPIO_BaseInit();
}


