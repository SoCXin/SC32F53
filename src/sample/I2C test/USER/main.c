#include "bsp_i2c.h"
#include "bsp_gpio.h"
#include "bsp_clock.h"

uint8_t	I2C_Reset_Flag;

int main()
{
		uint8_t temp = 0;
		int16_t Acc_x = 0;
    int16_t Acc_y = 0;
    int16_t Acc_z = 0;
	
		Set_SYSCLK();	
		LED_GPIO_Config();
		
		I2C_Init();
		
/*********对三轴的配置****************/
    I2C_Write(0x20,0x27);    
    I2C_Write(0x23,0xB0);
		while(1)
		{
				temp = I2C_Read(0x27);
        if((temp & 0x08) != 0x08)   //x,y,z位置数据更新
        {
            continue;
        }

				/*******读取xyz轴状态***************/
        Acc_x = (int16_t)(I2C_Read(0x28) + (I2C_Read(0x29) << 8));
        Acc_x >>= 6;

        Acc_y = (int16_t)(I2C_Read(0x2a) + (I2C_Read(0x2b) << 8));
        Acc_y >>= 6;

        Acc_z = (int16_t)(I2C_Read(0x2c) + (I2C_Read(0x2d) << 8));
        Acc_z >>= 6;
				
				if((Acc_x>0))
						GPIO_ResetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN);
				else
						GPIO_SetBits(RGB1_GPIO_PORT,RGB1_GPIO_PIN);
				
				if((Acc_y>0))
						GPIO_ResetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN); 
				else
						GPIO_SetBits(RGB2_GPIO_PORT,RGB2_GPIO_PIN);
				
				if((Acc_z>0)) 
						GPIO_ResetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN); 
				else
						GPIO_SetBits(RGB3_GPIO_PORT,RGB3_GPIO_PIN);	
				
				if(!GPIO_ReadOutputDataBit(LED2_GPIO_PORT,LED2_GPIO_PIN))
						GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);	
				else
						GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);	
		}
}



