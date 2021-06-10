#include "bsp_gpio.h"
#include "bsp_clock.h"

uint8_t Flag;
uint8_t Cnt=0;

void delay(uint32_t delay_time)
{	
		while(delay_time--);
}

int main()
{	
		Set_SYSCLK();   			//配置时钟为默认RCH-16M
		LED_GPIO_Config();		
	  while(1)
	  {					
				switch(Cnt)
				{
						case 0:
								LED_RGBOFF;     
								break;
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
				Cnt++;
				if(Cnt>=8)
						Cnt = 0;
				delay(500000);
				GPIO_SetOUTTGL(LED2_GPIO_PORT,LED2_GPIO_PIN);  //翻转LED2
	  }	
}


