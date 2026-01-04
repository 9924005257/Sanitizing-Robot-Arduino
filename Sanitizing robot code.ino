/*
  Sanitizing Robot using Arduino
  Control: Bluetooth (HC-05)
  Author: R R Hariharan
*/

char command;

// Motor Driver Pins
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

// Water Pump Pin
#define PUMP 8

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PUMP, OUTPUT);

  stopRobot();          // Safety: stop motors at start
  digitalWrite(PUMP, LOW);

  Serial.begin(9600);   // Bluetooth baud rate
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    switch (command) {

      case 'F':
        moveForward();
        break;

      case 'B':
        moveBackward();
        break;

      case 'L':
        turnLeft();
        break;

      case 'R':
        turnRight();
        break;

      case 'S':
        stopRobot();
        break;

      case 'P':
        digitalWrite(PUMP, HIGH);
        break;

      case 'p':
        digitalWrite(PUMP, LOW);
        break;

      default:
        stopRobot();   // Safety fallback
        break;
    }
  }
}

/* ---------- Motor Functions ---------- */

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
