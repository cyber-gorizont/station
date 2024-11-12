# station

Autonomous battery-changing system for UAV’s lifelong flight

## 🛠 Getting Started

#### Use Arduino IDE or makeEspArduino project

##### Prerequisites:

[Download and install Arduino IDE](https://www.arduino.cc/en/software) or [makeEspArduino](https://github.com/plerup/makeEspArduino#installing).

1. Clone the repository:

```
git clone https://github.com/cyber-gorizont/station.git
```

2. Navigate to the project directory:

```
cd station
```

3. [Download and install ESP32Servo](https://github.com/christophevg/ESP32Servo#installation)

4. Compile the program and flash a ESP32:

```
espmake32 SKETCH=src/drone_fixation.ino flash
```

Change the "ESP_ROOT", "CHIP" and "SKETCH" variables or remove it according to your project

