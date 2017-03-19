/*
*	Eren ERİŞ
*	Arduino RS-485 İletişim Master
*	www.ereneris.net
*/
#include <SoftwareSerial.h>

#define SSerialRX        10  
#define SSerialTX        11  

#define SSerialTxControl 3   

#define RS485Transmit    HIGH
#define RS485Receive     LOW

#define Pin13LED         13

SoftwareSerial RS485Serial(SSerialRX, SSerialTX); 

int byteReceived;
int byteSend;

void setup() 
{
  Serial.begin(9600); 
  pinMode(Pin13LED, OUTPUT);   
  pinMode(SSerialTxControl, OUTPUT);    
  
  digitalWrite(SSerialTxControl, RS485Receive);  
  
  RS485Serial.begin(4800);  

}


void loop()   
{
  digitalWrite(Pin13LED, HIGH);  
  if (Serial.available())
  {
    byteReceived = Serial.read();
    
    digitalWrite(SSerialTxControl, RS485Transmit); 
    RS485Serial.write(byteReceived);          
    
    digitalWrite(Pin13LED, LOW);   
    delay(10);
    digitalWrite(SSerialTxControl, RS485Receive);       
  }
  
  if (RS485Serial.available())  
   {
    digitalWrite(Pin13LED, HIGH); 
    byteReceived = RS485Serial.read();   
    Serial.write(byteReceived); 
    delay(10);
    digitalWrite(Pin13LED, LOW);   
   }  

}
