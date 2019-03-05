
/*Includes --------------------------------------------------------------------*/
  #include "includes.h"
	#include "GUIDEMO.h"
  


	

/* 类型定义 typedef------------------------------------------------------------*/
/* 预定义字符------------------------------------------------------------------*/
/* 宏定义----------------------------------------------------------------------*/
/* 变量定义--------------------------------------------------------------------*/ 
unsigned short int   delay_num =100; //软件延时参数
unsigned long        sys_time =0;
unsigned char  Usart_buf[2];     //  定义串口缓冲器
unsigned char  Key_num  =0;      //  按键键值
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

#define START_TASK_PRIO 1 //任务优先级
#define START_STK_SIZE 128 //任务堆栈大小
TaskHandle_t StartTask_Handler; //任务句柄
void start_task(void *pvParameters); //任务函数
#define LED0_TASK_PRIO 2 //任务优先级
#define LED0_STK_SIZE (4*1024) //任务堆栈大小
TaskHandle_t LED0Task_Handler; //任务句柄
void led0_task(void *p_arg); //任务函数
#define LED1_TASK_PRIO 3 //任务优先级
#define LED1_STK_SIZE 50 //任务堆栈大小
TaskHandle_t LED1Task_Handler; //任务句柄
void led1_task(void *p_arg); //任务函数



//开始任务任务函数

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL(); //进入临界区
    //创建LED0 任务
    xTaskCreate((TaskFunction_t )led0_task,
    (const char* )"led0_task",
    (uint16_t )LED0_STK_SIZE,
    (void* )NULL,
    (UBaseType_t )LED0_TASK_PRIO,
    (TaskHandle_t* )&LED0Task_Handler);
    //创建LED1 任务
    xTaskCreate((TaskFunction_t )led1_task,
    (const char* )"led1_task",
    (uint16_t )LED1_STK_SIZE,
    (void* )NULL,
    (UBaseType_t )LED1_TASK_PRIO,
    (TaskHandle_t* )&LED1Task_Handler);
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL(); //退出临界区
}

//LED0 任务函数

void led0_task(void *pvParameters)
{
	while(1)
	{
		MainTask();
		vTaskDelay(800);
	}
}

//LED1 任务函数
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
函数名称: main()
功    能: 主函数入口
参    数: 无
返 回 值: 无
*********************************************************************************/
int main(void)
{   
	    SystemInit(); //系统时钟配置函数，通过不同的时钟定义，来选择不同的主频
//===============================================================================//	   
      Nvic_Init();
      Systick_Init();	
	    LED_Init();
      Key_Init();
	    Uart_Init();
			DelayInit();
	    printf("STM32F429DISCOVERY串口初始化\r\n");
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
			xTaskCreate((TaskFunction_t )start_task, //任务函数
			(const char* )"start_task", //任务名称
			(uint16_t )START_STK_SIZE, //任务堆栈大小
			(void* )NULL, //传递给任务函数的参数
			(UBaseType_t )START_TASK_PRIO, //任务优先级
			(TaskHandle_t* )&StartTask_Handler); //任务句柄
			vTaskStartScheduler(); //开启任务调度

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
