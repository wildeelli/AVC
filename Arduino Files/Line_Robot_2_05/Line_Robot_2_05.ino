
void setup()
{
  QTRinit(true);
  mtrInit();
  delay(200);
}

void loop()
{
  int sensor = QTRpos();
  // these lines may need swapping if the sensor is the other way around
  if (sensor <3000)
    turnLeft(200, 200);
  
  else if (sensor >=5000)
    turnRight(200, 200);
  forwards(255);
}
