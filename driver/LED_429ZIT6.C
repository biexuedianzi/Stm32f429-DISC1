/*******************************************************************************                                      
  *                              fengye5340@163.com                      
  ******************************************************************************
  * 文件名称：LED_429ZIT6.C
  * 描    述：LED灯模块
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
  #include "LED_429ZIT6.H" 
	extern unsigned short int   delay_num ;
	
/********************************************************************************
函数名称：Delay()
功    能：延时函数
参    数：无
返 回 值：无
*********************************************************************************/
void LedDelay(__IO uint32_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
		nCount--;
  }
}

/********************************************************************************
函数名称：Delay_Us()
功    能：软件延时微秒级函数
参    数：无
返 回 值：无
*********************************************************************************/
void Delay_Us(__IO uint32_t nCount)
{
  /* 10uS延迟=>10.8uS,100uS延迟=>104uS*/
  while (nCount != 0)
  {
	  nCount--;  
	   LedDelay(375);
  }
}
/********************************************************************************
函数名称：Delay_Ms()
功    能：软件延时豪秒级函数
参    数：无
返 回 值：无
*********************************************************************************/
void Delay_Ms(__IO uint32_t nCount)
{
  /* 10uS延迟=>10.8uS,100uS延迟=>104uS*/
  while (nCount != 0)
  {
	nCount--;  
	LedDelay(37500);
  }
}
/********************************************************************************
函数名称：LED_Init()
功    能：F429板载LED初始化
参    数：无
返 回 值：无
*********************************************************************************/
void LED_Init(void)
{
     GPIO_InitTypeDef        GPIO_InitStructure;
     
     /* GPIOG 外部时钟使能 */
     RCC_AHB1PeriphClockCmd(LED_PORT_CLK, ENABLE);
     

     /* 配置 PG13 and PG14 外部输出上拉模式 */
     GPIO_InitStructure.GPIO_Pin   = LED_PIN;
     GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
     GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
     GPIO_Init(LED_PORT , &GPIO_InitStructure);
	   //关闭F429上两个LED
	   GPIO_ResetBits(LED_PORT,LED_PIN);
	  

}
/********************************************************************************
函数名称：LED_RED()
功    能：单个灯闪亮
参    数：无
返 回 值：无
*********************************************************************************/
void LED_RED(void)
{  
          GPIO_WriteBit(LED_PORT,  LED4_PIN , 
		             (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT,  LED4_PIN ))));
	  Delay_Ms(50);
}
/********************************************************************************
函数名称：LED_Flow(void)
功    能：流水灯
参    数：无
返 回 值：无
*********************************************************************************/
void LED_Flow(void)
{      
       GPIO_ResetBits(LED_PORT,LED3_PIN );
	     GPIO_SetBits(LED_PORT,LED4_PIN); 
			 Delay_Ms(delay_num);
			 GPIO_ResetBits(LED_PORT,LED4_PIN);
	     GPIO_SetBits(LED_PORT,LED3_PIN ); 
			 Delay_Ms(delay_num);

}
/********************************************************************************
函数名称：Led_Blink(void)
功    能：流水灯
参    数：无
返 回 值：无
*********************************************************************************/
void Led_Blink(void)
{
    GPIO_ToggleBits(LED_PORT ,LED_PIN);
}
void Led1_Blink(void)
{
    GPIO_ToggleBits(LED_PORT ,LED3_PIN);
}
void Led2_Blink(void)
{
    GPIO_ToggleBits(LED_PORT ,LED4_PIN);
}



 
