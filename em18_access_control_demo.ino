/* This is demonstration code for the EM-18 RFID reader module. This module lacks proper documentation and  
 *  is reported to show trouble working with the hardware serial port on the hardware serial port on the
 *  Arduino UNO board.
 *  This example makes use of a Software Serial port initialsed on pins 10&11 on th UNO. The TX pin of EM-18
 *  should be connected to D10 on the Arduino.
 *  
 *  Example by Aravind Jayan from Mak3r Space
 *  
 *   This example code is in the public domain.
 */

#include <SoftwareSerial.h>

char j=0,x;
char Card_No[13];
char rfid_N0[13]="14001BD4DE05";// Replac this with the ID of your card

SoftwareSerial mySerial(10, 11); // RX, TX
 
void setup() 
{
     mySerial.begin(9600);
     Serial.begin(9600);
     Serial.println("Swipe Card to login");

}
 
void loop() 
{ 
  if (mySerial.available()>0) 
  {
    x=mySerial.read();          
    Card_No[j] =x;                    // Save the read_data to an array
    j++;
    if(j==12)                         // After intake of 12 character 
    {  
      Card_No[j]='\0';
      j=0;
      Serial.print("Found Card with ID ");
      Serial.println(Card_No); 
      delay(3000);
      if(!strcmp(rfid_N0,Card_No))
      {                               // Matching found in read_dat & card_id
        Serial.println("Login succesful");
        delay(3000);
      }
      else                            // No matching found in read_dat & card_id
      {  
        Serial.println("Login failed! Wrong ID");
        delay(3000);
      }
    }  
  }

  
}
