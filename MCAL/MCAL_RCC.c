#include "MCAL_RCC.h"

/**
  * @brief   ϵͳʱ�����ú���
  * @param   ��
  * @retval  ��
  */
static void MCAL_SystemClockConfig(void)
{	
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /* ����ʱ��ԴHSE/HSI/LSE/LSI */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;                                                    /* ����HSI */
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;                                                    /* ����Ƶ */
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_16MHz;                           /* ����HSI���ʱ��Ϊ16MHz */
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;                                                   /* �ر�HSE */
  RCC_OscInitStruct.HSEFreq = RCC_HSE_16_32MHz;                                               /* HSE����Ƶ�ʷ�Χ16M~32M */
  RCC_OscInitStruct.LSIState = RCC_LSI_OFF;                                                   /* �ر�LSI */
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;                                                   /* �ر�LSE */
  RCC_OscInitStruct.LSEDriver = RCC_ECSCR_LSE_DRIVER_1;                                       /* LSEĬ���������� */
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;                                                /* ����PLL */
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;                                        /* PLL��ʱ��Դ��Ƶ�ʱ���Ҫ��12MHz������ */
  /* ��ʼ��RCC���� */
  while(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK);

  /*��ʼ��CPU,AHB,APB����ʱ��*/
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1; /* RCCϵͳʱ������ */
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;                                      /* ����PLLΪϵͳʱ�� */
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;                                             /* APHʱ�Ӳ���Ƶ */
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;                                              /* APBʱ�Ӳ���Ƶ */
  /* ��ʼ��RCCϵͳʱ�� */
  while(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK);
}

void MCAL_RCC_Init(void)
{
	MCAL_SystemClockConfig( );
	__HAL_RCC_ADC_FORCE_RESET();
	__HAL_RCC_ADC_RELEASE_RESET(); 	/* ��λADC */
	__HAL_RCC_ADC_CLK_ENABLE( );   	/* ADCʱ��ʹ�� */
	
	__HAL_RCC_TIM3_CLK_ENABLE();   	/* TIM3ʱ��ʹ�� */
	
	__HAL_RCC_GPIOA_CLK_ENABLE();  	/* ʹ��GPIOAʱ�� */
	
	__HAL_RCC_SYSCFG_CLK_ENABLE(); 	/* ʹ��SYSCFGʱ�� */
	
	__HAL_RCC_DMA_CLK_ENABLE();   	/* ʹ��DMAʱ�� */
	
}
