#include "bsp_adc.h"

static void ADCx_Mode_Config(void)
{
		ADC_InitTypeDef ADC_InitStructure;
		ADC_StructInit(&ADC_InitStructure);

		ADC_InitStructure.ADC_EXRFSel = ADC_EXTER_REF;		//ѡ���ⲿ�ο�
		ADC_InitStructure.ADC_RefVolSet = ADC_VREF_EXT;		//ѡ���ⲿ�ο���ѹ
		ADC_InitStructure.ADC_CLKDIV = 0x0B;							//ADCʱ�ӷ�Ƶ
		ADC_InitStructure.ADC_CLKON = ENABLE;							//ADCʱ�ӿ���
		ADC_InitStructure.ADC_R1xBSel = ADC_R12B_ENABLE;		//VDD��Ϊ�ο���ѹ
		ADC_InitStructure.ADC_VREFVDDSel = ADC_VREFVDD_ENABLE; 	//VDD��Ϊ�ο���ѹ
		ADC_Init(&ADC_InitStructure);
}

static void ADCx_PD_Config(void)
{
		PD_ConfigTypeDef PD_ConfigStructure;
		ADC_PDConfigStructInit(&PD_ConfigStructure);
	
		PD_ConfigStructure.ADC_CORE_PowerDown = DISABLE;
		PD_ConfigStructure.ADC_PowerDown = DISABLE;
		PD_ConfigStructure.ADC_REF_PowerDown = DISABLE;
		ADC_PDConfig(&PD_ConfigStructure);
}

void	SEQA_ADCx_Init()
{	
		GPIO_SetAnalogMode(ADC_PORT, ADC_PIN);  //����ģ��ͨ��	
		ADCx_Mode_Config();		//����ADC
		ADCx_PD_Config();
	
		ADC_SEQA_SoftwareTrigSet(ADC_Conversion_Single, ENABLE); //����ת��
		
	  ADC_SEQx_ConvWidthSet(ADC_SEQ_SEQA,SEQAConvWidth);		//ѡ��ͨ��ת�����
		ADC_SEQx_ModeConfig(ADC_SEQ_SEQA,Mode_DATx);				//ת����� 
		ADC_SEQx_ChannelSel(ADC_SEQ_SEQA,ADC_INCHANNEL);   //ѡ��ͨ��		
	  
		ADC_SEQA_StartENCmd(ENABLE);	        //SEQA�������	
}

void	SEQB_ADCx_Init()
{	
		GPIO_SetAnalogMode(ADC_PORT, ADC_PIN);  //����ģ��ͨ��
		ADCx_Mode_Config();			//����ADC
		ADCx_PD_Config();
			
		ADC_SEQB_SoftwareTrigSet(ADC_Conversion_Single, ENABLE); //����ת��
	
		ADC_SEQx_ModeConfig(ADC_SEQ_SEQB,Mode_DATx);					//ѡ��ͨ��ת�����
		ADC_SEQx_ConvWidthSet(ADC_SEQ_SEQB,SEQBConvWidth);		//ת�����
		ADC_SEQx_ChannelSel(ADC_SEQ_SEQB,ADC_Channel_AIN0);   //ѡ��ͨ��
		
		ADC_SEQBENCmd(ENABLE);
}

