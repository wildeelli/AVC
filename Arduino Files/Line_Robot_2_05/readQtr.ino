#include <QTRSensors.h>

#define NUM_SENSORS  8
#define TIMEOUT  2500
#define EMITTER_PIN 2
// sensors 0-7 connected to digital pins 3-10 for now
QTRSensorsRC qtrrc((unsigned char[]) {3, 4, 5, 6, 7, 8, 9, 10}, NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
boolean serial;

void QTRinit(boolean printSerial) 
{
  serial = printSerial;
  delay(500);
  int i;
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  for (i=0; i<400; i++)
  {
    qtrrc.calibrate();
  }
  digitalWrite(13, LOW);
  
  if (serial) 
  {
    Serial.begin(9600);
    for (i=0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibratedMaximumOn[i]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  }
  delay(1000);
}

unsigned int QTRpos()
{
  unsigned int position = qtrrc.readLine(sensorValues);
  if (serial)
  {
    unsigned char i;
    for (i=0; i < NUM_SENSORS; i++)
    {
      Serial.print(sensorValues[i] * 10/1001);
      Serial.print(' ');
    }
    Serial.print("  ");
    Serial.println(position);
  }
  delay(250);
  return position;
}
