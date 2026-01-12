#include "helloworld.h"
#include "lwip_netconf.h"
// #include "os_wrapper_task.h"
#include "FreeRTOS.h"
#include "task.h"


#define TAG "app_main" 

static void check_wifi_connected(void);

extern bool is_dhcp_ready;
void app_example(void)
{
    if (xTaskCreate((TaskFunction_t) check_wifi_connected, "check_wifi_connected", 1024, NULL, tskIDLE_PRIORITY, NULL) != pdPASS )
    {
        RTK_LOGE(TAG, "check_wifi_ready failed!\r\n");
        return;
    }
    else
    {
        // vTaskStartScheduler();
          /* hello_world(); */
        printf("This is a \"hello world\" from app_main function!\r\n");
        RTK_LOGA(TAG, "(RTK_LOG_ALWAYS),hello world!\r\n");
        RTK_LOGE(TAG, "(RTK_LOG_ERROR),hello world!\r\n");
        RTK_LOGW(TAG, "(RTK_LOG_WARN),hello world!\r\n");
        RTK_LOGI(TAG, "(RTK_LOG_INFO),hello world!\r\n");
        RTK_LOGD(TAG, "(RTK_LOG_DEBUG),hello world!\r\n");    
        // rtos_time_delay_ms(1000);
                   

        if (rtos_task_create( NULL, "my_hello_world", (rtos_task_t)hello_world, NULL, 1024, tskIDLE_PRIORITY + 2 ) != RTK_SUCCESS )
        {
            RTK_LOGE(TAG, "rtos_task_creat failed!\r\n");
        }        
    }
   
}

void check_wifi_connected(void)
{
    while (1) 
    {
        if (LwIP_Check_Connectivity(NETIF_WLAN_STA_INDEX) != CONNECTION_VALID)
        {
            is_dhcp_ready = false;
            vTaskDelay(pdMS_TO_TICKS(1000));            
        }
        else
        {
            is_dhcp_ready = true;
            //RTK_LOGI("check_dhcp_finished", "Get dhcp finished!\r\n");
            vTaskDelay(pdMS_TO_TICKS(5000)); 
            // vTaskDelete(NULL);
            // return;
        }
        		
	}
}