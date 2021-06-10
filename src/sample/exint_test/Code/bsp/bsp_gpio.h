#ifndef __GPIO_H
#define	__GPIO_H

#include "sc32f53xx_conf.h"


/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
// G-��ɫ
#define RGB1_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB1_GPIO_PIN		GPIO_Pin_8			        /* ���ӵ�RGB1��GPIO */

// R-��ɫ
#define RGB2_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB2_GPIO_PIN		GPIO_Pin_9			        /* ���ӵ�RGB2��GPIO */

// B-��ɫ
#define RGB3_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB3_GPIO_PIN		GPIO_Pin_10			        /* ���ӵ�RGB3��GPIO */

// LED2
#define LED2_GPIO_PORT    	PA			              /* GPIO�˿� */
#define LED2_GPIO_PIN		GPIO_Pin_11			        /* ���ӵ�LED2��GPIO */

//USR1 config
#define USR1_EXINT_PORT    PA			              /* GPIO�˿� */
#define USR1_EXINT_PIN		GPIO_Pin_0			          /* ���ӵ�USR1��GPIO */
#define USR1_EXINT_IRQ		GPIO_IRQFalling

// GPIO �ж���غ궨��
#define    PA_IRQ                       PA_IRQn
#define    PA_IRQHandler               PA_IRQHandler

/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

#define RGB1(a)	if(a)	\
					GPIO_SetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN)

#define RGB2(a)	if(a)	\
					GPIO_SetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN)

#define RGB3(a)	if(a)	\
					GPIO_SetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN)
					
#define LED2(a)	if(a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

//��
#define LED_GREEN \
					RGB1(ON);\
					RGB2(OFF);\
					RGB3(OFF);

//��
#define LED_RED		\
					RGB1(OFF);\
					RGB2(ON);\
					RGB3(OFF);

//��
#define LED_BLUE	\
					RGB1(OFF);\
					RGB2(OFF);\
					RGB3(ON);

					
//��(��+��)					
#define LED_YELLOW	\
					RGB1(ON);\
					RGB2(ON);\
					RGB3(OFF);
//��(��+��)
#define LED_PURPLE	\
					RGB1(OFF);\
					RGB2(ON);\
					RGB3(ON);

//��(��+��)
#define LED_CYAN \
					RGB1(ON);\
					RGB2(OFF);\
					RGB3(ON);
					
//��(��+��+��)
#define LED_WHITE	\
					RGB1(ON);\
					RGB2(ON);\
					RGB3(ON);
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					RGB1(OFF);\
					RGB2(OFF);\
					RGB3(OFF);


void LED_GPIO_Config(void);
void EXINT_GPIO_Config(void);

#endif /* __GPIO_H */

