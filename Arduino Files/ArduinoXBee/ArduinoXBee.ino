#include <SoftwareSerial.h>
// it sets up  second serial port for 
// comminacating with the radio over pins 4 and 5

int zb_txPin = 5;
int zb_rxPin = 4;

SoftwareSerial xBeeSerial(zb_rxPin, zb_txPin); // RX, TX

//SEND FRAME CODE
// array of chars to be send over the radio
char frame_to_xBee[256];
int n_frame_to_xBee;      // size of the array

//RECIEVE FRAME CODE
// array of chars received from the radio
char frame_from_xBee[256];
int n_frame_from_xBee;

int ex_flag=0;
char data[64];
int complete=0;
int i=0;

void setup()
{
  // start two serial ports
  
  //TESTING
  Serial.begin(9600);     // for communacations with computer
  //END TESTING
  
  xBeeSerial.begin(9600); // for communications with the radio
  
  mtrInit();
}

//MAIN CODE!!
// endlesly loops checking for data from the radio
// and executing commands
void loop()
{
  
 //THIS CODE RECIEVES
 if ( ReceiveXBee(2000) > 0) 
  {
    PrintReceivedFrame();
  };
  
  //NEED CODE THAT SENDS DATA
 
 
 
 
  //END DATA SEND 
  
}
//THIS IS CALLED ENDLESSLY!!


//CONDITION to read from transmit buffer
// waits timeout millisecs (2000ms = 2s) and receives all the data
// available from the radio
// returns number of bytes received
int ReceiveXBee(int timeout)
{
  char in_byte;         // buffer to read char from the radio
  n_frame_from_xBee = 0 ; 
  
  delay(timeout);      // wait timeout milliseconds
  
  
  if ( xBeeSerial.available() == 0)
  {
    return 0; // nothing is available from the radio
  }
  
  // read data until there are some in radio buffer
  while ( xBeeSerial.available() > 0 )
  {
     in_byte = xBeeSerial.read();  // reads one byte from radio buffer
     
     if (in_byte==0x7E){
       ex_flag=1;
       i=1; complete=0;
     }
     if (ex_flag==1){
       data[i]=in_byte;
       i++;
       Serial.print(data[i], HEX);
     }
     if (i==24){
       ex_flag=0;
       complete=1;
     }
     if (complete==1){
       ExecuteCommand();
     }
     
     
     
     
//     frame_from_xBee[n_frame_from_xBee] = in_byte;
     //Serial.print(frame_from_xBee[n_frame_from_xBee],HEX);  // 
//     n_frame_from_xBee++;
  }
  return i;
}

//DO ACTION
// print what was received from the radio 
// to the screen (as hexadecimal numbers)
void PrintReceivedFrame()
{
  int i;
  Serial.println("received");
  for ( i = 0 ; i < n_frame_from_xBee ; i++ )
  {
     Serial.print(frame_from_xBee[i],HEX);  // Print
     Serial.print(" ");  // Print
  }
  Serial.println(" ");
}

// extact information bytes from xBee
// frame and executes the command
void ExecuteCommand()
{
   //Response code for recieved
   

   char first=data[17], second=data[18], third=data[19];
   if (first=='q'){
     motorLeft(255, HIGH);
   } else if (first=='z'){
     motorLeft(255, LOW);
   } else {
     motorLeft(0, LOW);
   }
   
   if (second=='e'){
     motorRight(255, HIGH);
   } else if (second=='c'){
     motorRight(255, LOW);
   } else {
     motorRight(0, LOW);
   }
   
   
   
   
   
}
//Not called anywhere.


