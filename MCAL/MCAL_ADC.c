#include "MCAL_ADC.h"
#define ADC_SAPMLE_NUM 2048
uint16_t aADCxConvertedData[ADC_SAPMLE_NUM] = {0};
ADC_HandleTypeDef AdcHandle;
ADC_ChannelConfTypeDef sConfig;
void MCAL_ADC_Init(void)
{
	AdcHandle.Instance                   = ADC1;                                    /* ADC1 */
	AdcHandle.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV4;                /* ����ADCʱ�� */
	AdcHandle.Init.Resolution            = ADC_RESOLUTION_12B;                      /* ת���ֱ���12bit */
	AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;                     /* �����Ҷ��� */
	AdcHandle.Init.ScanConvMode          = ADC_SCAN_DIRECTION_BACKWARD;             /* ɨ�����з������� */
	AdcHandle.Init.LowPowerAutoWait      = ENABLE;                                  /* �ȴ�ת��ģʽ���� */
	AdcHandle.Init.ContinuousConvMode    = DISABLE;                                 /* ����ת��ģʽ */
	AdcHandle.Init.DiscontinuousConvMode = ENABLE;                                  /* ʹ�ܷ�����ģʽ */
	AdcHandle.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T3_TRGO;            /* �ⲿ����ת�������¼�ΪTIM3_TRGO */
	AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING;  /* �������������غ��½��� */
	AdcHandle.Init.DMAContinuousRequests = ENABLE;                                  /* DMAѭ��ģʽѡ�� */
	AdcHandle.Init.Overrun               = ADC_OVR_DATA_OVERWRITTEN;                /* �����ط���ʱ��������һ��ֵ */
	AdcHandle.Init.SamplingTimeCommon    = ADC_SAMPLETIME_28CYCLES_5;               /* ͨ������ʱ��Ϊ28.5ADCʱ������ */		

	sConfig.Rank         = ADC_RANK_CHANNEL_NUMBER;
	sConfig.Channel      = ADC_CHANNEL_0;
	/* ADCУ׼ */
	while( HAL_ADCEx_Calibration_Start(&AdcHandle) != HAL_OK );                          

	/* ADC��ʼ�� */
	while( HAL_ADC_Init(&AdcHandle) != HAL_OK );

	/* ͨ��0���� */
	while( HAL_ADC_ConfigChannel(&AdcHandle,&sConfig) != HAL_OK );                     
	/* ADC���� */
	while( HAL_ADC_Start_DMA(&AdcHandle,( uint32_t* )&aADCxConvertedData,ADC_SAPMLE_NUM ) != HAL_OK );     
}

/**
  * @brief This function handles DMA1_Channel1 Interrupt .
  */
void DMA1_Channel1_IRQHandler(void)
{
	HAL_DMA_IRQHandler(AdcHandle.DMA_Handle);
}
