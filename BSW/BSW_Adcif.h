#ifndef  BSW_ADCIF_H_
#define  BSW_ADCIF_H_

#include "Platform_Types.h"
#include "MCAL_Cfg_ADC.h"
#include <string.h>

extern void BSW_Adcif_Init(void);
extern void BSW_Adcif_Mainfunction(void);
extern float32 BSW_Adcif_Get_Ia(void);

#endif
