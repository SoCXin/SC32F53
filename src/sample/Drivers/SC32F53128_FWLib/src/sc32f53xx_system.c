#include "sc32f53xx_system.h"


#define MVRCTRL_CLEAR_Mask           ((uint32_t)0xFFFFCFFF)        /*!< CHIPCTL MVRCTRL Mask  */ 
#define LVD_CTRL_CLEAR_Mask          ((uint32_t)0xFE1FFFFF)        /*!< CHIPCTL LVD CTRL Mask  */ 

/**
  * @brief  Enables or disables the wake up source.
  * @param  WakeUpSource: specifies the wake up source.
  *   This parameter can be any combination of the following values:
  *     @arg System_Warkup_IO, System_Warkup_IWDT, 
  *          System_Warkup_DEBUG, System_Warkup_LVD, 
  *          System_Warkup_WT.
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SYSTEM_WakeUpSourceSel(uint32_t WakeUpSource, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_System_Warkup_Source(WakeUpSource));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	if (NewState != DISABLE)
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->WAKEUP_CTRL |= WakeUpSource;
  }
  else
  {
		CHIPCTL_WRITE_KEY;
    CHIPCTL->WAKEUP_CTRL &= ~WakeUpSource;
  }
}

/**
  * @brief Config the VANA analog test signal selection.
	* @param Power_VANA:Specifies the VANA analog test signal selection.
	*   This parameter can be one of the following values:
  *     @arg Power_VANA_VDD15: VANA analog test signal selection is VDD15.
  *     @arg Power_VANA_IB_1u: VANA analog test signal selection is IB_1u.
  *     @arg Power_VANA_VBG: VANA analog test signal selection is VBG.
	*     @arg Power_VANA_VTS: VANA analog test signal selection is VTS.
  * @param[in] NewState new state of VTSEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void VANA_Config(uint32_t Power_VANA)
{	
	/* Check the parameters */
	assert_param(IS_Power_VANA(Power_VANA));
	
	CHIPCTL_WRITE_KEY;
	CHIPCTL->POWER_CTRL |= Power_VANA;
}


/**
  * @brief Enables or disables the VTS.
  * @param[in] NewState new state of VTSEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void VTS_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set VTSEN bit */
    CHIPCTL->POWER_CTRL_b.VTSEN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset VTSEN bit */
    CHIPCTL->POWER_CTRL_b.VTSEN = 0;
  }
}


/**
  * @brief Config the LVR configuration.
	* @param LVRS:Specifies Low voltage reset voltage point.
	*   This parameter can be one of the following values:
  *     @arg Power_LVRS_2_3V: Low voltage reset voltage point 2.3V
  *     @arg Power_LVRS_2_7V: Low voltage reset voltage point 2.7V
  *     @arg Power_LVRS_3_7V: Low voltage reset voltage point 3.7V
	*     @arg Power_LVRS_4_1V: Low voltage reset voltage point 4.1V
  * @param NewState new state of LVREN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void LVR_Config(uint32_t LVRS,FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	assert_param(IS_Power_LVRS(LVRS));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		CHIPCTL->POWER_CTRL |= LVRS;
    CHIPCTL->POWER_CTRL_b.LVREN = 1;	
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		CHIPCTL->POWER_CTRL |= LVRS;
    CHIPCTL->POWER_CTRL_b.LVREN = 0;		
  }
}

/**
  * @brief Config the LVD configuration.
	* @param LVLS:Specifies Low voltage detection voltage point.
	*   This parameter can be one of the following values:
  *     @arg Power_LVLS_2_4V: Low voltage detection voltage point 2.4V
  *     @arg Power_LVLS_2_7V: Low voltage detection voltage point 2.7V
  *     @arg Power_LVLS_3_0V: Low voltage detection voltage point 3.0V
	*     @arg Power_LVLS_3_3V: Low voltage detection voltage point 3.3V
  *     @arg Power_LVLS_3_6V: Low voltage detection voltage point 3.6V
  *     @arg Power_LVLS_3_9V: Low voltage detection voltage point 3.9V
  *     @arg Power_LVLS_4_2V: Low voltage detection voltage point 4.2V
	*     @arg Power_LVLS_4_5V: Low voltage detection voltage point 4.5V
	* @param LVES:Specifies the low voltage detects the external level.
	*   This parameter can be one of the following values:
	*     @arg Power_LVES_Internal: the low voltage detects the external level chooose internal level
  *     @arg Power_LVES_External: the low voltage detects the external level chooose external level
  * @param NewState new state of LVREN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void LVD_Config(uint32_t LVLS,uint32_t LVES,FunctionalState NewState)
{	
	uint32_t tmpreg = 0x00;
	
	/* Check the parameters */
	assert_param(IS_Power_LVLS(LVLS));
	assert_param(IS_Power_LVES(LVES));
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	tmpreg = CHIPCTL->POWER_CTRL;
	tmpreg &= LVD_CTRL_CLEAR_Mask;
	tmpreg |= LVES;
	tmpreg |= LVLS;

  if (NewState != DISABLE)
		tmpreg |= (uint32_t)(1<<20);
  else
		tmpreg &= ~(uint32_t)(1<<20);
	
	CHIPCTL_WRITE_KEY;
	CHIPCTL->POWER_CTRL = tmpreg;
}

