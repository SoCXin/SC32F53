#ifndef __MISC_H
#define __MISC_H

#include "sc32f53xx_conf.h"

/** @defgroup System_Low_Power 
  * @{
  */

#define NVIC_LP_SEVONPEND            ((uint8_t)0x10)  
#define NVIC_LP_SLEEPDEEP            ((uint8_t)0x04)    /*!<Deep sleep in low power mode. */  
#define NVIC_LP_SLEEPONEXIT          ((uint8_t)0x02)
#define IS_NVIC_LP(LP)  (((LP) == NVIC_LP_SEVONPEND) || \
                        ((LP) == NVIC_LP_SLEEPDEEP) || \
                        ((LP) == NVIC_LP_SLEEPONEXIT))


void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);


#endif

