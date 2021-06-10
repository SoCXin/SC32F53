#ifndef __DMA_H
#define	__DMA_H

#include "sc32f53xx_conf.h"

#define DMA_CHANNEL0    //ѡ��DMAͨ��

//DMA parameter configuration
#define DMA_TransNum				0x07     											//8��DMA��������
#define DMA_SourcePTR			  (uint32_t *)&(UART1->UARTDR)    //Դ��ַָ��
#define DMA_TargetPTR				(uint32_t *)D_data1    			  //Ŀ���ַָ��


/* DMA_Channel_x��DMA_DATAxͨ��Ҫ��Ӧ */
/* ѡ��DMAͨ��0 */
#ifdef	DMA_CHANNEL0 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_0  
#define  DEBUG_DMA_DATA            		 DMA_DATA0
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL0 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* ѡ��DMAͨ��1 */
#ifdef	DMA_CHANNEL1 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_1  
#define  DEBUG_DMA_DATA            		 DMA_DATA1
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL1 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* ѡ��DMAͨ��2 */
#ifdef	DMA_CHANNEL2 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_2  
#define  DEBUG_DMA_DATA            		 DMA_DATA2
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL2 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* ѡ��DMAͨ��3 */
#ifdef	DMA_CHANNEL3 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_3  
#define  DEBUG_DMA_DATA            		 DMA_DATA3
#define  DEBUG_DMA_CTRLx             	 DMA_Channel_CTRL3 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* ѡ��DMAͨ��4 */
#ifdef	DMA_CHANNEL4 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_4  
#define  DEBUG_DMA_DATA            		 DMA_DATA4
#define  DEBUG_DMA_CTRLx             	 DMA_Channel_CTRL4
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* ѡ��DMAͨ��5 */
#ifdef	DMA_CHANNEL5
#define  DEBUG_DMA_CHANNEL             DMA_Channel_5  
#define  DEBUG_DMA_DATA            		 DMA_DATA5
#define  DEBUG_DMA_CTRLx             	 DMA_Channel_CTRL5
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif
void DMA_DATA0_CTLConfig(void);
void DMA_UARTx_RX_Channelx_Config(void);

#endif 

