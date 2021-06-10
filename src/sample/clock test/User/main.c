#include "bsp_clock.h"
#include "bsp_gpio.h"

extern uint8_t Flag;
extern uint8_t Cnt;

void delay(uint32_t a)
{
    while(a--);
}

int main()
{
		Set_SYSCLK();	
		LED_GPIO_Config();
		GPIO_EnableIRQ(PA, 0);
		GPIO_PinIRQConfig(PA,GPIO_Pin_0,GPIO_IRQFalling);  //PA0外部中断
		MCLK_Out();    //输出当前系统时钟

		while(1)
		{
				if(Flag)
				{
						Flag = 0;
						switch(Cnt)
						{
								case 1:
										CLK_SYSCLKConfig(CLK_SYSCLKSource_RCL);			/**< Select 32K Clock as System Clock  */
										LED_RED;
										break;
								case 2:
										CLK_SYSCLKConfig(CLK_SYSCLKSource_RCH);			/**< Select rch16m as System Clock  */
										LED_BLUE;
										break;
								case 3:
										CLK_SYSCLKConfig(CLK_SYSCLKSource_OSCH);		/**< Select OSCH as System Clock  */
										LED_GREEN;
										break;
								case 4:
										CLK_SYSCLKConfig(CLK_SYSCLKSource_OSCL);		/**< Select OSCL as System Clock  */
										LED_YELLOW;
										break;
								case 5:
										CLK_RCHCmd(ENABLE);     
										SysCLK_PLL_Config();		//PLL_Config
										CLK_PLLCmd(ENABLE); 	
										CLK_SYSCLKConfig(CLK_SYSCLKSource_PLLCLK);  	//PLL as SystemCLK
										LED_WHITE;
										break;
						}						
				}
		}
}


