#include "MCAL_DMA.h"

DMA_HandleTypeDef HdmaCh1;

/**
  * @brief  DMA传输完成函数
  * @param  ADC_HandleTypeDef* hadc
  * @retval 无
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

}

/**
  * @brief 初始化ADC相关MSP
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
	HAL_SYSCFG_DMA_Req(0);                                      /* DMA1_MAP选择为ADC */
	/* ------------ */
	/* DMA配置      */
	/* ------------ */
	HdmaCh1.Instance                 = DMA1_Channel1;           /* 选择DMA通道1 */
	HdmaCh1.Init.Direction           = DMA_PERIPH_TO_MEMORY;    /* 方向为从外设到存储器 */
	HdmaCh1.Init.PeriphInc           = DMA_PINC_DISABLE;        /* 禁止外设地址增量 */
	HdmaCh1.Init.MemInc              = DMA_MINC_ENABLE;         /* 禁止存储器地址增量 */
	HdmaCh1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; /* 外设数据宽度为16位 */
	HdmaCh1.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD; /* 存储器数据宽度位16位 */
	HdmaCh1.Init.Mode                = DMA_CIRCULAR;            /* 循环模式 */
	HdmaCh1.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* 通道优先级为很高 */

	HAL_DMA_DeInit(&HdmaCh1);                                   /* DMA反初始化 */
	HAL_DMA_Init(&HdmaCh1);                                     /* 初始化DMA通道1 */
	 /* DMA通道1中断使能 */
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
	__HAL_LINKDMA(hadc, DMA_Handle, HdmaCh1);                   /* 连接DMA句柄 */
}

void MCAL_DMA_Init(void)
{

}


