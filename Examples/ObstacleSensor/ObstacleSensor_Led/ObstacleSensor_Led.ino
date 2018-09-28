int obstacle;
int pinOutput = 16;
int pinLed = 5;
int count = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  digitalWrite(pinLed, LOW);
  obstacle = digitalRead(pinOutput);
  
  if (obstacle == LOW)
  {
    digitalWrite(pinLed, HIGH);
    Serial.println("Obstáculo detectado!");
    count++;
    Serial.println(count);
  }
  delay(300);
}

