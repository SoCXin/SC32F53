#include "bsp_gpio.h"


void GPIO_BaseInit(void) 
{
	
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructInit(&GPIO_InitStructure);   		 //��ʼ���ṹ�����
	
		GPIO_InitStructure.GPIO_Pin = TIM1_POut_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Dir = GPIO_DirOut;       //����IO��Ϊ���ģʽ
		GPIO_InitStructure.GPIO_OD = GPIO_ODDisable;		 //�رտ�©ģʽ
		GPIO_InitStructure.GPIO_Drive = GPIO_DriveLow;	 //����������
		GPIO_InitStructure.GPIO_SlewRate = GPIO_Fast;		 //ѡ��������б��
		/*���ÿ⺯������ʼ��TIM1_POut_GPIO*/
		GPIO_Init(TIM1_POut_GPIO_PORT , &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = TIM1_NOut_GPIO_PIN;
		/*���ÿ⺯������ʼ��TIM1_NOut_GPIO*/
		GPIO_Init(TIM1_NOut_GPIO_PORT, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;	
		/*���ÿ⺯������ʼ��LED2_GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
}

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void GPIO_Config(void)
{		
		GPIO_SetAFMode(TIM1_POut_GPIO_PORT,TIM1_POut_GPIO_PIN,GPIO_AF2);		//PA8����ΪTIM1_CH1  OSC1
		GPIO_SetAFMode(TIM1_NOut_GPIO_PORT,TIM1_NOut_GPIO_PIN,GPIO_AF2);		//PB13����ΪTIM1_CH1N  OSC1N	
		
		GPIO_BaseInit();
}


