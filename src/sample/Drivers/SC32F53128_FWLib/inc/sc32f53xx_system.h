#ifndef __SC32F53xx_SYSTEM_H
#define __SC32F53xx_SYSTEM_H

#include "sc32f53xx_conf.h"


/** @defgroup Power_VANA signal selection 
  * @{
  */
#define 	Power_VANA_VDD15				(uint32_t)0x00000000    /*!<VANA analog test signal selection is VDD15. */
#define 	Power_VANA_IB_1u				(uint32_t)0x10000000    /*!<VANA analog test signal selection is IB_1u. */
#define 	Power_VANA_VBG					(uint32_t)0x20000000    /*!<VANA analog test signal selection is VBG. */
#define 	Power_VANA_VTS					(uint32_t)0x30000000    /*!<VANA analog test signal selection is VTS. */

#define IS_Power_VANA(VANA)			(((VANA) == Power_VANA_VDD15) || ((VANA) == Power_VANA_IB_1u)|| \
																((VANA) == Power_VANA_VBG)  || ((VANA) == Power_VANA_VTS))

/** @defgroup Power_LVRS Select 
  * @{
  */
#define 	Power_LVRS_2_3V				(uint32_t)0x00000000    /*!<Low voltage reset voltage point selection is 2.3V. */
#define 	Power_LVRS_2_7V				(uint32_t)0x00010000    /*!<Low voltage reset voltage point selection is 2.7V. */			
#define 	Power_LVRS_3_7V				(uint32_t)0x00020000    /*!<Low voltage reset voltage point selection is 3.7V. */
#define 	Power_LVRS_4_1V				(uint32_t)0x00030000    /*!<Low voltage reset voltage point selection is 4.1V. */

#define IS_Power_LVRS(LVRS)			(((LVRS) == Power_LVRS_2_3V) || ((LVRS) == Power_LVRS_2_7V)|| \
																((LVRS) == Power_LVRS_3_7V)  || ((LVRS) == Power_LVRS_4_1V))

/** @defgroup Power_LVLS Select 
  * @{
  */
#define 	Power_LVLS_2_4V				(uint32_t)0x00000000    /*!<Low voltage detection voltage point selection is 2.4V. */
#define 	Power_LVLS_2_7V				(uint32_t)0x00400000    /*!<Low voltage detection voltage point selection is 2.7V. */			
#define 	Power_LVLS_3_0V				(uint32_t)0x00800000    /*!<Low voltage detection voltage point selection is 3.0V. */
#define 	Power_LVLS_3_3V				(uint32_t)0x00C00000    /*!<Low voltage detection voltage point selection is 3.3V. */
#define 	Power_LVLS_3_6V				(uint32_t)0x01000000    /*!<Low voltage detection voltage point selection is 3.6V. */
#define 	Power_LVLS_3_9V				(uint32_t)0x01400000    /*!<Low voltage detection voltage point selection is 3.9V. */			
#define 	Power_LVLS_4_2V				(uint32_t)0x01800000    /*!<Low voltage detection voltage point selection is 4.2V. */
#define 	Power_LVLS_4_5V				(uint32_t)0x01C00000    /*!<Low voltage detection voltage point selection is 4.5V. */

#define IS_Power_LVLS(LVLS)			(((LVLS) == Power_LVLS_2_4V) || ((LVLS) == Power_LVLS_2_7V)|| \
																((LVLS) == Power_LVLS_3_0V)  || ((LVLS) == Power_LVLS_3_3V)||\
																((LVLS) == Power_LVLS_3_6V)  || ((LVLS) == Power_LVLS_3_9V)|| \
																((LVLS) == Power_LVLS_4_2V)  || ((LVLS) == Power_LVLS_4_5V))

/** @defgroup Power_LVES Select 
  * @{
  */
#define  Power_LVES_Internal		(uint32_t)0x00000000    /*!<Low voltage detection external level select internal level. */
#define  Power_LVES_External		(uint32_t)0x00200000    /*!<Low voltage detection external level select external level. */	

#define IS_Power_LVES(LVES)			(((LVES) == Power_LVES_Internal) || ((LVES) == Power_LVES_External))

/** @defgroup LowPower_Source Select 
  * @{
  */
