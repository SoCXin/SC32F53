#include "bsp_gpio.h"

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;	
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //��ʼ���ṹ�����

		GPIO_InitStructure.GPIO_Pin = RGB1_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;       //����IO��Ϊ���ģʽ
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;		 //�رտ�©ģʽ
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;	 //����������
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;		 //ѡ��������б��
		/*���ÿ⺯������ʼ��RGB1_GPIO*/
		GPIO_Init(RGB1_GPIO_PORT , &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = RGB2_GPIO_PIN;
		/*���ÿ⺯������ʼ��RGB2_GPIO*/
		GPIO_Init(RGB2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = RGB3_GPIO_PIN;
		/*���ÿ⺯������ʼ��RGB3_GPIO*/
		GPIO_Init(RGB3_GPIO_PORT, &GPIO_InitStructure);
		
		
		GPIO_ResetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN);
		GPIO_ResetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN);
		GPIO_ResetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN);
}

void EXINT_GPIO_Config(void)
{
		GPIO_PinIRQConfig(USR1_EXINT_PORT,USR1_EXINT_PIN,USR1_EXINT_IRQ);   //USR1Ϊ�ⲿ�ж� �½��ش���
		GPIO_ClearAllIRQStatus(USR1_EXINT_PORT);							//Clear all interrupt flag bits
		GPIO_EnableIRQ(USR1_EXINT_PORT, USR1_EXINT_PIN);		//Enable the interrupt
}
