#include "bsp_timer.h"

void TIM_Init(void)
{
		TIM_BaseInitTypeDef TIM_BaseInitStructure;
		TIM_OCInitTypeDef TIM_OCInitStructure;
		TIM_TimeBaseStructInit(&TIM_BaseInitStructure);
		TIM_OCStructInit(&TIM_OCInitStructure);
	
		TIM_BaseInitStructure.TIM_Period = 0xffff;		//设置向上计数到的最大值
		TIM_BaseInitStructure.TIM_Prescaler = 0xff;   //TIM1时钟预分频
		TIM_BaseInitStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
		TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
		TIM_BaseInit(TIM1,&TIM_BaseInitStructure);    
	
		TIM_OCInitStructure.TIM_Pulse = 0x7fff;		  //CCR1=0x7fff 
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  					 		 //选择定时器模式:TIM脉冲宽度调制模式2
		TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;  		//0：OC1N高电平有效 1：OC1N低电平有效
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  			//0：OC1P高电平有效 1：OC1P低电平有效
		TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; // 0：OC1N禁止输出 1：OC1N使能输出	
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  // 0：OC1禁止输出 1：OC1使能输出
		TIM_OC1Init(TIM1,&TIM_OCInitStructure);
		
		TIM_CtrlPWMOutputs(TIM1,ENABLE);     // 0：禁止OCx和OCN输出或强制为空闲状态 1：开启OCx和OCN输出
		TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);   //开启预装载寄存器 
		TIM_ARRPreloadConfig(TIM1,ENABLE);		 //TIMx_ARR寄存器有缓冲
			
		TIM_Cmd(TIM1,ENABLE);  //TIM1使能
}
