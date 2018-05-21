/*
 * ServoMotor
 * Basic servo motor without button controlling
 */

#include <Servo.h>
Servo myservo;

void setup()
{
  Serial.begin(115200);
  myservo.attach(4);// Porta Digital 4 PWM
  myservo.write(0);
}

void loop() {

  for(int angle = 15; angle < 180; angle += 15) {
    myservo.write(angle);
    delay(50);
  }
  for(int angle = 180; angle >= 0; angle -= 15) {
    myservo.write(angle);
    delay(50);
  }
}
