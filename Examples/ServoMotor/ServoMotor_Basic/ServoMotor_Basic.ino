/*
 * ServoMotor
 * Basic servo motor without button controlling
 */

#include <Servo.h>
Servo myservo;
int delayTime = 50;

void setup()
{
  Serial.begin(115200);
  myservo.attach(8);
  myservo.write(0);
}

void loop() {

  for(int angle = 15; angle < 180; angle += 15) {
    myservo.write(angle);
    delay(delayTime);
  }
  for(int angle = 180; angle >= 0; angle -= 15) {
    myservo.write(angle);
    delay(delayTime);
  }
}
