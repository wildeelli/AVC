#define LEFT_FORWARDS 1
#define LEFT_BACKWARDS 2
#define LEFT_STOP 0
#define RIGHT_FORWARDS 1
#define RIGHT_BACKWARDS 2
#define RIGHT_STOP 0
#define FORWARDS 1
#define REVERSE 2
#define STOP 0

const int ledPin = 13;
int incomingByte;
int left, right;

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
//    left = incomingByte >> 4;
//    right = incomingByte & 0b1111;
//    if (left == FORWARDS)
//      motorLeft(255, 1);
//    else if (left == REVERSE)
//      motorLeft(255, 0);
//    else if (left == STOP);
//      motorLeft(0, 1);
//    if (right == FORWARDS)
//      motorRight(255, 1);
//    else if (right == REVERSE)
//      motorRight(255, 1);
//    else if (right == STOP)
//      motorRight(0, 1);
//    else motorStop();
    
    if (incomingByte == 'q')
      motorLeft(100, HIGH);
    else if (incomingByte == 'z')
      motorLeft(100, LOW);
    else if (incomingByte == 'a')
      motorLeft(0, LOW);
    else if (incomingByte == 'e')
      motorRight(100, HIGH);
    else if (incomingByte == 'c')
      motorRight(100, LOW);
    else if (incomingByte == 'd')
      motorRight(0, LOW);
    else if (incomingByte == 'w')
      forwards(100);
    else if (incomingByte == 'x')
      reverse(100);
      else motorStop();
    
  }
  Serial.println(incomingByte);
}
