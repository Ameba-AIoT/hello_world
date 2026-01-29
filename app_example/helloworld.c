#include "helloworld.h" 

bool is_dhcp_ready = false;

void hello_world(void)
{
    while(1)
    {
        if (is_dhcp_ready)
        {
            RTK_LOGI("app_example","Hello world!\r\n");
            rtos_time_delay_ms(1000);
        }
        else
        {
            RTK_LOGI("app_example","Waiting for wifi ready!\r\n");
            rtos_time_delay_ms(2000);
        }
    }
    rtos_task_delete(NULL);
}


void check_wifi_connected(void)
{
    while (1) 
    {
        if (LwIP_Check_Connectivity(NETIF_WLAN_STA_INDEX) != CONNECTION_VALID)
        {
            is_dhcp_ready = false;
            rtos_time_delay_ms(2000);          
        }
        else
        {
            is_dhcp_ready = true;
            RTK_LOGI("check_dhcp_finished", "Get dhcp succeed!\r\n");
           // vTaskDelay(pdMS_TO_TICKS(5000));     
            rtos_time_delay_ms(2000);           
        }        		
	}
    rtos_task_delete(NULL);
}