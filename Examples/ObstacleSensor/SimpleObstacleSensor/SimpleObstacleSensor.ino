int obstacle;
int pinOutput = 16;
int count = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  obstacle = digitalRead(pinOutput);
  
  if (obstacle == HIGH)
  {
    Serial.println("Obstáculo detectado!");
    count++;
    Serial.println(count);
  }
  delay(300);
}

