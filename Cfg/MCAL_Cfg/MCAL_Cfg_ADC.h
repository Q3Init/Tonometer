#ifndef __MCAL_CFG_ADC_H_
#define __MCAL_CFG_ADC_H_

#include "MCAL_CfgList.h"

#define ADC_SIGNALS_CNT 1

typedef struct {
	ADC_HandleTypeDef AdcHandle;
	ADC_ChannelConfTypeDef sConfig;

}ADCSignalsCfg;

extern const ADCSignalsCfg adcSignalsCfgTable[];
extern uint16_t aADCxConvertedData[];

#endif
