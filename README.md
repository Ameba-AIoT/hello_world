# Hello World example for Ameba RTL8721Dx Series SoC（free_rtos）
* [中文版](./README_CN.md)


This is a "Hello World" program based on the RTL8721Dx series SoC. It demonstrates the effects of different log levels in the system and checks WiFi connectivity and IP acquisition via DHCP.

* [EVB Link](https://item.taobao.com/item.htm?id=904981157046)
* [IC Link](https://riot.realmcu.com/cn/module/index.html)

## Features

- Automatically prints system event logs at different levels during initialization.
- Prints "Hello World" every second after successfully connecting to WiFi and obtaining an IP address.
- Pauses message printing if the WiFi connection is lost and resumes once it is restored.

## Working Principle

1. **Log Levels**: Displays logs of various levels (such as info, warning, error) during program initialization.
2. **WiFi Connection**: The system attempts to connect to WiFi and obtain an IP address.
3. **Message Loop**: Two threads are started in the program: thread 1 listens for the IP address, and thread 2 prints "Hello World".
4. **WiFi Disconnection**: When WiFi is disconnected, the printing of "Hello World" is paused and resumes after reconnection.

## Quick Start

1. **Select SDK**
   - Set the path for `env.sh` (`env.bat`): `source {sdk}/env.sh`
   - Replace `{sdk}` with the absolute path to `env.sh` in the root directory of the [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos). This step only needs to be performed once if the SDK path remains unchanged.

2. **Compile**
   - Execute the following in the HELLO_WORLD root directory:
     ```bash
     source env.sh
     ameba.py build
     ```

3. **Flash Burning**
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   **Note**: Precompiled bin files are provided in the project directory, which can be directly flashed using:
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4. **Monitor**
   - `ameba.py monitor --port COM5 --b 1500000`

5. **Connect to WiFi**
   - Use AT commands to connect to WiFi. Refer to [AT+WLCONN](https://riot.realmcu.com/cn/latest/rtos/atcmd/at_command_wifi.html#at-wlconn) for details.
   - Example: `AT+WLCONN=ssid,Xiaomi_Pro_2G,pw,12345678`

6. **Observe Log Outputs**

7. **Reboot the AP and observe log outputs**

8. **Press the RESET button on the development board and observe automatic WiFi reconnection**


---

 ```bash
 log：
2026-01-12 18:00:45.885 This is a "hello world" from app_main function!
2026-01-12 18:00:45.885 [app_main-A] (RTK_LOG_ALWAYS),hello world!
2026-01-12 18:00:45.885 [app_main-E] (RTK_LOG_ERROR),hello world!
2026-01-12 18:00:45.885 [app_main-W] (RTK_LOG_WARN),hello world!
2026-01-12 18:00:45.885 [app_main-I] (RTK_LOG_INFO),hello world!
2026-01-12 18:00:45.885 [MAIN-I] KM4 START SCHEDULER 
2026-01-12 18:00:45.885 interface 0 is initialized
2026-01-12 18:00:45.885 interface 1 is initialized
2026-01-12 18:00:45.885 [WLAN-I] LWIP consume heap 1312
2026-01-12 18:00:45.885 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:45.885 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:45.885 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:45.885 [WLAN-A] Init WIFI
2026-01-12 18:00:45.895 [WLAN-A] Band=2.4G&5G
2026-01-12 18:00:45.925 [WLAN-I] NP consume heap 20336
2026-01-12 18:00:45.925 [WLAN-A] set ssid Xiaomi_Pro_2G
2026-01-12 18:00:46.096 [WLAN-A] start auth to 50:64:2b:34:88:9e
2026-01-12 18:00:46.137 [WLAN-A] auth success, start assoc
2026-01-12 18:00:46.177 [WLAN-A] assoc success(2)
2026-01-12 18:00:46.389 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:46.893 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:46.893 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:46.893 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:47.386 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:47.890 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:47.890 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:47.890 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:48.323 [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
2026-01-12 18:00:48.323 [WLAN-A] set group key 4 1
2026-01-12 18:00:48.323 [WLAN-I] set cam: gtk alg 4 0
2026-01-12 18:00:48.323 [$]wifi connected
2026-01-12 18:00:48.383 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:48.887 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:48.887 Wait for WiFi and DHCP Connect Success...
2026-01-12 18:00:48.887 Please use AT+WLCONN to connect AP first time
2026-01-12 18:00:49.401 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:49.401 [$]wifi got ip:"192.168.32.39"
2026-01-12 18:00:49.401 wtn dhcp success
2026-01-12 18:00:49.401 [WLAN-I] AP consume heap 11832
2026-01-12 18:00:49.401 [WLAN-I] Available heap after wifi init 321952
2026-01-12 18:00:49.904 [app_example-I] Waiting for wifi ready!
2026-01-12 18:00:50.408 [app_example-I] Hello world!
2026-01-12 18:00:51.424 [app_example-I] Hello world!
2026-01-12 18:00:52.421 [app_example-I] Hello world!
2026-01-12 18:00:53.427 [app_example-I] Hello world!
2026-01-12 18:00:54.413 [app_example-I] Hello world!
2026-01-12 18:00:55.430 [app_example-I] Hello world!
 ```