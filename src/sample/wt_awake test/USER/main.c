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

		SYSTEM_WakeUpSourceSel(System_Warkup_WT,ENABLE);  //ѡ��WT����
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
							
								CLK_AHB23PeriphClockCmd(CLK_AHB23Periph_All,DISABLE);	  //�ر�AHB23��������ʱ��
								
								CLK_APB01PeriphClockCmd(CLK_APB01Periph_ALL,DISABLE);		//�ر�APB01��������ʱ��

								CLK_APB23PeriphClockCmd(CLK_APB23Periph_ALL,DISABLE);		//�ر�APB23��������ʱ��
								
								FLASH_SleepCLKConfig(CLKClose);  //˯��ģʽ�¹ر�FLASHʱ�� 
								
								SRAM_SleepCLKConfig(CLKClose);	 //˯��ģʽ�¹ر�SRAMʱ�� 
								
								Power_SourceConfig(DeepSleep_LowPower_MVR|DeepSleep_LowPower_FLASH,LowPower); 	 //���˯��ģʽ��FLASH��MVR����͹���ģʽ
							
								MVR_Config(MVR_PowerState_Low,Power_MVR_1_5V);	//MVRѡ��1.5V �͹���ģʽ
																	
								LVR_Config(Power_LVRS_2_3V,DISABLE);	//��ѹ��λ��2.3V  �ر�
								
							  GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
								NVIC_SystemLPConfig(NVIC_LP_SLEEPDEEP,ENABLE);
								__DSB();
								__WFI();  //����˯��ģʽ
						}
				}
		}
}	

