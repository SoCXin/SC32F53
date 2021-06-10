#include "bsp_timer.h"

void TIM_Init(void)
{
		TIM_BaseInitTypeDef TIM_BaseInitStructure;
		TIM_OCInitTypeDef TIM_OCInitStructure;
		TIM_TimeBaseStructInit(&TIM_BaseInitStructure);
		TIM_OCStructInit(&TIM_OCInitStructure);
	
		TIM_BaseInitStructure.TIM_Period = 0xffff;		//�������ϼ����������ֵ
		TIM_BaseInitStructure.TIM_Prescaler = 0xff;   //TIM1ʱ��Ԥ��Ƶ
		TIM_BaseInitStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
		TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
		TIM_BaseInit(TIM1,&TIM_BaseInitStructure);    
	
		TIM_OCInitStructure.TIM_Pulse = 0x7fff;		  //CCR1=0x7fff 
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  					 		 //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
		TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;  		//0��OC1N�ߵ�ƽ��Ч 1��OC1N�͵�ƽ��Ч
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  			//0��OC1P�ߵ�ƽ��Ч 1��OC1P�͵�ƽ��Ч
		TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; // 0��OC1N��ֹ��� 1��OC1Nʹ�����	
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  // 0��OC1��ֹ��� 1��OC1ʹ�����
		TIM_OC1Init(TIM1,&TIM_OCInitStructure);
		
		TIM_CtrlPWMOutputs(TIM1,ENABLE);     // 0����ֹOCx��OCN�����ǿ��Ϊ����״̬ 1������OCx��OCN���
		TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);   //����Ԥװ�ؼĴ��� 
		TIM_ARRPreloadConfig(TIM1,ENABLE);		 //TIMx_ARR�Ĵ����л���
			
		TIM_Cmd(TIM1,ENABLE);  //TIM1ʹ��
}
