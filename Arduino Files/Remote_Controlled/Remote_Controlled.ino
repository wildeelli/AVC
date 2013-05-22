#define LEFT_FORWARDS 1
#define LEFT_BACKWARDS 2
#define LEFT_STOP 0
#define RIGHT_FORWARDS 1
#define RIGHT_BACKWARDS 2
#define RIGHT_STOP 0
#define FORWARDS 1
#define REVERSE 2
#define STOP 0

#define pwm_r 3
#define pwm_l 11
#define dir_r 12
#define dir_l 13

const int ledPin = 13;
int incomingByte;
//int left, right;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  delay(200);
  pinMode(pwm_r, OUTPUT);
  pinMode(dir_r, OUTPUT);  

}

void loop()
{
//    digitalWrite(dir_r, HIGH);
//    analogWrite(pwm_r, 255);
//    delay(500);
//    digitalWrite(dir_r, LOW);
//    delay(500);
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
      motorLeft(255, HIGH);
    else if (incomingByte == 'z')
      motorLeft(255, LOW);
    else if (incomingByte == 'a')
      motorLeft(0, LOW);
    else if (incomingByte == 'e')
      motorRight(255, HIGH);
    else if (incomingByte == 'c')
      motorRight(255, LOW);
    else if (incomingByte == 'd')
      motorRight(0, LOW);
    else if (incomingByte == 'w')
      forwards(255);
    else if (incomingByte == 'x')
      reverse(255);
      else motorStop();
    
  }
  Serial.println(incomingByte);
}
