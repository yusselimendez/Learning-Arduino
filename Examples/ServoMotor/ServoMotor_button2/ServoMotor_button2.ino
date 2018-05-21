/*
 * ServoMotor
 * Controlling servomotor with push button and 
 * turnOn led when motor is moving
 */
 
#include <Servo.h>
Servo servo;

int buttonPin = 2;
int ledPin = 0;
int servoPin = 4; // Porta Digital 4 PWM

// variables will change
int buttonStatus = 0;
boolean isServoMoving = false;
int theta = 0;
int direc = 0;

void setup()
{
  Serial.begin(115200);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // attachs the servo on servoPin
  servo.attach(servoPin);
}

void loop()
{
  // check if the pushbutton is pressed
  if(digitalRead(buttonPin) == HIGH && buttonStatus == 0)
  {
    Serial.println("Botão pressionado");
    buttonStatus = 1;
    if (isServoMoving) {
      //digitalWrite(ledPin, LOW);
      isServoMoving = false;
      Serial.println("Stop servo motor");
    }
    else {
      //digitalWrite(ledPin, HIGH);
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
    MoveServo();
  }
  else {
    StopServo();
  }
}


void MoveServo() {  
  servo.write(theta);
  delay(50);
  
  if(direc == 0) {
    theta += 15;
  }
  if(direc == 1) {
    theta -= 15;
  }
  if(theta == 180) {
    direc = 1;
  }
  if(theta == 0) {
    direc = 0;
  }
}

void StopServo() {
  servo.write(0);
  delay(50);
}

