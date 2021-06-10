#include "bsp_clock.h"
#include "bsp_wt.h"
#include "bsp_gpio.h"

extern uint8_t Flag;
extern uint8_t Cnt;

void delay(uint32_t time_data);

int main()
{
		Set_SYSCLK();
		CHIPCTRL_WT_test(Alerm);   

		SYSTEM_WakeUpSourceSel(System_Warkup_WT,ENABLE);  //选择WT唤醒
    MCLK_Out();
		LED2_GPIO_Config();
		EXINT_GPIO_Config();
	
		while(1)
		{
				if(Flag)
				{
						Flag=0;					
						if(Cnt==1)
						{
							
								CLK_AHB23PeriphClockCmd(CLK_AHB23Periph_All,DISABLE);	  //关闭AHB23所有外设时钟
								
								CLK_APB01PeriphClockCmd(CLK_APB01Periph_ALL,DISABLE);		//关闭APB01所有外设时钟

								CLK_APB23PeriphClockCmd(CLK_APB23Periph_ALL,DISABLE);		//关闭APB23所有外设时钟
								
								FLASH_SleepCLKConfig(CLKClose);  //睡眠模式下关闭FLASH时钟 
								
								SRAM_SleepCLKConfig(CLKClose);	 //睡眠模式下关闭SRAM时钟 
								
								Power_SourceConfig(DeepSleep_LowPower_MVR|DeepSleep_LowPower_FLASH,LowPower); 	 //深度睡眠模式下FLASH、MVR进入低功耗模式
							
								MVR_Config(MVR_PowerState_Low,Power_MVR_1_5V);	//MVR选择1.5V 低功耗模式
																	
								LVR_Config(Power_LVRS_2_3V,DISABLE);	//低压复位点2.3V  关闭
								
							  GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
								NVIC_SystemLPConfig(NVIC_LP_SLEEPDEEP,ENABLE);
								__DSB();
								__WFI();  //进入睡眠模式
						}
				}
		}
}	

