#ifndef __WT_H
#define	__WT_H

#include "sc32f53xx_conf.h"

#define  Alerm		10


void CHIPCTRL_WT_test(uint8_t alerm);
void delay(uint32_t time_data);

#endif /* __WT_H */

