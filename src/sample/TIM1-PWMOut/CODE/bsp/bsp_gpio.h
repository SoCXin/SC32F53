#ifndef __GPIO_H
#define	__GPIO_H

#include "sc32f53xx_conf.h"

// TIM1_POut
#define	TIM1_POut_GPIO_PORT					PA
#define	TIM1_POut_GPIO_PIN					GPIO_Pin_8

// TIM1_NOut
#define	TIM1_NOut_GPIO_PORT					PB
#define	TIM1_NOut_GPIO_PIN					GPIO_Pin_13

// LED2
#define LED2_GPIO_PORT    	PA			              /* GPIO端口 */
#define LED2_GPIO_PIN		GPIO_Pin_11			        /* 连接到SCL时钟线的GPIO */


void GPIO_Config(void);
void GPIO_BaseInit(void) ;
#endif /* __GPIO_H */

