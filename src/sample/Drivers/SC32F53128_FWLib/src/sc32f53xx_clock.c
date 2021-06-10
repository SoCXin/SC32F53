/**
  ******************************************************************************
  * @file    sc32f53xx_clock.c
  * @author  MCU Application Team
  * @version V1.0.0
  * @date    21-05-2019
  * @brief   This file provides all the clock system firmware functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
  * AS A RESULT, SLMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
  * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
  * CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
  * INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
  * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
  * IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
  * <h2><center>&copy; COPYRIGHT 2019 Silan Microelectronics </center></h2>
  ********************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sc32f53xx_clock.h"


#define CLKCTRL_CLEAR_Mask           ((uint32_t)0xFFFFFC8D)        /*!< CHIPCTL CLKCTRL Mask  */ 
#define CLKCFG0_CLEAR_Mask           ((uint32_t)0xFFFFF30E)        /*!< CHIPCTL CLKCFG0 Mask  */ 
#define CLKCFG0_XCLKSEL_CLEAR_Mask   ((uint32_t)0x80FFFFFF)        /*!< CHIPCTL CLKCFG0 XCLKSEL Mask  */ 
#define CLKCFG1_SYSCLKSEL_CLEAR_Mask ((uint32_t)0xFFFFFFF8)        /*!< CHIPCTL CLKCFG1 SYSCLKSEL Mask  */ 
#define CLKCFG2_HDIV_CLEAR_Mask      ((uint32_t)0xFFFFFF00)        /*!< CHIPCTL CLKCFG2 HDIV Mask  */ 
#define CLKCFG2_PDIV01_CLEAR_Mask    ((uint32_t)0xFFF0FFFF)        /*!< CHIPCTL CLKCFG2 PDIV01 Mask  */ 
#define CLKCFG2_PDIV23_CLEAR_Mask    ((uint32_t)0xF0FFFFFF)        /*!< CHIPCTL CLKCFG2 PDIV23 Mask  */ 
#define CLKCFG2_MTDIV_CLEAR_Mask     ((uint32_t)0xFFFFF0FF)        /*!< CHIPCTL CLKCFG2 MTDIV Mask  */ 
#define OSC32K_CTRL_CLEAR_Mask       ((uint32_t)0xFFFFCAAB)        /*!< CHIPCTL OSC32K_CTRL Mask  */ 


/**
  * @brief  Enables or disables the AHB01 peripheral clock.
  * @param  CLK_AHB01Periph: specifies the AHB01 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_AHB01Periph_GPIOA, CLK_AHB01Periph_GPIOB, 
  *          CLK_AHB01Periph_GPIOC, CLK_AHB01Periph_GPIOF, 
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CLK_AHB01PeriphClockCmd(uint32_t CLK_AHB01Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CLK_AHB01_PERIPH(CLK_AHB01Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if (NewState != DISABLE)
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_H01 |= CLK_AHB01Periph;
  }
  else
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_H01 &= ~CLK_AHB01Periph;
  }
}

/**
  * @brief  Enables or disables the AHB23 peripheral clock.
  * @param  CLK_AHB23Periph: specifies the AHB23 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_AHB23Periph_COPROC, 
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CLK_AHB23PeriphClockCmd(uint32_t CLK_AHB23Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CLK_AHB23_PERIPH(CLK_AHB23Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if (NewState != DISABLE)
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_H23 |= CLK_AHB23Periph;
  }
  else
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_H23 &= ~CLK_AHB23Periph;
  }
}

/**
  * @brief  Enables or disables the APB01 peripheral clock.
  * @param  CLK_APB01Periph: specifies the APB01 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_APB01Periph_PPU, CLK_APB01Periph_ERU, 
  *          CLK_APB01Periph_DMA, CLK_APB01Periph_UART1, 
  *          CLK_APB01Periph_UART2, CLK_APB01Periph_UART3, 
  *          CLK_APB01Periph_UART4, CLK_APB01Periph_UART5, 
  *          CLK_APB01Periph_UART6, CLK_APB01Periph_I2C,CLK_APB01Periph_I2CCLK_APB01Periph_SSP
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CLK_APB01PeriphClockCmd(uint32_t CLK_APB01Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CLK_APB01_PERIPH(CLK_APB01Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if (NewState != DISABLE)
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_P01 |= CLK_APB01Periph;
  }
  else
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_P01 &= ~CLK_APB01Periph;
  }
}

/**
  * @brief  Enables or disables the APB23 peripheral clock.
  * @param  CLK_APB23Periph: specifies the APB23 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_APB23Periph_TIM14, CLK_APB23Periph_TIM15, 
  *          CLK_APB23Periph_TIM16, CLK_APB23Periph_TIM17, 
  *          CLK_APB23Periph_ADC, CLK_APB23Periph_ACMP_OPA, 
  *          CLK_APB23Periph_TIM1, CLK_APB23Periph_TIM3, 
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void CLK_APB23PeriphClockCmd(uint32_t CLK_APB23Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_CLK_APB23_PERIPH(CLK_APB23Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if (NewState != DISABLE)
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_P23 |= CLK_APB23Periph;
  }
  else
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKEN_P23 &= ~CLK_APB23Periph;
  }
}

/**
  * @brief  Configures the External High Speed oscillator (OSCH).
  * @note   OSCH can not be stopped if it is used directly or through the PLL as system clock.
  * @param  OSCH_ConfigStruct: pointer to a OSCH_ConfigStruct structure that
  *         contains the configuration information for the OSCH.
  * @retval None
  */
