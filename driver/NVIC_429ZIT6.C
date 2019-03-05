/*******************************************************************************                                     
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：NVIC_429ZIT6.C
  * 描    述：NVIC管理模块
  * 创 建 者: fengye5340
  * 创建日期: 2014-03-05   
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
  #include "NVIC_429ZIT6.H"
/* 类型定义 typedef-----------------------------------------------------------*/
/* 预定义字符     ------------------------------------------------------------*/
/* 宏定义        -------------------------------------------------------------*/
/********************************************************************************
函数名称：Nvic_Init(void)
功    能：Nvic_Init配置
参    数：无
返 回 值：无
*********************************************************************************/
void Nvic_Init(void)
{ 
	
  NVIC_InitTypeDef  NVIC_InitStructure;
  /* 配置先占优先级两位方式 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  /*1--串口中断管理*/
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /*2--按键中断管理*/
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
