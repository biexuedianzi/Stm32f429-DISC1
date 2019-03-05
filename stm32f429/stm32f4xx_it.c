/**
  ******************************************************************************
  * @file    stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-November-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "includes.h"

extern void LTDC_ISR_Handler(void);
extern void DMA2D_ISR_Handler(void);
extern __IO int32_t OS_TimeMS;
/** @addtogroup STM32F429I_DISCOVERY_Examples
  * @{
  */

/** @addtogroup SysTick_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
//void SVC_Handler(void)
//{
//}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}






/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//void SysTick_Handler(void)
//{
//   //TimingDelay_Decrement();
//	   OS_TimeMS ++;
//}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f429_439xx.s).  */
/******************************************************************************/
extern  unsigned char  Key_num ;
/*******************************************************************************
* ��������: EXTI0_IRQHandler()
* ��������: �ⲿ�жϷ�����
* �������: void
* ���ز���: ��
* ˵��    �� 
********************************************************************************/
void EXTI0_IRQHandler(void) 
{
    if(EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) != RESET)
   { 
  		    
		     Key_num ++ ;		     
         EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
   } 
        if(Key_num ==1)
	      {
            GPIO_SetBits(LED_PORT ,LED3_PIN);   
	          Delay_Ms(200);
					  GPIO_ResetBits(LED_PORT ,LED3_PIN); 
            printf("LED���ƣ���ɫ��\r\n");					
        }
       if(Key_num ==3)
        {   Key_num =0;
		        GPIO_SetBits(LED_PORT ,LED4_PIN);   
	          Delay_Ms(200);
					  GPIO_ResetBits(LED_PORT ,LED4_PIN);   
            printf("LED���ƣ���ɫ��\r\n");				
        }	 
  
   

}
extern unsigned char  Usart_buf[2];     // ������ջ�����
extern unsigned char  U_flag;
/*******************************************************************************
* ��������: USART1_IRQHandler()
* ��������: �����жϷ�����
* �������: void
* ���ز���: ��
* ˵��    �� ������ʱ��USART_ITConfig(USART1, USART_IT_TXE, DISABLE)�ر��ж�
********************************************************************************/
void USART1_IRQHandler(void)   
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);//�ȴ�����Ϊ��
	    
	      Usart_buf[0]= USART_ReceiveData(USART1); //�����һ������
	  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);	
        USART_SendData(USART1, Usart_buf[0]);  	//����ȥ���� 
    if(Usart_buf[0]==0xEE)
		{   
				Usart_buf[0]=0x00; //��մ���
				
				
    }
    if(Usart_buf[0]==0xDD)
		{   
				Usart_buf[0]=0x00; //��մ���
								
    }
}
void LTDC_IRQHandler(void)
{
    LTDC_ISR_Handler();
}

/**
  * @brief  This function handles DMA2D global interrupt request.
  * @param  None
  * @retval None
  */
void DMA2D_IRQHandler(void)
{
    DMA2D_ISR_Handler();
}


/**
  * @}
  */ 

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
