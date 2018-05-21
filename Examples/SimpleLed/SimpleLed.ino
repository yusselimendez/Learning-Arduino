/*
LED:
Led is on for half second and off for half second
*/

void setup()
{
  pinMode(16, OUTPUT);
}

void loop()
{
  digitalWrite(16, HIGH);
  delay(500);
  digitalWrite(16, LOW);
  delay(500);
}
