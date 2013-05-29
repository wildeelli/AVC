#define LEFT_FORWARDS 13
#define RIGHT_FORWARDS 12
#define LEFT_BACKWARDS 11
#define RIGHT_BACKWARDS 10

const int ledPin = 13;

void setup()
{
  Serial.begin(9600);
//  pinMode(ledPin, OUTPUT);

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
    delay(200);
}

void loop()
{
//  if (digitalRead(LEFT_FORWARDS))
//    Serial.write(1);
//  else if (digitalRead(LEFT_BACKWARDS))
//    Serial.write(3);
//  else
//    Serial.write(5);
//    
//  if (digitalRead(RIGHT_FORWARDS))
//    Serial.write(2);
//  else if (digitalRead(RIGHT_BACKWARDS))
//    Serial.write(4);
//  else
//    Serial.write(6);
//  
/*
  Serial.write("\n10: ");
  int r = digitalRead(10);
  Serial.write(r);
  Serial.write("\n11: ");
  r = digitalRead(11);
  Serial.write(r);
  Serial.write("\n12: ");
  r = digitalRead(12);
  Serial.write(r);
  Serial.write("\n13: ");
  r = digitalRead(13);
  Serial.write(r);
  Serial.write("\n");
  delay(250);*/
  int i=0;
  for (i=10; i<14; i++){
    Serial.print(i);
    Serial.print(':');
    Serial.println(digitalRead(i));
  }
  delay(200);
}
