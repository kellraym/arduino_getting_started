const int ledPin = 13;
const int delayPeriod = 250;

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  static int count = 0;
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);

  if (count == 20)
  {
    count = 0;
    delay(3000);
  }
}
