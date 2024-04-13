#include "MCAL_Timer.h"

void MCAL_Timer_Init(void)
{
	TIM_HandleTypeDef    TimHandle;
	TIM_MasterConfigTypeDef sMasterConfig;
	
	TimHandle.Instance = TIM3;                                          /* TIM1 */
	TimHandle.Init.Period            = 488 - 1;                         /* TIM1��װ��ֵλ488 - 1 */
	TimHandle.Init.Prescaler         = 48 - 1;                          /* Ԥ��ƵΪ48 - 1 */
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;          /* ʱ�Ӳ���Ƶ */
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;              /* ���ϼ��� */
	TimHandle.Init.RepetitionCounter = 0;                               /* ���ظ� */
	TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;  /* �Զ���װ�ؼĴ���û�л��� */
	/* ��ʼ��TIM1 */
	while(HAL_TIM_Base_Init(&TimHandle) != HAL_OK);                        

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;                /* ѡ������¼���Ϊ����Դ */
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;        /* ��/��ģʽ������ */
	HAL_TIMEx_MasterConfigSynchronization(&TimHandle, &sMasterConfig);  /* ����TIM1 */
	/* TIM1ʱ������ */
	while(HAL_TIM_Base_Start(&TimHandle) != HAL_OK);                        
}

