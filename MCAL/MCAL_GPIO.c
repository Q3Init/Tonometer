#include "MCAL_GPIO.h"

void MCAL_GPIO_Init(void)
{
    uint16 gpioIndex;
    GPIO_InitTypeDef gpioConfig;

    for (gpioIndex = 0; gpioIndex < GPIO_SIGNALS_CNT; gpioIndex++) {
		
		gpioConfig = (gpioSignalsCfgTable+gpioIndex)->GPIO_InitStruct;
		
		HAL_GPIO_Init((gpioSignalsCfgTable+gpioIndex)->GPIO, &gpioConfig);

		HAL_GPIO_WritePin((gpioSignalsCfgTable + gpioIndex)->GPIO,(gpioSignalsCfgTable + \
		gpioIndex)->GPIO_InitStruct.Pin,(gpioSignalsCfgTable + gpioIndex)->GPIO_level);
		
    }
}

