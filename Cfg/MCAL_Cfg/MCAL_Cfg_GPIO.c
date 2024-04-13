#include "MCAL_Cfg_GPIO.h"
const GPIOSignalsCfg gpioSignalsCfgTable[GPIO_SIGNALS_CNT] =
    {
		{
			.GPIO = GPIOA,
			.GPIO_level = GPIO_PIN_RESET,
			{
				.Pin  = GPIO_PIN_0,
				.Mode = GPIO_MODE_ANALOG,
				.Pull = GPIO_NOPULL,
			},
		},
	};