#define  DeepSleep_LowPower_MVR			(uint32_t)0x00000001    /*!<Deep Sleep mode,Low power selective source is MVR. */
#define  DeepSleep_LowPower_FLASH		(uint32_t)0x00000020    /*!<Deep Sleep mode,Low power selective source is FLASH. */
//#define  LowPower_Source_SRAM			(uint32_t)0x00000040

#define IS_DeepSleep_LowPower_Source(Source)			((((Source) & 0xFFFFFFDE) == 0x00) && ((Source) != 0x00))

/** @defgroup Power_MVR Select 
  * @{
  */
#define  Power_MVR_1_5V		(uint32_t)0x00000000    /*!<MVR voltage selection is 1.5V. */
#define  Power_MVR_1_7V		(uint32_t)0x00002000    /*!<MVR voltage selection is 1.7V. */	

#define IS_Power_MVRVolt(MVRVolt)			(((MVRVolt) == Power_MVR_1_5V) || ((MVRVolt) == Power_MVR_1_7V))

/** @defgroup MVR_Power_State Config 
  * @{
  */
#define  MVR_PowerState_Low				(uint32_t)0x00000000    /*!<MVR power consumption selects low power consumption mode. */
#define  MVR_PowerState_Normal		(uint32_t)0x00001000    /*!<MVR power consumption selects normal power consumption mode. */	

#define IS_MVR_PowerState(PowerState)		(((PowerState) == MVR_PowerState_Low) || ((PowerState) == MVR_PowerState_Normal))

/** @defgroup System_Config 
  * @{
  */
#define  System_Config_POR							(uint32_t)0x00000001    /*!<POR restoration bit. */
#define  System_Config_POC							(uint32_t)0x00000002    /*!<POC event bit. */
#define  System_Config_CVM							(uint32_t)0x00000004    /*!<Kernel voltage low voltage event bit. */
#define  System_Config_LVR							(uint32_t)0x00000008    /*!<LVR restoration bit. */
#define  System_Config_LVD							(uint32_t)0x00000010    /*!<LVD event bit. */
#define  System_Config_NRST							(uint32_t)0x00000020    /*!<NRST event bit. */
#define  System_Config_WDTRST						(uint32_t)0x00000040    /*!<WDT restoration bit. */
#define  System_Config_IWDTRST					(uint32_t)0x00000080    /*!<IWDT restoration bit. */
#define  System_Config_SRST							(uint32_t)0x00000100    /*!<System restoration request bit. */
#define  System_Config_LOCKUP						(uint32_t)0x00000200    /*!<CortexM0 lookup event bit. */
#define  System_Config_SYSCLKMUX_RST		(uint32_t)0x00000400    /*!<Reset event of system clock failure. */
#define  System_Config_IO_WARKUP				(uint32_t)0x00000800    /*!<IO wake up the event bit. */
#define  System_Config_DEBUG_VALID			(uint32_t)0x00001000    /*!<Debugging signal valid control bit. */
#define  System_Config_RCH_MISS					(uint32_t)0x00010000    /*!<RCH clock is stable or unstable. */
#define  System_Config_OSC_MISS					(uint32_t)0x00040000    /*!<OSC clock is stable or unstable. */
#define  System_Config_PLL_MISS					(uint32_t)0x00100000    /*!<PLL clock is stable or unstable. */
#define  System_Config_SYSCLKMUX_ERR		(uint32_t)0x00400000    /*!<System clock failure bit. */
#define  System_Config_SCLKSEL_CFGERR		(uint32_t)0x01000000    /*!<System clock configuration error bit. */
#define  System_Config_PLLSRC_CFGERR		(uint32_t)0x02000000    /*!<PLL reference clock source selection configuration error bit. */
#define  System_Config_RCHEN_CFGERR			(uint32_t)0x08000000    /*!<RCH enable configuration error bit. */
#define  System_Config_OSCEN_CFGERR			(uint32_t)0x10000000    /*!<OSC enable configuration error bit. */
#define  System_Config_PLLEN_CFGERR			(uint32_t)0x20000000    /*!<PSS enable configuration error bit. */


