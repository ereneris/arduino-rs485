/*
*	Eren ERİŞ
*	Arduino RS-485 İletişim Slave
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
  pinMode(2, OUTPUT);  
  
  digitalWrite(SSerialTxControl, RS485Receive);  

  RS485Serial.begin(4800);  
}


void loop()   
{
  if (RS485Serial.available()) 
  {
    byteSend = RS485Serial.read();  
    digitalWrite(Pin13LED, HIGH);  
    delay(10);              
    digitalWrite(Pin13LED, LOW);   

    if(byteSend=='z'){
      digitalWrite(2, HIGH);
    }
    else if(byteSend=='x'){
      digitalWrite(2, LOW);
    }     
  }
}


