#include "bsp_wt.h"


void CHIPCTRL_WT_test(uint8_t alerm)
{
	WT_IRQCmd(ENABLE,0);
	
	WT_SetAlerm(alerm);

	WT_Cmd(ENABLE);
}

void delay(uint32_t time_data)
{
	uint32_t i;
	
	for (i=0;i<time_data;i++);
}