/**
  * @brief Enables or disables the CVM.
  * @param[in] NewState new state of CVMEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CVM_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set CVMEN bit */
    CHIPCTL->POWER_CTRL_b.CVMEN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset CVMEN bit */
    CHIPCTL->POWER_CTRL_b.CVMEN = 0;
  }
}

/**
  * @brief Enables or disables the CVM RST.
  * @param[in] NewState new state of CVMREN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void CVMR_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set CVMREN bit */
    CHIPCTL->POWER_CTRL_b.CVMREN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset CVMREN bit */
    CHIPCTL->POWER_CTRL_b.CVMREN = 0;
  }
}

/**
  * @brief Enables or disables the POCR .
  * @param[in] NewState new state of POCREN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void POCR_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set POCREN bit */
    CHIPCTL->POWER_CTRL_b.POCREN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset POCREN bit */
    CHIPCTL->POWER_CTRL_b.POCREN = 0;
  }
}

/**
  * @brief Enables or disables the LOCKUPR .
  * @param[in] NewState new state of LOCKUPREN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void LOCKUPR_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set LOCKUPREN bit */
    CHIPCTL->POWER_CTRL_b.LOCKUPREN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset LOCKUPREN bit */
    CHIPCTL->POWER_CTRL_b.LOCKUPREN = 0;
  }
}

/**
  * @brief Enables or disables the SYSCLK_DCT.
  * @param[in] NewState new state of SYSCLK_DCTEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void SYSCLK_DCT_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set SYSCLK_DCTEN bit */
    CHIPCTL->POWER_CTRL_b.SYSCLK_DCTEN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset SYSCLK_DCTEN bit */
    CHIPCTL->POWER_CTRL_b.SYSCLK_DCTEN = 0;
  }
}

/**
  * @brief Enables or disables the SYSCLK_MUX_RSTEN .
  * @param[in] NewState new state of SYSCLK_MUX_RSTEN, value accepted ENABLE, DISABLE.
  * @retval None
  */
void SYSCLK_MUX_RST_Cmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
		/* Set SYSCLK_MUX_RSTEN bit */
    CHIPCTL->POWER_CTRL_b.SYSCLK_MUX_RSTEN = 1;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
		/* Reset SYSCLK_MUX_RSTEN bit */
    CHIPCTL->POWER_CTRL_b.SYSCLK_MUX_RSTEN = 0;
  }
}

/**
  * @brief Enables or disables enter Sleep mode under CMO Debug connection state .
  * @param[in] NewState new state of enter Sleep mode under CMO Debug, value accepted ENABLE, DISABLE.
  * @retval None
  */
void Debug_SleepStateCmd(FunctionalState NewState)
{	
	/* Check the parameters */
	assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  if (NewState != DISABLE)
  {
    CHIPCTL_WRITE_KEY;
    CHIPCTL->POWER_CTRL_b.DEBUG_NOSLEEP = 0;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
    CHIPCTL->POWER_CTRL_b.DEBUG_NOSLEEP = 1; 
  }
}

/**
  * @brief  Config the MVR voltage and power dissipation
  * @param PowerState : Specifies the MVR power dissipation.
  * This parameter can be @arg MVR_PowerState_Low ,MVR_PowerState_Normal.
  * @param MVRVolt : Specifies the MVR voltage.
  * This parameter can be @arg Power_MVR_1_5V ,Power_MVR_1_7V.
  * @retval None
  */
