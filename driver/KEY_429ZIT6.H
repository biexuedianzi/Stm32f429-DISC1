/*******************************************************************************                                     
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：KEY_429ZIT6.H
  * 描    述：按键头文件
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

#ifndef  __KEY_429ZIT6_H__ 
#define  __KEY_429ZIT6_H__
/**********************头文件调用及变量定义声明****************************************/
/*  包含必要的头文件  */
#include "stm32f4xx_conf.h"
/*  宏定义  */

/*----------------------------------------------------------------------------*/



//说明：用户按键PA0--采用中断方式

#define USER_BUTTON_PIN                GPIO_Pin_0
#define USER_BUTTON_PORT               GPIOA
#define USER_BUTTON_CLK                RCC_AHB1Periph_GPIOA
#define USER_BUTTON_EXTI_LINE          EXTI_Line0
#define USER_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOA
#define USER_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource0
#define USER_BUTTON_EXTI_IRQn          EXTI0_IRQn 

#define  KEY_USER  GPIO_ReadInputDataBit(USER_BUTTON_PORT,USER_BUTTON_PIN)  //读取用户按键的值

#define  USER_BUTTON    1


//函数声明部分
extern  void  Key_Init(void);
extern  unsigned char Key_Scan(void);
#endif  

