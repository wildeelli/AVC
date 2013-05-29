#define pwm_r 3
#define pwm_l 11
#define dir_r 12
#define dir_l 13

/** Arduino vicMoto Motor Driver Header version 1.1
    Has methods for forwards, reverse, turning,
    and driving individual motors
    (c) Elliot "wildeone" Wilde 2013 **/

void mtrInit()
{
   pinMode(pwm_l, OUTPUT);
   pinMode(pwm_r, OUTPUT);
   pinMode(dir_l, OUTPUT);
   pinMode(dir_r, OUTPUT);
   
   analogWrite(pwm_l, 0);
   analogWrite(pwm_r, 0);
}
void forwards(byte speed, int duration)
{
  forwards(speed);
  delay(duration);
}
void forwards(byte speed)
{
  motorLeft(speed, HIGH);
  motorRight(speed, HIGH);
}

void reverse(byte speed, int duration)
{
  reverse(speed);
  delay(duration);
  motorStop();
}
void reverse(byte speed)
{
  motorLeft(speed, LOW);
  motorRight(speed, LOW);
}

void turnLeft(byte speed, int duration)
{
  turnLeft(speed);
  delay(duration);
  motorStop;
}
void turnLeft(byte speed)
{
  digitalWrite(dir_l, HIGH);
  analogWrite(pwm_l, speed);
  analogWrite(pwm_r, LOW);
}

void turnRight(byte speed, int duration)
{
  turnRight(speed);
  delay(duration);
  motorStop();
}
void turnRight(byte speed)
{
    digitalWrite(dir_r, HIGH);
  analogWrite(pwm_r, speed);
  analogWrite(pwm_l, LOW);
}

void motorLeft(byte speed, byte direction)
{
  digitalWrite(dir_l, direction);
  analogWrite(pwm_l, speed);
}

void motorRight(byte speed, byte direction)
{
  digitalWrite(dir_r, direction);
  analogWrite(pwm_r, speed);
}

void pivotClockwise(byte speed, int duration){
	pivotClockwise(speed);
	delay(duration);
	motorStop();
}

void pivotClockwise(byte speed){
	analogWrite(pwm_r, LOW);
	analogWrite(pwm_l, LOW);
	digitalWrite(dir_r, LOW);
	digitalWrite(dir_l, HIGH);
	analogWrite(pwm_r, speed);
	analogWrite(pwm_l, speed);
}

void pivotCounterClockwise(byte speed, int duration){
	pivotCounterClockwise(speed);
	delay(duration);
	motorStop();
}

void pivotCounterClockwise(byte speed){
	analogWrite(pwm_r, LOW);
	analogWrite(pwm_l, LOW);
	digitalWrite(dir_r, HIGH);
	digitalWrite(dir_l, LOW);
	analogWrite(pwm_r, speed);
	analogWrite(pwm_l, speed);
}

void motorStop(){
  analogWrite(pwm_l, 0);
  analogWrite(pwm_r, 0);
}
