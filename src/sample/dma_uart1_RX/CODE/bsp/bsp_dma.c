#include "bsp_dma.h"

uint8_t D_data1[1024];

void DMA_DATA0_CTLConfig(void)
{
		DMA_CTLInitTypeDef DMA_CTLInitStruct;
		DMA_CTLStructInit(&DMA_CTLInitStruct);
	
		DMA_CTLInitStruct.DMA_DataSize = DMA_DataSize_Byte;							//传输数据为字节
		DMA_CTLInitStruct.DMA_Mode = DMA_Mode_Basic;										//基本模式
		DMA_CTLInitStruct.DMA_SourceAddInc = DMA_SourceAddInc_Fixed;	
		DMA_CTLInitStruct.DMA_TargetAddInc = DMA_TargetAddInc_Byte;
		DMA_CTLInitStruct.DMA_TotalNum = DMA_TransNum;									//8次DMA传输总数
		DMA_CTLInitStruct.DMA_TransferNum = DMA_TransferNum_1;					//完成1次后仲裁
		DMA_CTLInit(DEBUG_DMA_DATA,&DMA_CTLInitStruct);
}

void DMA_UARTx_RX_Channelx_Config(void)
{
		DMA_InitTypeDef	DMA_InitStruct;
		DMA_InitStructInit(&DMA_InitStruct);
	
		DEBUG_DMA_APBxClkCmd(DEBUG_DMA_CLK,ENABLE);    			//开启DMA时钟
		
		DMA_32BitsSourcePTR_Write(DEBUG_DMA_DATA,DMA_SourcePTR);	//源地址为UART1中UARTDR的硬件地址
		DMA_32BitsTargetPTR_Write(DEBUG_DMA_DATA,DMA_TargetPTR);				//目标地址为D_data1数组地址
		DMA_DATA0_CTLConfig();			//相关控制配置								
	
		DMA_BasePTR_Write();      //写DMA通道控制基址指针 选择DMA通道
	
		DMA_InitStruct.DMA_Channel_CTRLx = DEBUG_DMA_CTRLx;						//DMA中CTRL寄存器Number选择
		DMA_InitStruct.DMA_REQ0 = DMA_REQ0_ENABLE;										//通道请求0使能
		DMA_InitStruct.DMA_REQ1 = DMA_REQ1_DISABLE;										//通道请求1不使能
		DMA_InitStruct.DMA_Request0 = DEBUG_DMA_TRIGGER;							//选择请求0信号
		DMA_InitStruct.DMA_CHxPriority = DMA_CHxPriority_Default;		 
		DMA_InitStruct.DMA_BasePoint = DMA_BasePoint_Main;					//选用主用基址指针
		DMA_InitStruct.DMA_Burst = DMA_REQ_SREQ_All;								//响应DMA_REQ和DMA_SREQ信号
		DMA_Init(&DMA_InitStruct);	
		
		DMA_Channel_Cmd(DEBUG_DMA_CTRLx,ENABLE);		//DMA通道0使能
		DMA_ITConfig(DEBUG_DMA_CTRLx,DMA_IT_DONE,ENABLE);			//开启DMA完成中断
		DMA_EnableIRQ(1);  	//DMA中断使能		
		DMA_Cmd(ENABLE);		//DMA使能
}
