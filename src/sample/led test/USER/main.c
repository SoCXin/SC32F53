#include "bsp_led.h"
#include "bsp_clock.h"
#include "bsp_gpio.h"
#include "sc32f53xx_it.h" 

extern uint16_t	ChangeFlag;
uint16_t	LowSEGnDigit[10]={0xd7,0x14,0xcd,0x5d,0x1e,0x5b,0xdb,0x15,0xdf,0x5f};   //0~9
uint16_t	HignSEGnDigit[10]={0xd7,0x14,0xcd,0x5d,0x1e,0x5b,0xdb,0x15,0xdf,0x5f};	//0~9
uint16_t	Value1=1234;
uint16_t	Value2=5678;
uint32_t RAM0_Value;
uint32_t RAM1_Value;
uint32_t RAM2_Value;
uint32_t RAM3_Value;

void delay(uint32_t delay_time)
{
  while(delay_time--);
}

int main()
{
		Set_SYSCLK();
		LED_GPIO_Config();
		EXINT_GPIO_Config();
		LED_Init();
		
	  RAM0_Value = LowSEGnDigit[(Value1/1000)]+(LowSEGnDigit[(Value1%1000/100)]<<16);
	  RAM1_Value = LowSEGnDigit[(Value1%100/10)]+(LowSEGnDigit[(Value1%10)]<<16);
	  RAM2_Value = (HignSEGnDigit[(Value2/1000)]<<8)+(HignSEGnDigit[(Value2%1000/100)]<<24);
	  RAM3_Value = (HignSEGnDigit[(Value2%100/10)]<<8)+(HignSEGnDigit[(Value2%10)]<<24);
		LED_WriteRAM(RAM0_Value,RAM1_Value,RAM2_Value,RAM3_Value);    //¸üÐÂ¸÷RAM
		LED_Cmd(ENABLE);
		while(1)
		{
				if(ChangeFlag)
				{
						ChangeFlag=0;
						if(Value1>=9999)
								Value1=0;
						else	
								Value1++;						
						if(Value2<=0)
								Value2=9999;
						else
								Value2--;
						RAM0_Value = LowSEGnDigit[(Value1/1000)]+(LowSEGnDigit[(Value1%1000/100)]<<16);
						RAM1_Value = LowSEGnDigit[(Value1%100/10)]+(LowSEGnDigit[(Value1%10)]<<16);
						RAM2_Value = (HignSEGnDigit[(Value2/1000)]<<8)+(HignSEGnDigit[(Value2%1000/100)]<<24);
						RAM3_Value = (HignSEGnDigit[(Value2%100/10)]<<8)+(HignSEGnDigit[(Value2%10)]<<24);
						LED_WriteRAM(RAM0_Value,RAM1_Value,RAM2_Value,RAM3_Value);
				}											
		}
}




