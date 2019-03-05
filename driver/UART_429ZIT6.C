/*******************************************************************************                                      
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：UART_429ZIT6.C
  * 描    述：串口通信模块
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
  #include "UART_429ZIT6.H" 
  #include <stdarg.h>
/* 类型定义 typedef-----------------------------------------------------------*/
/* 预定义字符     ------------------------------------------------------------*/
/* 宏定义        -------------------------------------------------------------*/
/* 变量定义          ---------------------------------------------------------*/ 



/*******************************************************************************
* 函数名称: Uart_Init()
* 功能描述: 串口初始化
* 输入参数: void
* 返回参数: 无
********************************************************************************/
void Uart_Init(void)
{
   
        GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	//开启RX和TX引脚时钟并配置成对应的模式
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);  //TX初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;             //RX初始化
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	//开启串口6的时钟并做相应配置
	USART_DeInit(USART1);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
 	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  //将对应的IO口配置成USART6模式
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	USART_InitStructure.USART_BaudRate = 9600;                  
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode =USART_Mode_Tx|USART_Mode_Rx;
	USART_Init(USART1, &USART_InitStructure);

	//开启串口接收中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1, ENABLE);
	//配置NVIC寄存器
	   
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);  //中断优先级组
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //中断io对应的通道
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //响应优先级
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  //中断通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4 
	
}
/*******************************************************************************
* 函数名称: Uart_Put_Char()
* 功能描述: 通过UART发送一个字符
* 输入参数: void
* 返回参数: 无
********************************************************************************/
void Uart_Put_Char(unsigned char c)
{    
     while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);	
	   USART_SendData(USART1,c);  
     
	   
}
/*******************************************************************************
* 函数名称:  Uart_Put_string
* 功能描述: 通过UART发送字符串
* 输入参数: void
* 返回参数: 无
********************************************************************************/
void Uart_Put_string(unsigned char *s)
{
    while (*s != '\0') 
    { 
      Uart_Put_Char(*(s++));
    }	
}
/*******************************************************************************
* 函数名称:  Uart_Put_string
* 功能描述: 通过UART发送字符串
* 输入参数: void
* 返回参数: 无
********************************************************************************/
void Uart_Char_Num( unsigned char *pucBuffer, unsigned long ulCount )
{
     while(ulCount--)
    {
       Uart_Put_Char(*pucBuffer++); 
    }
}

/*******************************************************************************
* 函数名称: Uart_Get_Char()
* 功能描述: 通过UART接收一个字符
* 输入参数: void
* 返回参数: 无
********************************************************************************/ 
unsigned char Uart_Get_Char(void)
{    
     unsigned char temp;
     while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);//等待接收为空
     temp = (unsigned char)(USART_ReceiveData(USART1));
     return(temp);    
}
/*******************************************************************************
函数名称：PUTCHAR_PROTOTYPE 
功    能：串口实现Printf()函数功能
参    数：无
返回值  ：
********************************************************************************/
int fputc(int ch, FILE *f)
{
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
  USART_SendData(USART1,(uint8_t)ch);
  return (ch);
}
	
 
