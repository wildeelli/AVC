#define LEFT_FORWARDS 1
#define RIGHT_FORWARDS 2
#define LEFT_BACKWARDS 3
#define RIGHT_BACKWARDS 4
#define FORWARDS 1
#define REVERSE 0

const int ledPin = 13;
int incomingByte;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  delay(200);
}

void loop()
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == LEFT_FORWARDS)
      motorLeft(255, FORWARDS);
    else if (incomingByte == RIGHT_FORWARDS)
      motorRight(255, FORWARDS);
    else if (incomingByte == LEFT_BACKWARDS)
      motorLeft(255, REVERSE);
    else if (incomingByte == RIGHT_BACKWARDS)
      motorRight(255, REVERSE);
    else if (incomingByte == LEFT_FORWARDS+4)
      motorLeft(0, FORWARDS);
    else if (incomingByte == RIGHT_FORWARDS+4)
      motorRight(0, FORWARDS);
    else motorStop();
  }
}
