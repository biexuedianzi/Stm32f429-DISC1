/*******************************************************************************                                      
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：LED_429ZIT6.H
  * 描    述：LED头文件
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

#ifndef  __LED_429ZIT6_H__ 
#define  __LED_429ZIT6_H__
/**********************头文件调用及变量定义声明****************************************/
/*  包含必要的头文件  */
#include "stm32f4xx_conf.h"
/*  宏定义  */


#define LED_PIN                          GPIO_Pin_13|GPIO_Pin_14
#define LED_PORT                         GPIOG
#define LED_PORT_CLK                     RCC_AHB1Periph_GPIOG  
#define LED3_PIN                         GPIO_Pin_13
#define LED4_PIN                         GPIO_Pin_14





extern    void LED_Init(void);
extern    void LED_RED(void);
extern    void LED_Flow(void);
extern    void Led_Blink(void);
void Led1_Blink(void);
void Led2_Blink(void);
extern    void Delay(__IO uint32_t nCount);
extern    void Delay_Us(__IO uint32_t nCount);
extern    void Delay_Ms(__IO uint32_t nCount);

#endif  

