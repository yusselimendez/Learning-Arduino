/* 
Push button:
Print in monitor when button is push and back 
*/

int buttonPin = 2;
int buttonStatus = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT); //D4
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH && buttonStatus == 0)
  {
    Serial.println("Botão pressionado!");
    buttonStatus = 1;
    delay(100);
  }

  if(digitalRead(buttonPin) == LOW && buttonStatus == 1)
  {
    Serial.println("Botão solto!");
    buttonStatus = 0;    
    delay(100);
  }
}
