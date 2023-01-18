#define GET_SIZE(x) (sizeof(x) / sizeof(x[0]))

const int durations[] = { 200, 200, 200, 500, 500, 500, 200, 200, 200 };
const int ledPin = 13;

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  for (int i = 0; i < GET_SIZE(durations); i++)
  {
    flash(durations[i]);
  }
  delay(1000);
}

void flash(int duration)
{
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}
