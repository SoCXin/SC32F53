#ifndef __ADC_H
#define	__ADC_H

#include "sc32f53xx_conf.h"


// ADC GPIO�궨��
// ע�⣺����ADC�ɼ���IO����û�и��ã�����ɼ���ѹ����Ӱ��
#define    ADC_PORT                      PA
#define    ADC_PIN                       GPIO_Pin_2
// ADC ͨ���궨��
#define    ADC_CHANNEL                   ADC_Channel_2
#define    ADC_INCHANNEL                 ADC_Channel_AIN2

// ע�⣺����ADC�ɼ�������
#define    ADC_Assist_PORT               PA
#define    ADC_Assist_PIN                GPIO_Pin_3
 
// ADC �ж���غ궨��
#define    ADC_IRQ                       ADC_IRQn
#define    ADC_IRQHandler                ADC_IRQHandler

//SEQA
#define  SEQAConvWidth   0x0A

//SEQB
#define  SEQBConvWidth   0x0A


void SEQA_ADCx_Init(void);


#endif /* __ADC_H */

