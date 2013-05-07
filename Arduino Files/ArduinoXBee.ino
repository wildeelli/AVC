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




void setup()
{
  // start two serial ports
  
  //TESTING
  Serial.begin(9600);     // for communacations with computer
  //END TESTING
  
  xBeeSerial.begin(9600); // for communications with the radio
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
     frame_from_xBee[n_frame_from_xBee] = in_byte;
     //Serial.print(frame_from_xBee[n_frame_from_xBee],HEX);  // 
     n_frame_from_xBee++;
  }
  return n_frame_from_xBee;
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
}
//Not called anywhere.






// sends fixed string through xBee
void SendToZB(){
  
  int j;
  unsigned int check_sum_total = 0;
  unsigned int CRC = 0;
  
   // delimiter
  frame_to_xBee[0] = 0x7E;
  // length
  frame_to_xBee[1] = 0x00;
  frame_to_xBee[2] = 0x16; // length
  //API ID
  frame_to_xBee[3] = 0x10; // tramsmission frame
  frame_to_xBee[4] = 0x01;
  // destination 64 bit address - broadcast
  frame_to_xBee[5] = 0x00;
  frame_to_xBee[6] = 0x00;
  frame_to_xBee[7] = 0x00;
  frame_to_xBee[8] = 0x00;
  frame_to_xBee[9] = 0x00;
  frame_to_xBee[10] = 0x00;
  frame_to_xBee[11] = 0xFF;
  frame_to_xBee[12] = 0xFF;
  // destination 16 bit address - broadcast
  frame_to_xBee[13] = 0xFF;
  frame_to_xBee[14] = 0xFE;
  // number of hops
  frame_to_xBee[15] = 0x00;
  //option
  frame_to_xBee[16] = 0x00;
  //data
  frame_to_xBee[17] = '0';
  frame_to_xBee[18] = '0';
  frame_to_xBee[19] = '0';
  frame_to_xBee[20] = '0';
  frame_to_xBee[21] = '0';
  frame_to_xBee[22] = '0';
  frame_to_xBee[23] = '0';
  frame_to_xBee[24] = '0';
  
  n_frame_to_xBee = 25;

  // add CRC  
 
  for ( j = 3 ; j < n_frame_to_xBee ; j++)
  {
    check_sum_total = check_sum_total + frame_to_xBee[j];
  }
  //Checksum to check the packet has not been lost
  check_sum_total = check_sum_total & 0xFF;
  CRC = 0xFF - check_sum_total;
  //TO DO: add code to repeat transmission if checksum fails on recieving end.
  
  //Serial.println(CRC);
  
  frame_to_xBee[n_frame_to_xBee] = CRC;
  //Puts CRC into the 25th place in the array frame_to_xBee
  
  n_frame_to_xBee++;
  
  //write code to transmit
  for (j = 0; j < n_frame_to_xBee; j++)
  {
    //Write to both transmit, and to computer
    xBeeSerial.write(frame_to_xBee[j]);
    Serial.println(frame_to_xBee[j],HEX);
  }
  Serial.println("transmitting...");
  //End Transmission
}

