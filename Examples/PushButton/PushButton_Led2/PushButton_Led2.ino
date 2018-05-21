/* 
Push button:
TurnOn led when pushbutton is pressed and TurnOff led when pushbutton is pressed again
*/

int buttonPin = 2;
int buttonStatus = 0;

int ledPin = 7;
boolean isTurnOn = false;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH && buttonStatus == 0)
  {
    Serial.println("Botão pressionado");
    buttonStatus = 1;
    if (isTurnOn) {
      digitalWrite(ledPin, LOW);
      isTurnOn = false;
      Serial.println("Turn off led");
    }
    else {
      digitalWrite(ledPin, HIGH);
      isTurnOn = true;
      Serial.println("Turn on led");
    }
    delay(100);
  }

  if(digitalRead(buttonPin) == LOW && buttonStatus == 1)
  {
    Serial.println("Botão solto");
    buttonStatus = 0;    
    delay(100);
  }
}
