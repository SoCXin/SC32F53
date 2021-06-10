#include "bsp_dma.h"

uint8_t D_data1[1024];

void DMA_DATA0_CTLConfig(void)
{
		DMA_CTLInitTypeDef DMA_CTLInitStruct;
		DMA_CTLStructInit(&DMA_CTLInitStruct);
	
		DMA_CTLInitStruct.DMA_DataSize = DMA_DataSize_Byte;							//��������Ϊ�ֽ�
		DMA_CTLInitStruct.DMA_Mode = DMA_Mode_Basic;										//����ģʽ
		DMA_CTLInitStruct.DMA_SourceAddInc = DMA_SourceAddInc_Fixed;	
		DMA_CTLInitStruct.DMA_TargetAddInc = DMA_TargetAddInc_Byte;
		DMA_CTLInitStruct.DMA_TotalNum = DMA_TransNum;									//8��DMA��������
		DMA_CTLInitStruct.DMA_TransferNum = DMA_TransferNum_1;					//���1�κ��ٲ�
		DMA_CTLInit(DEBUG_DMA_DATA,&DMA_CTLInitStruct);
}

void DMA_UARTx_RX_Channelx_Config(void)
{
		DMA_InitTypeDef	DMA_InitStruct;
		DMA_InitStructInit(&DMA_InitStruct);
	
		DEBUG_DMA_APBxClkCmd(DEBUG_DMA_CLK,ENABLE);    			//����DMAʱ��
		
		DMA_32BitsSourcePTR_Write(DEBUG_DMA_DATA,DMA_SourcePTR);	//Դ��ַΪUART1��UARTDR��Ӳ����ַ
		DMA_32BitsTargetPTR_Write(DEBUG_DMA_DATA,DMA_TargetPTR);				//Ŀ���ַΪD_data1�����ַ
		DMA_DATA0_CTLConfig();			//��ؿ�������								
	
		DMA_BasePTR_Write();      //дDMAͨ�����ƻ�ַָ�� ѡ��DMAͨ��
	
		DMA_InitStruct.DMA_Channel_CTRLx = DEBUG_DMA_CTRLx;						//DMA��CTRL�Ĵ���Numberѡ��
		DMA_InitStruct.DMA_REQ0 = DMA_REQ0_ENABLE;										//ͨ������0ʹ��
		DMA_InitStruct.DMA_REQ1 = DMA_REQ1_DISABLE;										//ͨ������1��ʹ��
		DMA_InitStruct.DMA_Request0 = DEBUG_DMA_TRIGGER;							//ѡ������0�ź�
		DMA_InitStruct.DMA_CHxPriority = DMA_CHxPriority_Default;		 
		DMA_InitStruct.DMA_BasePoint = DMA_BasePoint_Main;					//ѡ�����û�ַָ��
		DMA_InitStruct.DMA_Burst = DMA_REQ_SREQ_All;								//��ӦDMA_REQ��DMA_SREQ�ź�
		DMA_Init(&DMA_InitStruct);	
		
		DMA_Channel_Cmd(DEBUG_DMA_CTRLx,ENABLE);		//DMAͨ��0ʹ��
		DMA_ITConfig(DEBUG_DMA_CTRLx,DMA_IT_DONE,ENABLE);			//����DMA����ж�
		DMA_EnableIRQ(1);  	//DMA�ж�ʹ��		
		DMA_Cmd(ENABLE);		//DMAʹ��
}
