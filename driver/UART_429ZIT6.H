/*******************************************************************************                                    
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：UART_429ZIT6.H
  * 描    述：头文件
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

#ifndef  __UART_429ZIT6_H__ 
#define  __UART_429ZIT6_H__
/**********************头文件调用及变量定义声明****************************************/
/*  包含必要的头文件  */
  #include <stdarg.h>
  #include <stdio.h>


//板载串口1的宏定义

#define F429C_COM                        USART1
#define F429C_COM_CLK                    RCC_APB2Periph_USART1

#define F429C_COM_TX_PIN                 GPIO_Pin_6
#define F429C_COM_TX_PORT           	   GPIOB
#define F429C_COM_TX_CLK            	   RCC_AHB1Periph_GPIOB
#define F429C_COM_TX_SOURCE              GPIO_PinSource6
#define F429C_COM_TX_AF                  GPIO_AF_USART1

#define F429C_COM_RX_PIN                 GPIO_Pin_7
#define F429C_COM_RX_PORT           	   GPIOB
#define F429C_COM_RX_CLK                 RCC_AHB1Periph_GPIOB
#define F429C_COM_RX_SOURCE              GPIO_PinSource7
#define F429C_COM_RX_AF                  GPIO_AF_USART1


/*  子函数定义        */



extern  int fputc(int ch, FILE *f);
extern  void Uart_Init(void);  
extern  void Uart_Put_Char(unsigned char c);
extern  void Uart_Put_string(unsigned char *s);
extern  void Uart_Char_Num( unsigned char *pucBuffer, unsigned long ulCount );
extern  unsigned char Uart_Get_Char(void);


#endif  

