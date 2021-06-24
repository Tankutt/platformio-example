#include <Arduino.h>

int led1=13;
char message;
void setup() 
{
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available()>0)
  {
    message=Serial.read();
    if(message == '1')
      {
        digitalWrite(led1,HIGH);
        Serial.println("ON");
      }
      else if(message == '2')
      {
        digitalWrite(led1,LOW);
        Serial.println("OFF");
      }

      else if(message == '3')
      {
        
        delay(5000);
        //Serial.println("Message Received...");
      }
  
    }
}