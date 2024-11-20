// Define GPIO pins connected to the L298N
#define IN1 12 // Replace with your IN1 pin
#define IN2 14 // Replace with your IN2 pin
#define IN3 27 // Replace with your IN3 pin
#define IN4 26 // Replace with your IN4 pin
#define EN 25 // Replace with your ENABLE pin

// Define steps per revolution for your stepper motor (adjust as needed)
#define STEPS_PER_REV 200


void setup() {
  Serial.begin(115200); // Initialize serial communication for debugging

  // Set GPIO pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN, OUTPUT);

  // Enable the motor driver (set ENABLE pin HIGH)
  digitalWrite(EN, HIGH);
}

void stepClockwise() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delayMicroseconds(1000); // Adjust delay for speed. Smaller value = faster.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delayMicroseconds(1000);
}

void stepCounterClockwise() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delayMicroseconds(1000); // Adjust delay for speed. Smaller value = faster.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delayMicroseconds(1000);
}

void stepMotor(int steps, int direction) {
  for (int i = 0; i < abs(steps); i++) {
    if (direction > 0) { // Clockwise rotation
      stepClockwise();
    } else { // Counter-clockwise rotation
      stepCounterClockwise();
    }
  }
}

void loop() {
  // Rotate the motor 100 steps clockwise
  Serial.println("Rotating 100 steps clockwise");
  stepMotor(100, 1);
  delay(2000); //Pause for 2 seconds

  // Rotate the motor 100 steps counter-clockwise
  Serial.println("Rotating 100 steps counter-clockwise");
  stepMotor(100, -1);
  delay(2000); //Pause for 2 seconds
}
