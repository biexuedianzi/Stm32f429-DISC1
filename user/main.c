
/*Includes --------------------------------------------------------------------*/
  #include "includes.h"
	#include "GUIDEMO.h"
  


	

/* ���Ͷ��� typedef------------------------------------------------------------*/
/* Ԥ�����ַ�------------------------------------------------------------------*/
/* �궨��----------------------------------------------------------------------*/
/* ��������--------------------------------------------------------------------*/ 
unsigned short int   delay_num =100; //�����ʱ����
unsigned long        sys_time =0;
unsigned char  Usart_buf[2];     //  ���崮�ڻ�����
unsigned char  Key_num  =0;      //  ������ֵ
unsigned char  U_flag=0;


void vApplicationIdleHook(void)
{
  printf("vApplicationIdleHook function");
	while(1);
}
void vApplicationTickHook(void)
{
//	printf("vApplicationTickHook function");
#if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 0 )
    {
        // In this case the tick hook is used as part of the queue set test. 
    }
#endif // mainCREATE_SIMPLE_BLINKY_DEMO_ONLY 
}
void vApplicationMallocFailedHook(void)
{
	printf("vApplicationMallocFailedHook function");
    taskDISABLE_INTERRUPTS();
    for(;;);
}

#define START_TASK_PRIO 1 //�������ȼ�
#define START_STK_SIZE 128 //�����ջ��С
TaskHandle_t StartTask_Handler; //������
void start_task(void *pvParameters); //������
#define LED0_TASK_PRIO 2 //�������ȼ�
#define LED0_STK_SIZE (4*1024) //�����ջ��С
TaskHandle_t LED0Task_Handler; //������
void led0_task(void *p_arg); //������
#define LED1_TASK_PRIO 3 //�������ȼ�
#define LED1_STK_SIZE 50 //�����ջ��С
TaskHandle_t LED1Task_Handler; //������
void led1_task(void *p_arg); //������



//��ʼ����������

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL(); //�����ٽ���
    //����LED0 ����
    xTaskCreate((TaskFunction_t )led0_task,
    (const char* )"led0_task",
    (uint16_t )LED0_STK_SIZE,
    (void* )NULL,
    (UBaseType_t )LED0_TASK_PRIO,
    (TaskHandle_t* )&LED0Task_Handler);
    //����LED1 ����
    xTaskCreate((TaskFunction_t )led1_task,
    (const char* )"led1_task",
    (uint16_t )LED1_STK_SIZE,
    (void* )NULL,
    (UBaseType_t )LED1_TASK_PRIO,
    (TaskHandle_t* )&LED1Task_Handler);
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL(); //�˳��ٽ���
}

//LED0 ������

void led0_task(void *pvParameters)
{
	while(1)
	{
		MainTask();
		vTaskDelay(800);
	}
}

//LED1 ������
void led1_task(void *pvParameters)
{
	int i=0;
	while(1)
	{
		i++;
//		Led_Blink();
		Pointer_Update();
		vTaskDelay(50);
	}

}

/********************************************************************************
��������: main()
��    ��: ���������
��    ��: ��
�� �� ֵ: ��
*********************************************************************************/
int main(void)
{   
	    SystemInit(); //ϵͳʱ�����ú�����ͨ����ͬ��ʱ�Ӷ��壬��ѡ��ͬ����Ƶ
//===============================================================================//	   
      Nvic_Init();
      Systick_Init();	
	    LED_Init();
      Key_Init();
	    Uart_Init();
			DelayInit();
	    printf("STM32F429DISCOVERY���ڳ�ʼ��\r\n");
	    /* LCD initialization */
	    /***********************GUI*********************************/
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	    WM_SetCreateFlags(WM_CF_MEMDEV);
	    GUI_Init();
			IOE_Config();
	    //GUI_SetOrientation(0);
//			GUI_DispString("Hello world!");
	
//			IOE_Config();
			/***********************RTOS*********************************/
			xTaskCreate((TaskFunction_t )start_task, //������
			(const char* )"start_task", //��������
			(uint16_t )START_STK_SIZE, //�����ջ��С
			(void* )NULL, //���ݸ��������Ĳ���
			(UBaseType_t )START_TASK_PRIO, //�������ȼ�
			(TaskHandle_t* )&StartTask_Handler); //������
			vTaskStartScheduler(); //�����������

}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif




/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