void MVR_Config(uint32_t PowerState, uint32_t MVRVolt)
{	
	uint32_t tmpreg = 0x00;
	
	/* Check the parameters */
	assert_param(IS_Power_MVRVolt(MVRVolt));
	assert_param(IS_MVR_PowerState(PowerState));
	
  tmpreg = CHIPCTL->POWER_CTRL;
	tmpreg &= MVRCTRL_CLEAR_Mask;
	tmpreg |= PowerState;
	tmpreg |= MVRVolt;
	
	CHIPCTL_WRITE_KEY;
	CHIPCTL->POWER_CTRL = tmpreg;
}

/**
  * @brief  Config the Power Source to be low power or normal power
  * @param LowPower_Source : Specifies  power dissipation Source.
  * This parameter can be  @arg DeepSleep_LowPower_MVR£¬DeepSleep_LowPower_FLASH
	*	LowPower_Source_SRAM.
  * @param NewState : Specifies the Source power dissipation State.
  * This parameter can be  @arg NormalPower£¬LowPower.
  * @retval None
  */
void Power_SourceConfig(uint32_t LowPower_Source, PowerState NewState)
{		
	/* Check the parameters */
	assert_param(IS_DeepSleep_LowPower_Source(LowPower_Source));
	assert_param(IS_POWER_STATE(NewState));
	
  if (NewState != NormalPower)
  {
    CHIPCTL_WRITE_KEY;
    CHIPCTL->POWER_CTRL |= LowPower_Source;
  }
  else
  {		
		CHIPCTL_WRITE_KEY;
    CHIPCTL->POWER_CTRL &= ~LowPower_Source;
  }
}

/**
  * @brief  Config the state of the SRAM clock in sleep mode
  * @param NewState : Specifies the SRAM clock State in sleep mode.
  * This parameter can be @arg CLKOpen£¬CLKClose.
  * @retval None
  */
void SRAM_SleepCLKConfig(SleepCLKState STATE)
{	
	
	/* Check the parameters */
	assert_param(IS_SleepCLK_STATE(STATE));
	
	CHIPCTL_WRITE_KEY;
	CHIPCTL->POWER_CTRL_b.SRAM_CG = STATE;
}

/**
  * @brief  Config the state of the FLASH clock in sleep mode
  * @param NewState : Specifies the FLASH clock State in sleep mode.
  * This parameter can be @arg CLKOpen£¬CLKClose.
  * @retval None
  */
void FLASH_SleepCLKConfig(SleepCLKState STATE)
{	
	
	/* Check the parameters */
	assert_param(IS_SleepCLK_STATE(STATE));
	
	CHIPCTL_WRITE_KEY;
	CHIPCTL->POWER_CTRL_b.FLASH_CG = STATE;
}

/**
  * @brief  Config the Status of interrupt mask events
  * @param ITMask : Specifies  interrupt mask Source.
  *   This parameter can be one of the following values:
  *     @arg System_Config_PRO: POR reset interrupt mask
  *     @arg System_Config_POC: POC interrupt mask
  *     @arg System_Config_CVM: Kernel voltage monitoring interrupt mask
	*     @arg System_Config_LVR:	LVR reset interrupt mask
  *     @arg System_Config_LVD: LVD interrupt mask	
  *     @arg System_Config_NRST: External reset interrupt mask
  *     @arg System_Config_WDTRST: WDT reset interrupt mask
	*     @arg System_Config_IWDTRST:	IWDT reset interrupt mask
  *     @arg System_Config_SRST: System reset request interrupt mask
  *     @arg System_Config_LOCKUP: Lockup interrupt mask
  *     @arg System_Config_SYSCLKMUX_RST: System clock failure reset interrupt mask
	*     @arg System_Config_IO_WARKUP: IO awaken interrupt mask
  *     @arg System_Config_DEBUG_VALID: Debug awaken interrupt mask
  *     @arg System_Config_RCH_MISS: RCH Clock instability interrupt mask
  *     @arg System_Config_OSC_MISS: OSC clock instability interrupt mask
	*     @arg System_Config_PLL_MISS:	PLL unlocking interrupt mask
  *     @arg System_Config_SYSCLKMUX_ERR: System clock failure interrupt mask
  *     @arg System_Config_SCLKSEL_CFGERR: System clock configuration error interrupt mask
	*     @arg System_Config_PLLSRC_CFGERR: PLL reference clock source selection configuration error interrupt mask
  *     @arg System_Config_RCHEN_CFGERR: RCH enable configuration error interrupt mask
  *     @arg System_Config_OSCEN_CFGERR: OSC enable configuration error interrupt mask
  *     @arg System_Config_PLLEN_CFGERR: PLL enable configuration error interrupt mask
  * @param NewState : Specifies the interrupt mask State.
  * This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void System_ITMaskConfig(uint32_t ITMask,FunctionalState NewState)
{
		/* Check the parameters */
		assert_param(IS_System_ITMask(ITMask));	
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		
		if (NewState != DISABLE)
		{
				CHIPCTL_WRITE_KEY;
				CHIPCTL->INTMASK &= ~ITMask;
		}
		else
		{
				CHIPCTL_WRITE_KEY;
				CHIPCTL->INTMASK |= ITMask;
		}
}