#define IS_System_EventStatus(EventStatus)		(((EventStatus) == System_Config_POR) || ((EventStatus) == System_Config_POC)||\
																							((EventStatus) == System_Config_CVM) || ((EventStatus) == System_Config_LVR)||\
																							((EventStatus) == System_Config_LVD) || ((EventStatus) == System_Config_NRST)||\
																							((EventStatus) == System_Config_WDTRST) || ((EventStatus) == System_Config_IWDTRST)||\
																							((EventStatus) == System_Config_SRST) || ((EventStatus) == System_Config_LOCKUP)||\
																							((EventStatus) == System_Config_SYSCLKMUX_RST) || ((EventStatus) == System_Config_IO_WARKUP)||\
																							((EventStatus) == System_Config_DEBUG_VALID) || ((EventStatus) == System_Config_RCH_MISS)||\
																							((EventStatus) == System_Config_OSC_MISS) || ((EventStatus) == System_Config_PLL_MISS)||\
																							((EventStatus) == System_Config_SYSCLKMUX_ERR) || ((EventStatus) == System_Config_SCLKSEL_CFGERR)||\
																							((EventStatus) == System_Config_PLLSRC_CFGERR) || ((EventStatus) == System_Config_RCHEN_CFGERR)||\
																							((EventStatus) == System_Config_OSCEN_CFGERR) || ((EventStatus) == System_Config_PLLEN_CFGERR))

#define IS_System_ITMask(ITMask)		(((ITMask) == System_Config_POR) || ((ITMask) == System_Config_POC)||\
																		((ITMask) == System_Config_CVM) || ((ITMask) == System_Config_LVR)||\
																		((ITMask) == System_Config_LVD) || ((ITMask) == System_Config_NRST)||\
																		((ITMask) == System_Config_WDTRST) || ((ITMask) == System_Config_IWDTRST)||\
																		((ITMask) == System_Config_SRST) || ((ITMask) == System_Config_LOCKUP)||\
																		((ITMask) == System_Config_SYSCLKMUX_RST) || ((ITMask) == System_Config_IO_WARKUP)||\
																		((ITMask) == System_Config_DEBUG_VALID) || ((ITMask) == System_Config_RCH_MISS)||\
																		((ITMask) == System_Config_OSC_MISS) || ((ITMask) == System_Config_PLL_MISS)||\
																		((ITMask) == System_Config_SYSCLKMUX_ERR) || ((ITMask) == System_Config_SCLKSEL_CFGERR)||\
																		((ITMask) == System_Config_PLLSRC_CFGERR) || ((ITMask) == System_Config_RCHEN_CFGERR)||\
																		((ITMask) == System_Config_OSCEN_CFGERR) || ((ITMask) == System_Config_PLLEN_CFGERR))


/** @defgroup System_Status1_Register 
  * @{
  */
#define  System_Status1_OSCSTOP							(uint32_t)0x00000001    /*!<OSC stop bit. */
#define  System_Status1_RCHSTB							(uint32_t)0x00000008    /*!<RCH stable bit. */
#define  System_Status1_PLL_LOCK						(uint32_t)0x00000020    /*!<PLL lock bit. */
#define  System_Status1_LVDFLAG							(uint32_t)0x00000080    /*!<Low voltage detection flag bit. */
#define  System_Status1_CVMFLAG							(uint32_t)0x00000200    /*!<Kernel voltage monitoring flag bit. */
#define  System_Status1_BGRFLAG							(uint32_t)0x00000800    /*!<Bandgap flag bit. */
#define  System_Status1_IWDT_INTR						(uint32_t)0x00002000    /*!<IWDT interrupt bit. */

#define IS_System_Status1(Status1)		(((Status1) == System_Status1_OSCSTOP) || ((Status1) == System_Status1_RCHSTB)||\
																			((Status1) == System_Status1_PLL_LOCK) || ((Status1) == System_Status1_LVDFLAG)||\
																			((Status1) == System_Status1_CVMFLAG) || ((Status1) == System_Status1_BGRFLAG)||\
																			((Status1) == System_Status1_IWDT_INTR))


/** @defgroup System_Warkup_Source Select 
  * @{
  */
