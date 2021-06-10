#include "bsp_adc.h"

static void ADCx_Mode_Config(void)
{
		ADC_InitTypeDef ADC_InitStructure;
		ADC_StructInit(&ADC_InitStructure);

		ADC_InitStructure.ADC_EXRFSel = ADC_EXTER_REF;		//选择外部参考
		ADC_InitStructure.ADC_RefVolSet = ADC_VREF_EXT;		//选择外部参考电压
		ADC_InitStructure.ADC_CLKDIV = 0x0B;							//ADC时钟分频
		ADC_InitStructure.ADC_CLKON = ENABLE;							//ADC时钟开启
		ADC_InitStructure.ADC_R1xBSel = ADC_R12B_ENABLE;		//VDD作为参考电压
		ADC_InitStructure.ADC_VREFVDDSel = ADC_VREFVDD_ENABLE; 	//VDD作为参考电压
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
		GPIO_SetAnalogMode(ADC_PORT, ADC_PIN);  //配置模拟通道	
		ADCx_Mode_Config();		//配置ADC
		ADCx_PD_Config();
	
		ADC_SEQA_SoftwareTrigSet(ADC_Conversion_Single, ENABLE); //单次转换
		
	  ADC_SEQx_ConvWidthSet(ADC_SEQ_SEQA,SEQAConvWidth);		//选择通道转换完成
		ADC_SEQx_ModeConfig(ADC_SEQ_SEQA,Mode_DATx);				//转换宽度 
		ADC_SEQx_ChannelSel(ADC_SEQ_SEQA,ADC_INCHANNEL);   //选择通道		
	  
		ADC_SEQA_StartENCmd(ENABLE);	        //SEQA软件触发	
}

void	SEQB_ADCx_Init()
{	
		GPIO_SetAnalogMode(ADC_PORT, ADC_PIN);  //配置模拟通道
		ADCx_Mode_Config();			//配置ADC
		ADCx_PD_Config();
			
		ADC_SEQB_SoftwareTrigSet(ADC_Conversion_Single, ENABLE); //单次转换
	
		ADC_SEQx_ModeConfig(ADC_SEQ_SEQB,Mode_DATx);					//选择通道转换完成
		ADC_SEQx_ConvWidthSet(ADC_SEQ_SEQB,SEQBConvWidth);		//转换宽度
		ADC_SEQx_ChannelSel(ADC_SEQ_SEQB,ADC_Channel_AIN0);   //选择通道
		
		ADC_SEQBENCmd(ENABLE);
}

