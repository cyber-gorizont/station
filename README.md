# station

Autonomous battery-changing system for UAV’s lifelong flight

## 🛠 Getting Started

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)

2. Clone the repository:

```
$ git clone https://github.com/cyber-gorizont/station.git
```

3. Navigate to the project directory:

```
$ cd station/src
```

4. Build the firmware:

```
$ pio run
```

5. Upload the firmware

```
$ pio run --target upload
```

6. After first flashing you can upload firmware wirelessly in your browser or using curl command

```
$ curl -X POST -F "firmware=@path/to/your/firmware.bin" http://<ESP32_IP>/update
```

