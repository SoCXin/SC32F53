#ifndef __LED_H
#define	__LED_H

#include "sc32f53xx_conf.h"

#define Debug_LED_COM				0x0f		//COM1~4	
#define Debug_LED_SEG				0x00df  //SEG1~5“‘º∞SEG7°¢8

#define Debug_Clock_Width		0x20	
#define Debug_Dead_Width		0x7f
void LED_Init(void);

#endif /* __LED_H */

