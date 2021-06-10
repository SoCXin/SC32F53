#ifndef __ADC_H
#define	__ADC_H

#include "sc32f53xx_conf.h"


// ADC GPIO宏定义
// 注意：用作ADC采集的IO必须没有复用，否则采集电压会有影响
#define    ADC_PORT                      PA
#define    ADC_PIN                       GPIO_Pin_2
// ADC 通道宏定义
#define    ADC_CHANNEL                   ADC_Channel_2
#define    ADC_INCHANNEL                 ADC_Channel_AIN2

// 注意：用作ADC采集辅助脚
#define    ADC_Assist_PORT               PA
#define    ADC_Assist_PIN                GPIO_Pin_3
 
// ADC 中断相关宏定义
#define    ADC_IRQ                       ADC_IRQn
#define    ADC_IRQHandler                ADC_IRQHandler

//SEQA
#define  SEQAConvWidth   0x0A

//SEQB
#define  SEQBConvWidth   0x0A


void SEQA_ADCx_Init(void);


#endif /* __ADC_H */

