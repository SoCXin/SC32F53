#include "bsp_gpio.h"

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //初始化结构体变量
	
		GPIO_InitStructure.GPIO_Pin = RGB1_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;       //配置IO口为输出模式
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;		 //关闭开漏模式
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;	 //低驱动电流
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;		 //选择快速输出斜率
		/*调用库函数，初始化LED1_GPIO*/
		GPIO_Init(RGB1_GPIO_PORT , &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = RGB2_GPIO_PIN;
		/*调用库函数，初始化LED2_GPIO*/
		GPIO_Init(RGB2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = RGB3_GPIO_PIN;
		/*调用库函数，初始化LED3_GPIO*/
		GPIO_Init(RGB3_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
		/*调用库函数，初始化LED4_GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		LED_BLUE;  //默认RCH对应的LED灯亮起
		GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);   //默认点亮
}