void CLK_OSCHConfig(OSCH_ConfigTypeDef* OSCH_ConfigStruct)
{
  uint32_t tmpreg = 0x00;
	
	tmpreg = CHIPCTL->CLKCTRL;
	/* Clear OSCDEN, OSCGAIN, OSCREN, OSCSTS bits */
	tmpreg &= CLKCTRL_CLEAR_Mask;
  /* Set the OSCH configuration bits */
	tmpreg |= (uint32_t)(OSCH_ConfigStruct->OSCH_Detection_ENABLE << 1);
	tmpreg |= (uint32_t)(OSCH_ConfigStruct->OSCH_InResist_ENABLE << 6);
	tmpreg |= (uint32_t)(OSCH_ConfigStruct->CRY_GainSelection << 4);		
	tmpreg |= (uint32_t)(OSCH_ConfigStruct->CRY_StableTime << 8);
	
	/* Write to CLKCTRL */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCTRL = tmpreg;	
}

/**
  * @brief  Fills each OSCH_ConfigStruct member with its default value.
  * @param  OSCH_ConfigStruct : pointer to a OSCH_ConfigTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void OSCH_ConfigStructInit(OSCH_ConfigTypeDef* OSCH_ConfigStruct)
{
  /* Set the default configuration */
  OSCH_ConfigStruct->OSCH_Detection_ENABLE = DISABLE;
  OSCH_ConfigStruct->OSCH_InResist_ENABLE = ENABLE;
  OSCH_ConfigStruct->CRY_GainSelection = OSCH_GAIN_16_32M;
  OSCH_ConfigStruct->CRY_StableTime = OSCH_StableTime_4ms;
}

/**
  * @brief  Configures the External Low Speed oscillator (OSCL).
  * @note   OSCL can not be stopped if it is used directly system clock.
  * @param  OSCL_ConfigStruct: pointer to a OSCL_ConfigStruct structure that
  *         contains the configuration information for the OSCL.
  * @retval None
  */
void CLK_OSCLConfig(OSCL_ConfigTypeDef* OSCL_ConfigStruct)
{
  uint32_t tmpreg = 0x00;
	
	tmpreg = CHIPCTL->OSC32K_CTRL;
	/* Clear REFEN, DETEN, FILEN, INVEN, FAST, GAIN bits */
	tmpreg &= OSC32K_CTRL_CLEAR_Mask;
  /* Set the OSCL configuration bits */
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_InResist_ENABLE << 2);
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_Detection_ENABLE << 4);
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_Filt_ENABLE << 6);		
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_Inverter_ENABLE << 8);
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_FastMode_ENABLE << 10);
	tmpreg |= (uint32_t)(OSCL_ConfigStruct->OSCL_GainSelection << 12);	
	
	/* Write to OSC32K_CTRL */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->OSC32K_CTRL = tmpreg;	
}

