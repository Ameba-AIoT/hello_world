#include "helloworld.h"
#include "FreeRTOS.h"
#include "task.h"
#include "log.h"


#define TAG     "app_main" 
extern bool is_dhcp_ready;

void app_example(void)
{   
        /* hello_world(); */
    printf("This is a \"hello world\" from app_main function!\r\n");
    RTK_LOGA(TAG, "(RTK_LOG_ALWAYS),hello world!\r\n");
    RTK_LOGE(TAG, "(RTK_LOG_ERROR),hello world!\r\n");
    RTK_LOGW(TAG, "(RTK_LOG_WARN),hello world!\r\n");
    RTK_LOGI(TAG, "(RTK_LOG_INFO),hello world!\r\n");
    RTK_LOGD(TAG, "(RTK_LOG_DEBUG),hello world!\r\n");  
                

    // if (xTaskCreate((TaskFunction_t) check_wifi_connected, "check_wifi_connected", 1024, NULL, tskIDLE_PRIORITY, NULL) != pdPASS )
    if (rtos_task_create( NULL, "check_wifi_connected", (rtos_task_t)check_wifi_connected, (void *)NULL, 1024, tskIDLE_PRIORITY + 1 ) != RTK_SUCCESS )
    {
        RTK_LOGE(TAG, "check_wifi_ready failed!\r\n");        
    }
   
    // vTaskStartScheduler();

    if (rtos_task_create( NULL, "my_hello_world", (rtos_task_t)hello_world, (void *)NULL, 1024, tskIDLE_PRIORITY ) != RTK_SUCCESS )
    {
        RTK_LOGE(TAG, "rtos_task_creat failed!\r\n");
    }        
    
}
