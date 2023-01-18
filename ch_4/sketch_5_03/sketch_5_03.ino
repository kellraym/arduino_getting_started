char* letters[] = {
  ".-", "-...", "-.-.", "-..",  ".",
  "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-,",
  "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--",
  "-..-", "-.--", "--.."
};

char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

const int dotDelay = 200;
const int ledPin = 13;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  char ch;
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9')
    {
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' ')
    {
      delay(dotDelay * 4);
    }
  }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while(sequence[i] != '\0')
  {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char c)
{
  int delay_time;
  switch(c)
  {
    case '.': delay_time = dotDelay; break;
    case '-': delay_time = dotDelay * 3; break;
    default: delay_time = 0; break;
  }

    digitalWrite(ledPin, HIGH);
    delay(delay_time);
    digitalWrite(ledPin, LOW);
    delay(delay_time);
}