/**
  * @brief  Fills each OSCL_ConfigStruct member with its default value.
  * @param  OSCL_ConfigStruct : pointer to a OSCL_ConfigTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void OSCL_ConfigStructInit(OSCL_ConfigTypeDef* OSCL_ConfigStruct)
{
  /* Set the default configuration */
  OSCL_ConfigStruct->OSCL_InResist_ENABLE = ENABLE;
  OSCL_ConfigStruct->OSCL_Detection_ENABLE = ENABLE;
  OSCL_ConfigStruct->OSCL_Filt_ENABLE = DISABLE;
  OSCL_ConfigStruct->OSCL_Inverter_ENABLE = DISABLE;
  OSCL_ConfigStruct->OSCL_FastMode_ENABLE = DISABLE;
  OSCL_ConfigStruct->OSCL_GainSelection = CRY_GAIN_Lowest;
}

/**
  * @brief  Configures the PLL clock source and multiplication factor.
  * @note   This function must be used only when the PLL is disabled.
  * @param  PLL_ConfigStruct: pointer to a PLL_ConfigStruct structure that
  *         contains the configuration information for the PLL.
  * @retval None
  */
void CLK_PLLConfig(PLL_ConfigTypeDef* PLL_ConfigStruct)
{
  uint32_t tmpreg = 0x00;
	
	tmpreg = CHIPCTL->CLKCFG0;
	/* Clear PLLSRC, PLLDIV, PLLMUL, bits */
	tmpreg &= CLKCFG0_CLEAR_Mask;
  /* Set the PLL configuration bits */
	tmpreg |= (uint32_t)(PLL_ConfigStruct->PLL_Source << 0);
	tmpreg |= (uint32_t)(PLL_ConfigStruct->PLL_DIV << 4);
	tmpreg |= (uint32_t)(PLL_ConfigStruct->PLL_MUL << 10);		
	
	/* Write to CLKCFG0 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG0 = tmpreg;	
}

/**
  * @brief  Fills each PLL_ConfigStruct member with its default value.
  * @param  PLL_ConfigStruct : pointer to a PLL_ConfigTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void PLL_ConfigStructInit(PLL_ConfigTypeDef* PLL_ConfigStruct)
{
  /* Set the default configuration */
  PLL_ConfigStruct->PLL_Source = PLLSource_RCH;
  PLL_ConfigStruct->PLL_DIV = PLLDIV_1;
  PLL_ConfigStruct->PLL_MUL = PLLMUL_24;
}

/**
  * @brief Enables or disables the Internal High Speed oscillator (RCH).
  * @param[in] NewState new state of RCHEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CLK_RCHCmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set RCHEN bit */
    CHIPCTL->CLKCTRL_b.RCHEN = 1;
		while(!CHIPCTL->CLKCTRL_b.RCHSTB);
  }
  else
  {
		/* Reset RCHEN bit */
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKCTRL_b.RCHEN = 0;
  }
}

/**
  * @brief Enable or Disable the External High Speed oscillator (OSCH).
  * @param[in] NewState new state of OSCHEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CLK_OSCHCmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set OSCHEN bit */
    CHIPCTL->CLKCTRL_b.OSCEN = 1;
		while(!CHIPCTL->CLKCTRL_b.OSCSTB);
  }
  else
  {
		/* Reset OSCHEN bit */
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKCTRL_b.OSCEN = 0;
  }
}

/**
  * @brief Enable or Disable the External Low Speed oscillator (OSCL).
  * @param[in] NewState new state of OSCLEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CLK_OSCLCmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set OSCLEN bit */
    CHIPCTL->OSC32K_CTRL_b.EN = 1;
  }
  else
  {
		/* Reset OSCLEN bit */
		CHIPCTL_WRITE_KEY;
    CHIPCTL->OSC32K_CTRL_b.EN = 0;
  }
}

/**
  * @brief Enables or disables the Phase-locked loop (PLL).
  * @param[in]  NewState new state of PLLEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CLK_PLLCmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set PLLEN bit */
    CHIPCTL->CLKCTRL_b.PLLEN = 1;
		while(!CHIPCTL->CLKCTRL_b.PLLLOCK);
  }
  else
  {
		/* Reset PLLEN bit */
		CHIPCTL_WRITE_KEY;
    CHIPCTL->CLKCTRL_b.PLLEN = 0;
  }
}

