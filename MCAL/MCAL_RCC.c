#include "MCAL_RCC.h"

/**
  * @brief   系统时钟配置函数
  * @param   无
  * @retval  无
  */
static void MCAL_SystemClockConfig(void)
{	
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /* 配置时钟源HSE/HSI/LSE/LSI */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;                                                    /* 开启HSI */
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;                                                    /* 不分频 */
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_16MHz;                           /* 配置HSI输出时钟为16MHz */
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;                                                   /* 关闭HSE */
  RCC_OscInitStruct.HSEFreq = RCC_HSE_16_32MHz;                                               /* HSE工作频率范围16M~32M */
  RCC_OscInitStruct.LSIState = RCC_LSI_OFF;                                                   /* 关闭LSI */
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;                                                   /* 关闭LSE */
  RCC_OscInitStruct.LSEDriver = RCC_ECSCR_LSE_DRIVER_1;                                       /* LSE默认驱动能力 */
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;                                                /* 开启PLL */
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;                                        /* PLL的时钟源，频率必须要求12MHz及以上 */
  /* 初始化RCC振荡器 */
  while(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK);

  /*初始化CPU,AHB,APB总线时钟*/
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1; /* RCC系统时钟类型 */
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;                                      /* 配置PLL为系统时钟 */
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;                                             /* APH时钟不分频 */
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;                                              /* APB时钟不分频 */
  /* 初始化RCC系统时钟 */
  while(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK);
}

void MCAL_RCC_Init(void)
{
	MCAL_SystemClockConfig( );
	__HAL_RCC_ADC_FORCE_RESET();
	__HAL_RCC_ADC_RELEASE_RESET(); 	/* 复位ADC */
	__HAL_RCC_ADC_CLK_ENABLE( );   	/* ADC时钟使能 */
	
	__HAL_RCC_TIM3_CLK_ENABLE();   	/* TIM3时钟使能 */
	
	__HAL_RCC_GPIOA_CLK_ENABLE();  	/* 使能GPIOA时钟 */
	
	__HAL_RCC_SYSCFG_CLK_ENABLE(); 	/* 使能SYSCFG时钟 */
	
	__HAL_RCC_DMA_CLK_ENABLE();   	/* 使能DMA时钟 */
	
}
