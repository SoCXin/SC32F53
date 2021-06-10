#include "bsp_gpio.h"

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED2_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //��ʼ���ṹ�����
		
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;
		/*���ÿ⺯������ʼ��LED2_GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(DEBUG_EXINT_PORT,DEBUG_EXINT_PIN,DEBUG_EXINT_IRQ);   //PA0Ϊ�ⲿ�ж� �½��ش���
		GPIO_ClearAllIRQStatus(DEBUG_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(DEBUG_EXINT_PORT, DEBUG_EXINT_PIN);		//Enable the interrupt
}