/**
  * @brief  Selects the clock source to output on MCO pin.
  * @param[in] CLK_MCO : Specifies the clock source.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_MCO_RCL, CLK_MCO_RCH, CLK_MCO_OSCIN,CLK_MCO_XCLKINA,CLK_MCO_XCLKINB,
  *          CLK_MCO_PLLOUT,CLK_MCO_PLLREFCLK, CLK_MCO_SYSCLK, CLK_MCO_FCLK.
  * @param[in] MCO_DIV : Specifies the clock division.
  *   This parameter can be any combination of the following values:
  *     @arg CLK_MCO_DIV1, CLK_MCO_DIV2, CLK_MCO_DIV4,CLK_MCO_DIV8,CLK_MCO_DIV16,
  *          CLK_MCO_DIV32,CLK_MCO_DIV64, CLK_MCO_DIV128.
  * @retval None
  */
void CLK_MCOConfig(CLKOutput_TypeDef CLK_MCO, CLKOutDiv_TypeDef MCO_DIV)
{
  uint32_t tmpreg = 0x00;

	tmpreg = CHIPCTL->CLKCFG0;
	/* Clear XCLKSEL, XCLKDIV, bits */
	tmpreg &= CLKCFG0_XCLKSEL_CLEAR_Mask;
	/* Set the MCO configuration bits */
	tmpreg |= (CLK_MCO << 24);
	tmpreg |= (MCO_DIV << 28);
	
	/* Write to CLKCFG0 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG0 = tmpreg;
}

/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  RCC_SYSCLKSource: specifies the clock source used as system clock.
  *   This parameter can be one of the following values:
  *     @arg CLK_SYSCLKSource_RCH: RCH selected as system clock
  *     @arg CLK_SYSCLKSource_OSCH: OSCH selected as system clock
  *     @arg CLK_SYSCLKSource_RCL: RCL selected as system clock
  *     @arg CLK_SYSCLKSource_OSCL: OSCL selected as system clock
  *     @arg RCC_SYSCLKSource_PLLCLK: PLL selected as system clock
  * @retval None
  */
void CLK_SYSCLKConfig(uint32_t CLK_SYSCLKSource)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_CLK_SYSCLK_SOURCE(CLK_SYSCLKSource));
	
	tmpreg = CHIPCTL->CLKCFG1;
	/* Clear SYSCLKSEL, CLK32KSEL, bits */
	tmpreg &= CLKCFG1_SYSCLKSEL_CLEAR_Mask;	
	/* Set the SYSCLK configuration bits */
	tmpreg |= CLK_SYSCLKSource;	
	
	/* Write to CLKCFG1 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG1 = tmpreg;
  while(!CHIPCTL->CLKCFG1_b.SYSCLKLOCK);
}

/**
  * @brief  Configures the AHB clock (HCLK).
  * @param  CLK_SYSCLK: defines the AHB clock divider. This clock is derived from 
  *   the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  *     @arg CLK_SYSCLK = 0x00: AHB clock = SYSCLK
  *     @arg CLK_SYSCLK = 0x01: AHB clock = SYSCLK/2
  *     ...
  *     ...
  *     ...
  *     @arg CLK_SYSCLK = 0xfe: AHB clock = SYSCLK/255
  *     @arg CLK_SYSCLK = 0xff: AHB clock = SYSCLK/256
  * @retval None
  */
