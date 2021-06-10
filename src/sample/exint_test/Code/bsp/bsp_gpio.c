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
		/*调用库函数，初始化RGB1_GPIO*/
		GPIO_Init(RGB1_GPIO_PORT , &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = RGB2_GPIO_PIN;
		/*调用库函数，初始化RGB2_GPIO*/
		GPIO_Init(RGB2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = RGB3_GPIO_PIN;
		/*调用库函数，初始化RGB3_GPIO*/
		GPIO_Init(RGB3_GPIO_PORT, &GPIO_InitStructure);
		
		
		GPIO_ResetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN);
		GPIO_ResetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN);
		GPIO_ResetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN);
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(USR1_EXINT_PORT,USR1_EXINT_PIN,USR1_EXINT_IRQ);   //USR1为外部中断 下降沿触发
		GPIO_ClearAllIRQStatus(USR1_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(USR1_EXINT_PORT, USR1_EXINT_PIN);		//Enable the interrupt
}
