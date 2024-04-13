#include "MCAL_ADC.h"
#define ADC_SAPMLE_NUM 2048
uint16_t aADCxConvertedData[ADC_SAPMLE_NUM] = {0};
ADC_HandleTypeDef AdcHandle;
ADC_ChannelConfTypeDef sConfig;
void MCAL_ADC_Init(void)
{
	AdcHandle.Instance                   = ADC1;                                    /* ADC1 */
	AdcHandle.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV4;                /* 设置ADC时钟 */
	AdcHandle.Init.Resolution            = ADC_RESOLUTION_12B;                      /* 转换分辨率12bit */
	AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;                     /* 数据右对齐 */
	AdcHandle.Init.ScanConvMode          = ADC_SCAN_DIRECTION_BACKWARD;             /* 扫描序列方向：向下 */
	AdcHandle.Init.LowPowerAutoWait      = ENABLE;                                  /* 等待转换模式开启 */
	AdcHandle.Init.ContinuousConvMode    = DISABLE;                                 /* 单次转换模式 */
	AdcHandle.Init.DiscontinuousConvMode = ENABLE;                                  /* 使能非连续模式 */
	AdcHandle.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T3_TRGO;            /* 外部触发转换启动事件为TIM3_TRGO */
	AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING;  /* 触发边沿上升沿和下降沿 */
	AdcHandle.Init.DMAContinuousRequests = ENABLE;                                  /* DMA循环模式选择 */
	AdcHandle.Init.Overrun               = ADC_OVR_DATA_OVERWRITTEN;                /* 当过载发生时，覆盖上一个值 */
	AdcHandle.Init.SamplingTimeCommon    = ADC_SAMPLETIME_28CYCLES_5;               /* 通道采样时间为28.5ADC时钟周期 */		

	sConfig.Rank         = ADC_RANK_CHANNEL_NUMBER;
	sConfig.Channel      = ADC_CHANNEL_0;
	/* ADC校准 */
	while( HAL_ADCEx_Calibration_Start(&AdcHandle) != HAL_OK );                          

	/* ADC初始化 */
	while( HAL_ADC_Init(&AdcHandle) != HAL_OK );

	/* 通道0配置 */
	while( HAL_ADC_ConfigChannel(&AdcHandle,&sConfig) != HAL_OK );                     
	/* ADC开启 */
	while( HAL_ADC_Start_DMA(&AdcHandle,( uint32_t* )&aADCxConvertedData,ADC_SAPMLE_NUM ) != HAL_OK );     
}

/**
  * @brief This function handles DMA1_Channel1 Interrupt .
  */
void DMA1_Channel1_IRQHandler(void)
{
	HAL_DMA_IRQHandler(AdcHandle.DMA_Handle);
}
