#include "MCAL_DMA.h"

DMA_HandleTypeDef HdmaCh1;

/**
  * @brief  DMA������ɺ���
  * @param  ADC_HandleTypeDef* hadc
  * @retval ��
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

}

/**
  * @brief ��ʼ��ADC���MSP
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
	HAL_SYSCFG_DMA_Req(0);                                      /* DMA1_MAPѡ��ΪADC */
	/* ------------ */
	/* DMA����      */
	/* ------------ */
	HdmaCh1.Instance                 = DMA1_Channel1;           /* ѡ��DMAͨ��1 */
	HdmaCh1.Init.Direction           = DMA_PERIPH_TO_MEMORY;    /* ����Ϊ�����赽�洢�� */
	HdmaCh1.Init.PeriphInc           = DMA_PINC_DISABLE;        /* ��ֹ�����ַ���� */
	HdmaCh1.Init.MemInc              = DMA_MINC_ENABLE;         /* ��ֹ�洢����ַ���� */
	HdmaCh1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; /* �������ݿ��Ϊ16λ */
	HdmaCh1.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD; /* �洢�����ݿ��λ16λ */
	HdmaCh1.Init.Mode                = DMA_CIRCULAR;            /* ѭ��ģʽ */
	HdmaCh1.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* ͨ�����ȼ�Ϊ�ܸ� */

	HAL_DMA_DeInit(&HdmaCh1);                                   /* DMA����ʼ�� */
	HAL_DMA_Init(&HdmaCh1);                                     /* ��ʼ��DMAͨ��1 */
	 /* DMAͨ��1�ж�ʹ�� */
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
	__HAL_LINKDMA(hadc, DMA_Handle, HdmaCh1);                   /* ����DMA��� */
}

void MCAL_DMA_Init(void)
{

}


