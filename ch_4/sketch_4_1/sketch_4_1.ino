const int ledPin = 13;
const int delayPeriod = 250;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  // put your setup code here, to run once:
}

void loop() 
{
  flash(ledPin, 10, delayPeriod);
  delay(3000);
  // put your main code here, to run repeatedly:
}

void flash(int led, int numFlashes, int delayTime)
{
  for (int i = 0;  i < numFlashes; i++)
  {
    digitalWrite(led, HIGH);
    delay(delayTime);
    digitalWrite(led, LOW);
    delay(delayTime);
  }

}
