#define LEFT_FORWARDS
#define RIGHT_FORWARDS
#define LEFT_BACKWARDS
#define RIGHT_BACKWARDS

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
  else
    Serial.write(-1);
  if (digitalRead(RIGHT_FORWARDS))
    Serial.write(2);
  else
    Serial.write(-2);
  if (digitalRead(LEFT_BACKWARDS))
    Serial.write(3);
  else
    Serial.write(-3);
  if (digitalRead(RIGHT_BACKWARDS))
    Serial.write(4);
  else
    Serial.write(-4);
  
  
  
  
  
}
