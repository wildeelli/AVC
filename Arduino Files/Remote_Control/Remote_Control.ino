#define LEFT_FORWARDS 1
#define RIGHT_FORWARDS 2
#define LEFT_BACKWARDS 3
#define RIGHT_BACKWARDS 4

const int ledPin = 13;

void setup()
{
  Serial.begin();
  pinMode(ledPin, OUTPUT);
  delay(200);
}

void loop()
{
  if (digitalRead(LEFT_FORWARDS))
    Serial.write(1);
  else if (digitalRead(LEFT_BACKWARDS))
    Serial.write(3);
  else
    Serial.write(5);
    
  if (digitalRead(RIGHT_FORWARDS))
    Serial.write(2);
  else if (digitalRead(RIGHT_BACKWARDS))
    Serial.write(4);
  else
    Serial.write(6);
  
  
}
