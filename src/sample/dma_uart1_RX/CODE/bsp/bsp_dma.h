#ifndef __DMA_H
#define	__DMA_H

#include "sc32f53xx_conf.h"

#define DMA_CHANNEL0    //选择DMA通道

//DMA parameter configuration
#define DMA_TransNum				0x07     											//8次DMA传输总数
#define DMA_SourcePTR			  (uint32_t *)&(UART1->UARTDR)    //源地址指针
#define DMA_TargetPTR				(uint32_t *)D_data1    			  //目标地址指针


/* DMA_Channel_x与DMA_DATAx通道要对应 */
/* 选择DMA通道0 */
#ifdef	DMA_CHANNEL0 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_0  
#define  DEBUG_DMA_DATA            		 DMA_DATA0
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL0 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* 选择DMA通道1 */
#ifdef	DMA_CHANNEL1 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_1  
#define  DEBUG_DMA_DATA            		 DMA_DATA1
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL1 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* 选择DMA通道2 */
#ifdef	DMA_CHANNEL2 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_2  
#define  DEBUG_DMA_DATA            		 DMA_DATA2
#define  DEBUG_DMA_CTRLx               DMA_Channel_CTRL2 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* 选择DMA通道3 */
#ifdef	DMA_CHANNEL3 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_3  
#define  DEBUG_DMA_DATA            		 DMA_DATA3
#define  DEBUG_DMA_CTRLx             	 DMA_Channel_CTRL3 
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* 选择DMA通道4 */
#ifdef	DMA_CHANNEL4 
#define  DEBUG_DMA_CHANNEL             DMA_Channel_4  
#define  DEBUG_DMA_DATA            		 DMA_DATA4
#define  DEBUG_DMA_CTRLx             	 DMA_Channel_CTRL4
#define  DEBUG_DMA_TRIGGER             DMA_UART1_RX

#define  DEBUG_DMA_APBxClkCmd          CLK_APB01PeriphClockCmd
#define  DEBUG_DMA_CLK           			 CLK_APB01Periph_DMA
#endif

/* 选择DMA通道5 */
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

