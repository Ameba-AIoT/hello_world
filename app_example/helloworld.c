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
            rtos_time_delay_ms(500);
        }
      
    }
}
 