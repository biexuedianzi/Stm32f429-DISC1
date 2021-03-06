/*******************************************************************************                                      
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：SYSTICK_429ZIT6.H
  * 描    述：头文件
  * 创 建 者: fengye5340
  * 创建日期: 2014-03-04    
  * 修 改 者:             
  * 修改日期: 2014-03-05     
  * 版    本: v1.0.0
  ******************************************************************************
  * attention
  *
  ******************************************************************************
  */

#ifndef  __SYSTICK_429ZIT6_H__
#define  __SYSTICK_429ZIT6_H__

#include "stm32f4xx_conf.h"

/**********************头文件调用及变量定义声明*********************************/
/*  包含必要的头文件  */
/*  子函数定义        */

extern   void Systick_Init(void);
extern   void Delay_ms( unsigned long nTime );
extern   void TimingDelay_Decrement(void);


#endif  

