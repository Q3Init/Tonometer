#ifndef __MCAL_CFG_GPIO_H_
#define __MCAL_CFG_GPIO_H_

#include "MCAL_CfgList.h"

#define GPIO_SIGNALS_CNT 1

typedef struct {
	GPIO_TypeDef *GPIO;
	GPIO_PinState GPIO_level;
	GPIO_InitTypeDef GPIO_InitStruct;
} GPIOSignalsCfg;

extern const GPIOSignalsCfg gpioSignalsCfgTable[];

#endif
