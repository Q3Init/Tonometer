#include "MCAL_Timer.h"

void MCAL_Timer_Init(void)
{
	TIM_HandleTypeDef    TimHandle;
	TIM_MasterConfigTypeDef sMasterConfig;
	
	TimHandle.Instance = TIM3;                                          /* TIM1 */
	TimHandle.Init.Period            = 488 - 1;                         /* TIM1重装载值位488 - 1 */
	TimHandle.Init.Prescaler         = 48 - 1;                          /* 预分频为48 - 1 */
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;          /* 时钟不分频 */
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;              /* 向上计数 */
	TimHandle.Init.RepetitionCounter = 0;                               /* 不重复 */
	TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* 自动重装载寄存器没有缓冲 */
	/* 初始化TIM1 */
	while(HAL_TIM_Base_Init(&TimHandle) != HAL_OK);                        

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;                /* 选择更新事件作为触发源 */
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;        /* 主/从模式无作用 */
	HAL_TIMEx_MasterConfigSynchronization(&TimHandle, &sMasterConfig);  /* 配置TIM1 */
	/* TIM1时钟启动 */
	while(HAL_TIM_Base_Start(&TimHandle) != HAL_OK);                        
}

