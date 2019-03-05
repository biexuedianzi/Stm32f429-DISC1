/*******************************************************************************                                  
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：KEY_429ZIT6.C
  * 描    述：按键模块
  * 创 建 者: fengye5340
  * 创建日期: 
  * 修 改 者:             
  * 修改日期: 2014-03-05   
  * 版    本: v1.0.0
  ******************************************************************************
  * attention
  *
  ******************************************************************************
  */
/*Includes --------------------------------------------------------------------*/
  #include "includes.h"
  #include "KEY_429ZIT6.H" 

/********************************************************************************
函数名称：Key_Init()
功    能：按键初始化
参    数：无
返 回 值：无
*********************************************************************************/
void Key_Init(void)
{
      GPIO_InitTypeDef GPIO_InitStructure;
      EXTI_InitTypeDef EXTI_InitStructure;
      // 用户按键时钟使能
      RCC_AHB1PeriphClockCmd(USER_BUTTON_CLK     , ENABLE); //用户按键     
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

      //用户按键配置--IO配置
      GPIO_InitStructure.GPIO_Pin   = USER_BUTTON_PIN ;
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
      GPIO_Init(USER_BUTTON_PORT , &GPIO_InitStructure);

      //用户按键--外部中断源配置
      SYSCFG_EXTILineConfig(USER_BUTTON_EXTI_PORT_SOURCE, USER_BUTTON_EXTI_PIN_SOURCE );
      EXTI_InitStructure.EXTI_Line = USER_BUTTON_EXTI_LINE ;
      EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
      EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
      EXTI_InitStructure.EXTI_LineCmd = ENABLE;
      EXTI_Init(&EXTI_InitStructure);




}
/********************************************************************************
函数名称：Key_Scan()
功    能：按键处理函数--扫描方式
参    数：
返 回 值：无
*********************************************************************************/
unsigned char Key_Scan(void)
{    	 
   return 0;  
}