void CLK_HCLKConfig(uint8_t CLK_SYSCLK)
{
  uint32_t tmpreg = 0;
  
	tmpreg = CHIPCTL->CLKCFG2;
	/* Clear HDIV, bits */
	tmpreg &= CLKCFG2_HDIV_CLEAR_Mask;	
	/* Set the SYSCLK configuration bits */
	tmpreg |= CLK_SYSCLK;

	/* Write to CLKCFG2 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG2 = tmpreg;		
}

/**
  * @brief  Configures the Low Speed APB01 clock (PCLK01).
  * @param  CLK_HCLK: defines the PCLK01 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg CLK_HCLK_Div1: PCLK01 clock = HCLK
  *     @arg CLK_HCLK_Div2: PCLK01 clock = HCLK/2
  *     ...
  *     @arg CLK_HCLK_Div15: PCLK01 clock = HCLK/15
  *     @arg CLK_HCLK_Div16: PCLK01 clock = HCLK/16
  * @retval None
  */
void CLK_PCLK01Config(uint32_t CLK_HCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_PCLK(CLK_HCLK));
	
  tmpreg = CHIPCTL->CLKCFG2;
  /* Clear PDIV01[3:0] bits */
  tmpreg &= CLKCFG2_PDIV01_CLEAR_Mask;
  /* Set PDIV01[3:0] bits according to CLK_HCLK value */
  tmpreg |= CLK_HCLK<<16;

	/* Write to CLKCFG2 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG2 = tmpreg;
}

/**
  * @brief  Configures the Low Speed APB23 clock (PCLK23).
  * @param  CLK_HCLK: defines the PCLK23 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg CLK_HCLK_Div1: PCLK23 clock = HCLK
  *     @arg CLK_HCLK_Div2: PCLK23 clock = HCLK/2
  *     ...
  *     @arg CLK_HCLK_Div15: PCLK23 clock = HCLK/15
  *     @arg CLK_HCLK_Div16: PCLK23 clock = HCLK/16
  * @retval None
  */
void CLK_PCLK23Config(uint32_t CLK_HCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_PCLK(CLK_HCLK));
	
  tmpreg = CHIPCTL->CLKCFG2;
  /* Clear PDIV23[3:0] bits */
  tmpreg &= CLKCFG2_PDIV23_CLEAR_Mask;
  /* Set PDIV23[3:0] bits according to CLK_HCLK value */
  tmpreg |= CLK_HCLK << 24;

	/* Write to CLKCFG2 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG2 = tmpreg;
}

/**
  * @brief  Configures the Motor control clock (MTCLK).
  * @param  CLK_SYSCLK: defines the MTCLK clock divider. This clock is derived from 
  *   the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  *     @arg CLK_SYSCLK_Div1: MTCLK clock = SYSCLK
  *     @arg CLK_SYSCLK_Div2: MTCLK clock = SYSCLK/2
  *     ...
  *     @arg CLK_SYSCLK_Div15: MTCLK clock = SYSCLK/15
  *     @arg CLK_SYSCLK_Div16: MTCLK clock = SYSCLK/16
  * @retval None
  */
void CLK_MTCLKConfig(uint32_t CLK_SYSCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_MTCLK(CLK_SYSCLK));
	
  tmpreg = CHIPCTL->CLKCFG2;
  /* Clear MTDIV[3:0] bits */
  tmpreg &= CLKCFG2_MTDIV_CLEAR_Mask;
  /* Set MTDIV[3:0] bits according to CLK_SYSCLK value */
  tmpreg |= CLK_SYSCLK;

	/* Write to CLKCFG2 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG2 = tmpreg;
}

/**
  * @brief  SYSTICK Clock source selection.
  * @param  Systick_Source: defines the SYSTICK clock selection. 
  *   This parameter can be one of the following values:
  *     @arg SYSTICK_Source_RCL: select RCL
  *     @arg SYSTICK_Source_RCH_DIV16: select RCH_DIV16
  *     @arg SYSTICK_Source_SCLK_DIV16: select SCLK_DIV16
  * @retval None
  */
void CLK_SystickSel(SystickSel_Typedef Systick_Source)
{
  uint32_t tmpreg = 0;  
	
	tmpreg= CHIPCTL->CLKCFG1;
	
	tmpreg &= ~CHIPCTL_CLKCFG1_SYSTICKSEL_Msk;
	tmpreg |= (Systick_Source << 8);
	
	/* Write to CLKCFG1 */
	CHIPCTL_WRITE_KEY;
	CHIPCTL->CLKCFG1 = tmpreg;	
}


/**
  * @brief  Returns the frequencies of sysclk on chip clocks.
  * @note   The result of this function could be not correct when using 
  *         fractional value for HSE crystal.  
  * @retval The value of SYSCLK clock.
  */
uint32_t CLK_GetSysclkFreq()
{
  uint32_t source = 0, pllmul = 0, plldiv = 0, pllsource = 0;
	uint32_t sysclk_Frequency;
	
  /* Get SYSCLK source -------------------------------------------------------*/
	source = CHIPCTL->CLKCFG1;
	source = source & CHIPCTL_CLKCFG1_SYSCLKSEL_Msk;
	
	switch (source)
	{
    case 0x00:  /* RCH used as system clock */
      sysclk_Frequency = RCH_VALUE;
      break;
    case 0x01:  /* OSCH used as system clock */
      sysclk_Frequency = OSCH_VALUE;
      break;
		case 0x02:  /* PLL used as system clock */
	    /* Get PLL clock source and multiplication factor ----------------------*/
      plldiv = CHIPCTL->CLKCFG0 & CHIPCTL_CLKCFG0_PLLDIV_Msk;
      pllmul = CHIPCTL->CLKCFG0 & CHIPCTL_CLKCFG0_PLLMUL_Msk;
		  pllsource = CHIPCTL->CLKCFG0 & CHIPCTL_CLKCFG0_PLLSRC_Msk;
		
		  plldiv = (plldiv >> 4) + 1;
		  pllmul = ( pllmul >> 10)*4 + 24;
		
      if (pllsource == 0x00)
      { /* HSI oscillator clock selected as PLL clock entry */
        sysclk_Frequency = (RCH_VALUE / plldiv) * pllmul;
      }	
      else 
      { /* OSCH oscillator clock selected as PLL clock entry */
        sysclk_Frequency = (OSCH_VALUE / plldiv) * pllmul;
			}				
		  break;
    case 0x03:
		  if (CHIPCTL->CLKCFG0_b.XCLKINSEL)
			{	
				/* OSCL used as system clock */
        sysclk_Frequency = OSCL_VALUE;
      }
      else 
      {
				/* RCL used as system clock */
			  sysclk_Frequency = RCL_VALUE;
			}		
      break;
    default:
      sysclk_Frequency = RCH_VALUE;
      break;			
	}
  return sysclk_Frequency; 	 
}

/**
  * @brief  Returns the frequencies of hclk on chip clocks.
  * @note   The result of this function could be not correct when using 
  *         fractional value for HSE crystal.  
  * @retval The value of HCLK clock.
  */
uint32_t CLK_GetHclkFreq()
{
  uint32_t hdiv;
	uint32_t hclk_Frequency;
	
  /* Get AHB clock division factor ----------------------*/
  hdiv = CHIPCTL->CLKCFG2 & CHIPCTL_CLKCFG2_HDIV_Msk;
  hdiv = hdiv + 1;	
	/* HCLK clock frequency */
	hclk_Frequency = (CLK_GetSysclkFreq() / hdiv);
	
  return hclk_Frequency; 	 
}

/**
  * @brief  Returns the frequencies of pclk01 on chip clocks.
  * @note   The result of this function could be not correct when using 
  *         fractional value for HSE crystal.  
  * @retval The value of PCLK01 clock.
  */
uint32_t CLK_GetPclk01Freq()
{
  uint32_t pdiv01;
	uint32_t pclk01_Frequency;
	
  /* Get APB clock division factor ----------------------*/
  pdiv01 = CHIPCTL->CLKCFG2 & CHIPCTL_CLKCFG2_PDIV01_Msk; 
	pdiv01 = (pdiv01 >> 16) + 1;
	/* PCLK01 clock frequency */
	pclk01_Frequency = (uint32_t)(CLK_GetHclkFreq() / pdiv01);
	
  return pclk01_Frequency; 	 
}

/**
  * @brief  Returns the frequencies of pclk23 on chip clocks.
  * @note   The result of this function could be not correct when using 
  *         fractional value for HSE crystal.  
  * @retval The value of PCLK23 clock.
  */
uint32_t CLK_GetPclk23Freq()
{
  uint32_t pdiv23;
	uint32_t pclk23_Frequency;
	
  /* Get APB clock division factor ----------------------*/
  pdiv23 = CHIPCTL->CLKCFG2 & CHIPCTL_CLKCFG2_PDIV23_Msk; 
	pdiv23 = (pdiv23 >> 24) + 1;
	/* PCLK23 clock frequency */
	pclk23_Frequency = (CLK_GetHclkFreq() / pdiv23);
	
  return pclk23_Frequency; 	 
}

/**
  * @brief  Returns the frequencies of mtclk on chip clocks.
  * @note   The result of this function could be not correct when using 
  *         fractional value for HSE crystal.  
  * @retval The value of MTCLK clock.
  */
uint32_t CLK_GetMTclkFreq()
{
  uint32_t mtdiv;
	uint32_t mtclk_Frequency;
	
  /* Get MT clock division factor ----------------------*/
  mtdiv = CHIPCTL->CLKCFG2 & CHIPCTL_CLKCFG2_MTDIV_Msk; 
	mtdiv = (mtdiv >> 8) + 1;
	/* MTCLK clock frequency */
	mtclk_Frequency = (CLK_GetSysclkFreq() / mtdiv);
	
  return mtclk_Frequency; 	 
}


