
# Hello World Example for Ameba RTL8721Dx Series SoC (FreeRTOS)

* [中文版](./README_CN.md)

🚀 This is a "Hello World" program based on the RTL8721Dx series SoC. It demonstrates the effects of different log levels in the system and checks WiFi connectivity and IP acquisition via DHCP.

🖥️ *EVB Link:* [EVB Board](https://item.taobao.com/item.htm?id=904981157046)  
🔗 *IC Details:* [Chip Information](https://riot.realmcu.com/cn/module/index.html)

## Features

🔹 Automatically prints system event logs at different levels during initialization.  
🔹 Prints "Hello World" every second after successfully connecting to WiFi and obtaining an IP address.  
🔹 Pauses message printing if the WiFi connection is lost and resumes once it is restored.

## Working Principle

1️⃣ **Log Levels**: Displays logs of various levels (such as info, warning, error) during program initialization.  
2️⃣ **WiFi Connection**: The system attempts to connect to WiFi and obtain an IP address.  
3️⃣ **Message Loop**: Two threads are started in the program: thread 1 listens for the IP address, and thread 2 prints "Hello World".  
4️⃣ **WiFi Disconnection**: When WiFi is disconnected, the printing of "Hello World" is paused and resumes after reconnection.

## Quick Start

1️⃣ **Select SDK**  
   - Set the path for `env.sh` (`env.bat`): `source {sdk}/env.sh`  
   - Replace `{sdk}` with the absolute path to `env.sh` in the root directory of the [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos). This step only needs to be performed once if the SDK path remains unchanged.

2️⃣ **Build**  
   - Execute the following in the HELLO_WORLD root directory:  
     ```bash
     source env.sh
     ameba.py build
     ```

3️⃣ **Flash Burning**  
   ⚡ **Note**: Precompiled bin files are provided in the project directory, which can be directly flashed using:  
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```

4️⃣ **Monitor**  
   - `ameba.py monitor --port COM5 --b 1500000`

5️⃣ **Connect to Wi-Fi**  
   - Use AT commands to connect to WiFi. Refer to [AT+WLCONN](https://riot.realmcu.com/cn/latest/rtos/atcmd/at_command_wifi.html#at-wlconn) for details.  
   - Example: `AT+WLCONN=ssid,Xiaomi_Pro_2G,pw,12345678`

6️⃣ **Observe Log Outputs** 📜

7️⃣ **Reboot the AP and observe log outputs** 🔄

8️⃣ **Press the RESET button on the development board and observe automatic WiFi reconnection** 🔁

---

```plaintext
Example log:
16:30:14.033  ROM:[V1.1]
16:30:14.033  FLASH RATE:1, Pinmux:1
16:30:14.048  IMG1(OTA1) VALID, ret: 0
16:30:14.048  IMG1 ENTRY[f80078d:0]
16:30:14.048  [BOOT-I] KM4 BOOT REASON 0: Initial Power on
16:30:14.048  [BOOT-I] KM4 CPU CLK: 240000000 Hz
16:30:14.048  [BOOT-I] KM0 CPU CLK: 96000000 Hz
16:30:14.048  [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz 
16:30:14.091  [BOOT-I] IMG1 ENTER MSP:[30009FDC]
16:30:14.091  [BOOT-I] Build Time: Jan 23 2026 16:29:37
16:30:14.091  [BOOT-I] IMG1 SECURE STATE: 1
16:30:14.091  [FLASH-I] FLASH CLK: 80000000 Hz
16:30:14.091  [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
16:30:14.091  [FLASH-I] Flash Read 4IO
16:30:14.091  [FLASH-I] FLASH HandShake[0x2 OK]
16:30:14.091  [BOOT-I] KM0 XIP IMG[0c000000:52de0]
16:30:14.091  [BOOT-I] KM0 SRAM[20068000:30e0]
16:30:14.091  [BOOT-I] KM0 PSRAM[0c055ec0:20]
16:30:14.091  [BOOT-I] KM0 ENTRY[20004d00:60]
16:30:14.091  [BOOT-I] KM4 XIP IMG[0e000000:668c0]
16:30:14.091  [BOOT-I] KM4 SRAM[2000b000:1ea0]
16:30:14.091  [BOOT-I] KM4 PSRAM[0e068760:20]
16:30:14.092  [BOOT-I] KM4 ENTRY[20004d80:40]
16:30:14.092  [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1 
16:30:14.092  [BOOT-I] Image2Entry @ 0xe00d359 ...
16:30:14.092  [APP-I] KM4 APP START 
16:30:14.092  [APP-I] VTOR: 30007000, VTOR[LOCKS-I_NS:3000] KM0 init_retar7000
16:30:14.092  get_lock[APP-I]s
16:30:14.092   VTOR: 30007000, VTOR_NS:30007000
16:30:14.092  [APP-I] IMG2 SECURE STATE: 1
16:30:14.092  [MAIN-I] IWDG refresh on!
16:30:14.092  [MAIN-I] KM0 [COLSK S-TIA]R T[C A
16:30:14.092  L4M]: delta:0 target:320 PPM: 0 PPM_Limit:30000 
16:30:14.092  [CLK-I] [CAL131K]: delta:8 target:2441 PPM: 3277 PPM_Limit:30000 
16:30:14.092  [LOCKS-I] KM4 init_retarget_locks
16:30:14.092  [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
16:30:14.092  [MAIN-I] KM4 MAIN 
16:30:14.092  [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
16:30:14.092  [MAIN-I] File System Init Success 
16:30:14.092  This is a "hello world" from app_main function!
16:30:14.093  [app_main-A] (RTK_LOG_ALWAYS),hello world!
16:30:14.093  [app_main-E] (RTK_LOG_ERROR),hello world!
16:30:14.093  [app_main-W] (RTK_LOG_WARN),hello world!
16:30:14.093  [app_main-I] (RTK_LOG_INFO),hello world!
16:30:14.093  [MAIN-I] KM4 START SCHEDULER 
16:30:14.093  interface 0 is initialized
16:30:14.093  interface 1 is initialized
16:30:14.093  [WLAN-I] LWIP consume heap 1312
16:30:14.093  Wait for WiFi and DHCP Connect Success...
16:30:14.093  Please use AT+WLCONN to connect AP first time
16:30:14.093  [app_example-I] Waiting for wifi ready!
16:30:14.093  [WLAN-A] Init WIFI
16:30:14.099  [WLAN-A] Band=2.4G&5G
16:30:14.121  [WLAN-I] NP consume heap 20336
16:30:14.131  [WLAN-A] set ssid Xiaomi_Pro_2G
16:30:14.289  [WLAN-A] start auth to 50:64:2b:34:88:9e
16:30:14.337  [WLAN-A] auth success, start assoc
16:30:14.368  [WLAN-A] assoc success(3)
16:30:14.493  [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
16:30:14.525  [WLAN-A] set group key 4 1
16:30:14.525  [WLAN-I] set cam: gtk alg 4 0
16:30:14.525  [$]wifi connected
16:30:14.902  [$]wifi got ip:"192.168.32.32"
16:30:14.902  wtn dhcp success
16:30:14.902  [WLAN-I] AP consume heap 12184
16:30:14.902  [WLAN-I] Available heap after wifi init 325984
16:30:16.077  [check_dhcp_finished-I] Get dhcp succeed!
16:30:16.077  [app_example-I] Hello world!
16:30:17.078  [app_example-I] Hello world!
16:30:18.078  [check_dhcp_finished-I] Get dhcp succeed!
16:30:18.078  [app_example-I] Hello world!
16:30:19.094  [app_example-I] Hello world!
16:30:20.080  [check_dhcp_finished-I] Get dhcp succeed!
16:30:20.080  [app_example-I] Hello world!
16:30:21.535  [app_example-I] Hello world!
16:30:22.410  [check_dhcp_finished-I] Get dhcp succeed!
16:30:22.410  [app_example-I] Hello world!
16:30:23.081  [app_example-I] Hello world!
16:30:24.098  [check_dhcp_finished-I] Get dhcp succeed!
16:30:24.098  [app_example-I] Hello world!
16:30:25.081  [app_example-I] Hello world!
16:30:26.271  [check_dhcp_finished-I] Get dhcp succeed!
16:30:26.271  [app_example-I] Hello world!
16:30:27.085  [app_example-I] Hello world!
16:30:28.097  [check_dhcp_finished-I] Get dhcp succeed!
16:30:28.097  [app_example-I] Hello world!
16:30:29.098  [app_example-I] Hello world!
16:30:30.099  [check_dhcp_finished-I] Get dhcp succeed!
16:30:30.099  [app_example-I] Hello world!
16:30:31.099  [app_example-I] Hello world!
...
```
