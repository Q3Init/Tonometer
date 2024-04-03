#include "RTE.h"
#include "Os_EvtHdl.h"
#include "Os_TimerHdl.h"
#include "Os_TaskHdl_Lv0.h"

/**
  * @brief  GPIO配置
  * @param  无
  * @retval 无
  */
static void APP_GpioConfig(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();                          /* 使能GPIOA时钟 */

  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
  GPIO_InitStruct.Pull = GPIO_PULLUP;                    /* 使能上拉 */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* GPIO速度 */  
  /* GPIO初始化 */
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);                
}


static volatile boolean rteBswRdyFlg = FALSE;
void RTE_Init(void)
{
    __DISENBLE_IRQ(); /* chip disable irq */
    /* System Tick */
    HAL_Init();
    /* OS Init */
    OsEvt_Init();
    OsTimer_Init();
    /* MCAL Init */
    APP_GpioConfig();
    /* BSW Init */

    /* application Init */

    rteBswRdyFlg = TRUE; /* Init complete flag */
    __ENABLE_IRQ(); /* chip enable irq */
}


boolean Get_rteBswRdyFlg(void)
{
	return(rteBswRdyFlg);
}


