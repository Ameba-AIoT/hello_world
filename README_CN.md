* [English Version](./README.md)

### Ameba RTL8721Dx 系列 SoC 的 Hello World 示例（FreeRTOS）


🚀 这是一个基于RTL8721Dx系列SoC的“Hello World”程序，演示了系统中不同日志级别的效果，并检查WiFi连接和通过DHCP获取IP。

- 📎 开发板链接  [🛒 淘宝](https://item.taobao.com/item.htm?id=904981157046)   |[📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)
- 📄 [芯片详情](https://aiot.realmcu.com/cn/module/index.html)
- 📚 [AT+WLCONN](https://aiot.realmcu.com/cn/latest/rtos/atcmd/at_command_wifi.html#at-wlconn)

### 功能特点

✅ 在初始化期间自动打印不同级别的系统事件日志。  
✅ 成功连接到WiFi并获取IP地址后，每秒打印“Hello World”。  
✅ 如果WiFi连接丢失，暂停消息打印，恢复连接后继续打印。

### 工作原理

1️⃣ **日志级别**：在程序初始化期间显示各类日志（如信息、警告、错误）。  
2️⃣ **WiFi连接**：系统尝试连接WiFi并获取IP地址。  
3️⃣ **消息循环**：程序中启动了两个线程：线程1监听IP地址，线程2打印“Hello World”。  
4️⃣ **WiFi断开连接**：当WiFi断开连接时，暂停“Hello World”打印，在重新连接后恢复。

### 快速开始

1️⃣ **选择SDK**  
   - 设置`env.sh`（`env.bat`）路径：`source {sdk}/env.sh`  
   - 将`{sdk}`替换为[ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos)根目录中`env.sh`的绝对路径。如果SDK路径没有改变，此步骤仅需执行一次。

2️⃣ **编译**  
   - 在HELLO_WORLD根目录下执行：  
     ```bash
     source env.sh
     ameba.py build
     ```

3️⃣ **烧录**  
   ```bash
   ameba.py flash --p COMx --image boot.bin 0x08000000 0x8014000 --image app.bin 0x08014000 0x8200000
   ```
   ⚡ **注意**：项目目录中提供了预编译的bin文件，可以直接使用以下方式烧录：
   ```bash
   ameba.py flash --p COMx --image ../boot.bin 0x08000000 0x8014000 --image ../app.bin 0x08014000 0x8200000
   ```

> ⚠️ **bin 文件命名说明**：bin 文件名称取决于所使用的 SDK 版本。
> 最新 SDK 编译产物为 `boot.bin` + `app.bin`；
> 旧版 SDK 编译产物为 `km4_boot_all.bin` + `km0_km4_app.bin`。
> 请根据实际编译输出修改上方命令中的文件名。

4️⃣ **打开串口监视**  
   - `ameba.py monitor --port COM5 --b 1500000`

5️⃣ **连接Wi-Fi**  
   - 使用AT命令连接WiFi，详情参考[AT+WLCONN](https://aiot.realmcu.com/cn/latest/rtos/atcmd/at_command_wifi.html#at-wlconn)。  
   - 示例：`AT+WLCONN=ssid,Xiaomi_Pro_2G,pw,12345678`

6️⃣ **观察日志输出** 📜

7️⃣ **重启AP并观察日志输出** 🔄

8️⃣ **按开发板上的RESET按钮，观察自动重新连接WiFi** 🔁

### 日志示例
---

```plaintext
日志示例：
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