/*******************************************************************************                                      
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：includes.h
  * 描    述：STM32F429驱动头文件
  * 创 建 者: fengye5340
  * 创建日期: 2014-03-05
  * 修 改 者:             
  * 修改日期: 2014-03-05
  * 版    本: v1.0
  ******************************************************************************
  * attention
  *
  ******************************************************************************
  */
#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__	
	
/*Includes --------------------------------------------------------------------*/
  #include "stm32f4xx.h"
  #include "stm32f4xx_it.h"
  #include  <stdio.h>
  #include  <string.h>
  #include  "stm32f4xx_conf.h"
  #include  "LED_429ZIT6.H" 
  #include  "SYSTICK_429ZIT6.H" 
  #include  "UART_429ZIT6.H" 
  #include  "NVIC_429ZIT6.H"
  #include  "KEY_429ZIT6.H" 

  #include "stm32f429i_discovery.h"
  #include "stm32f429i_discovery_lcd.h"
  #include "stm32f429i_discovery_sdram.h"
  #include "stm32f429i_discovery_ioe.h"
  #include "GUI.h"
  #include "DIALOG.h"
  #include "fonts.h"
	
	#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "GUIDEMO.h"


//#include "arm_math.h"
#include  "WM.h"
#include  "GUIDEMO.h"
#include  "GUI.h"
  //#include "GUI_X.h" 
	
	#include "delay.h"



/* 类型定义 typedef------------------------------------------------------------*/
/* 预定义字符------------------------------------------------------------------*/
/* 宏定义----------------------------------------------------------------------*/
/* 变量定义--------------------------------------------------------------------*/ 
   void TimingDelay_Decrement(void);
/* Exported macro ------------------------------------------------------------*/
#define LOBYTE(x)  ((uint8_t)(x & 0x00FF))
#define HIBYTE(x)  ((uint8_t)((x & 0xFF00) >>8)) 
/* 子函数声明--------------------------------------------------------------------*/ 
 extern  int main(void);


#endif  


