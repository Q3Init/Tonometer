#include "BSW_FFT_APP.h"
#include "table_fft.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_common_tables.h"
#include <string.h>
#include "stdio.h"


#define FFT_LENGTH 1024

float32 lBufInArray[FFT_LENGTH * 2] = {0};
float32 lBufOutArray[FFT_LENGTH / 2] = {0};
uint16 ADC_my_test_value[1024]= {0};

uint32 maxIndex = 0;
float32 maxIndex_1 = 0;
float32 maxValue = 0;
float32 frequency = 0;
arm_rfft_instance_f32 fftInstance;


void FFT(void)
{
    for (int i = 0; i < FFT_LENGTH; i++) {

        lBufInArray[i *2 ] = (ADC_my_test_value[i]*3.3)/4096; //实部赋值
        lBufInArray[i * 2 + 1] = 0; //虚部赋值
    }
    arm_cfft_f32(&arm_cfft_sR_f32_len1024, lBufInArray, 0, 1); //傅里叶变换
    arm_cmplx_mag_f32(lBufInArray, lBufOutArray, FFT_LENGTH); /// 取模
    lBufOutArray[0] /= 1024;
    for (int i = 1; i < FFT_LENGTH/2; i++) {
        lBufOutArray[i] /= 512; //归一化

    }

    // arm_rfft_fast_f32(&fftInstance,fftInput,fftOutput,0); //执行FFT
    arm_max_f32(lBufOutArray,512,&maxValue,&maxIndex); //查找最大幅度的频率
    if ((maxValue > 0) && (maxIndex == 0)) {
        for (int i = 0; i < 512; i++) {
            if(lBufOutArray[i] > 1) {
                maxIndex_1 = (float32)(i-1) + 0.5f;
            }
        }
    } else {
        maxIndex_1 = maxIndex;
    }
    frequency = (float32_t)maxIndex_1 * 1024 / 1024; 
}

void get_adcvalues(uint16* adcbuffer)
{
    for (int i = 0; i < 1024; i++) {
        ADC_my_test_value[i] = adcbuffer[i];
    }
}

