/*
 * ServoMotor
 * Start servomotor with push button,  
 * TurnOn led when motor is moving and
 * Stop servomotor only after to complete a turn
 */

#include <Servo.h>
Servo myservo;

int buttonPin = 2;
int ledPin = 7;
int delayTime = 50;

// variables will change
int buttonStatus = 0;
boolean isServoMoving = false;

void setup()
{
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // attachs the servo on one pin 8 to servo object
  myservo.attach(8);
  myservo.write(0);
}

void loop()
{
  // check if the pushbutton is pressed
  if(digitalRead(buttonPin) == HIGH && buttonStatus == 0)
  {
    Serial.println("Botão pressionado");
    buttonStatus = 1;
    if (isServoMoving) {
      digitalWrite(ledPin, LOW);
      isServoMoving = false;
      Serial.println("Stop servo motor");
    }
    else {
      digitalWrite(ledPin, HIGH);
      isServoMoving = true;
      Serial.println("Start servo motor");
    }
    delay(100);
  }

  if(digitalRead(buttonPin) == LOW && buttonStatus == 1)
  {
    Serial.println("Botão solto");
    buttonStatus = 0;    
    delay(100);
  }

  if(isServoMoving) {
    StartServo();
  }
  else {
    StopServo();
  }
}

void StartServo() {  
  for(int angle = 15; angle < 180; angle += 15) {
  myservo.write(angle);
  delay(delayTime);
  }
  for(int angle = 180; angle >= 0; angle -= 15) {
  myservo.write(angle);
  delay(delayTime);
  }
}

void StopServo() {
  myservo.write(0);
  delay(delayTime);
}
