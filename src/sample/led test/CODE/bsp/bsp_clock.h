#ifndef __CLOCK_H
#define	__CLOCK_H

#include "sc32f53xx_conf.h"

#define  SystemCLK		CLK_SYSCLKSource_RCH   //选择系统时钟

void Set_SYSCLK(void);
void SysCLK_OSCL_Config(void);
void SysCLK_OSCH_Config(void);
void SysCLK_PLL_Config(void);
void MCLK_Out(void);
	
#endif /* __CLOCK_H */

