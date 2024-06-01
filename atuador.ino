#include <ESP32Servo.h>

static const int servoPin = 13;

Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.setPeriodHertz(50);    // Standard 50hz servo
  servo1.attach(servoPin, 500, 2400); // attaches the servo on pin 13 to the servo object
                                      // 500-2400 us are typical control pulse widths for standard servos
}

void loop() {
  for (int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees); // move the servo to position in variable 'posDegrees'
    Serial.println(posDegrees);
    delay(20);
  }

  for (int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
}
