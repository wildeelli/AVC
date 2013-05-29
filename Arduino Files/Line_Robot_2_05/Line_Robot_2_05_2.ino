
void setup()
{
  QTRinit(true);
  mtrInit();
  delay(200);
  Serial.begin(9600);
}

void loop()
{
  int sensor = QTRpos();
  // these lines may need swapping if the sensor is the other way around
  Serial.println(sensor);
  if (sensor <3000)
    turnLeft(200, 200);
  
  else if (sensor >=5000)
    turnRight(200, 200);
  forwards(255);
}x  
