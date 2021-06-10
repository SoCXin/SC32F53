#include "bsp_gpio.h"

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED2_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //初始化结构体变量
		
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;
		/*调用库函数，初始化LED2_GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(DEBUG_EXINT_PORT,DEBUG_EXINT_PIN,DEBUG_EXINT_IRQ);   //PA0为外部中断 下降沿触发
		GPIO_ClearAllIRQStatus(DEBUG_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(DEBUG_EXINT_PORT, DEBUG_EXINT_PIN);		//Enable the interrupt
}