#define  System_Warkup_IO				(uint32_t)0x00000001    /*!<IO wake up enable bit. */
#define  System_Warkup_IWDT			(uint32_t)0x00000004    /*!<IWDT wake up enable bit. */
#define  System_Warkup_DEBUG		(uint32_t)0x00000010    /*!<Debug wake up enable bit. */
#define  System_Warkup_LVD			(uint32_t)0x00000100    /*!<LVD wake up enable bit. */	
#define  System_Warkup_WT				(uint32_t)0x00010000    /*!<WT wake up enable bit. */

#define IS_System_Warkup_Source(Source)		((((Source) & 0xFFFEFEEA)== 0x00) && ((Source) != 0x00))

/** @defgroup PA13_PA14_Reuse 
  * @{
  */
#define PA13_PA14_Reuse_Debug            (uint8_t)0x00    /*!<PA13¡¢PA14 use as debug pins. */ 
#define PA13_PA14_Reuse_IOPort           (uint8_t)0x01    /*!<PA13¡¢PA14 use as IO pins. */

#define IS_PA13_PA14_Reuse(Reuse)  (((Reuse) == PA13_PA14_Reuse_Debug) ||\
																	 ((Reuse) == PA13_PA14_Reuse_IOPort))

/** @defgroup XRST_Reuse 
  * @{
  */
#define XRST_Reuse_RST            	(uint8_t)0x00    /*!<use as RST pin. */
#define XRST_Reuse_IOPort           (uint8_t)0x01    /*!<use as IO pin. */

#define IS_XRST_Reuse(Reuse)  			(((Reuse) == XRST_Reuse_RST) ||\
																	  ((Reuse) == XRST_Reuse_IOPort))
																	 
/** @defgroup SYSRESRT_OUTSEL 
  * @{
  */
#define SYSRESRT_OutSel_PC2            	(uint8_t)0x00    /*!<Reset output pin selection is PC2. */
#define SYSRESRT_OutSel_PB4           	(uint8_t)0x01    /*!<Reset output pin selection is PB4. */

#define IS_SYSRESRT_OutSel(OutSel)  		(((OutSel) == SYSRESRT_OutSel_PC2) ||\
																				((OutSel) == SYSRESRT_OutSel_PB4))
																				
																				
typedef enum {NormalPower = 0, LowPower = !NormalPower} PowerState;
#define IS_POWER_STATE(STATE) (((STATE) == NormalPower) || ((STATE) == LowPower))

typedef enum {CLKOpen = 0, CLKClose = !CLKOpen} SleepCLKState;
#define IS_SleepCLK_STATE(STATE) (((STATE) == CLKOpen) || ((STATE) == CLKClose))


void SYSTEM_WakeUpSourceSel(uint32_t WakeUpSource, FunctionalState NewState);
void VANA_Config(uint32_t Power_VANA);
void VTS_Cmd(FunctionalState NewState);
void LVR_Config(uint32_t LVRS,FunctionalState NewState);
void LVD_Config(uint32_t LVLS,uint32_t LVES,FunctionalState NewState);
void CVM_Cmd(FunctionalState NewState);
void CVMR_Cmd(FunctionalState NewState);
void POCR_Cmd(FunctionalState NewState);
void LOCKUPR_Cmd(FunctionalState NewState);
void SYSCLK_DCT_Cmd(FunctionalState NewState);
void SYSCLK_MUX_RST_Cmd(FunctionalState NewState);
void Debug_SleepStateCmd(FunctionalState NewState);
void MVR_Config(uint32_t PowerState, uint32_t MVRVolt);
void Power_SourceConfig(uint32_t LowPower_Source, PowerState NewState);
void SRAM_SleepCLKConfig(SleepCLKState NewState);
void FLASH_SleepCLKConfig(SleepCLKState NewState);
void System_ITMaskConfig(uint32_t ITMask,FunctionalState NewState);
FlagStatus System_GetEventStatus0(uint32_t EventStatus);
void System_ClearEventStatus0(void);
void PA13_PA14_ReuseConfig(uint8_t Reuse);
void XRST_ReuseConfig(uint8_t Reuse);
void SYSRESET_OUTEN_Cmd(FunctionalState NewState);
void SYSRESRT_OutSel_Config(uint8_t OutSel);


#endif
