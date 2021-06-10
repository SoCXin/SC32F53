#ifndef __USART_H
#define	__USART_H

#include "sc32f53xx_conf.h"


/** 
  * ���ں궨�壬��ͬ�Ĵ��ڸ��õ�IO��һ������ֲʱ��ע�⣡
  */

#define  UART1_On


// ����1-UART1����
#ifdef	UART1_On
#define  DEBUG_UARTx                   UART1
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART1
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

//����PB6--UART_TX��PB7--UART_RX   
#define  DEBUG_UART_TX_GPIO_PORT       PB  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_6   
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF0
#define  DEBUG_UART_RX_GPIO_PORT       PB
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_7
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF0

////����PA2--UART_TX��PA3--UART_RX��ע��QSB��PA2���е���C15�� 
//#define  DEBUG_UART_TX_GPIO_PORT       PA  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_2   
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF1
//#define  DEBUG_UART_RX_GPIO_PORT       PA
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_3
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF1

////����PA9--UART_TX��PA10--UART_RX 
//#define  DEBUG_UART_TX_GPIO_PORT       PA  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_9   
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF1
//#define  DEBUG_UART_RX_GPIO_PORT       PA
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_10
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF1

////����PA14--UART_TX��PA15--UART_RX  ���Ƽ�ʹ�ã�P14Ϊ����ܽţ�  
//#define  DEBUG_UART_TX_GPIO_PORT       PA  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_14   
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF1
//#define  DEBUG_UART_RX_GPIO_PORT       PA
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_15
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF1
#endif


// ����2-UART2����  
#ifdef	UART2_On
#define  DEBUG_UARTx                   UART2
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART2
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

//����PA2--UART_TX��PA3--UART_RX ��ע��QSB�ϲ�����ȥ�����ߵ���SA2)
#define  DEBUG_UART_TX_GPIO_PORT       PA  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_2
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF2
#define  DEBUG_UART_RX_GPIO_PORT       PA
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_3
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF2

////����PA14--UART_TX��PA15--UART_RX   ���Ƽ�ʹ�ã�P14Ϊ����ܽţ�  
//#define  DEBUG_UART_TX_GPIO_PORT       PA  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_14
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF2
//#define  DEBUG_UART_RX_GPIO_PORT       PA
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_15
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF2
#endif


//����3-UART3����
#ifdef	UART3_On
#define  DEBUG_UARTx                   UART3
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART3
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

//����PB10--UART_TX��PB11--UART_RX  
#define  DEBUG_UART_TX_GPIO_PORT       PB  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_10
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF4
#define  DEBUG_UART_RX_GPIO_PORT       PB
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_11
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF4

//����PC4--UART_TX��PC5--UART_RX  
//#define  DEBUG_UART_TX_GPIO_PORT       PC  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_4
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF1
//#define  DEBUG_UART_RX_GPIO_PORT       PC
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_5
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF1

////����PC10--UART_TX��PC11--UART_RX  
//#define  DEBUG_UART_TX_GPIO_PORT       PC  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_10
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF1
//#define  DEBUG_UART_RX_GPIO_PORT       PC
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_11
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF1

#endif


// ����4-UART4����
#ifdef	UART4_On
#define  DEBUG_UARTx                   UART4
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART4
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

//////����PC10--UART_TX��PC11--UART_RX      
////#define  DEBUG_UART_TX_GPIO_PORT       PC  
////#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_10
////#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF0
////#define  DEBUG_UART_RX_GPIO_PORT       PC
////#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_11
////#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF0

//����PA0--UART_TX��PA1--UART_RX  ��ע��QSB�ϲ�����ȥ�����ߵ���SA0��SA1�� 
#define  DEBUG_UART_TX_GPIO_PORT       PA  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_0
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF4
#define  DEBUG_UART_RX_GPIO_PORT       PA
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_1
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF4

#endif


// ����5-UART5����
#ifdef	UART5_On
#define  DEBUG_UARTx                   UART5
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART5
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

//����PB3--UART_TX��PB4--UART_RX     
#define  DEBUG_UART_TX_GPIO_PORT       PB  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_3
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF4
#define  DEBUG_UART_RX_GPIO_PORT       PB
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_4
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF4

////����PC12--UART_TX��PF2--UART_RX     
//#define  DEBUG_UART_TX_GPIO_PORT       PC  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_12
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF2
//#define  DEBUG_UART_RX_GPIO_PORT       PF
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_2
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF2
#endif


// ����6-UART6����
#ifdef	UART6_On
#define  DEBUG_UARTx                   UART6
#define  DEBUG_UART_CLK                CLK_APB01Periph_UART6
#define  DEBUG_UART_APBxClkCmd         CLK_APB01PeriphClockCmd
#define  DEBUG_UART_BAUDRATE           115200

////����PA4--UART_TX��PA5--UART_RX     
//#define  DEBUG_UART_TX_GPIO_PORT       PA  
//#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_4
//#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF5
//#define  DEBUG_UART_RX_GPIO_PORT       PA
//#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_5
//#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF5

//����PC0--UART_TX��PC1--UART_RX     
#define  DEBUG_UART_TX_GPIO_PORT       PC  
#define  DEBUG_UART_TX_GPIO_PIN        GPIO_Pin_0
#define  DEBUG_UART_TX_GPIO_AFx        GPIO_AF2
#define  DEBUG_UART_RX_GPIO_PORT       PC
#define  DEBUG_UART_RX_GPIO_PIN        GPIO_Pin_1
#define  DEBUG_UART_RX_GPIO_AFx        GPIO_AF2
#endif


void UART_Config(void);
void UART_SendArray( UART1_Type* UARTx, uint8_t *array, uint16_t num);
void UART_SendString( UART1_Type* UARTx, char *str);
void UART_SendHalfWord( UART1_Type* UARTx, uint16_t ch);

#endif /* __USART_H */