/**
  * @brief  Get the Status0 of interrupt mask events
  * @param EventStatus : Specifies  interrupt mask Source.
  *   This parameter can be one of the following values:
  *     @arg System_Config_PRO: POR reset interrupt mask
  *     @arg System_Config_POC: POC interrupt mask
  *     @arg System_Config_CVM: Kernel voltage monitoring interrupt mask
	*     @arg System_Config_LVR:	LVR reset interrupt mask
  *     @arg System_Config_LVD: LVD interrupt mask	
  *     @arg System_Config_NRST: External reset interrupt mask
  *     @arg System_Config_WDTRST: WDT reset interrupt mask
	*     @arg System_Config_IWDTRST:	IWDT reset interrupt mask
  *     @arg System_Config_SRST: System reset request interrupt mask
  *     @arg System_Config_LOCKUP: Lockup interrupt mask
  *     @arg System_Config_SYSCLKMUX_RST: System clock failure reset interrupt mask
	*     @arg System_Config_IO_WARKUP: IO awaken interrupt mask
  *     @arg System_Config_DEBUG_VALID: Debug awaken interrupt mask
  *     @arg System_Config_RCH_MISS: RCH Clock instability interrupt mask
  *     @arg System_Config_OSC_MISS: OSC clock instability interrupt mask
	*     @arg System_Config_PLL_MISS:	PLL unlocking interrupt mask
  *     @arg System_Config_SYSCLKMUX_ERR: System clock failure interrupt mask
  *     @arg System_Config_SCLKSEL_CFGERR: System clock configuration error interrupt mask
	*     @arg System_Config_PLLSRC_CFGERR: PLL reference clock source selection configuration error interrupt mask
  *     @arg System_Config_RCHEN_CFGERR: RCH enable configuration error interrupt mask
  *     @arg System_Config_OSCEN_CFGERR: OSC enable configuration error interrupt mask
  *     @arg System_Config_PLLEN_CFGERR: PLL enable configuration error interrupt mask
  * @retval The new state of interrupt mask events(SET or RESET).
  */
FlagStatus System_GetEventStatus0(uint32_t EventStatus)
{
		FlagStatus bitstatus = RESET;
		/* Check the parameters */
		assert_param(IS_System_EventStatus(EventStatus));	
	
		if((CHIPCTL->STATUS0 & EventStatus) != (uint32_t)RESET)
		{
				bitstatus = SET;
		}
		else
		{
				bitstatus = RESET;
		}
		return bitstatus;
}

/**
  * @brief  Clear the state0 of interrupt mask events
  * @retval None
  */
void System_ClearEventStatus0(void)
{
		CHIPCTL_WRITE_KEY;
		CHIPCTL->STATUS0 = (uint32_t)0xa05fcccc;
}


/**
  * @brief  Get the Status of status1 register events
  * @param Status1 : Specifies the status1 register events
  *   This parameter can be one of the following values:
  *     @arg System_Status1_OSCSTOP: POR reset interrupt mask
  *     @arg System_Status1_RCHSTB: POC interrupt mask
  *     @arg System_Status1_PLL_LOCK: Kernel voltage monitoring interrupt mask
	*     @arg System_Status1_LVDFLAG:	LVR reset interrupt mask
  *     @arg System_Status1_CVMFLAG: LVD interrupt mask	
  *     @arg System_Status1_BGRFLAG: External reset interrupt mask
  *     @arg System_Status1_IWDT_INTR: IWDT interrupt state
  * @retval The new state ofthe status1 register events(SET or RESET).
  */
