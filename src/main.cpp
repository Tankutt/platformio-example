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

    else
    {
    digitalWrite(led1,LOW);
    delay(message); // message text formatında geliyor ve int olmadığı için pyqt'den gelen değer kadar programı bekletemiyorum.
    Serial.println("evet");
    }
  
    }
}