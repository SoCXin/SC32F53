#include "bsp_gpio.h"
#include "bsp_clock.h"

extern uint8_t Flag;
extern uint8_t Cnt;

int main()
{	
		Set_SYSCLK();
		LED_GPIO_Config();
		EXINT_GPIO_Config();   //外部中断口配置
			
	  while(1)
	  {
				if(Flag)
				{
						Flag = 0;
						switch(Cnt)
						{
								case 1:
										LED_RED;
										break;
								case 2:
										LED_GREEN;
										break;
								case 3:
										LED_BLUE;
										break;
								case 4:
										LED_YELLOW;
										break;
								case 5:
										LED_PURPLE;
										break;
								case 6:
										LED_CYAN;
										break;
								case 7:
										LED_WHITE;
										break;
								default:
										break;
						}						
				}
				
	  }	
}



