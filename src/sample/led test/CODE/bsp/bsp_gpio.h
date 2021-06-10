#ifndef __GPIO_H
#define	__GPIO_H

#include "sc32f53xx_conf.h"

//USR1 config
#define USR1_EXINT_PORT    PA			              /* GPIO�˿� */
#define USR1_EXINT_PIN		GPIO_Pin_0			        /* ���ӵ�USR1��GPIO */
#define USR1_EXINT_IRQ		GPIO_IRQFalling

//USR0 config
#define USR2_EXINT_PORT    PA			              /* GPIO�˿� */
#define USR2_EXINT_PIN		GPIO_Pin_1			        /* ���ӵ�USR2��GPIO*/
#define USR2_EXINT_IRQ		GPIO_IRQFalling

// GPIO �ж���غ궨��
#define    PA_IRQ                       PA_IRQn
#define    PA_IRQHandler               PA_IRQHandler



void LED_GPIO_Config(void);
void EXINT_GPIO_Config(void);

#endif /* __GPIO_H */

