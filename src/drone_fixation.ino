/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald

 modified for the ESP32 on March 2017
 by John Bennett

 see http://www.arduino.cc/en/Tutorial/Sweep for a description of the original code

 * Different servos require different pulse widths to vary servo angle, but the range is 
 * an approximately 500-2500 microsecond pulse every 20ms (50Hz). In general, hobbyist servos
 * sweep 180 degrees, so the lowest number in the published range for a particular servo
 * represents an angle of 0 degrees, the middle of the range represents 90 degrees, and the top
 * of the range represents 180 degrees. So for example, if the range is 1000us to 2000us,
 * 1000us would equal an angle of 0, 1500us would equal 90 degrees, and 2000us would equal 1800
 * degrees.
 * 
 * Circuit: (using an ESP32 Thing from Sparkfun)
 * Servo motors have three wires: power, ground, and signal. The power wire is typically red,
 * the ground wire is typically black or brown, and the signal wire is typically yellow,
 * orange or white. Since the ESP32 can supply limited current at only 3.3V, and servos draw
 * considerable power, we will connect servo power to the VBat pin of the ESP32 (located
 * near the USB connector). THIS IS ONLY APPROPRIATE FOR SMALL SERVOS. 
 * 
 * We could also connect servo power to a separate external
 * power source (as long as we connect all of the grounds (ESP32, servo, and external power).
 * In this example, we just connect ESP32 ground to servo ground. The servo signal pins
 * connect to any available GPIO pins on the ESP32 (in this example, we use pin 18.
 * 
 * In this example, we assume a Tower Pro MG995 large servo connected to an external power source.
 * The published min and max for this servo is 1000 and 2000, respectively, so the defaults are fine.
 * These values actually drive the servos a little past 0 and 180, so
 * if you are particular, adjust the min and max values to match your needs.
 */

#include <ESP32Servo.h>

Servo servo1;  // create servo object to control a servo 1
Servo servo2;  // create servo object to control a servo 2
// 16 servo objects can be created on the ESP32

static const int gerConPin = 12;
static const int servo1Pin = 14;
static const int servo2Pin = 27;
static int isDroneLanded = 0;
static bool isDroneFixed = false;
static int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42
// Possible PWM GPIO pins on the ESP32-S3: 0(used by on-board button),1-21,35-45,47,48(used by on-board LED)
// Possible PWM GPIO pins on the ESP32-C3: 0(used by on-board button),1-7,8(used by on-board LED),9-10,18-21

void setup() {
  Serial.begin(115200);
  pinMode(gerConPin, INPUT);
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo1.setPeriodHertz(50);    // standard 50 hz servo
  servo2.setPeriodHertz(50);    // standard 50 hz servo
	//servo1.attach(servo1Pin);     // attaches the servo on pin 14 to the servo 1 object
  //servo2.attach(servo2Pin);     // attaches the servo on pin 27 to the servo 2 object
	servo1.attach(servo1Pin, 1000, 2000); // attaches the servo on pin 14 to the servo 1 object
  servo2.attach(servo2Pin, 1000, 2000); // attaches the servo on pin 27 to the servo 2 object
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
}

void loop() {
  isDroneLanded = digitalRead(gerConPin);
  Serial.println(isDroneLanded);
  if (isDroneLanded == 1 && isDroneFixed == false) {
    Serial.println("Turning servos to 180 degrees...");
    servo1.write(0);      // tell servo 1 to go to position to 180 degrees
    servo2.write(0);      // tell servo 2 to go to position to 180 degrees
    delay(1000);
    Serial.println("Stopping servos...");
    servo1.write(90);        // stop servo 1
    servo2.write(90);        // stop servo 2
    isDroneFixed = true;
    Serial.println("Servos turned to 180 degrees...");
    delay(5000);
  } else if (isDroneLanded = 1 && isDroneFixed == true) {
    Serial.println("Turning servos to 0 degrees...");
    servo1.write(180);      // tell servo 1 to go to position to 0 degrees
    servo2.write(180);      // tell servo 2 to go to position to 0 degrees
    delay(1000);
    Serial.println("Stopping servos...");
    servo1.write(90);        // stop servo 1
    servo2.write(90);        // stop servo 2
    isDroneFixed = false;
    Serial.println("Servos turned to 0");
    delay(5000);
	}
  delay(10);
}
