#ifndef __GPIO_H
#define	__GPIO_H

#include "sc32f53xx_conf.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// G-绿色
#define RGB1_GPIO_PORT    	PA			              /* GPIO端口 */
#define RGB1_GPIO_PIN		GPIO_Pin_8			        /* 连接到RGB1的GPIO */

// R-红色
#define RGB2_GPIO_PORT    	PA			              /* GPIO端口 */
#define RGB2_GPIO_PIN		GPIO_Pin_9			        /* 连接到RGB2的GPIO */

// B-蓝色
#define RGB3_GPIO_PORT    	PA			              /* GPIO端口 */
#define RGB3_GPIO_PIN		GPIO_Pin_10			        /* 连接到RGB3的GPIO */

// LED2
#define LED2_GPIO_PORT    	PA			              /* GPIO端口 */
#define LED2_GPIO_PIN		GPIO_Pin_11			        /* 连接到LED2的GPIO */

//USR1 config
#define USR1_EXINT_PORT    PA			              /* GPIO端口 */
#define USR1_EXINT_PIN		GPIO_Pin_0			          /* 连接到USR1的GPIO */
#define USR1_EXINT_IRQ		GPIO_IRQFalling

// GPIO 中断相关宏定义
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

//绿
#define LED_GREEN \
					RGB1(ON);\
					RGB2(OFF);\
					RGB3(OFF);

//红
#define LED_RED		\
					RGB1(OFF);\
					RGB2(ON);\
					RGB3(OFF);

//蓝
#define LED_BLUE	\
					RGB1(OFF);\
					RGB2(OFF);\
					RGB3(ON);

					
//黄(红+绿)					
#define LED_YELLOW	\
					RGB1(ON);\
					RGB2(ON);\
					RGB3(OFF);
//紫(红+蓝)
#define LED_PURPLE	\
					RGB1(OFF);\
					RGB2(ON);\
					RGB3(ON);

//青(绿+蓝)
#define LED_CYAN \
					RGB1(ON);\
					RGB2(OFF);\
					RGB3(ON);
					
//白(红+绿+蓝)
#define LED_WHITE	\
					RGB1(ON);\
					RGB2(ON);\
					RGB3(ON);
					
//黑(全部关闭)
#define LED_RGBOFF	\
					RGB1(OFF);\
					RGB2(OFF);\
					RGB3(OFF);


void LED_GPIO_Config(void);
void EXINT_GPIO_Config(void);

#endif /* __GPIO_H */

