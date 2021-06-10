#ifndef __BSP_I2C_H
#define __BSP_I2C_H

#include "sc32f53xx_conf.h"


extern uint8_t	I2C_Reset_Flag;


#define  MEMS_ADDR        0x30
#define  MEMS_WR          0x00
#define  MEMS_RD          0x01


#define  I2C_Enable          I2C_Cmd(SET)
#define  I2C_SET_STA         I2C_STA_Cmd(SET)
#define  I2C_SET_STO         I2C_STO_Cmd(SET)
#define  I2C_SET_AA          I2C_AA_Cmd(SET)

#define  I2C_Disable         I2C_Cmd(RESET)
#define  I2C_CLR_STA         I2C_STA_Cmd(RESET)
#define  I2C_CLR_STO         I2C_STO_Cmd(RESET)
#define  I2C_CLR_SI          I2C_Clear_SI()
#define  I2C_CLR_AA          I2C_AA_Cmd(RESET)

// G-��ɫ
#define RGB1_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB1_GPIO_PIN		GPIO_Pin_8			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// R-��ɫ
#define RGB2_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB2_GPIO_PIN		GPIO_Pin_9			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// B-��ɫ
#define RGB3_GPIO_PORT    	PA			              /* GPIO�˿� */
#define RGB3_GPIO_PIN		GPIO_Pin_10			        /* ���ӵ�SCLʱ���ߵ�GPIO */

// LED2
#define LED2_GPIO_PORT    	PA			              /* GPIO�˿� */
#define LED2_GPIO_PIN		GPIO_Pin_11			        /* ���ӵ�SCLʱ���ߵ�GPIO */

void I2C_Init(void);
void I2C_SI_Check(void);
void I2C_Write(uint8_t addr,uint8_t dat);
uint8_t I2C_Read(uint8_t addr);
void SetSystemClk(void);


#endif
