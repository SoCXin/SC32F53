#include "bsp_gpio.h"
#include "bsp_clock.h"
#include "bsp_timer.h"

uint8_t Flag;
uint16_t Cnt;

int main()
{	
		Set_SYSCLK();
		CLK_APB23PeriphClockCmd(CLK_APB23Periph_TIM1,ENABLE);  //open TIM1 clock
		GPIO_Config();
		TIM_Init();
	  while(1)
	  {
			
	  }	
}

