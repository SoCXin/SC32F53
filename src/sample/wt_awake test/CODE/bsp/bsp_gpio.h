#ifndef __GPIO_H
#define	__GPIO_H

#include "sc32f53xx_conf.h"

// LED2
#define LED2_GPIO_PORT    	PA			              /* GPIO端口 */
#define LED2_GPIO_PIN		GPIO_Pin_11			        /* 连接到SCL时钟线的GPIO */

// GPIO 中断相关宏定义
#define    PA_IRQ                       PA_IRQn
#define    PA_IRQHandler               PA_IRQHandler

//EXINT config
#define DEBUG_EXINT_PORT    PA			              /* GPIO端口 */
#define DEBUG_EXINT_PIN		GPIO_Pin_0			        /* 连接到SCL时钟线的GPIO */
#define DEBUG_EXINT_IRQ		GPIO_IRQFalling

void LED2_GPIO_Config(void);
void EXINT_GPIO_Config(void);

#endif /* __GPIO_H */

