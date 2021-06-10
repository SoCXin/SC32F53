#include "bsp_i2c.h"


void I2C_Init(void)
{
		GPIO_SetAFMode(PB,GPIO_Pin_8,GPIO_AF1);    //PB8 SCL
		GPIO_SetAFMode(PB,GPIO_Pin_9,GPIO_AF1);		 //PB9 SDA
	
		CLK_APB01PeriphClockCmd(CLK_APB01Periph_I2C,ENABLE);  //使能I2C时钟    
		I2C_SysclkConfig(I2C_PCLK_Div256);
	
    I2C_Enable;   //使能I2C
}

void I2C_SI_Check(void)  
{
    if(I2C_Read_SRState() == 0x00)
    {
        I2C_Reset_Flag = 1;
        I2C_SET_STO;
        I2C_CLR_SI;
        if(I2C_Read_SIState())
        {
            I2C_Disable;
            I2C_Enable;
            I2C_CLR_SI;
            I2C_Disable;
        }
    }
}

void I2C_Write(uint8_t addr,uint8_t dat)
{
    /* Step1 */
    I2C_SET_STA;                            /* Send Start bit */
//    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x08)                     /* 0x08:  A START condition has been transmitted*/
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send STA' error");
        goto Write_Error_Stop;
    }
		
    /* Step2 */
    I2C_CLR_STA;                            /* Clear STA and Keep SI value in I2CON */
    I2C_Write_DATA(MEMS_ADDR | MEMS_WR);           /* Send (MEMS_ADDR+MEMS_WR) */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x18)                     /* 0x18: (MEMS_ADDR+MEMS_WR) has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send MEMS_ADDR+WR' error");
        goto Write_Error_Stop;
    }

    /* Step3 */
    I2C_Write_DATA(addr);                          /* Send addr */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x28)                     /* 0x28:  Data byte in I2CDAT has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send addr' error");
        goto Write_Error_Stop;
    }

    /* Step4 */
    I2C_Write_DATA(dat);                           /* Send data */
    I2C_CLR_SI;
    while(!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x28)                     /* 0x28:  Data byte in I2CDAT has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Write Data' error");
        goto Write_Error_Stop;
    }

    /* Step5 */
    I2C_SET_STO;                            /* Set STOP Bit */
    I2C_CLR_SI;
    while(I2C_Read_STOState())                             /* Check STOP signal */
    {
        I2C_SI_Check();
        if (I2C_Reset_Flag)
        {
            goto Write_Error_Stop;
        }
    }

		Write_Error_Stop:
    if (I2C_Reset_Flag)
    {
        I2C_SI_Check();
        I2C_Reset_Flag  = 0;
        //printf("\nI2C Write error, test stop");
    }
}

uint8_t I2C_Read(uint8_t addr)
{
    uint8_t dat;

    /* Step1 */
    I2C_SET_STA;                            /* Send Start bit */
//    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x08)                         /* 0x08:  A START condition has been transmitted*/
    {
        I2C_Reset_Flag = 1;
//        printf("\nI2C 'Send STA' error");
        goto Read_Error_Stop;
    }

    /* Step2 */
    I2C_Write_DATA(MEMS_ADDR | MEMS_WR);             /* Send (MEMS_ADDR+MEMS_WR) */
    I2C_CLR_STA;                                /* Clear STA and Keep SI value in I2CON */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x18)                         /* 0x18: (MEMS_ADDR+MEMS_WR) has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send MEMS_ADDR' error");
        goto Read_Error_Stop;
    }

    /* Step3 */
    I2C_Write_DATA(addr);                              /* Send addr */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x28)                         /* 0x28:  Data byte in I2CDAT has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send I2C addr' error");
        goto Read_Error_Stop;
    }

    /* Step4 */
    I2C_SET_STA;                                /* Repeated START */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x10)                         /* 0x10: A repeated START condition has been transmitted */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send STA' error");
        goto Read_Error_Stop;
    }

    /* Step5 */
    I2C_CLR_STA;                                /* Clear STA and Keep SI value in I2CON */
    I2C_Write_DATA(MEMS_ADDR | MEMS_RD);             /* Send (MEMS_ADDR+MEMS_RD) */
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x40)                         /* 0x40:  MEMS_ADDR+MEMS_RD has been transmitted; ACK has been received */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Send DEVICEADDR+R' error");
        goto Read_Error_Stop;
    }

    /* Step6 */                                 /* read I2C data */
    I2C_SET_AA;                                 /* Set Assert Acknowledge Control Bit */
    I2C_CLR_SI;
    while(!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x50)             /* 0x50:Data byte has been received; NOT ACK has been returned */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'No Ack' error");
        goto Read_Error_Stop;
    }
    dat = I2C_Read_DATA();

    /* Step7 */
    I2C_CLR_AA;                                 /* Send a NACK to disconnect*/
    I2C_CLR_SI;
    while (!I2C_Read_SIState());
    if(I2C_Read_SRState() != 0x58)                         /* 0x58:Data byte has been received; ACK has been returned */
    {
        I2C_Reset_Flag = 1;
        //printf("\nI2C 'Ack' error");
        goto Read_Error_Stop;
    }

    /* Step8 */   
    I2C_SET_STO;
    I2C_CLR_SI;
    while(I2C_Read_STOState())                                 /* Check STOP signal */
    {
        I2C_SI_Check();
        if (I2C_Reset_Flag)
        {
            goto Read_Error_Stop;
        }
    }
    return dat;
		Read_Error_Stop:
    if (I2C_Reset_Flag)
    {
        I2C_SI_Check();
        I2C_Reset_Flag = 0;
        //printf("\nI2C Read error, test stop");
    }
    return 0;
}