FlagStatus System_GetStatus1(uint32_t Status1)
{
		FlagStatus bitstatus = RESET;
		/* Check the parameters */
		assert_param(IS_System_Status1(Status1));		
	 
		if((CHIPCTL->STATUS1 & Status1) != (uint32_t)RESET)
		{
				bitstatus = SET;
		}
		else
		{
				bitstatus = RESET;
		}
		return bitstatus;
}

/**
  * @brief  Config the PA13¡¢PA14 Reuse status.
  * @param  Reuse: Specifies PA13¡¢PA14 Reuse status.
  *   This parameter can be one of the following values:
*     @arg PA13_PA14_Debug:	as Debug Port
*     @arg PA13_PA14_IOPort: as IO Port
  * @retval None
  */
void PA13_PA14_ReuseConfig(uint8_t Reuse)
{
		/* Check the parameters */
		assert_param(IS_PA13_PA14_Reuse(Reuse));
		
		if(Reuse == PA13_PA14_Reuse_IOPort)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL |= 0xa05f1000;
		}	
		else if(Reuse == PA13_PA14_Reuse_Debug)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL = (uint32_t)((~CHIPCTL_REMAP_CTRL_DEBUG_USEASFUNC_Msk&CHIPCTL->REMAP_CTRL)|(0xa05f0000));				
		}	
}

/**
  * @brief  Config the XRST Reuse status.
  * @param  Reuse: Specifies the XRST Reuse status.
  *   This parameter can be one of the following values:
*     @arg XRST_Reuse_IOPort:	as IO Port
*     @arg XRST_Reuse_RST: as RST Port
  * @retval None
  */
void XRST_ReuseConfig(uint8_t Reuse)
{
		/* Check the parameters */
		assert_param(IS_XRST_Reuse(Reuse));
		
		if(Reuse == XRST_Reuse_IOPort)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL |= 0xa05f0100;
		}	
		else if(Reuse == XRST_Reuse_RST)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL = (uint32_t)((~CHIPCTL_REMAP_CTRL_XRST_USEASFUNC_Msk&CHIPCTL->REMAP_CTRL)|(0xa05f0000));				
		}	
}

/**
  * @brief Enables or disables system reset output.
  * @param[in]  NewState new state of system reset output, value accepted ENABLE, DISABLE.
  * @retval None
  */
void SYSRESET_OUTEN_Cmd(FunctionalState NewState)
{	
		/* Check the parameters */
		assert_param(IS_FUNCTIONAL_STATE(NewState));
		
		if (NewState != DISABLE)
		{
				CHIPCTL_WRITE_KEY;
				CHIPCTL->REMAP_CTRL |= 0xa05f0200;
		}
		else
		{		
				CHIPCTL_WRITE_KEY;
				CHIPCTL->REMAP_CTRL = (uint32_t)((~CHIPCTL_REMAP_CTRL_SYSRESET_OUTEN_Msk&CHIPCTL->REMAP_CTRL)|(0xa05f0000));
		}
}

/**
  * @brief  Config the system reset output port.
  * @param  OutSel: Specifies the system reset output port.
  *   This parameter can be one of the following values:
*     @arg SYSRESRT_OutSel_PB4:	system reset output port is PB4
*     @arg SYSRESRT_OutSel_PC2: system reset output port is PC2
  * @retval None
  */
void SYSRESRT_OutSel_Config(uint8_t OutSel)
{
		/* Check the parameters */
		assert_param(IS_SYSRESRT_OutSel(OutSel));
		
		if(OutSel == SYSRESRT_OutSel_PB4)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL |= 0xa05f0400;
		}	
		else if(OutSel == SYSRESRT_OutSel_PC2)
		{
				CHIPCTL->CHIP_KEY =0x05fa659aul;
				CHIPCTL->REMAP_CTRL = (uint32_t)((~CHIPCTL_REMAP_CTRL_SYSRESET_OUTSEL_Msk&CHIPCTL->REMAP_CTRL)|(0xa05f0000));				
		}	
}


